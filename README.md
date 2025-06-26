# Login2Play 🎮 (IE Project – PPS @ TCET)

A terminal-based project in C that combines a full **user authentication system** (registration and login) with a playable **Tic-Tac-Toe game**. Developed as a **group academic project** for the subject **PPS (Programming for Problem Solving)** under the **Innovative Examination (IE)** of Semester 2 at **TCET**.

🧑‍💻 **Group Members:**
- **Prince Jha**
- **Sachin Jha**

---

## 📋 Features

- **Sign-Up System**  
  - Takes full name, phone number, Gmail ID, and masked password
  - Validates phone number (10 digits) and email (must end with `@gmail.com`)
  - Generates a username automatically from email
  - Saves user data in a binary file (`Users.dat`)

- **Login System**
  - Verifies credentials from stored data
  - Shows progress bar animation on successful login
  - Displays full user profile (name, phone, email, username)

- **Tic-Tac-Toe Game**
  - Optionally launches after login
  - Classic 2-player mode with win/draw logic
  - Clean, centered CLI layout using `printf`
  - Game continues until win or draw condition is met

- **Polished User Interface**
  - Blue background screen (`system("color B0")`)
  - Menu and game layout centered and clearly formatted
  - Prompts are displayed for **every invalid input** (e.g., wrong password, wrong email/phone format, username not found, position already filled, etc.)
  - Feedback is given using **`Beep()` sounds**, messages, and clean structure

---

## 🚫 Limitations

- Passwords stored in plain text (no encryption)
- Windows-only (`windows.h`, `conio.h`, `Beep()` usage)
- No admin panel or user management features
- No multiplayer over network — local only

---

## 🧪 Academic Context

| Field                | Info                                      |
|---------------------|-------------------------------------------|
| 📚 Subject           | Programming for Problem Solving (PPS)     |
| 🏫 College           | Thakur College of Engineering & Technology (TCET) |
| 📘 Semester          | 2nd Semester                              |
| 🧪 Project Type      | Innovative Examination (IE) Group Project |
| 👨‍👦 Contributors      | Prince Jha, Sachin Jha                    |

---

## 🛠️ How to Run

1. Open `loginformnew.c` in **VS Code**, **Turbo C**, or any C compiler (Windows)
2. Compile the file
3. Run in terminal/command prompt
4. Choose from the menu:
   - 1 → Register
   - 2 → Login (launches game option after success)
   - 3 → Exit

---

## 📂 Files Used

- `loginformnew.c` → Main source code
- `Users.dat` → Stores user credentials locally (binary format)

🗃️ Note: Users.dat is auto-generated when users register. It should not be pushed to GitHub.

---

## ✍️ Author

**Prince Jha**  
Group Project for TCET – Semester 2 – PPS Subject (IE Format)

---

## ✅ Status

🎯 Project completed, tested, and presented as part of an academic submission.
