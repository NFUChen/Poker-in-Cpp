#ifndef PAIRVALIDATOR_H
#define PAIRVALIDATOR_H

#include "validator.h"
#include "count_calulator.h"
#include "../card.h"
#include <string>
#include <vector>

class PairValidator : public Validator
{
public:
    PairValidator() = default;
    PairValidator(std::vector<Card> cards)
    {
        this->cards = cards;
    }
    std::string name() override
    {
        return "Pair";
    }
    bool is_valid() override
    {
        std::vector<std::string> ranks_with_pair = CountCalculator::ranks_with_target_count(this->cards, 2);
        return (ranks_with_pair.size() == 1);
    }
    std::vector<Card> valid_cards() override
    {
        std::vector<std::string> ranks_with_pair = CountCalculator::ranks_with_target_count(this->cards, 2);

        for (Card &card : this->cards)
        {
            for (std::string rank : ranks_with_pair)
            {
                if (card.rank == rank)
                {
                    this->_valid_cards.push_back(card);
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