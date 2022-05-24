#ifndef FOUROFAKINDVALIDATOR_H
#define FOUROFAKINDVALIDATOR_H

#include "validator.h"
#include "count_calulator.h"
#include "../card.h"
#include <string>
#include <vector>

class FourOfAKindValidator : public Validator
{
public:
    FourOfAKindValidator(std::vector<Card> cards)
    {
        this->cards = cards;
    }
    std::string name() override
    {
        return "Four of A Kind";
    }
    bool is_valid() override
    {
        std::vector<std::string> ranks_with_four_of_a_kind = CountCalculator::ranks_with_target_count(this->cards, 4);
        return (ranks_with_four_of_a_kind.size() == 1);
    }
    std::vector<Card> valid_cards() override
    {
        std::vector<std::string> ranks_with_four_of_a_kind = CountCalculator::ranks_with_target_count(this->cards, 4);

        for (Card &card : this->cards)
        {
            for (std::string rank : ranks_with_four_of_a_kind)
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