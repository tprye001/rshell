#!/bin/sh

cd ..
cd ./bin

(echo "ls" && echo "exit") | ./rshell
echo "echo \"Hi\"" | ./rshell
echo "mkdir laaaame" | ./rshell
echo "ls" | ./rshell
