
 * https://matthew-brett.github.io/docosx/flat_packages.html
 * https://matthew-brett.github.io/docosx/legacy_package_redux.html
 * http://preserve.mactech.com/articles/mactech/Vol.26/26.02/TheFlatPackage/index.html
 * http://s.sudre.free.fr/Stuff/Ivanhoe/FLAT.html
 * https://ilostmynotes.blogspot.com/2012/06/mac-os-x-pkg-bom-files-package.html
 * https://stackoverflow.com/questions/11487596/making-macos-installer-packages-which-are-developer-id-ready/11487658#11487658
 * https://github.com/open-eid/osx-installer

## Distribution XML Reference

### allowed-os-versions

Defines OS version requirements. These consist of one or more version ranges, specified as os-version elements. The version of the operating system on the target volume must fall into one of these ranges to allow installation.

 * Attributes: None.
 * Availability: Available in OS X v10.6.6 and later.
 * Content
This element can contain the following element:

### os-version (one or more): The supported OS versions.
app
Identifies an application that must be closed before the package is installed.

Attributes
Attribute name

Type

Description

### id - String

Required. The bundle identifier of the application.

Content
None.

### auxinfo
Reserved.

### background
Defines a background image for the Installer.

Attributes
Requirements: You must provide either the mime-type or uti attribute. If you provide both, they must be consistent.

Attribute name

Type

Description

### alignment - String

Optional. The alignment used to render the background image. Values: center (default), left, right, top, bottom, topleft, topright, bottomleft, and bottomright.

Only used by the Installer.

### file - String

Required. The filename of an image in the distribution package—for example, background.png or ./background.png.

mime-type

String

The standard MIME type of the image.

### scaling - String

Optional. The scaling used to render the background image. Values: tofit (default), none, and proportional.

### uti - String

The UTI type of the image. This attribute is provided because some file types don’t have a MIME type.

Content
None.

### bundle
Defines a single bundle. The meaning of this element differs considerably depending on its parent element; see the parent element’s documentation for details.

Attributes
Attribute name

Type

Description

### CFBundleShortVersionString - String

Optional. The short version string of the bundle, as defined in its Info.plist file.

### CFBundleVersion - String

Optional. The bundle’s version, as defined in its Info.plist file.

### id - String

Required. The identifier of the bundle—that is, the value of CFBundleIdentifier in the bundle’s Info.plist file.

### path - String

Required. The path at which the bundle is installed, relative to where the package is installed. For example, Applications/Sample.app.

### search - Boolean

Optional. Indicates whether to search for the bundle by its identifier if it is not found at the given path. Values: false (default), true.

Only valid when this element is a child of a required-bundles element.

### BuildVersion

-
-
-Reserved.

### SourceVersion

-
-
-Reserved.

Content
None.

### bundle-version
Defines the version of the bundles delivered by the parent element. You do not typically specify this element; productbuild inserts it from the actual package data when the product archive is created.

Attributes
None.

Availability
Available in OS X v10.6.6 and later.

Content
This element can contain the following elements:

### bundle (one or more): The package-relative path and version strings of the bundles installed.
choice
Defines an installation choice of a distribution package.

Attributes
Attribute name

Type

Description

### customLocation

Absolute file path

Optional. Specifies the default installation location, within the installation volume, for this choice. Implies that the user can choose a different installation location. If unspecified, the user cannot choose the installation location for this choice.

### customLocationAllowAlternateVolumes - Boolean

Optional if customLocation is specified; otherwise, not allowed. Specifies whether the user can choose the installation volume. Values: false (default) indicates that the user can choose a different location than what is given by customLocation but cannot change the volume; true indicates that the user can choose the installation volume and the location on that volume. A value of true is only valid for packages that use the Installer.

### description - String, localization key

Required for packages that use the Installer; otherwise, optional. Specifies the description of the installation choice. Localizable.

### description-mime-type - String

Optional. The MIME type of the text data in the description attribute. Values: text/plain (default), text/rtf, or text/html.

### enabled

Boolean JavaScript expression

Optional. Specifies whether the user can select or deselect this option in the Installer customization pane. If false, or a JavaScript expression that evaluates to false, the choice is dimmed so the user cannot select or deselect it. Re-evaluated as the user interacts with the choice tree, so a choice can be enabled or disabled based on the state of other choices. Default value is true.

### id - String

Required. Unique identifier of the installation choice, used to bind this element to the line element that determines its position in the installation-choice hierarchy.

Must match the choice attribute of exactly one line element.

### selected

Boolean JavaScript expression

Optional. Specifies whether this option is selected or deselected for installation. If false, or a JavaScript expression that evaluates to false, the choice will not be installed. In general, you should not declare this attribute on a choice that is visible and enabled, because it can interfere with the user’s selections. Default value is true.

### start_enabled - Boolean

Optional. Specifies whether this option is initially enabled in the Installer customization pane. Values: true (default), or false.

### start_selected - Boolean

Optional. Specifies whether this option is initially selected or deselected for installation. Values: true (default), or false.

### start_visible - Boolean

Optional. Specifies whether this option is initially visible in the Installer customization pane. Values: true (default), or false.

### title - String, localization key

Required. Specifies the title of the installation choice. Localizable.

### visible - Boolean JavaScript expression

Optional. Specifies whether this option is visible in the Installer customization pane. If false, or a JavaScript expression that evaluates to false, the choice is hidden from the user. Default value is true.

Avoid making choices appear and disappear while the user is interacting with the installation process. This provides a poor user experience.

### bundle

-
-
-Reserved.

### customLocationIsSelfContained

-
-
-Reserved.

### tooltip

-
-
-Reserved.

### versStr

-
-
-Reserved.

Content
This element can contain the following element:

### pkg-ref (zero or more): The choice’s packages. You should only associate packages with a choice that has no subchoices (as defined by the hierarchy of line elements).
choices-outline
Defines the installation-choice hierarchy of a distribution package.

Attributes
Attribute name

Type

Description

### ui

-
-
-Reserved.

Content
This element can contain the following element:

### line (one or more): The top-level installation choices.
conclusion
Specifies text that is displayed by Installer at the end of the installation process.

Attributes
Requirements: You must provide either the mime-type or uti attribute. If you provide both, they must be consistent.

Attribute name

Type

Description

### file

String

Required. The filename of the conclusion file in the distribution package—for example, conclusion.rtf.

### mime-type

String

The MIME-type specifier for the data contained in the file.

### uti

String

The UTI-type specifier for the data contained in the file.

### language

-
-
-Reserved.

Content
None.

### domains
Indicates what domains the package may be installed into. If this element is not present, enable_anywhere is true, enable_currentUserHome is false, and enable_localSystem is true.

Attributes
Attribute name

Type

Description

### enable_anywhere

Boolean JavaScript expression

Required. If true, or a JavaScript expression that evaluates to true, the product can be installed at the root of any volume, including nonsystem volumes. Otherwise, it cannot be installed at the root of a volume.

### enable_currentUserHome

Boolean JavaScript expression

Required. If true, or a JavaScript expression that evaluates to true, the product can be installed into the current user’s home directory. Otherwise, it cannot be installed in the current user’s home directory.

A home directory installation is done as the current user (not as root), and it cannot write outside of the home directory. You should enable this only if the product can be installed in the user’s home directory and be completely functional from that location.

### enable_localSystem

Boolean JavaScript expression

Required. If true, or a JavaScript expression that evaluates to true, the product can be installed into the root directory. This attribute should usually be true unless the product can be installed only to the user’s home directory.

Content
None.

### installation-check
Specifies whether the installation host meets the distribution’s system requirements. The installation check passes if the script returns true, any RAM requirements are met, and any graphics requirements are met.

Attributes
Attribute name

Type

Description

### script

Boolean JavaScript expression

Optional. Specifies whether the requirements are met. If true (default), or a Boolean JavaScript expression that evaluates to true, the installation proceeds, subject to the other checks.

If the script evaluates to false, it must also set my.result.type and my.result.message to indicate the severity of the problem and provide a message to display. If my.result.type is Warning, the installation may be allowed to proceed after informing the user.

Content
This element can contain the following elements:

### ram (zero or one): The required RAM.
required-graphics (zero or one): The GPU requirements.
installer-gui-script
The root element of the distribution definition. All other elements in the distribution definition file are children of this element.

Attributes
Attribute name

Type

Description

### minSpecVersion

Integer

Required. The schema version of a distribution file. Use 1 for the version used prior to OS X v10.6.6, or 2 after that.

### maxSpecVersion

-
-
-Reserved.

### verifiedSpecVersion

-
-
-Reserved.

Content
This element can contain the following elements:

background (zero or one)
choice (one or more)
choices-outline (exactly one)
conclusion (zero or one)
domains (zero or one)
installation-check (zero or one)
license (zero or one)
locator (zero or more)
options (zero or one)
pkg-ref (one or more)
product (zero or one)
readme (zero or one)
script (zero or one)
title (exactly one)
volume-check (zero or one)
welcome (zero or one)
license
Specifies text that is displayed by Installer during the installation process.

Attributes
Requirements: You must provide either the mime-type or uti attribute. If you provide both, they must be consistent.

Attribute name

Type

Description

### file

String

Required. The filename of the welcome file in the distribution package—for example, welcome.rtf.

mime-type

Stier for the data contained in the file.

### uti

String

The UTI-fines where a choice fits into the installation-choice hierarctring

Required. Identifies the installation choice associated with this node of the installation-choice hierarchy of a distribution package. The value must match the ID of a choice element. See choice.

Do not reference the same ID from more than one line element, not even from different installation-choice hierarchies; if you do so, the behavior is undefined.

Content
Tnt:

### line (zero or more): The subchoices of this choice.
localn the system.

Attributes
None.

Content
This element can contore the package is installed.

Applications are considered onlys
Specifies the installation properties of a package within the distribution.

Attributes
Attribute name

Type

Description

### allow-external-scripts

Boolean

Optional. Specifies whether the run and runOnce JavaScript functions can be executed. Values: false (default) or true. For information about these functions, see System in Installer JavaScript Reference.

### customize

String

Optional. Specifies whether the user can customize the inst user an opportunity to customize the installation, always preschitectures

String

Optional. A comma-separated list of suppornd 64-bit systems, but x86_64 matches only 64-bit systems.

mpk be performed as part of the installation of this distribution.

Deprecated.

### require-scripts

Boolean

Optional. Indicates whether the distribution uses JavaScript code. Values: true (default) or false. If this value is false, all attributes whose value may be a JavaScript expression must be set to either true or false.

Available in OS X v10.6.6 and later.

### rootVolumeOnly

efines a range of supported OS versions.

This element is desigre attribute. The expectation is that you will know an exact mihe last minor revision before the next major revision, as you w to do if the before attribute were inclusive.

Attributes
Attribute name

Type

Description

### before

String

Optional. The maximum allowed version (exclusive). If the OS version is greater than or equal to this version, installation will be disalloweddisallowed (unless the OS falls in the range of another os-verse

Type

Description

### active

Boolean JavaScript expression

Opn that evaluates to false, the package is not installed, even is an additional way to activate and deactivate packages. It overrides the setting on the parent element.

### auth

String

Defines the authorization level needed to install this package. Values: none or root.

Deprecated. The installation domain determines the necessary authorization level.

### id

String

Required. Uniquely identifies a component package within a distribution packof this attribute is usually the same as the component packageâthe same ID, their attributes will be collapsed together as ily an ID can be used inside of a choice element to bind that chuild sets it from the actual package when the product archive is created.

### onConclusion

String

Optional. Specifies the action to take after the installation has finished. Values, from lowest to highest: None (default), RequireLogout, RequireRestart, or RequireShutdown.

The Installer takes the highest value from all enabled packages and requires the associated action.

### onConclusionScript

String

Optional. A JavaScript expression that evaluates to one of the string values expected for onConclusion. If this attribute is present, any onConclusion attribute is ipecifies the version of the package’s payload.

You typicallylement refers. Typically, you specify a simple filename and productbuild adjusts the URL as needed when the product archive is created. If you define multiple pkg-ref elements with the same ID, exactly one of them should have text content.

This element can contain the following elements:

must-close (zero or one): The application(s) to be closed before installing this package.
bundle-version (zero or one): The bundle version.
relocateor more): The information to support relocatable bundles.
To prment. For example:

<pkg-ref id="abc">x.pkg</pkg-ref>
<pkg-ref ed. The top-level product identifier. The value should be the sred. The version string for the top-level product. The value should be the same as the short version string of the contained application.

Availability
Available in OS X v10.6.6 and later.

Content
None.

### ram
Specifies the minimum amount of RAM that thion

### min-gb

String

Required. The minimum required RAM in giga30 bytes.)

Availability
Available in OS X v10.6.6 and later.

String

Required. The filename of the readme file in the distriThe UTI-type specifier for the data contained in the file.

### language

-
-
-Reserved.

Content
None.

### relocate
Describes a relocatable bundle. Relocatable bundles allow the user to install an upgrade in the same path as the current version. The path is le is specified by the child bundle element. For example, appliothing. If the search returns an array of results, the first redle (within the package) that will be installed at the path. Theady installed on the system.

If the child bundle element has a version specified, this is interpreted as the minimum supported version for that bundle. It may also have its search attribute set to true, indicating that the bundle should be located by its identifier if it doesn’t exist at the specified path.

Attributes
Attribute name

Type

Description

all

Boolean

Opti

String, localization key

Optional. A description of the reque): The required bundles.
required-cl-device
Specifies requiremhe predicate from being interpreted by the XML parser, mark it as CDATA content.

### required-gl-renderer
Specifies requirements that must be met by at least one OpenGL hardware renderer.

Attributes
None.

Availability
Available in OS X v10.6.8 and later.

Content
The predicate, as a string. For details about the predicate format, see Specifying required OpenGL capabilities f in the predicate from being interpreted by the XML parser, maration key

Optional. A description of the graphics requirement.sage unless the requirements are very straightforward.

single-es, or true to require a single device to simultaneously meet both requirements.

Content
This element can contain the following elements:

### required-cl-device (zero or one): The OpenCL requ JavaScript functions.

Attributes
Attribute name

Type

Descrialled from attributes of other elements.

To prevent charactersTA[
// ... JavaScript ...
]]>
</script>
If you choose not to md by another search rule or bound to a bundle via a relocate eUniquely identifies the search; used in the search-id attribute of other elements to reference this search.

### script

String

Required if type is script; otherwise, not allowed.

A JavaScript expression that evaluates to false, a path as a string, or an array of paths. If it returns an array of paths, the firstnction must be defined in the child script element.

search-id
element. This allows the other search to be qualified for certa is component; otherwise, not allowed.

A path to a bundle. If element, then the path is used as the search result.

### type

String

Required. Indicates the type of the search. Valid values are:

component Search for a bundle on disk that matches the identifier and version strings given by the child bundle elemeitle or a localization key used to look up the title.

volume-cbute and the child elements must pass.

Attributes
Attribute name

Type

Description

### script

Boolean JavaScript expression

Required. Specifies whether the requirements for installing on aresult.type and my.result.message to indicate the severity of t volume being checked.

Content
This element can contain the fot volume.
required-bundles (zero or one): The bundles that mustistent.

Attribute name

Type

Description

### file - String

Requibution package—for example, welcome.rtf.

### mime-type - String

The MIME-type specifier for the data contained in the file.

### uti - String

The UTI-type specifier for the data contained in thele.

### language

-
-
-Reserved.

Content
None.

