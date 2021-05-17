#!/bin/bash

# this sample nonce comes from the RFC
nonce=$( echo -n "the sample nonce" | base64 )
# Print the header as it would appear
echo "Sec-WebSocket-Key: $nonce"

# This is the well known UUID used in this header
uuid=258EAFA5-E914-47DA-95CA-C5AB0DC85B11
# create the key for the response using sha-1
key=$( echo -n "$nonce$uuid" | shasum | awk '{printf("%s",$1)}' )
echo "Key: $key"

# The key needs to be base64 encoded from the binary representation
# xxd takes ascii rep of hex data and makes it binary
response=$( echo -n $key | xxd -r -p - | base64 )
echo "Sec-WebSocket-Accept: $response"

# echo -n dGhlIHNhbXBsZSBub25jZQ==258EAFA5-E914-47DA-95CA-C5AB0DC85B11  | shasum | awk '{printf("%s", $1)}'  |  xxd -r -p - | base64
# s3pPLMBiTxaQ9kYGzzhZRbK+xOo=
