# Lesson 04: Control Flow — Decisions and Loops

So far, our programs have mostly executed from top to bottom. Real programs need to make decisions and repeat work.

> **Goal:** By the end of this lesson, you should be able to choose between paths with `if`/`else` and `switch`, repeat work with loops, and recognize the conditions that control program execution.

---

## What You Will Learn

- Boolean conditions
- `if`
- `else`
- `else if`
- Nested decisions
- `switch`
- `while` loops
- `do while` loops
- `for` loops
- `break` and `continue`
- Avoiding infinite loops
- Debugging branches and loops in VS Code

---

## 1. Programs Need Decisions

A program often needs to answer questions:

```text
Is the password correct?
Is the user old enough?
Is the account balance sufficient?
Has the game been won?
```

C++ represents these decisions with Boolean expressions.

```cpp
int age{20};

bool adult{age >= 18};
```

We can use that result to choose what happens next.

---

## 2. `if`

The simplest decision is an `if` statement:

```cpp
if (age >= 18)
{
    std::cout << "You are an adult.\n";
}
```

The code inside the braces executes only when the condition is `true`.

Think of it as:

```text
condition?
   │
   ├── true  → execute block
   │
   └── false → skip block
```

---

## 3. `if` / `else`

Use `else` when you need an alternative:

```cpp
if (age >= 18)
{
    std::cout << "Adult\n";
}
else
{
    std::cout << "Minor\n";
}
```

Exactly one of these blocks executes.

---

## 4. `else if`

When there are multiple possibilities:

```cpp
if (score >= 90)
{
    std::cout << "A\n";
}
else if (score >= 80)
{
    std::cout << "B\n";
}
else if (score >= 70)
{
    std::cout << "C\n";
}
else
{
    std::cout << "Needs improvement\n";
}
```

C++ checks the conditions from top to bottom and executes the first matching branch.

That means **order matters**.

---

## 5. Combining Conditions

The logical operators from Lesson 03 become useful here:

```cpp
if (age >= 18 && hasLicense)
{
    std::cout << "Can drive.\n";
}
```

You can also use `||`:

```cpp
if (isStudent || isVeteran)
{
    std::cout << "Discount applies.\n";
}
```

Keep complicated conditions readable. Parentheses and well-named Boolean variables can make a major difference.

---

## 6. `switch`

A `switch` is useful when comparing one value against several discrete choices.

```cpp
int choice{};

std::cin >> choice;

switch (choice)
{
    case 1:
        std::cout << "Start\n";
        break;

    case 2:
        std::cout << "Settings\n";
        break;

    case 3:
        std::cout << "Quit\n";
        break;

    default:
        std::cout << "Invalid choice\n";
        break;
}
```

### Why `break`?

Without `break`, execution can continue into the next case. This behavior is called **fallthrough**.

For beginners, use `break` unless you intentionally want fallthrough.

---

## 7. Repetition: `while`

An `if` decides whether a block runs. A loop decides whether it should run repeatedly.

```cpp
int count{1};

while (count <= 5)
{
    std::cout << count << '\n';
    ++count;
}
```

The condition is checked before every iteration.

```text
check condition
      ↓
   true? ── no → stop
      │
     yes
      ↓
 run body
      ↓
 repeat
```

> **Critical rule:** Make sure something inside the loop can eventually make the condition false.

---

## 8. Infinite Loops

This loop never changes `count`:

```cpp
int count{1};

while (count <= 5)
{
    std::cout << count << '\n';
}
```

Because `count` stays `1`, the condition remains true forever.

When debugging, an unexpected infinite loop is one of the first things to investigate.

---

## 9. `do while`

A `do while` loop executes its body at least once before checking the condition.

```cpp
int choice{};

do
{
    std::cout << "Enter 1 to continue, 0 to quit: ";
    std::cin >> choice;
}
while (choice != 0);
```

This is useful when you need to perform an action before deciding whether to repeat it.

---

## 10. `for` Loops

A `for` loop is convenient when you know the loop's initialization, condition, and update in one place.

```cpp
for (int count{1}; count <= 5; ++count)
{
    std::cout << count << '\n';
}
```

Read the three parts as:

```text
initialization ; condition ; update
```

```text
int count{1}  ; count <= 5 ; ++count
```

The loop variable `count` is created by the loop and normally exists only inside the loop.

---

## 11. `break` and `continue`

`break` exits the nearest loop immediately:

```cpp
for (int i{1}; i <= 10; ++i)
{
    if (i == 5)
        break;

    std::cout << i << '\n';
}
```

This prints `1` through `4`.

`continue` skips the rest of the current iteration and moves to the next one:

```cpp
for (int i{1}; i <= 5; ++i)
{
    if (i == 3)
        continue;

    std::cout << i << '\n';
}
```

This prints `1`, `2`, `4`, and `5`.

Don't use these as a substitute for clear loop conditions. They are tools, not magic escape hatches.

---

## 12. Complete Example: Simple Access Check

```cpp
#include <iostream>

int main()
{
    int age{};
    bool hasTicket{};

    std::cout << "Enter your age: ";
    std::cin >> age;

    int ticketAnswer{};
    std::cout << "Do you have a ticket? (1=yes, 0=no): ";
    std::cin >> ticketAnswer;

    hasTicket = (ticketAnswer == 1);

    if (age >= 18 && hasTicket)
    {
        std::cout << "Access granted.\n";
    }
    else
    {
        std::cout << "Access denied.\n";
    }

    return 0;
}
```

Notice the flow:

```text
input
 ↓
variables
 ↓
Boolean expression
 ↓
if/else
 ↓
output
```

This pattern will appear constantly in real programs.

---

## Exercises

### Exercise 1 — Positive, Negative, or Zero

Ask for a number and print whether it is:

- positive
- negative
- zero

### Exercise 2 — Grade Classifier

Ask for a score from 0–100 and classify it as A, B, C, D, or F.

### Exercise 3 — Menu

Create a menu with:

```text
1. Start
2. Settings
3. Help
4. Quit
```

Use `switch` to print the selected action.

### Exercise 4 — Count to 100

Use a `while` loop to print numbers from 1 through 100.

### Exercise 5 — Sum Numbers

Ask for a positive integer `n` and calculate the sum from `1` through `n` using a `for` loop.

### Exercise 6 — Input Until Quit

Use a `do while` loop that repeatedly asks the user for a menu choice until they select `0`.

### Exercise 7 — Even Numbers

Use a loop to print the even numbers from 1 through 50. Use `%` to identify even values.

---

## Debugger Exercise: See the Branches

Use VS Code to investigate this program:

```cpp
int score{};
std::cin >> score;

if (score >= 90)
{
    std::cout << "A\n";
}
else if (score >= 80)
{
    std::cout << "B\n";
}
else
{
    std::cout << "Below B\n";
}
```

1. Open the **Run and Debug** panel.
2. Select **Debug active C++ file**.
3. Set a breakpoint on the first `if`.
4. Start debugging and enter `95` in the integrated terminal.
5. Step through the program and inspect the condition values in **Variables** or **Watch**.
6. Repeat with `85`.
7. Repeat with `60`.

Then debug a `for` loop:

```cpp
for (int i{1}; i <= 5; ++i)
{
    std::cout << i << '\n';
}
```

Stop inside the loop and watch `i` change after each iteration.

**Debugger question:** What changes between iterations, and what eventually makes the loop stop?

---

## Checkpoint Project: Number Guessing Game

Build a console game in which the program chooses a secret number and the player tries to guess it.

For the first version, you may use a fixed secret number:

```cpp
const int secretNumber{42};
```

Example:

```text
=== Number Guessing Game ===

Guess the number: 25
Too low!

Guess the number: 60
Too high!

Guess the number: 42
Correct! You win!
```

### Requirements

Your program must:

- repeatedly ask for guesses
- tell the player `Too high`, `Too low`, or `Correct`
- stop when the correct number is guessed
- use a loop
- use `if`/`else if`/`else`
- count the number of attempts
- display the final attempt count

### Stretch Challenge

Use `<random>` to generate a different secret number each time the program starts.

Do **not** worry about classes, functions, or complex input validation yet. Those belong to later lessons.

---

## LearnCpp Companion Reading

Use LearnCpp as your reference for the mechanics:

- [Chapter 8 — Control Flow and Error Handling](https://www.learncpp.com/cpp-tutorial/chapter-8-control-flow-and-error-handling/)
- [If statements](https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/)
- [If/else](https://www.learncpp.com/cpp-tutorial/if-statements-and-blocks/)
- [Switch statements](https://www.learncpp.com/cpp-tutorial/switch-statement-basics/)
- [While loops](https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/)
- [Do while](https://www.learncpp.com/cpp-tutorial/introduction-to-do-while-loops/)
- [For loops](https://www.learncpp.com/cpp-tutorial/for-statements/)

---

## Summary

You should now understand:

- Conditions control which code executes.
- `if` handles a decision.
- `else` provides an alternative.
- `else if` handles additional conditions.
- `switch` is useful for discrete choices.
- `while` repeats while a condition remains true.
- `do while` always runs its body at least once.
- `for` combines initialization, condition, and update.
- `break` exits a loop.
- `continue` skips to the next iteration.
- A loop needs a path toward termination.
- The debugger lets you watch branch decisions and loop variables.

---

## Next Lesson

→ [Lesson 05: Functions](05-functions.md)
