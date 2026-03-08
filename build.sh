#!/bin/bash
cp src/nosebert.png build/nosebert.png
g++ src/nosebert.cpp -o build/nosebert.exe -lSDL3 -lSDL3_image
echo "Build Finished"