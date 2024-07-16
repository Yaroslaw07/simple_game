This is a basic shooter game developed in C++ that allows players to load levels from a file and engage in simple gameplay using the ncurses library for the terminal interface.

![image](https://github.com/user-attachments/assets/43f6a8bf-d234-4c2e-9748-aab7da4499a6)

## Features ✨
- Load Levels from File: The game reads and loads levels from a level.txt file.
- Terminal-Based Gameplay: Utilizes the ncurses library for the game interface.
- Simple Shooting Mechanics: Players can move and shoot within the game environment.

## To implement 📌
- [ ] Multi-level support
- [ ] Enemy logic
- [ ] Game pause

## To run 🚀
### Prerequisites
To run this game, you will need:

- A C++ compiler (such as g++, clang++) 
- ncurses library installed on your system)
- CMake (optional, for building the project)

### Cloning the Repository
First, clone the repository to your local machine using Git:

```sh
git clone https://github.com/Yaroslaw07/simple_game.git
cd simple_game
```
### Building the Game
You can build the game using a C++ compiler directly or using CMake. Below are the instructions for both methods.

#### Using C++ Compiler Directly
```sh
g++ -o simple_game src/*.cpp -lncurses
```
#### Using CMake

Create a build directory:

```sh
mkdir build
cd build
```

Generate the build files using CMake:

```sh
cmake ..
```
Build the project:

```sh
cmake --build .
```

##### Running the Game

After building the game, you can run it using the following command:

```sh
./simple_game
```

### Acknowledgments 🙏
ncurses library

