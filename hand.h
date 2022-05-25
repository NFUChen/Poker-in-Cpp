
#ifndef HAND_H
#define HAND_H

#include <algorithm>
#include <vector>
#include <string>
#include "card.h"
// validators
#include "validator/validator.h"
#include "validator/straight_validator.h"
#include "validator/flush_validator.h"
#include "validator/straight_flush_validator.h"
#include "validator/royal_flush_validator.h"
#include "validator/two_pair_validator.h"
#include "validator/pair_validator.h"
#include "validator/no_card_validator.h"
#include "validator/high_card_validator.h"
#include "validator/three_of_a_kind_validator.h"
#include "validator/full_house_validator.h"
#include "validator/four_of_a_kind_validator.h"

class Hand
{

public:
    int hand_rank_idx;
    std::string hand_rank_name;
    std::vector<Card> cards;

    Hand() = default;
    Hand(std::vector<Card> cards)
    {
        this->cards = cards;
        std::sort(this->cards.begin(), this->cards.end());
        update_best_rank();
    }

    void update_best_rank()
    {
        const std::vector<Card> &card = this->cards;

        RoyalFlushValidator royal_flush(cards);
        StraightFlushValidator straight_flush(cards);
        FourOfAKindValidator four_of_a_kind(cards);
        FullHouseValidator full_house(cards);
        FlushValidator flush(cards);
        StraightValidator straight(cards);
        ThreeOfAKindValidator three_of_a_kind(cards);
        TwoPairValidator two_pair(cards);
        PairValidator pair(cards);
        HighCardValidator high_card(cards);
        NoCardValidator no_card(cards);

        std::vector<Validator *> VALIDATORS = {&royal_flush,
                                               &straight_flush,
                                               &four_of_a_kind,
                                               &full_house,
                                               &flush,
                                               &straight,
                                               &three_of_a_kind,
                                               &two_pair,
                                               &pair,
                                               &high_card,
                                               &no_card};

        int current_hand_rank_index = VALIDATORS.size();
        for (auto validator : VALIDATORS)
        {
            if (validator->is_valid())
            {
                this->hand_rank_idx = current_hand_rank_index;
                this->hand_rank_name = validator->name();
                return;
            }
            current_hand_rank_index -= 1;
        }
    }
    bool operator<(const Hand &_other_hand) const
    {
        return (this->hand_rank_idx < _other_hand.hand_rank_idx);
    }
};

std::ostream &operator<<(std::ostream &stream, Hand &_current_hand)
{
    stream << "----Current Hand----" << std::endl;
    for (const Card &card : _current_hand.cards)
    {
        stream << card;
    }
    stream << "--------------------";
    return stream;
}

#endif