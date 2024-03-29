/*
 */
package com.redgates.jenkins.plugins.storage;

import java.io.IOException;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

import javax.annotation.Nullable;

import static com.google.common.base.Preconditions.checkArgument;
import static com.google.common.base.Preconditions.checkNotNull;
import static com.google.jenkins.plugins.storage.AbstractUploadDescriptor.GCS_SCHEME;

import hudson.Extension;
import hudson.Launcher;
import hudson.model.AbstractBuild;
import hudson.model.AbstractProject;
import hudson.model.Action;
import hudson.model.BuildListener;
import hudson.model.Result;
import hudson.tasks.BuildStepDescriptor;
import hudson.tasks.BuildStepMonitor;
import hudson.tasks.Publisher;
import hudson.tasks.Recorder;

/**
 * A Jenkins plugin for uploading files to Google Cloud Storage (GCS).
 */
@RequiresDomain(value = StorageScopeRequirement.class)
public class StorageUploader extends Recorder {

  /**
   * Construct the GCS uploader to use the provided credentials to
   * upload build artifacts.
   *
   * @param credentialsId The credentials to utilize for authenticating with GCS
   * @param uploads The list of uploads the user has requested be done
   */
  @DataBoundConstructor
  public StorageUploader(
      String credentialsId, @Nullable List<AbstractUpload> uploads) {
    this.credentialsId = checkNotNull(credentialsId);
    if (uploads == null) {
      this.uploads = ImmutableList.<AbstractUpload>of();
    } else {
      checkArgument(uploads.size() > 0);
      this.uploads = uploads;
    }
  }

  /**
   * The unique ID for the credentials we are using to
   * authenticate with GCS.
   */
  public String getCredentialsId() {
    return credentialsId;
  }

  private final String credentialsId;

  /**
   * The credentials we are using to authenticate with GCS.
   */
  public GoogleRobotCredentials getCredentials() {
    return GoogleRobotCredentials.getById(getCredentialsId());
  }

  /**
   * The set of tuples describing the artifacts to upload, and where
   * to upload them.
   */
  public Collection<AbstractUpload> getUploads() {
    return Collections.unmodifiableCollection(uploads);
  }

  private final List<AbstractUpload> uploads;

  /**
   * {@inheritDoc}
   */
  @Override
  public boolean perform(AbstractBuild<?, ?> build, Launcher launcher,
      BuildListener listener) throws IOException, InterruptedException {
    // TODO(mattmoor): threadpool?
    boolean result = true;
    for (AbstractUpload upload : uploads) {
      try {
        upload.perform(getCredentialsId(), build, listener);
      } catch (UploadException e) {
        e.printStackTrace(listener.error(
            Messages.StorageUtil_PrefixFormat(
                getDescriptor().getDisplayName(),
                Messages.GoogleCloudStorageUploader_ExceptionDuringUpload(
                    e.getMessage()))));
        build.setResult(Result.FAILURE);
        result = false;
      }
    }
    return result;
  }

  /**
   * {@inheritDoc}
   */
  @Override
  public BuildStepMonitor getRequiredMonitorService() {
    return BuildStepMonitor.NONE;
  }

  /**
   * {@inheritDoc}
   */
  @Override
  public DescriptorImpl getDescriptor() {
    return (DescriptorImpl) super.getDescriptor();
  }

  /**
   * Descriptor for the extension for uploading build artifacts to
   * Google Cloud Storage.
   */
  @Extension
  public static final class DescriptorImpl
      extends BuildStepDescriptor<Publisher> {

    /**
     * {@inheritDoc}
     */
    @Override
    public boolean isApplicable(
        @SuppressWarnings("rawtypes") Class<? extends AbstractProject> aClass) {
      // Indicates that this builder can be used with all kinds of project types
      return true;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public String getDisplayName() {
      return Messages.GoogleCloudStorageUploader_DisplayName();
    }

    /**
     * @return the default uploads when the user configure
     * {@link GoogleCloudStorageUploader} for the first time.
     */
    public List<AbstractUpload> getDefaultUploads() {
      StdoutUpload upload = new StdoutUpload(GCS_SCHEME, null,
          "build-log.txt", null /* legacy arg: bucketNameWithVars */);
      upload.setForFailedJobs(true);
      return ImmutableList.<AbstractUpload>of(upload);
    }

    public List<AbstractUploadDescriptor> getUploads() {
      return AbstractUpload.all();
    }
  }

  /**
   * {@inheritDoc}
   */
  @Override
  public Action getProjectAction(AbstractProject<?, ?> project) {
    return new ProjectGcsUploadReport(project);
  }
}
