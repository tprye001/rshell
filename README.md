Jonathan Alcaraz

Tricia Pryer
# CS100 Assignment 1 | rshell

People much smarter than us have made shells much better than ours, but this is ours and we love it.

Rshell is a shell made with C++. Below are its capabilities.

### Commands and Connectors

Rshell currently supports the following commands:

| Command | Description |
| ------- | ----------- |
| `ls [FLAGS]` | Prints everything in working directory. |
| `echo [ARGS]` | Prints `[ARGS]` to standard out. |
| `mkdir [DIR]` | Creates a directory `[DIR]` in working directory. |

(these should all work with any flags in bash)

Rshell currently supports the following connectors:

| Connector | Description |
| --------- | ----------- |
| `cmd1 ; cmd2` | Executes both `cmd1` and `cmd2`. |
| `cmd1 || cmd2` | Executes `cmd2` only if `cmd1` fails to execute. |
| `cmd1 && cmd2` | Executes `cmd2` only if `cmd1` successfully executes. |

(where `cmd1` and `cmd2` are supported 
commands which may include arguments and flags)

Rshell also supports an `exit` command and commenting with `#`
(everything after `#` is ignored).

### Extensibility

We tried to keep rshell generally extensible.

Our connectors are not very extensible. Most of the connector functionality is hard-coded into rshell. Adding any more connectors would require editing our main source file.

Our commands on the other hand are easily extensible. Rshell simply calls an executable in `/bin/`, so adding a new command is simply done by adding an executable with in bin (you shouldn't even need to recompile).

### Known Bugs
- rshell interpets `"` as part of string
- rshell freaks out when you end a command with a connector

### Notes
- When `mkdir` gets called on a directory that already exists, mkdir throws a warning, but execvp still registers as succeful. We consider this as `mkdir` executing properly, but bash handles it differently.

### Authors
Tricia Pryer _tprye001@ucr.edu_ 

Jonathan Alcaraz _jalca011@ucr.edu_
