#!/bin/bash

cd ../../../
docker rmi -f ereva/valgrind/matrix
docker build . -t ereva/valgrind/matrix -f materials/build/Valgrind/Dockerfile
docker run --rm ereva/valgrind/matrix
