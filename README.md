# 🗿✂️📄 Rock Paper Scissors Game (C++ Console)

---

**•** A fun and interactive **Rock Paper Scissors** game built entirely in **C++** using basic programming concepts such as enums, structs, loops, conditionals, and random number generation.

**•** The game runs in the **Windows Console**, featuring **colorful feedback** and **sound effects** for each round.
---

## 🎮 Features

- Play **1 to 10 rounds** per session.  
- Real-time **random computer choices**.  
- **Colored output** to indicate round results:  
  - 🟢 Green → Player wins  
  - 🔴 Red → Computer wins  
  - 🟡 Yellow → Draw  
- **Sound effect** when the computer wins.  
- **Displays full game statistics**, including:  
  - Total rounds  
  - Wins for player and computer  
  - Number of draws  
  - Final winner  
- Option to **restart the game** after finishing.

---

## 🧠 Concepts Used

- **Enums** for game choices (`Stone`, `Paper`, `Scissors`)  
- **Structs** to store game results  
- **Functions** for modular and clean code  
- **Random number generation** (`rand() %`)  
- **Windows Console commands** (`system("color")`, `system("cls")`)  
- **Loops and conditional logic**  
- **Input validation**

---

## ⚙️ How It Works

1. The player chooses the number of rounds (1–10).  
2. In each round:
   - The player selects between **Stone (1)**, **Paper (2)**, or **Scissors (3)**.
   - The computer randomly picks one as well.
   - The winner of the round is determined and displayed with color and sound.
3. After all rounds, the final results and winner are displayed.  
4. The player can choose to play again or exit.

---

## 🧾 Example Output

```
How many round from 1 to 10 ? : 3

---------------Round [1]-----------------
Your choice : [1]:Stone, [2]:Paper [3]:Scissors ? : 1
Player1 Choice :  Stone
Computer Choice :  Paper
Round Winner :  Computer

---------------Round [2]-----------------
Your choice : [1]:Stone, [2]:Paper [3]:Scissors ? : 3
Player1 Choice :  Scissors
Computer Choice :  Paper
Round Winner :  Player

---------------Round [3]-----------------
Your choice : [1]:Stone, [2]:Paper [3]:Scissors ? : 2
Player1 Choice :  Paper
Computer Choice :  Paper
Round Winner :  Draw [No Winner]

--------------------------------------------------
         +++ G  A  M  E   O  V  E  R +++
--------------------------------------------------

Game Rounds : 3
Player1 Won Times : 1
Computer Won Times : 1
Draw Times : 1
Finall Winner :  Draw [No Winner]
```

## 🏁 Future Improvements

- Add score saving between sessions  
- Add player names  
- Support multiplayer (Player vs Player)  
- Add ASCII animations  

---

## 👨‍💻 Author

**Damoni**  
🎓 Student of Mohammed Abu-Hadhoud’s C++ Course  
💬 Focused on learning algorithms, clean coding, and C++ game logic  
