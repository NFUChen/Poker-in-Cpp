#ifndef STRAIGHTFLUSHVALIDATOR_H
#define STRAIGHTFLUSHVALIDATOR_H

#include "validator.h"
#include "count_calulator.h"
#include "../card.h"
#include "../util.h"
#include <string>
#include <vector>
#include "straight_validator.h"
#include "flush_validator.h"

class StraightFlushValidator : public Validator
{
public:
    StraightFlushValidator() = default;
    StraightFlushValidator(std::vector<Card> cards)
    {
        this->cards = cards;
        this->straight = StraightValidator(cards);
        this->flush = FlushValidator(cards);
    }
    std::string name() override
    {
        return "Straight Flush";
    }
    bool is_valid() override
    {
        if (!this->straight.is_valid())
        {
            return false;
        }

        if (!this->flush.is_valid())
        {
            return false;
        }

        return true;
    }
    std::vector<Card> valid_cards() override
    {

        for (Card &card : straight.valid_cards())
        {
            this->_valid_cards.push_back(card);
        }

        return this->_valid_cards;
    }

private:
    std::vector<Card> cards;
    std::vector<Card> _valid_cards;
    StraightValidator straight;
    FlushValidator flush;
};

#endif