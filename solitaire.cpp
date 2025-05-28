#include <windows.h>
#include "logic.hpp"
#include "render.hpp"

void init() {
    start();

    while (true) {
        try {
            renderSolitaire();
            // we are waiting on inputHandler
            inputHandler(); // like this the entire game
            checkState(); // checking if won/lose/playing
            Sleep(100);
        } catch (const std::bad_alloc) {
            std::cout << RED << "Error in initializing deck, auto refreshing in 200ms" << RESET << "\nExit by clicking anything on keyboard in 10ms";
            Sleep(10);
            for (int i = 0; i < 200; i++) {
                if (_kbhit()) {
                    std::cout << "\nExiting, Reason: Clicked a Keyboard";
                    exit(1);
                }
                Sleep(1); // sleep 1ms 
            }
            init();
            return;
        } catch (const std::exception& e) {
            std::cerr << RED << "Exception caught: " << RESET << e.what() << '\n';
            exit(1);
        }
        
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    
    SetConsoleTitleA("Console Solitaire - By Leon 4 Gigathon");

    cursorInfo.bVisible = FALSE; // hiding some stuff :3
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    init();

    cursorInfo.bVisible = TRUE; // showing some stuff :3
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    return 0;
}
