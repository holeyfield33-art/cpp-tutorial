# Lesson 00: Setting Up Your Environment

Before we write a single line of C++, we need a working compiler and a place to write code.

This lesson is short on purpose. Get the tools installed, verify they work, then move on.

> [!NOTE]
> **Real life:** think of the compiler as a translator. You write instructions in a language humans can read (C++); the compiler turns that into a language your computer can actually run (machine code). No compiler, no translation, no program.

> [!TIP]
> **Already in this repo's Codespace?** You can skip most of this lesson — the `.devcontainer` config already installs `g++` and `gdb` for you automatically when the Codespace builds. Jump to [Step 3](#3-create-a-test-file) to confirm it's working, then move on to Lesson 01.

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
2. Install the official **C/C++** extension by Microsoft
3. Open a folder → create a `.cpp` file → you’re ready

---

## 3. Create a Test File

Create a file named `hello.cpp`:

```cpp
#include <iostream>

int main() {
    std::cout << "Setup successful!\n";
    return 0;
}
```

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

| Problem                        | Fix                                      |
|--------------------------------|------------------------------------------|
| `g++: command not found`       | Compiler not installed or not in PATH    |
| Permission denied on `./hello` | Run `chmod +x hello`                     |
| Weird encoding / line endings  | Use UTF-8 and LF (Unix) line endings     |

---

## Next Lesson

→ [Lesson 01: Hello, World & Your First Program](01-hello-world.md)
