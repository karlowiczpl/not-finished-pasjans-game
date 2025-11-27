# Not-Finished Pasjans Game

A solitaire (pasjans) card game written in C++. This repository is a work in progress — core game/UX parts are incomplete. The project currently uses Qt for UI (widgets/) and CMake for build.

This README fills in missing documentation, provides concrete build/run steps, lists what's missing in the repo, and proposes a roadmap, contribution guide and a license (MIT). If you want, I can create files (README.md / LICENSE / CI workflow) and push them to the repository.

---

## Table of Contents

- Overview
- Status
- Features (implemented & TODO)
- Screenshots
- Requirements
- Build & Run
  - Linux / macOS
  - Windows
  - From Qt Creator
- Project structure
- How to play
- Development notes
- Missing items I detected in the repository
- Suggested roadmap / issues
- Contribution guide
- Coding style & testing
- CI / packaging suggestions
- License (MIT)
- Contact

---

## Overview

Not-Finished Pasjans Game is an implementation of a single-player solitaire (pasjans) card game in C++, built with Qt (widgets). It aims to provide a clean desktop UI and correct game rules, with optional features like save/load, undo, statistics and hints.

The project is currently incomplete — this README documents the expected structure, how to build what exists, and what remains to be implemented.

---

## Status

- Repository status: Work in progress / not finished.
- UI framework: Qt (widgets directory).
- Build system: CMake (CMakeLists.txt present).
- Executable: main.cpp present.
- Missing (observed): README (added by this file), LICENSE (added below), automated tests, CI, detailed documentation, many game features and polish.

---

## Features

Implemented (based on repository contents):
- Qt-based application skeleton (main.cpp).
- Resource file (resources.qrc) for images/assets.
- Project CMake configuration (CMakeLists.txt).

Planned / TODO (recommended and likely missing):
- Full game logic (tableau, foundations, stock/waste mechanics).
- Move validation and rule enforcement.
- Undo/redo stack.
- Save/load game state.
- Scoring and statistics.
- Hints/auto-moves.
- Keyboard shortcuts and accessibility.
- Unit tests for core game logic.
- Packaging / installers for Windows/macOS/Linux.
- Documentation of public APIs and internals.

---

## Requirements

- C++ compiler with C++17 support (g++ 9+, clang 10+, MSVC 2019+)
- CMake 3.16 or newer
- Qt 6 (recommended) or Qt 5.15+ (Widgets module required)
  - Required Qt modules: Widgets, Gui, Core, (optional: Svg, Multimedia if used)
- (Optional) Qt Creator for development
- pkg-config (Linux) or proper Qt installation for CMake to detect Qt

Note: The repository contains a Qt resource file (resources.qrc) and a `widgets/` directory, so Qt Widgets is expected.

---

## Build & Run

General CMake-based instructions:

1. Clone the repo
   git clone https://github.com/karlowiczpl/not-finished-pasjans-game.git
   cd not-finished-pasjans-game

2. Configure and build
   mkdir -p build
   cd build
   cmake -S .. -B . -DCMAKE_BUILD_TYPE=Release
   cmake --build . --config Release

3. Run
   - On Linux/macOS:
     ./not-finished-pasjans-game
     (If binary name differs, check `build` directory; e.g. ./pasjans)
   - On Windows:
     build\Release\not-finished-pasjans-game.exe  (or check produced .exe)

Notes for Qt detection:
- If CMake doesn't find Qt automatically, pass CMAKE_PREFIX_PATH to point to your Qt installation.
  Example (Linux/macOS):
  cmake -S .. -B . -DCMAKE_PREFIX_PATH="/opt/Qt/6.6.0/gcc_64/lib/cmake"
- On Windows with Qt installed via installer, use the Qt Visual Studio Tools or set CMAKE_PREFIX_PATH similarly.

Using Qt Creator:
- Open the top-level CMakeLists.txt in Qt Creator and configure the kit. Build & run from the IDE.

---

## Project structure (expected)

Top-level:
- CMakeLists.txt — project build configuration
- main.cpp — application entrypoint
- resources.qrc — Qt resource file for images/assets
- images/ — placeholder for screenshots / game assets
- source/ — C++ source files (game logic, controllers)
- widgets/ — Qt widget classes for UI
- build/ — build output (gitignored normally)
- .vscode/ , .idea/ — editor config (private; consider removing before publishing)

Typical source layout (what I expect and recommend to adopt):
- source/game/ — core game logic (Deck, Card, Pile, MoveValidator)
- source/ui/ — UI controllers and glue code
- widgets/ — custom Qt widgets for the card views, pile views, controls
- resources.qrc — images for cards / background / icons
- tests/ — unit tests

---

## How to play (example / placeholder)

This depends on the implemented UI. Suggested controls:
- Drag and drop cards between piles with the mouse.
- Double-click a card to auto-move to a foundation when available

Add the exact controls once the widgets code implements them.

---

## Development notes

Coding responsibilities to split:
- Core logic: Deck, shuffle, deal, move validation, game state (serializable).
- UI: Card rendering, animations, input handling, accessibility.
- Persistence: Save format (JSON) and load/restore.
- Tests: Unit tests for game rules and edge cases.

Suggested design:
- Keep game logic independent of Qt. Core logic should have zero Qt dependencies — makes unit testing very easy.
- Provide a small Qt wrapper that holds a GameController and updates model → UI.
- Use signals/slots for UI updates.
- Keep resources (card images) in `resources.qrc`.

---

## Contribution guide

1. Fork the repo.
2. Create a feature branch: git checkout -b feat/<short-description>
3. Implement your feature and add tests where applicable.
4. Follow code style (use clang-format or agreed style).
5. Open a pull request describing changes, link related issues, and include screenshots if UI changed.

Notes:
- Keep game logic deterministic; use seed injection for RNG to make tests reproducible.
- Write unit tests for all non-UI logic.

---

## Coding style & testing

- Language: C++17
- Prefer header-only interfaces for small utilities.
- Keep UI code (Qt) separated from logic code (plain C++).
- Test with GoogleTest or Catch2. Add tests in `tests/` and integrate with CTest.
- Example test command:
  mkdir build && cd build
  cmake -S .. -B . -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON
  cmake --build . --target test
  ctest --output-on-failure

(Adjust depending on how you integrate test framework)

---

## CI / Packaging suggestions

- Add GitHub Actions workflow to:
  - Build with CMake on Ubuntu (and optionally macOS/Windows)
  - Run unit tests
  - Optionally build artifacts (AppImage for Linux, .zip/.exe for Windows, .dmg or .app for macOS)
- Example jobs:
  - ubuntu-latest: install Qt via apt or use prebuilt Qt installer (or use official Qt GitHub Actions)
  - Use matrix builds to test multiple compilers
- Add a `release` workflow to create release artifacts.

---

## License (MIT)

Add this text as `LICENSE` file in the repo.

MIT License

Copyright (c) 2025 karlowiczpl

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

---

## Contact

Repository: https://github.com/karlowiczpl/not-finished-pasjans-game

Author: karlowiczpl