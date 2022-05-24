#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <vector>
#include "util.h"
static std::vector<std::string> RANK = {"2", "3", "4", "5", "6", "7", "8", "9", "10",
                                        "Jack", "Queen", "King", "Ace"};
static std::vector<std::string> SUIT = {"Hearts", "Clubs", "Spades", "Diamonds"};

class Card
{
public:
    std::string rank;
    int rank_idx;
    std::string suit;
    int suit_idx;

    Card(std::string rank, std::string suit)
    {
        if (!is_valid_suit(suit))
        {
            std::string error_msg = std::string{"'suit' must be one of the following "} + Util::vector_to_string(SUIT);
            throw std::invalid_argument(error_msg);
        }
        if (!is_valid_rank(rank))
        {
            std::string error_msg = std::string{"'rank' must be one of the following "} + Util::vector_to_string(RANK);
            throw std::invalid_argument(error_msg);
        }

        this->rank = rank;
        this->suit = suit;

        this->rank_idx = Util::find_index<std::string>(RANK, rank);
        this->suit_idx = Util::find_index<std::string>(SUIT, suit);
    }

    std::string to_string() const
    {
        std::string _repr = this->rank + " of " + this->suit;
        return _repr;
    }

    static std::vector<Card> create_standard_52_cards()
    {

        std::vector<Card> _52_cards;
        for (std::string suit : SUIT)
        {
            for (std::string rank : RANK)
            {
                _52_cards.push_back(
                    Card(rank, suit));
            }
        }
        return _52_cards;
    }

    bool operator==(const Card &_other_card)
    {
        return (this->rank == _other_card.rank) &&
               (this->suit == _other_card.suit);
    }
    bool operator>(const Card &_other_card) const
    {
        return (this->rank_idx > _other_card.rank_idx);
    }

    bool operator<(const Card &_other_card) const
    {
        return (this->rank_idx < _other_card.rank_idx);
    }

private:
    bool is_valid_suit(std::string check_suit)
    {

        for (auto suit : SUIT)
        {
            if (check_suit == suit)
            {
                return true;
            }
        }
        return false;
    }
    bool is_valid_rank(std::string check_rank)
    {
        for (auto rank : RANK)
        {
            if (check_rank == rank)
            {
                return true;
            }
        }
        return false;
    }
};

std::ostream &operator<<(std::ostream &stream, const Card card)
{
    stream << card.to_string() << std::endl;

    return stream;
}

#endif