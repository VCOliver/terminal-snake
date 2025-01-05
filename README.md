# Snake Game

A classic Snake game implemented in C++ using the `ncurses` library for terminal-based rendering.

## Requirements

- CMake 3.25.1 or higher
- A C++17-compatible compiler
- `ncurses` library

### Installing `ncurses`

Before building the project, ensure `ncurses` is installed on your system:

- **Debian/Ubuntu**:
  ```bash
  sudo apt update
  sudo apt install libncurses5-dev libncursesw5-dev
  ```

- **Fedora**:
  ```bash
    sudo dnf install ncurses-devel
  ```

- **Arch Linux**:
  ```bash
    sudo pacman -S ncurses
  ```

  - **macOS (via Homebrew)**:
  ```bash
    brew install ncurses
  ```


## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/snake-game.git
   cd snake-game
   ```

2. Create a build directory and navigate into it:
   ```bash
   mkdir build
   cd build
   ```

3. Configure and build the project using CMake:
   ```bash
   cmake ..
   make
   ```

4. Run the game:
   ```bash
   ./snake
   ```

## Controls

- **WASD Keys**: Move the snake in the desired direction.
- **Other Keys**: Any other key inputs are ignored during gameplay.

## Code Structure

- **Core Game Logic**: Handles game initialization, running, and cleanup (`core/game.cpp`).
- **Screen Rendering**: Manages `ncurses` screen initialization and updates (`screen/screen.cpp`).
- **Snake and Food Management**: Logic for the snake's movement, food placement, and related events (`snake/snake.cpp`, `snake/food.cpp`).
- **Collision Detection**: Ensures the game handles collisions properly (`event/collision.cpp`).
- **Input Handling**: Processes user inputs to control the snake (`input/inputHandler.cpp`).

## Customization

- **Game Speed**: Adjust the snake's speed by modifying the `WAIT_TIME` constant in `core/game.cpp`.  
  ```cpp
  #define WAIT_TIME 400 // Milliseconds
  ```

## Known Issues

- This version is a basic implementation and may have minor bugs. Feel free to report issues or contribute enhancements.

## Credits

Developed by [VCOliver](https://github.com/VCOliver).

---
Enjoy the game and feel free to share feedback or improvements!
```

Let me know if you'd like to customize this further!