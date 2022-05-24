#ifndef COUNTCALCULATOR_H
#define COUNTCALCULATOR_H

#include <vector>
#include <string>
#include <map>
#include "../card.h"
#include "../util.h"

struct CountCalculator
{
    static std::vector<std::string> ranks_with_target_count(std::vector<Card> cards, int target_count)
    {
        std::vector<std::string> rank_vector;
        for (Card &card : cards)
        {
            rank_vector.push_back(card.rank);
        }
        std::map<std::string, int> rank_count = Util::count(rank_vector);

        std::vector<std::string> ranks_with_target_count_vector;
        for (const auto [rank, count] : rank_count)
        {
            if (count == target_count)
            {
                ranks_with_target_count_vector.push_back(rank);
            }
        }

        return ranks_with_target_count_vector;
    }

    static std::vector<std::string> suits_with_target_count(std::vector<Card> cards, int target_count)
    {
        std::vector<std::string> suit_vector;
        for (Card &card : cards)
        {
            suit_vector.push_back(card.suit);
        }
        std::map<std::string, int> suit_count = Util::count(suit_vector);

        std::vector<std::string> suits_with_target_count_vector;
        for (const auto [rank, count] : suit_count)
        {
            if (count == target_count)
            {
                suits_with_target_count_vector.push_back(rank);
            }
        }

        return suits_with_target_count_vector;
    }
};

#endif