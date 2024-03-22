# Dining Philosophers problem
## Introduction
The dining philosophers problem is an exemple problem often used in concurrent alorithm to illustrate synchronization issues and techniques for resolving them. This solution in C++ utilizes mutexes and ncurses for synchronization and visualization, respectively.
## Preview
![preview screenshot](/img/preview.png)

# Getting started
## Prerequisites
- g++
- ncurses

# Installation
- Clone the repo
```bash
git clone https://github.com/Chavoniasty/dining-philosophers.git
```
- Build
```bash
g++ -o build/main src/main.cpp src/Fork.cpp src/Table.cpp src/Philosopher.cpp src/GUI.cpp -Iinclude -lncurses
```
- Run
```bash
cd build
./main
```
