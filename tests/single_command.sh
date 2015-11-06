#!/bin/sh

cd ..

(echo "ls" && echo "exit") | ./bin/rshell
(echo "echo \"Hi\"" && echo "exit") | ./bin/rshell
(echo "mkdir laaaame" && echo "exit") | ./bin/rshell
(echo "ls" && echo "exit") | ./bin/rshell
