#pragma once
#include <vector>

enum class CardColor {
    RED,
    BLACK
};

enum class CardType {
    // in polish cuz im stupid
    KIER,
    PIK,
    KARO, 
    TREFL
};

enum class CardRank {
    Ace, // As
    Two, 
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack, // Jopek
    Queen, // Dama
    King // Król
};

class Card {
    private:
        CardType type;
        CardRank rank;
    public:
        bool hidden;

        Card() {}
        Card(CardType t, CardRank r): type(t), rank(r) {}
        // ~Card() {
        //     ~hidden;

        // }

        CardType getType() { return type; }
        CardRank getRank() { return rank; }

        CardColor getColor() {
            switch(getType()) {
                case CardType::KIER:
                case CardType::KARO:
                    return CardColor::RED;
                case CardType::PIK:
                case CardType::TREFL:
                    return CardColor::BLACK;
            }
            // So the guy (G++) compiling this will not crap about it
            return CardColor::BLACK;
        }
};


typedef std::vector<Card> Stack;
