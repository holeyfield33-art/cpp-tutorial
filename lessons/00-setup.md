# Lesson 00: Setting Up Your Environment

Before we write a single line of C++, we need a working compiler and a place to write code.

This lesson is short on purpose. Get the tools installed, verify they work, then move on.

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

If that worked — congratulations. Your environment is ready.

---

## Common Problems

| Problem                        | Fix                                      |
|--------------------------------|------------------------------------------|
| `g++: command not found`       | Compiler not installed or not in PATH    |
| Permission denied on `./hello` | Run `chmod +x hello`                     |
| Weird encoding / line endings  | Use UTF-8 and LF (Unix) line endings     |

---

## Next Lesson

→ [Lesson 01: Hello, World & Your First Program](01-hello-world.md)
