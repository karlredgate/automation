Docker Image Skel
=================

Create a docker image without docker

## RPM

 * https://rpm.org/devel_doc/file_format.html

Want to be able to install rpms without rpm - need rpm2cpio

 * lead header (96 bytes)
 * signature header (12 bytes, followed by 4 byte length, followed by data)
 * payload header   (same)
 * payload

header HM1, HM2, HM3, VER, (4 bytes reserved), 4 bytes count of indexes,
4 bytes size of data store

index entries:
 4 bytes tag, 4 bytes type, 4 bytes offset, 4 bytes count

skip 96 bytes,
skip 8 bytes, read 4 bytes -> count, read 4 bytes -> size,
skip count * 16 bytes, skip size bytes


https://en.wikipedia.org/wiki/Zstandard

another tool - to take a docker image tar and collapse the layers

## Image

Docker image format - tarball of:
 * manifest.json points to hash.json for individual images
   * manifest also points at layer files
 * hash.json metainfo about image points at "diff"s which are not the image ids
 * layers are a directory with a sig-like id
   * layer.tar
   * "json" file
   * VERSION file
 * layer contains set of files to write into the layer

```
 +---- manifest.json
 |
 +---- repositories  (also json)
 |
 +---- HASH1.json
 |
 +---+ HASH2 (layer1)
 |   |
 |   +----- json
 |   |
 |   +----- layer.tar
 |   |
 |   +----- VERSION
 |
 +---+ HASH3 (layer2)
     |
     +----- json
     |
     +----- layer.tar
     |
     +----- VERSION
```

 * https://docs.docker.com/registry/spec/deprecated-schema-v1/
 * https://github.com/moby/moby/blob/master/image/spec/v1.md
 * https://docs.docker.com/registry/spec/manifest-v2-2/
 * https://github.com/moby/moby/blob/master/pkg/tarsum/tarsum_spec.md
 * https://dzone.com/articles/docker-manifest-a-peek-into-images-manifestjson-fi
 * https://docs.docker.com/engine/reference/commandline/manifest/
