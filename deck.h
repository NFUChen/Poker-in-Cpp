#ifndef DECK_H
#define DECK_H
#include <vector>
#include <algorithm>
#include "card.h"
#include "util.h"

class Deck
{
private:
    std::vector<Card> cards;

public:
    Deck()
    {
        std::vector<Card> standard_52_cards = Card::create_standard_52_cards();
        add_cards(standard_52_cards);
    }
    void add_cards(std::vector<Card> cards)
    {
        for (Card card : cards)
        {
            this->cards.push_back(card);
        }
    }
    std::vector<Card> remove_cards(int number_of_cards)

    {
        if (number_of_cards > this->cards.size())
        {
            throw std::invalid_argument("Only have " + std::to_string(this->cards.size()) + " cards, entering" + std::to_string(number_of_cards) + " cards.");
        }
        std::vector<Card> cards_removed;
        for (int idx = 0; idx < number_of_cards; idx++)
        {
            cards_removed.push_back(this->cards.at(idx));
            this->cards.erase(this->cards.begin() + idx);
        }

        return cards_removed;
    }

    void shuffle_deck()
    {
        Util::shuffle_vector<Card>(this->cards);
    }
    std::vector<Card> get_all_cards_on_deck() const
    {

        return this->cards;
    }
    bool is_empty_deck() const
    {
        return this->cards.empty();
    }
    int cards_remaining_on_deck() const
    {
        return this->cards.size();
    }
};

std::ostream &operator<<(std::ostream &stream, const Deck &deck)
{
    if (deck.is_empty_deck())
    {
        stream << "No Cards!" << std::endl;
        return stream;
    }
    for (const Card &card : deck.get_all_cards_on_deck())
    {
        stream << card.to_string() << std::endl;
    }

    return stream;
}

#endif