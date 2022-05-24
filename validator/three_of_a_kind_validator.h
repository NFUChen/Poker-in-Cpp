#ifndef THREEOFAKINDVALIDATOR_H
#define THREEOFAKINDVALIDATOR_H

#include "validator.h"
#include "count_calulator.h"
#include "../card.h"
#include <vector>
#include <string>

class ThreeOfAKindValidator : public Validator
{
public:
    ThreeOfAKindValidator() = default;
    ThreeOfAKindValidator(std::vector<Card> cards)
    {
        this->cards = cards;
    }
    std::string name() override
    {
        return "Three of A Kind";
    }
    bool is_valid() override
    {
        std::vector<std::string> ranks_with_three_of_a_kind = CountCalculator::ranks_with_target_count(this->cards, 3);
        return (ranks_with_three_of_a_kind.size() == 1);
    }
    std::vector<Card> valid_cards() override
    {
        std::vector<std::string> ranks_with_three_of_a_kind = CountCalculator::ranks_with_target_count(this->cards, 3);

        for (Card &card : this->cards)
        {
            for (std::string rank : ranks_with_three_of_a_kind)
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