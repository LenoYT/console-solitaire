# 🃏🇪🇳 Solitaire Console Application

A minimalist console-based Solitaire game written in C++.  
Includes smooth arrow-key navigation and automatic crash recovery.

---

## 📦 Build & Run

To **compile and automatically run** the application:

```bash
compile
```

To **run a previously compiled version**:

```bash
play
```

This runs the archived file:
`SolitaireConsoleApp.arch.exe`
(*Automatically updated on each new run.*)

---

## 🎮 Controls

* **← / →**: Move selection left or right.
* **↓**: Draw a card from the deck.
* **↑**: Pick up or move a stack.
* **Enter**: Place the held stack.

---

## 💥 Crash Handling

If the program encounters a `std::bad_alloc` error (usually due to memory exhaustion), it **automatically restarts**.

> 🛑 To **cancel the automatic restart**, press any key within **200 milliseconds** after the crash.

---

## 🗃 Archive Behavior

Each time the game runs, it creates a fresh archive:
`SolitaireConsoleApp.arch.exe`
It contains the **last working version** of the app for easy recovery or testing.

---

<html>
    </br>
    <div align="center">
        <img alt="author" src="https://img.shields.io/badge/Author-Leo-purple" />
        <img alt="license_mit" src="https://img.shields.io/badge/License-MIT-null" />
        <img alt="gigathon" src="https://img.shields.io/badge/Made_for-Gigathon-red" />
        <img alt="cpp" src="https://img.shields.io/badge/In-C%2B%2B-yellow" />
        <img alt="preffered_platform" src="https://img.shields.io/badge/Preferred_Platform-Windows-0078c2" />
        <img alt="version" src="https://img.shields.io/badge/Version-2.0.0-006e35" />
        <a href="https://github.com/LenoYT/console-solitaire">
            <img alt="github" src="https://img.shields.io/badge/Github-black" />
    </div>
    </br>
</html>

---

# 🃏🇵🇱 Solitaire w Konsoli

Minimalistyczna gra w pasjansa działająca w konsoli, napisana w C++.
Obsługa za pomocą klawiatury (strzałek) oraz automatyczne odzyskiwanie po awarii.

---

## 📦 Kompilacja i Uruchomienie

Aby **skompilować i automatycznie uruchomić** aplikację:

```bash
compile
```

Aby **uruchomić już istniejący plik**:

```bash
play
```

Program uruchamia tworzy plik:
`SolitaireConsoleApp.arch.exe`
(*Tworzony automatycznie przy każdym uruchomieniu.*)

---

## 🎮 Sterowanie

* **← / →**: Przesuwanie wyboru w lewo lub prawo.
* **↓**: Dobranie karty z talii.
* **↑**: Podniesienie lub przenoszenie stosu.
* **Enter**: Upuszczenie trzymanego stosu.

---

## 💥 Obsługa Błędów

W przypadku błędu `std::bad_alloc` (np. brak pamięci), program **automatycznie się restartuje**.

> 🛑 Aby **przerwać restart**, naciśnij dowolny klawisz w ciągu **200 ms** od momentu awarii.

---

## 🗃 Zachowanie Archiwum

Za każdym uruchomieniem tworzony jest nowy plik archiwalny:
`SolitaireConsoleApp.arch.exe`
Zawiera **ostatnią działającą wersję** aplikacji do odzyskiwania lub testów.

---
