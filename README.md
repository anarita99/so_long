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

**Prerequisites**: Before running the game, ensure you have the necessary dependencies for the MinilibX (on Linux, this usually includes libxext-dev and libbsd-dev).


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

**Objective:** Help the cat collect all the Fish (C) on the map. Once all fish are eaten, the Exit (E) opens. Reaching the exit wins the game.

## Key	Action
W	Move Up
A	Move Left
S	Move Down
D	Move Right
ESC	Close Game

**Move Counter:** The current number of moves is printed to your shell as you play.

# Features

**Animated Sprites:** The player (cat) has idle animations and directional walking animations (up, down, left, right).

**Leak Free:** All images, windows, and map memory are cleanly freed upon exit.

# Map Format

Maps use the `.ber` extension and must follow these rules:

### Valid Characters

| Symbol | Meaning |
|:------:|:--------|
| `1` | Wall   |
| `0` | Empty floor |
| `P` | Player start position (Cat) 🐱 |
| `C` | Collectible (Fish) 🐟 |
| `E` | Exit  |

### Requirements

- Must be rectangular  
- Surrounded by walls (`1`)  
- Contains exactly **one** player (`P`)  
- Contains exactly **one** exit (`E`)  
- Contains at least **one** collectible (`C`)  
- Valid path must exist to all collectibles and the exit  

### Example Map

```text
111111111111
100000000001
10P000C00001
1000111110C1
1C0000000001
100000000E01
111111111111
```

**Made with ❤️ and ☕ at 42**

*Go help that cat get some fish!* 🐱🐟

