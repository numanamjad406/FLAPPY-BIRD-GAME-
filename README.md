# FLAPPY-BIRD-GAME-
🐦 Flappy Bird clone built in C++ using Raylib &amp; OOP principles — featuring Bird, Pipe &amp; Game classes, 2-level system, physics-based gameplay, scrolling background &amp; state machine. My first OOP mini project (BSAI · Semester 2) 🎮
<div align="center">

# 🐦 Flappy Bird — C++ OOP Edition

<img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white"/>
<img src="https://img.shields.io/badge/Library-Raylib-black?style=for-the-badge&logo=raylib&logoColor=white"/>
<img src="https://img.shields.io/badge/Paradigm-Object--Oriented-blueviolet?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Semester-2nd-orange?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge"/>

<br/>

> 🎮 **A fully playable Flappy Bird clone** built from scratch using **C++ OOP principles** and the **Raylib** graphics library — my very first mini project in Object-Oriented Programming!

<br/>

---

</div>

## 📖 Table of Contents

- [✨ About the Project](#-about-the-project)
- [🏗️ OOP Architecture](#-oop-architecture)
- [🎮 Gameplay Features](#-gameplay-features)
- [🕹️ Controls](#-controls)
- [📁 File Structure](#-file-structure)
- [⚙️ Prerequisites](#-prerequisites)
- [🚀 How to Build & Run](#-how-to-build--run)
- [📸 Assets](#-assets)
- [🧠 Concepts Applied](#-concepts-applied)
- [👤 Author](#-author)

---

## ✨ About the Project

This is **Mini Project 1** from my **2nd Semester OOP course (BSAI)**. The goal was to apply Object-Oriented Programming concepts by building a real, functional game.

I chose to recreate the classic **Flappy Bird** — tap to flap, dodge the pipes, survive as long as you can!

The project uses the **Raylib** library for graphics, textures, and window management, while the game logic is cleanly separated into **three OOP classes**: `Bird`, `Pipe`, and `Game`.

---

## 🏗️ OOP Architecture

The project is organized around **3 core classes**, each with its own `.h` header and `.cpp` implementation file:

```
┌─────────────────────────────────────────────────┐
│                    Game                          │
│  ┌──────────┐    ┌──────────────────────────┐   │
│  │   Bird   │    │     Pipe  [×3 array]     │   │
│  │          │    │                          │   │
│  │ • x, y   │    │ • x, gapY, gapSize       │   │
│  │ • vel    │    │ • speed, passed          │   │
│  │ • grav   │    │                          │   │
│  │ • rot    │    │ • init()                 │   │
│  │          │    │ • reset()                │   │
│  │ flap()   │    │ • update()               │   │
│  │ update() │    │ • draw()                 │   │
│  │ draw()   │    │ • collision()            │   │
│  │ getRect()│    │ • checkPassed()          │   │
│  └──────────┘    └──────────────────────────┘   │
│                                                  │
│  • state (MENU / PLAYING / GAMEOVER)             │
│  • score, level, level2Unlocked                  │
│  • scrolling background (bg1, bg2)               │
│  • startGame(), update(), draw(), input()        │
└─────────────────────────────────────────────────┘
```

### Class Breakdown

| Class | File | Responsibility |
|-------|------|----------------|
| `Bird` | `Bird.h` / `Bird.cpp` | Player character — physics, flap, rotation, collision rect |
| `Pipe` | `Pipe.h` / `Pipe.cpp` | Obstacle — random gap generation, scrolling, scoring |
| `Game` | `Game.h` / `Game.cpp` | Game loop — state machine, input, rendering, score tracking |

---

## 🎮 Gameplay Features

| Feature | Description |
|---------|-------------|
| 🐦 **Physics-based bird** | Realistic gravity + upward flap velocity with rotation animation |
| 🌊 **Infinite scrolling** | Two background textures seamlessly loop for endless parallax effect |
| 🟩 **Random pipes** | 3 pipes with randomized gap positions recycle when off-screen |
| 📊 **Score system** | Score increments each time a pipe is successfully passed |
| 🔓 **Level unlock** | Score **10+** to unlock **Level 2** — faster pipes, tighter gaps! |
| 🎛️ **State machine** | Clean `MENU → PLAYING → GAMEOVER` state transitions |
| 🔁 **Restart anytime** | Restart, return to menu, or quit from the game over screen |

---

## 🕹️ Controls

### 📋 Main Menu

| Key | Action |
|-----|--------|
| `1` | Start **Level 1** (beginner) |
| `2` | Start **Level 2** *(unlocked after scoring 10)* |
| `Q` | Quit the game |

### 🐦 While Playing

| Key | Action |
|-----|--------|
| `SPACE` | Flap — make the bird fly upward |

### 💀 Game Over Screen

| Key | Action |
|-----|--------|
| `R` | Restart current level |
| `M` | Return to Main Menu |
| `Q` | Quit the game |

---

## 📁 File Structure

```
📦 BSAI25033-MINI-PROJECT-1/
│
├── 🗂️ BSAI25033-MINI-PROJECT-1.cpp        ← main() entry point
│
├── 🐦 BSAI25033-MINI-PROJECT-1-Bird.h     ← Bird class declaration
├── 🐦 BSAI25033-MINI-PROJECT-1-Bird.cpp   ← Bird class implementation
│
├── 🟩 BSAI25033-MINI-PROJECT-1-Pipe.h     ← Pipe class declaration
├── 🟩 BSAI25033-MINI-PROJECT-1-Pipe.cpp   ← Pipe class implementation
│
├── 🎮 BSAI25033-MINI-PROJECT-1-Game.h     ← Game class declaration
├── 🎮 BSAI25033-MINI-PROJECT-1-Game.cpp   ← Game class implementation
│
├── 🖼️ Background.png                      ← Scrolling background texture
├── 🐤 birds.png                           ← Bird sprite texture
└── 🌿 pipe.png                            ← Pipe obstacle texture
```

---

## ⚙️ Prerequisites

Before building the project, make sure you have the following installed:

- ✅ **C++ Compiler** — `g++` (GCC) or `MSVC` (Visual Studio)
- ✅ **Raylib** — The graphics library used for rendering

### Installing Raylib

**Windows (via w64devkit or MSYS2):**
```bash
pacman -S mingw-w64-x86_64-raylib
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt install libraylib-dev
```

**macOS (via Homebrew):**
```bash
brew install raylib
```

> 📖 For more options, visit the [official Raylib installation guide](https://github.com/raysan5/raylib#build-and-installation).

---

## 🚀 How to Build & Run

### 🔧 Option 1 — Compile with g++ (Linux / macOS / MinGW)

```bash
# Clone or download the project files, then navigate to the folder:
cd BSAI25033-MINI-PROJECT-1/

# Compile all source files together:
g++ BSAI25033-MINI-PROJECT-1.cpp \
    BSAI25033-MINI-PROJECT-1-Bird.cpp \
    BSAI25033-MINI-PROJECT-1-Pipe.cpp \
    BSAI25033-MINI-PROJECT-1-Game.cpp \
    -o FlappyBird \
    -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Run the game:
./FlappyBird
```

### 🪟 Option 2 — Windows (MinGW)

```bash
g++ BSAI25033-MINI-PROJECT-1.cpp ^
    BSAI25033-MINI-PROJECT-1-Bird.cpp ^
    BSAI25033-MINI-PROJECT-1-Pipe.cpp ^
    BSAI25033-MINI-PROJECT-1-Game.cpp ^
    -o FlappyBird.exe ^
    -lraylib -lopengl32 -lgdi32 -lwinmm

FlappyBird.exe
```

### 🏗️ Option 3 — Visual Studio / Code::Blocks

1. Create a new **C++ project**
2. Add all `.cpp` files to the project
3. Link the **Raylib** library in project settings
4. Copy `Background.png`, `birds.png`, and `pipe.png` into the **same folder** as the executable
5. **Build & Run** ▶️

> ⚠️ **Important:** Make sure all `.png` asset files are in the **same directory** as the compiled executable, or the textures won't load!

---

## 📸 Assets

The game uses **3 texture files** for visuals:

| File | Used For |
|------|----------|
| `Background.png` | Infinitely scrolling sky/background |
| `birds.png` | The player bird sprite |
| `pipe.png` | The obstacle pipes (drawn flipped for top pipe) |

---

## 🧠 Concepts Applied

This project demonstrates the following **OOP and C++ concepts** learned in Semester 2:

| Concept | Where Used |
|---------|-----------|
| **Classes & Objects** | `Bird`, `Pipe`, `Game` classes |
| **Encapsulation** | Private data members with public methods |
| **Constructors** | `Bird()`, `Game()` initialize all members |
| **Separation of Concerns** | Header (`.h`) and implementation (`.cpp`) files |
| **Object Composition** | `Game` contains `Bird` and `Pipe[]` objects |
| **Enum (State Machine)** | `MENU`, `PLAYING`, `GAMEOVER` states |
| **Arrays of Objects** | `Pipe pipes[PIPE_COUNT]` — 3 pipe instances |
| **Pass by Reference** | `collision(Bird& b)`, `checkPassed(Bird& b)` |
| **Game Loop** | `input()` → `update()` → `draw()` each frame |
| **Delta Time Physics** | `velocity`, `gravity`, `position` updated with `dt` |

---

## 👤 Author

**BSAI25033** — 2nd Semester Student  
📚 Object-Oriented Programming — Mini Project 1  
🗓️ February 2026

---

<div align="center">

**⭐ If you found this project helpful or interesting, consider giving it a star!**

*Built with ❤️ using C++ and Raylib*

</div>
