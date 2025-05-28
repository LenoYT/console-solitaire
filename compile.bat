@echo off
copy SolitaireConsoleApp.exe SolitaireConsoleApp.arch.exe
g++ solitaire.cpp -o SolitaireConsoleApp
pause
.\SolitaireConsoleApp.exe
del SolitaireConsoleApp.exe