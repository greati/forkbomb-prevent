# forkbomb-prevent
This project aims to show how to avoid a Linux system crash by a fork bomb. 

## Programmer's view
The `preventbomb.cpp` file is a C++ program which contains a fork bomb and some code to
avoid the system crash. It uses the setrlimit function to give an upper bound on the
number of processes the user can have.
You can run it and check its effects just by compilling with

```
g++ preventbomb.cpp -o preventbomb -std=c++11
```
and executing with
```
./preventbomb [maximum number of processes]
```
## Administrator's view
The script `configmaxproc` can be executed by an administrator in order to
limit the number of processes for common users. Its effects are permanent
because they are stored in the `/etc/bash.bashrc` file, which is
executed every time a terminal is opened.

You can run just by typing
```
sudo ./configmaxproc
```
and following the instructions. Maybe it will be necessary to run
```
source /etc/bash.bashrc
```
for making changes available to the current terminal.


## Contributors ##
---
Vitor Greati
Vinicius Campos
