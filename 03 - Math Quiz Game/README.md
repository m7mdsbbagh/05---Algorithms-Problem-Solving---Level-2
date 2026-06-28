<div align="center">

<pre>
███╗   ███╗  █████╗  ████████╗ ██╗  ██╗
████╗ ████║ ██╔══██╗ ╚══██╔══╝ ██║  ██║
██╔████╔██║ ███████║    ██║    ███████║
██║╚██╔╝██║ ██╔══██║    ██║    ██╔══██║
██║ ╚═╝ ██║ ██║  ██║    ██║    ██║  ██║
╚═╝     ╚═╝ ╚═╝  ╚═╝    ╚═╝    ╚═╝  ╚═╝
</pre>

# ➕ ➖ ✖️ ➗ Math Quiz

**A customizable console math quiz — levels, operations, and instant feedback.**

<img src="https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" />
<img src="https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white" />
<img src="https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge" />

</div>

---

## 📸 Preview

```
╔══════════════════════════════════════╗
║   Question [3/10]                    ║
║                                      ║
║   [ Question Level: Hard ]           ║
║                                      ║
║     47                               ║
║   *  13                              ║
║   ------                             ║
║      ?                               ║
║                                      ║
║   Wrong Answer :(                    ║
║   The Right Answer is: 611           ║
╚══════════════════════════════════════╝
```

---

## ⚡ Features

| # | Feature | Details |
|---|---------|---------|
| 🔢 | Up to 100 Questions | Choose how many questions per session |
| 🎚️ | 4 Difficulty Levels | Easy · Medium · Hard · **Mix** |
| ➕ | 5 Operation Types | Add · Sub · Mul · Div · **Mix** |
| 🎨 | Color Feedback | 🟢 Correct · 🔴 Wrong · 🟡 Tie |
| 🔊 | Sound Effects | Victory melody or defeat tone at the end |
| 📊 | Full Report | Question-by-question review after quiz ends |
| 🔁 | Play Again | Start a new quiz without restarting the app |

---

## 🕹️ How to Play

```
1. Launch the quiz
2. Enter number of questions  →  (1 to 100)
3. Choose a difficulty level:

        [ 1 ]  Easy
        [ 2 ]  Medium
        [ 3 ]  Hard
        [ 4 ]  Mix  (random per question)

4. Choose an operation type:

        [ 1 ]  Addition
        [ 2 ]  Subtraction
        [ 3 ]  Multiplication
        [ 4 ]  Division
        [ 5 ]  Mix  (random per question)

5. Answer each question — feedback shown immediately
6. Final score + full report displayed at the end
```

---

## 🏆 Difficulty Breakdown

```
  Easy    →  Small numbers, multiples of 10, basic facts
  Medium  →  Two-digit numbers, no round numbers
  Hard    →  Larger operands, tricky combinations
  Mix     →  Random level assigned per question
```

---

## 🔧 Requirements

```
  OS        →  Windows
  Compiler  →  MinGW / MSVC / g++
  Standard  →  C++11 or later
```

---

## ▶️ Compile & Run

```bash
# Compile
g++ main.cpp -o quiz.exe

# Run
./quiz.exe
```

---

## 📁 Project Structure

```
📂 03 - Math Quiz/
│
├── 📄 Project 2.cpp        ← All quiz logic lives here
└── 📄 README.md            ← You are here
```

---

## 🧠 Code Highlights

```cpp
enum enLvlQuestion { EASY = 1, MED, HARD, MIX_LVL };
enum enOpType      { ADD = 1, SUB, MUL, DIV, MIX_OP };
```

> The quiz uses **enums** and **structs** to separate question data, quiz state, and logic — keeping every layer clean and independent.

---

<div align="center">

Made with ❤️ by **Mohammad Al-Sabbagh** — CS Student, Year 1

</div>
