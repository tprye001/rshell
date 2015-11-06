#!/bin/sh

cd ..

echo "ls" > temp.txt
./bin/rshell < temp.txt
