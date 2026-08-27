# Lesson 00: Setting Up Your Environment

Before we write a single line of C++, we need a working compiler and a place to write code.

This lesson is short on purpose. Get the tools installed, verify they work, then move on.

> [!NOTE]
> **Real life:** think of the compiler as a translator. You write instructions in a language humans can read (C++); the compiler turns that into a language your computer can actually run (machine code). No compiler, no translation, no program.

> [!TIP]
> **Already in this repo's Codespace?** You can skip most of this lesson — the `.devcontainer` config already installs `g++` and `gdb` for you automatically when the Codespace builds. Jump to [Step 3](#3-create-a-test-file) to confirm it's working, then move on to Lesson 01.

---

## What Is C++, and What Is It For?

C++ is a **compiled, general-purpose programming language**. "Compiled" means you write
human-readable text and a program called a compiler translates it, ahead of time, into raw
machine instructions your CPU runs directly. That is why C++ programs are fast: there is no
translator sitting in the middle while your program runs.

C++ gives you **direct control over memory and hardware**, while still offering high-level
tools like classes and the Standard Library. That combination — close to the metal, but not
*only* close to the metal — is what it is known for.

### What people actually build with it

| Field | Real examples |
|---|---|
| **Game engines & games** | Unreal Engine, Unity's core, most AAA game titles |
| **Operating systems & browsers** | Parts of Windows, macOS, Linux tooling, Chrome, Firefox |
| **Embedded & real-time systems** | Cars, medical devices, drones, robotics, microcontrollers |
| **Finance** | High-frequency trading systems where microseconds matter |
| **Creative & engineering software** | Photoshop, Blender, AutoCAD, MySQL, Adobe suite |
| **Scientific / high-performance computing** | Physics simulation, machine-learning backends (PyTorch and TensorFlow are C++ underneath) |

### When you would pick something else

C++ is not always the right tool, and knowing that is part of learning it:

- Simple scripts or quick data work → Python is faster to write
- Websites and browser front-ends → JavaScript/TypeScript
- Standard mobile apps → Swift (iOS) or Kotlin (Android)

> [!NOTE]
> **Reach for C++ when performance, hardware control, or memory precision genuinely matter.**
> It asks more of you than most languages, and pays you back in speed and control.

---

## What You Need

1. A **C++ compiler** (g++ or clang++)
2. A **text editor** or IDE
3. A terminal (Command Prompt / PowerShell / Terminal / bash)

---

## 1. Install a Compiler

### Windows

**Recommended: Install via MSYS2 or use the Visual Studio Build Tools**

**Option A – MinGW-w64 via MSYS2 (cleanest for beginners)**
1. Download and install [MSYS2](https://www.msys2.org/)
2. Open the MSYS2 terminal and run:
   ```bash
   pacman -Syu
   pacman -S mingw-w64-ucrt-x86_64-gcc
   ```
3. Add `C:\msys64\ucrt64\bin` to your system PATH.

**Option B – Visual Studio**
- Install [Visual Studio Community](https://visualstudio.microsoft.com/) and select the “Desktop development with C++” workload.

**Verify:**
```bash
g++ --version
```
or
```bash
cl
```
(if using MSVC)

### macOS

```bash
xcode-select --install
```

This installs `clang++`.

Verify:
```bash
clang++ --version
```

### Linux (Ubuntu/Debian)

```bash
sudo apt update
sudo apt install build-essential
```

Verify:
```bash
g++ --version
```

---

## 2. Choose an Editor

Any of these work well:

| Tool              | Notes                                      |
|-------------------|--------------------------------------------|
| **VS Code**       | Free, lightweight, excellent C++ extension |
| **CLion**         | Powerful IDE (free for students)           |
| **Vim / Neovim**  | Fast once you learn it                     |
| **Notepad++**     | Simple, Windows-only                       |

**VS Code quick start:**
1. Install [VS Code](https://code.visualstudio.com/)
2. Install the extensions listed below
3. Open a folder → create a `.cpp` file → you’re ready

### Extensions you need

Open the Extensions panel with `Ctrl+Shift+X` (`Cmd+Shift+X` on macOS), search the ID, click **Install**.

| Extension | ID | Why you need it |
|---|---|---|
| **C/C++ Extension Pack** | `ms-vscode.cpptools-extension-pack` | **The only one that is required.** Bundles the three below in one click. |
| ↳ C/C++ | `ms-vscode.cpptools` | IntelliSense (autocomplete), red squiggles, and the debugger |
| ↳ C/C++ Themes | `ms-vscode.cpptools-themes` | Syntax colors tuned for C++ |
| ↳ CMake Tools | `ms-vscode.cmake-tools` | Not used in early lessons; harmless to have |

> [!TIP]
> **In this repo’s Codespace, the extension pack installs itself.** It is listed in
> `.devcontainer/devcontainer.json`, so it is already there. If IntelliSense looks dead —
> no autocomplete, no colors — run **Developer: Reload Window** from the Command Palette
> (`Ctrl+Shift+P`) before installing anything by hand.

**Optional, genuinely useful for this course:**

| Extension | ID | Why |
|---|---|---|
| Error Lens | `usernamehw.errorlens` | Prints the error message *on the line itself* instead of hiding it in the Problems panel. Excellent while learning. |
| Code Spell Checker | `streetsidesoftware.code-spell-checker` | Catches typos in your strings and comments |

> [!WARNING]
> **Do not install a second C++ IntelliSense engine** (for example `clangd`) alongside
> `ms-vscode.cpptools`. Two engines analyzing the same file fight each other and produce
> duplicate or phantom errors.

---

## 3. Create a Test File

### Step 3a — Make the file

**In VS Code / Codespaces:**

1. Look at the **Explorer** sidebar on the left. If you cannot see it, press `Ctrl+Shift+E`.
2. Hover over the folder name at the top of that sidebar (`CPP-TUTORIAL`).
3. Click the **New File** icon — the small page icon with a `+` on it.
4. Type the name **exactly**: `hello.cpp` — then press `Enter`.
5. The file opens in the editor, empty, ready to type in.

**From a terminal instead** (`Ctrl+` ` opens one in VS Code):

```bash
touch hello.cpp     # macOS / Linux
code hello.cpp      # then open it in the editor
```

> [!IMPORTANT]
> **The `.cpp` part is not optional.** A file called `hello` or `hello.txt` will not be
> treated as C++ — you will get no syntax colors, no autocomplete, and the compiler will
> refuse it. The extension is how every tool knows what the file is.

### Step 3b — Type the code

```cpp
#include <iostream>

int main() {
    std::cout << "Setup successful!\n";
    return 0;
}
```

> [!CAUTION]
> **The single most common beginner mistake, and it is a copy-paste trap.**
>
> In the *rendered* lesson (the pretty preview), that grey box shows only the code.
> But the raw Markdown behind it is fenced like this:
>
> ````text
> ```cpp
> #include <iostream>
> ...
> ```
> ````
>
> If you select the text by dragging your mouse, it is very easy to drag in the
> ` ```cpp ` fence line and to stop short of the closing `}`. You then end up with a file
> that starts with a stray word `cpp` and never closes `main()`.
>
> **That one stray `cpp` produces literally hundreds of errors** — over 300 of them —
> because the compiler cannot make sense of `#include <iostream>` after it, so every symbol
> in the standard library fails in turn. The error list looks catastrophic. The fix is
> deleting one word.

> [!TIP]
> **How to avoid it entirely:** hover over any code block in the rendered preview and click
> the **copy icon** that appears in its top-right corner. That copies exactly the code and
> never the fence. Better still while you are learning: **type it out by hand.** It is six
> lines, and typing them is how they stick.

### Step 3c — Sanity-check what you typed

Before compiling, confirm all four:

- [ ] The first line is `#include <iostream>` — **not** `cpp`, and nothing above it
- [ ] There is a closing `}` on the last line
- [ ] Every `{` has a matching `}` (VS Code highlights the partner when you click one)
- [ ] Both lines inside `main()` end in a semicolon `;`

> [!TIP]
> **Press `Ctrl+S` to save.** An unsaved file has a **white dot** instead of an `✕` on its
> editor tab. The compiler reads the file on disk, not what is on your screen — so unsaved
> changes are invisible to it, and you will "fix" a bug that keeps happening.

---

## 4. Compile and Run

Open a terminal in the same folder as `hello.cpp` and run:

```bash
g++ hello.cpp -o hello
./hello          # macOS / Linux
hello.exe        # Windows
```

You should see:
```
Setup successful!
```

> [!TIP]
> If that worked — congratulations. Your environment is ready. This is the exact same command your debugger will run behind the scenes for the rest of the course, so if it works here, everything downstream will work too.

---

## Common Problems

> [!WARNING]
> These three cover almost every setup issue beginners hit. Check here before assuming your code is wrong — it might just be the environment.

| Problem | What it means | Fix |
|---|---|---|
| **Hundreds of errors** (300+) from a 6-line file | A stray ` ```cpp ` fence line got pasted in as line 1 | Delete the word `cpp` from line 1. See [Step 3b](#step-3b--type-the-code). |
| `error: expected '}' at end of input` | Missing the closing brace | Add `}` on the last line |
| `'cout' is not a member of 'std'` | Missing the include | Add `#include <iostream>` at the top |
| Squiggles everywhere but it compiles fine | IntelliSense is confused, not the compiler | Command Palette → **C/C++: Reset IntelliSense Database**, then reload the window |
| No colors, no autocomplete at all | Extension missing, or file is not named `.cpp` | Install `ms-vscode.cpptools-extension-pack`; check the filename ends in `.cpp` |
| Your edit seems to have no effect | The file was never saved | Press `Ctrl+S` — a white dot on the tab means unsaved |
| `g++: command not found` | Compiler not installed or not in PATH | Install it (Step 1); in a Codespace, rebuild the container |
| Permission denied on `./hello` | Binary is not marked executable | Run `chmod +x hello` |
| Weird encoding / line endings | File saved as UTF-16 or with CRLF | Use UTF-8 and LF (Unix) line endings |

> [!TIP]
> **Always fix the FIRST error in the list, then recompile.** C++ errors cascade — one
> broken line makes the compiler misread everything after it. Those 338 errors were a
> single mistake wearing a costume. Fix one thing, recompile, and watch the count collapse.

---

## Next Lesson

→ [Lesson 01: Hello, World & Your First Program](01-hello-world.md)
