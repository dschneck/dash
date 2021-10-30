<div style="display: flex;">
<img src="https://img.shields.io/badge/c-c%2B%2B-blue">
<img src="https://img.shields.io/badge/-Unix-brightgreen">
<img src="https://img.shields.io/badge/-Posix-yellow">
</div>

# Dash #
- - - -
... is my own shell - **David Again SHell** :thumbsup:
To run, run the following commands:
	make
	./run.out

There will be warnings but everything is fine.

If you'd like to load a history file, set that as the first and only argument.

Ex.
	./run.out history.txt

## TODO ##
- - - -
- [x] Basic Shell Layout
- [] clean up/document code
- [x] implement __movetodir__
- [x] implement __whereami__
- [x] implement __history__
- [x] implement __byebye__
- [] implement __replay__
- [x] implement __start__
- [x] implement __background__
- [x] implement __dalek__
- [x] implement __repeat__
- [x] implement __dalekall__

## Extra Credit ##

# dalekall
Works exactly like the doc describes. No arguments, exterminates all of the processes spawned by shell

# repeat

Works exactly like the doc describes. Only will run programs that are external to this shell (i.e. anything that you would use start or background to call, like ls, vim, grep, etc.) 
Ex. repeat 4 /bin/ls

It would print the current directory 4 times
