# CS 1750: Computer Graphics — Assignments

Starter code for the CS 1750 programming assignments, one folder per problem set.

```
cs1750-assignments/
├── docs/
└── asst1/
```

## Getting started

1. Clone this repository. You only need to do this once.
2. Create your own **private** repository for your work, following the GitHub guide below.
3. Set up your development environment, following the guide for your platform.
4. Copy the problem set folder into your private repository and work there.

Never edit files inside your clone of this repository. It exists to be pulled
from and copied out of. Run `git pull` here before starting each new problem set.

## Guides

| Guide | For |
|---|---|
| [GitHub setup](docs/github-setup.md) | Everyone. How to create your private repo and submit |
| [VS Code setup, macOS](docs/setup-macos.md) | Mac users, both Apple Silicon and Intel |
| [Visual Studio setup, Windows](docs/setup-windows.md) | Windows users |

There is also a [demo video of the GitHub setup](https://harvard.zoom.us/rec/share/E5kxDtvfTkcHvJVpUDt2XWLsO8pYt5CJFzQQWE8ZxSpfhKkNydvR1sLmy2X9IzRp.4WHk1cvyhA6j35TM),
recorded by Vihaan, which walks through the same steps.

The same guides are posted on Canvas under Files > handouts.

## What is in each problem set folder

| | |
|---|---|
| `asst1.cpp`, `glsupport.*`, `ppm.*` | The source you work from |
| `Makefile` | Build on macOS and Linux |
| `asst1.sln`, `asst1.vcxproj`, `lib/` | Build on Windows with Visual Studio |
| `GL/`, `shaders/`, `*.ppm` | Headers, shaders and textures loaded at runtime |
| `.vscode/launch.json` | Debugger configuration, so F5 works in VS Code |
| `README.txt` | Fill this in and submit it with your work |
| `bin/` | The finished program, so you can see what yours should do |

The binaries in `bin/` are the reference solution, one per platform. Run them
from the problem set folder rather than from inside `bin`, because they look for
the texture files in the directory you launch them from.

| File | Platform |
|---|---|
| `asst1-solution-macos-arm64` | Mac, Apple Silicon |
| `asst1-solution-macos-intel` | Mac, Intel |
| `asst1-solution-windows.exe` | Windows |

So from the root of the problem set folder, the one containing `asst1.cpp`:

```
cd asst1
./bin/asst1-solution-macos-arm64     # Mac, Apple Silicon
./bin/asst1-solution-macos-intel     # Mac, Intel
./bin/asst1-solution-windows.exe     # Windows
```

Double-clicking them in Finder or Explorer will not work, for the same reason:
the textures are found relative to where you launched the program from.

## Questions

Post on Ed, or come to office hours.
