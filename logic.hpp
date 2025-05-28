#pragma once
#include <random>
#include <algorithm>
#include "emergency/conio.h"
#include "render.hpp"
using namespace std;

Stack draw_pile {};

vector<Card> createDeck() {
    vector<Card> deck;
    deck.reserve(124);
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 1; rank <= 13; rank++) {
            Card c((CardType)suit, (CardRank)rank);
            deck.push_back(c);
        }
    }
    // Shuffle deck
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
    return deck;
}

void start() {
    stacks.clear();
    stacks.reserve(84);
    draw_pile.clear();
    draw_pile.reserve(84);

    vector<Card> deck = createDeck();
    int index = 0;

    for (int i = 0; i < 7; i++) {
        Stack sb;
        for (int j = 0; j <= i; j++) {
            Card c = deck[index++];
            c.hidden = (j != i); // only last card is visible
            sb.push_back(c);
        }
        stacks.push_back(sb);
    }

    // add cards to the draw pile
    while (index < (int)deck.size()) {
        Card c = deck[index++];
        c.hidden = true;
        draw_pile.push_back(c);
    }
}

void checkState() {
    // WIN | PLAYING | LOSE
    bool kier=0, pik=0, karo=0, trefl=0;
    for (Stack stack : stacks) {
        for (Card card : stack) {
            if (card.getRank() == CardRank::Ace) switch (card.getType()) {
                case CardType::KIER: kier=1; break;
                case CardType::PIK: pik=1; break;
                case CardType::KARO: karo=1; break;
                case CardType::TREFL: trefl=1; break;
                default: break;
            }
        }
    }
    if (kier && pik && karo && trefl) state = GameState::WIN; // idk conditions to lose
}

bool handlePuttingStackCheckingIfCanPlace(int target_stack_id, Stack& invstack) {
    if (target_stack_id < 0 || target_stack_id >= (int)stacks.size()) return false;
    if (stacks[target_stack_id].empty() || invstack.empty()) return false;

    Card& oncard = stacks[target_stack_id].back(); // card to put on top of
    Card& ourcard = invstack.front(); // card we want to put down

    return (
        ((int)ourcard.getRank() + 1 == (int)oncard.getRank()) &&
        (ourcard.getType() == oncard.getType())
    );
}

void handlePuttingStacks() {
    int ch;
    int lastTargetedStackID = selected_stack;
    bool pressedPut = false;

    if (selected_stack < 0 || selected_stack >= (int)stacks.size()) return;

    Stack& stack = stacks[selected_stack];
    Stack visible_cards;

    // Extract visible cards
    for (const Card& card : stack) {
        if (!card.hidden) {
            visible_cards.push_back(card);
        }
    }

    if (visible_cards.empty()) return; // Nothing to move

    // Remove visible cards from original stack (backwards)
    for (int i = (int)stack.size() - 1; i >= 0; --i) {
        if (!stack[i].hidden) {
            stack.erase(stack.begin() + i);
        }
    }

    while (!pressedPut) {
        renderSolitaire();
        ch = _getch();

        if (ch == 13) {  // ENTER to place cards
            int target_stack = selected_stack;
            if (handlePuttingStackCheckingIfCanPlace(target_stack, visible_cards)) {
                for (Card& c : visible_cards) {
                    stacks[target_stack].push_back(c);
                }

                // Reveal next card of original stack if any
                if (!stacks[lastTargetedStackID].empty()) {
                    stacks[lastTargetedStackID].back().hidden = false;
                }

                visible_cards.clear();
                pressedPut = true;
            }
        }
        else if (ch == 27) {  // ESC to cancel
            for (Card& c : visible_cards) {
                stack.push_back(c);
            }
            visible_cards.clear();
            pressedPut = true;
        }
        else if (ch == 0 || ch == 0xE0) {
            int spec = _getch();
            switch (spec) {
                case 75:  // Left
                    selected_stack = max(0, selected_stack - 1);
                    break;
                case 77:  // Right
                    selected_stack = min((int)stacks.size() - 1, selected_stack + 1);
                    break;
            }
        }
    }
}

void getFromDrawPile() {
    // idk how this should work so:
    // adding top card from draw tile to random && possible stack
    if (draw_pile.empty()) return;

    Card card = draw_pile.front();

    for (auto& stack : stacks) {
        if (!stack.empty() &&
            (int)card.getRank() == (int)stack.front().getRank() - 1 &&
            card.getType() == stack.front().getType()) {
            card.hidden = false;
            stack.push_back(card);
            draw_pile.erase(draw_pile.begin());
            return;  // card added, stop
        }
    }

    // deleting cuz card was used / card can block other cards
    draw_pile.erase(draw_pile.begin());
}


void inputHandler() {
    bool left=0, right=0, up=0, down=0, esc=0;
    while (!_kbhit()) ; // wait for click
    int ch = _getch();
    if (ch == 0 || ch == 0xE0) { // 0xE0 chceking if presses advaced
        int arrow = _getch();
        switch (arrow) {
            case 72: up=true; break;
            case 80: down=true; break;
            case 75: left=true; break;
            case 77: right=true; break;
            case 27: esc=true; break;
            default: break;
        }
    }

    // moving
    if (left) selected_stack = max(0, selected_stack-1);
    if (right) selected_stack = min(8, selected_stack+1);
    if (up) handlePuttingStacks();
    if (down) getFromDrawPile();
    if (esc) exit(0);
}