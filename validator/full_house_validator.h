#ifndef FULLHOUSEVALIDATOR_H
#define FULLHOUSEVALIDATOR_H

#include "validator.h"
#include "count_calulator.h"
#include "../card.h"
#include "../util.h"
#include <string>
#include <vector>
#include "pair_validator.h"
#include "three_of_a_kind_validator.h"

class FullHouseValidator : public Validator
{
public:
    FullHouseValidator(std::vector<Card> cards)
    {
        this->cards = cards;
        this->pair = PairValidator(cards);
        this->three_of_a_kind = ThreeOfAKindValidator(cards);
    }
    std::string name() override
    {
        return "Full House";
    }
    bool is_valid() override
    {
        if (!this->pair.is_valid())
        {
            return false;
        }
        if (!this->three_of_a_kind.is_valid())
        {
            return false;
        }

        return true;
    }
    std::vector<Card> valid_cards() override
    {
        for (Card &card : pair.valid_cards())
        {
            this->_valid_cards.push_back(card);
        }

        for (Card &card : three_of_a_kind.valid_cards())
        {
            this->_valid_cards.push_back(card);
        }
        return this->_valid_cards;
    }

private:
    std::vector<Card> cards;
    std::vector<Card> _valid_cards;
    PairValidator pair;
    ThreeOfAKindValidator three_of_a_kind;
};

#endif