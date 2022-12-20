#!/bin/bash

cd ../../../
docker rmi -f ereva/valgrind/math
docker build . -t ereva/valgrind/math -f materials/build/Valgrind/Dockerfile
docker run --rm ereva/valgrind/math
