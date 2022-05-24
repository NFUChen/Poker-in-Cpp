#ifndef TWOPAIRVALIDATOR_H
#define TWOPAIRVALIDATOR_H

#include "validator.h"
#include "count_calulator.h"
#include "../card.h"
#include <vector>

class TwoPairValidator : public Validator
{
public:
    TwoPairValidator(std::vector<Card> cards)
    {
        this->cards = cards;
    }
    std::string name() override
    {
        return "Two Pair";
    }

    bool is_valid() override
    {
        std::vector<std::string> ranks_with_two_pair = CountCalculator::ranks_with_target_count(this->cards, 2);
        return (ranks_with_two_pair.size() == 2);
    }
    std::vector<Card> valid_cards() override
    {
        std::vector<std::string> ranks_with_two_pair = CountCalculator::ranks_with_target_count(this->cards, 2);

        for (Card &card : this->cards)
        {
            for (std::string rank : ranks_with_two_pair)
            {
                if (card.rank == rank)
                {
                    this->_valid_cards.push_back(card);
                    break;
                }
            }
        }

        return this->_valid_cards;
    }

private:
    std::vector<Card> cards;
    std::vector<Card> _valid_cards;
};

#endif