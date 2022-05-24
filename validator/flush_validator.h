#ifndef FLUSHVALIDATOR_H
#define FLUSHVALIDATOR_H

#include "validator.h"
#include "count_calulator.h"
#include "../card.h"
#include "../util.h"
#include <string>
#include <vector>

class FlushValidator : public Validator
{
public:
    FlushValidator() = default;
    FlushValidator(std::vector<Card> cards)
    {
        this->cards = cards;
        for (Card &card : this->cards)
        {
            this->suit_vector.push_back(card.suit);
        }
    }
    std::string name() override
    {
        return "Flush";
    }

    bool is_valid() override
    {
        std::map<std::string, int> suit_count = Util::count(this->suit_vector);
        std::vector<std::string> suits_that_occur_5_or_more_times;
        for (const auto [suit, count] : suit_count)
        {
            if (count >= 5)
            {
                this->valid_suit = suit;
                return true;
            }
        }
        return false;
    }
    std::vector<Card> valid_cards() override
    {
        for (Card &card : this->cards)
        {
            if (card.suit == this->valid_suit)
            {
                this->_valid_cards.push_back(card);
            }
        }
        return this->_valid_cards;
    }

private:
    std::vector<Card> cards;
    std::vector<Card> _valid_cards;
    std::vector<std::string> suit_vector;
    std::string valid_suit;
};

#endif