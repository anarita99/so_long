# 🐱 so_long

A 2D puzzle game developed in **C** using the **MiniLibX** library. You play as a cat collecting fish to unlock the exit! This project involves texture handling, sprite animation, and map validation.

## Project Structure

```text
.
├── 📁 ft_printf/       # Custom printf implementation
├── 📁 get_next_line/   # GNL implementation
├── 📁 libft/           # Standard helper library
├── 📁 maps/            # .ber map files
├── 📁 textures/        # .xpm sprites (cat, fish, walls)
├── 📄 .gitignore
├── 📄 Makefile
├── 📄 cat.c            # Sprite animation logic
├── 📄 check_map.c      # Wall and element validation
├── 📄 check_map2.c     # Flood fill & pathfinding checks
├── 📄 copy_map.c       # Map duplication utility
├── 📄 for_main.c       # Image loading & main loop hooks
├── 📄 free_things.c    # Clean exit & memory freeing
├── 📄 initiate.c       # Struct initialization
├── 📄 keys.c           # Movement & gameplay logic
├── 📄 map.c            # Map reading & rendering
├── 📄 so_long.c        # Main entry point
└── 📄 so_long.h        # Header file
```
## Compilation Instructions

**Important:** This project requires the MiniLibX library to be compiled before the main game. You must run the commands in this specific order:

1. **Build the Graphics Library**
```bash
make mlx
```
2. **Build the Game**
```bash
make
```
    Note: If you run make without building the mlx library first, the linker will fail.

## How to run

Run the game by providing a valid .ber map file:
```bash
./so_long maps/map.ber
```
## Gameplay & Controls

Objective: Help the cat collect all the Fish (C) on the map. Once all fish are eaten, the Exit (E) opens. Reaching the exit wins the game.
Key	Action
W	Move Up
A	Move Left
S	Move Down
D	Move Right
ESC	Close Game

    Move Counter: The current number of moves is printed to your shell as you play.

# Features

    Animated Sprites: The player (cat) has idle animations and directional walking animations (up, down, left, right).

    Map Validation: The game checks if the map is rectangular, surrounded by walls, and uses a Flood Fill algorithm to ensure there is a valid path to all collectibles and the exit.

    Leak Free: All images, windows, and map memory are cleanly freed upon exit.

# Map Rules

The map file (.ber) must follow these rules:

    Rectangular shape.

    Closed by walls (1).

# Components:

        1 : Wall

        0 : Floor

        P : Player Start (Cat)

        C : Collectible (Fish)

        E : Map Exit
