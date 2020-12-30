  Arkanoid!
=============

> Arkanoid is a 1986 block breaker arcade game developed and published by Taito. In North America,
  it was published by Romstar. Controlling a paddle-like craft known as the Vaus, the player is tasked
  with clearing a formation of colorful blocks by deflecting a ball towards it without letting the ball
  leave the playfield. Some blocks contain power-ups that have various effects, such as increasing the
  length of the Vaus, creating several additional balls, or turning the Vaus into a laser cannon.

[Arkanoid](https://en.wikipedia.org/wiki/Arkanoid), Wikipedia

This recreation by [Magno El Magnífico](https://github.com/MagnoElMagnifico) is just for learning and
practise purposes.

## Features
- Open a black window (tested on Windows 10 MinGW)

## Requirements
- [CMake](https://cmake.org/download/)
- A C++ compiler
- [SFML](https://www.sfml-dev.org/download/sfml/2.5.1/)

## Set up
- Download this repository throught [git](https://git-scm.com/downloads)
```
git clone https://github.com/MagnoElMagnifico/Arkanoid-CPP.git
```
or you can download a `.zip` file from
[here](https://github.com/MagnoElMagnifico/Arkanoid-CPP/archive/main.zip)
- Download and extract [SFML](https://www.sfml-dev.org/download/sfml/2.5.1/) under the libraries folder.
The structure should be as the following:

```
  libraries
  └─ SFML
     ├─ bin
     │  └─ Some .dll files
     ├─ include
     │  └─ SFML
     │     └─ Some folder and .hpp files
     └─ lib
        ├─ cmake
        │  └─ SFML
        │     └─ CMake files
        └─ Some .a files

```

- Copy those `.dll`s under `libraries/SFML/bin` to the `build` folder and you are good to go.

### How to compile and run
- In the command line and the repository root directory type:
```
  cd build
  cmake ..
  cmake --build .
```
- If you got any errors running these commands try using other types of Makefiles, try `cmake -G` for more info
(after changing the Makefile's type, remember to delete the CMake files from the `build` folder).
- Finally, run the `.exe` generated there.
