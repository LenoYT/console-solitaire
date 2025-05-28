#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <cstdlib>
#include <map>
#include "card.hpp"
using namespace std;

enum class GameState {
    PLAYING,
    LOSE,
    WIN
};

GameState state = GameState::PLAYING;

vector<Stack> stacks(7);

void clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int selected_stack = 0;

map<CardType, string> render_symbols = {
    {CardType::KIER, "♥"},
    {CardType::KARO, "♦"},
    {CardType::PIK, "♠"},
    {CardType::TREFL, "♣"}
};

vector<string> rankStrings = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

string RED = "\033[31m";
string BLACK = "\033[30m";
string BG_CHOSEN = "\033[47m";
string RESET = "\033[0m";

string renderCard(Card& card, int col) {
    cout << ((selected_stack == col) ? BG_CHOSEN : RESET);
    cout << ((card.getColor() == CardColor::RED) ? RED : BLACK);

    cout << (string) rankStrings[(int) card.getRank()];
    cout << render_symbols[card.getType()];

    return RESET; // we have to return something
}

void renderSolitaire() {
    clear();

    switch (state) {
        default: break;
        case GameState::PLAYING: break;
        case GameState::LOSE: cout << RED << "\nYou lose!"; exit(0);
        case GameState::WIN: cout << "\nYou win!"; exit(0);
    }

    size_t maxHeight = 0;
    for (auto& stack : stacks) {
        if (stack.size() > maxHeight) maxHeight = stack.size();
    }

    for (size_t row = 0; row < maxHeight; row++) {
        for (size_t col = 0; col < stacks.size(); col++) {
            if (row < stacks[col].size()) {
                Card& c = stacks[col][row];
                if (c.hidden) cout << "##  ";
                else cout << renderCard(c, col) + "  ";
                
            } else cout << "    "; 
            
        }
        cout << "\n";
    }

    for (int i = 0; i < 12; i++) {
        if (i == selected_stack) cout << "^^";
        else cout << "    ";
    }
}
