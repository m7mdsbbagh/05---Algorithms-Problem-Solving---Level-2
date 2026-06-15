<div align="center">



```

██████╗  ██████╗  ██████╗    ██████╗  ███████╗

██╔══██╗██╔═══██╗██╔════╝    ██╔══██╗ ██╔════╝

██████╔╝██║   ██║██║         ██████╔╝ ███████╗

██╔══██╗██║   ██║██║         ██╔═══╝  ╚════██║

██║  ██║╚██████╔╝╚██████╗    ██║      ███████║

╚═╝  ╚═╝ ╚═════╝  ╚═════╝   ╚═╝      ╚══════╝

```



\# ✊ 🖐️ ✌️ Rock · Paper · Scissors



\*\*A classic console game — built with C++, played against the machine.\*\*



!\[C++](https://img.shields.io/badge/C%2B%2B-17-blue?style=for-the-badge\&logo=c%2B%2B\&logoColor=white)

!\[Platform](https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge\&logo=windows\&logoColor=white)

!\[Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)



</div>



\---



\## 📸 Preview



```

╔══════════════════════════════════════╗

║     ++ R o u n d  \[ 1 ]  B e g i n s ++

║                                      ║

║   Your Choice                        ║

║   ──────────────────────             ║

║   '1' : Rock                         ║

║   '2' : Paper                        ║

║   '3' : Scissors                     ║

║   --> 1                              ║

║                                      ║

║   Player Choice     : Rock           ║

║   Computer Choice   : Scissors       ║

║   Round Winner      : ✅ Player      ║

╚══════════════════════════════════════╝

```



\---



\## ⚡ Features



| # | Feature | Details |

|---|---------|---------|

| 🎮 | Multi-Round | Play from \*\*1 up to 20 rounds\*\* per session |

| 🤖 | Smart Random | Computer picks randomly every round |

| 🎨 | Color Console | 🟢 You win · 🔴 CPU wins · 🟡 Draw |

| 🔊 | Sound Effects | Beep feedback on win or loss |

| 📊 | Game Summary | Full scoreboard displayed after the last round |

| 🔁 | Play Again | Restart instantly without closing the program |



\---



\## 🕹️ How to Play



```

1\. Launch the game

2\. Choose number of rounds  →  (1 to 20)

3\. Each round, pick your move:



&#x20;       \[ 1 ]  ✊  Rock

&#x20;       \[ 2 ]  🖐️  Paper

&#x20;       \[ 3 ]  ✌️  Scissors



4\. The result shows after every round

5\. Final winner is revealed at the end 🏆

```



\---



\## 🏆 Win Conditions



```

&#x20; ✊ Rock     beats   ✌️ Scissors

&#x20; ✌️ Scissors beats   🖐️ Paper

&#x20; 🖐️ Paper    beats   ✊ Rock

```



\---



\## 🔧 Requirements



```

• Windows OS

• C++ Compiler  →  MinGW / MSVC / g++

• C++11 or later

```



\---



\## ▶️ Compile \& Run



```bash

\# Compile

g++ main.cpp -o rps.exe



\# Run

./rps.exe

```



\---



\## 📁 Project Structure



```

📂 02 - Rock Paper Scissors/

│

├── 📄 Project 1.cpp        ← All game logic lives here

└── 📄 README.md       ← You are here

```



\---



\## 🧠 Code Highlights



```cpp

enum enRockPaperScissors { ROCK = 1, PAPER, SCISSORS };

enum enWinner            { PLAYER, COMPUTER, DRAW     };

```



> The game uses \*\*enums\*\* and \*\*structs\*\* to keep data clean and organized — no messy global variables.



\---



<div align="center">



Made with ❤️ by Mohammad Al-Sabbagh — CS Student, Year 1



</div>

