#ifndef STRAIGHTHOUSEVALIDATOR_H
#define STRAIGHTHOUSEVALIDATOR_H

#include "validator.h"
#include "count_calulator.h"
#include "../card.h"
#include "../util.h"
#include <string>
#include <vector>
#include "straight_flush_validator.h"

class RoyalFlushValidator : public Validator
{
public:
    RoyalFlushValidator(std::vector<Card> cards)
    {
        this->cards = cards;
        this->straight_flush = StraightFlushValidator(cards);
    }
    std::string name() override
    {
        return "Royal Flush";
    }
    bool is_valid() override
    {

        if (!this->straight_flush.is_valid())
        {
            return false;
        }

        bool is_royal = this->cards.front().rank == "10" && this->cards.back().rank == "Ace";
        if (!is_royal)
        {
            return false;
        }

        return true;
    }
    std::vector<Card> valid_cards() override
    {

        for (Card &card : straight_flush.valid_cards())
        {
            this->_valid_cards.push_back(card);
        }

        return this->_valid_cards;
    }

private:
    std::vector<Card> cards;
    std::vector<Card> _valid_cards;
    StraightFlushValidator straight_flush;
};

#endif