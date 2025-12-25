# Login2Play 🎮  
CLI-Based Authentication System with Game Logic

Login2Play is a terminal-based application written in C that implements a user registration and login system, followed by an optional two-player Tic-Tac-Toe game. The project demonstrates structured programming, file handling, input validation, and control flow in a command-line environment.

---

## 🚀 Features

### 🔐 User Authentication
- User registration with:
  - Full name
  - Phone number (10-digit validation)
  - Email ID validation
  - Password input
- User login with credential verification
- Persistent storage using binary file handling
- Automatic username generation

### 🎮 Tic-Tac-Toe Game
- Optional launch after successful login
- Classic 2-player mode
- Win, lose, and draw detection
- Clean CLI-based board layout
- Input validation for occupied positions

### 🖥️ Command-Line Interface
- Menu-driven navigation
- Clear prompts and error messages
- Structured flow for registration, login, and gameplay

---

## 🛠️ Tech Stack
- **Language:** C  
- **Concepts Used:**
  - File handling
  - Structures
  - Input validation
  - Conditional logic
  - Loops and functions

---

## ⚠️ Limitations
- Passwords stored in plain text (no encryption)
- Platform-dependent features (Windows-specific headers)
- No role-based access or admin management
- Local execution only (no networking)

---

## 📂 Project Structure
- `loginformnew.c` — main source file  
- `Users.dat` — auto-generated binary file for user data  

> ⚠️ `Users.dat` is generated at runtime and should not be pushed to GitHub.

---

## ▶️ How to Run
1. Open the source file in any C compiler (e.g., VS Code, GCC, Turbo C on Windows)
2. Compile the program
3. Run the executable in the terminal
4. Choose from the menu:
   - Register
   - Login
   - Exit

---

## 🎯 Learning Outcomes
- Applied structured programming in C
- Implemented persistent storage using files
- Designed a menu-driven CLI application
- Strengthened understanding of control flow and logic building

---

## 👤 Author
**Prince Jha**  
Computer Engineering Student  
Thakur College of Engineering and Technology (TCET)

---

## ✅ Project Status
✔ Completed  
✔ Tested  
✔ Maintained for learning and demonstration purposes
