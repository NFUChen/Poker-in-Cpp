#ifndef STRAIGHTVALIDATOR_H
#define STRAIGHTVALIDATOR_H

#include "validator.h"
#include "count_calulator.h"
#include "../card.h"
#include "../util.h"
#include <vector>
#include <string>
#include <algorithm>

class StraightValidator : public Validator
{
public:
    StraightValidator() = default;
    StraightValidator(std::vector<Card> cards)
    {
        this->cards = cards;
        std::sort(this->cards.begin(), this->cards.end());
    }
    std::string name() override
    {
        return "Straight";
    }
    bool is_valid() override
    {
        if (this->cards.size() < 5)
        {
            return false;
        }

        int number_of_cards = 5;
        std::vector<std::vector<Card>> cards_in_a_row;
        for (int idx = 0; idx < (this->cards.size() + 1 - number_of_cards); idx++)
        {

            std::vector<Card> curr_cards = Util::vector_slice<Card>(this->cards, idx, idx + number_of_cards);
            cards_in_a_row.push_back(curr_cards);
        }

        std::vector<std::vector<Card>> valid_cards_vector;
        for (std::vector<Card> five_cards : cards_in_a_row)
        {
            int first_card_rank_idx = five_cards.front().rank_idx;
            int final_card_rank_idx = five_cards.back().rank_idx;
            std::vector<int> consecutive_rank_indexes = Util::create_range_vector(first_card_rank_idx, final_card_rank_idx + 1);

            std::vector<int> five_cards_rank_index_vector;
            for (const Card &card : five_cards)
            {
                five_cards_rank_index_vector.push_back(card.rank_idx);
            }

            bool is_two_vectors_equal = Util::is_two_vectors_equal(five_cards_rank_index_vector, consecutive_rank_indexes);
            if (is_two_vectors_equal)
            {
                valid_cards_vector.push_back(five_cards);
            }
        }
        if (!valid_cards_vector.empty())
        {
            this->_valid_cards = valid_cards_vector.back(); // best hand
            return true;
        }
        return false;
    }
    std::vector<Card> valid_cards() override
    {
        return this->_valid_cards;
    }

private:
    std::vector<Card> cards;
    std::vector<Card> _valid_cards;
};

#endif