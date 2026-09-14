**CS 1750 VS Code Setup for Problem Sets (macOS)**

**Alexandra Irger**  
**Fall 2026**

This guide sets up VS Code to build and run the CS 1750 problem sets on macOS.
It covers both Apple Silicon and Intel Macs. Windows users should follow the
Windows handout.

Steps 1 to 4 are a one-time install for the whole semester. Steps 5 and 6 are
repeated for each problem set.

---

## Prerequisites

### 1. Install the Xcode Command Line Tools

These provide the C++ compiler, `make`, and the `lldb` debugger. This is not the
Xcode application and installs no IDE. VS Code does not include a compiler, so
these are required.

```
xcode-select --install
```

Accept the dialog and wait for it to finish. If the tools are already installed,
the command says so and exits.

### 2. Install Homebrew

Skip this if `brew --version` already prints something.

```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Homebrew prints two or three commands under "Next steps" at the end. Run them,
then close and reopen the terminal.

### 3. Install the GLFW and GLEW libraries

```
brew install glfw glew
```

GLFW opens the window and handles mouse and keyboard input. GLEW loads the
modern OpenGL function pointers. Both are required.

---

## Setting up VS Code

### 4. Install VS Code and the C/C++ extension

Download VS Code from <https://code.visualstudio.com>, then install Microsoft's
**C/C++** extension (`ms-vscode.cpptools`) from the Extensions panel. It provides
the debugger used below. CMake Tools is not needed.

### 5. Open the assignment folder

Use **File > Open Folder** on the folder that contains `asst1.cpp`. For pset 1
this is the `asst1` folder inside your private repository, not the repository
root.

The program loads `shaders/`, `smiley.ppm` and `reachup.ppm` by paths relative
to the directory it was launched from, so it must be run from this folder.

---

## Building the program

### 6. Build and run

Open the integrated terminal with **Terminal > New Terminal**, then:

```
make
./asst1
```

A 512x512 window opens showing a textured square on a light blue background.
Right-drag shifts the square, left-drag blends the two textures, `s` writes a
screenshot to `out.ppm`, and `Esc` quits.

If you see `make: Nothing to be done for 'all'`, the program is already built and
can be run. To rebuild from scratch, run `make clean` and then `make`. Any time
you change a source file you must rebuild to see your changes.

### 7. Run the reference solution

Each assignment includes the finished program in `bin/`, so you can see what
yours should do. Run it from the assignment folder, not from inside `bin`:

```
./bin/asst1-solution-macos-arm64
```

On an Intel Mac, use `./bin/asst1-solution-macos-intel`.

---

## Debugging in VS Code

Debug mode lets you set breakpoints: markers on a line of code that pause
execution when it is reached. You can then step in and out of functions and see
exactly where an error occurs.

Documentation: <https://code.visualstudio.com/docs/debugtest/debugging>

The assignment folder already contains `.vscode/launch.json`, so there is nothing
to create.

1. Run `make`.
2. Open **Run and Debug** in the left sidebar, the play button with a bug on it.
3. Choose "(lldb) Launch asst1".
4. Press the green play button, or F5.

Set a breakpoint by clicking to the left of a line number until a red marker
appears.

| Key | Action |
|---|---|
| F5 | Continue: run until the next breakpoint or until the program exits |
| F10 | Step over: execute the current line, but skip into function calls |
| F11 | Step into: step into the function call |
| Shift+F11 | Step out: finish the current function and return |

For later problem sets, change `asst1` to `asst2` and so on in `launch.json`.

---

## Common issues

### `ld: library not found for -lglfw`, or the same for `-lGLEW`

Check that both libraries were installed in step 3. If they were, check where
Homebrew put them:

```
brew --prefix
```

If this prints `/opt/homebrew`, you are on Apple Silicon and the Makefile is
already correct. If it prints `/usr/local`, you are on an Intel Mac and every
build needs:

```
make HOMEBREW_PREFIX=/usr/local
```

### `Exception caught: Cannot open file shaders/asst1-sq-gl3.vshader`

This also appears as `ppmRead: Cannot open file smiley.ppm for read`. The
program was run from the wrong directory. `cd` into the folder containing
`asst1.cpp` and run `./asst1` from there. If this happens when you press F5, the
VS Code workspace root is the repository rather than the assignment folder. See
step 5.

---

If you run into problems, come to office hours or post on Ed.
