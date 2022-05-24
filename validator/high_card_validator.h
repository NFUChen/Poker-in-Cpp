#ifndef HIGHCARDVALIDATOR_H
#define HIGHCARDVALIDATOR_H

#include "validator.h"
#include "../card.h"
#include <string>
#include <string>
#include <vector>

class HighCardValidator : public Validator
{
public:
    HighCardValidator(std::vector<Card> cards)
    {
        this->cards = cards;
        }
    std::string name() override
    {
        return "High Card";
    }
    bool is_valid() override
    {
        return (!this->cards.empty());
    }
    std::vector<Card> valid_cards() override
    {
        return this->cards;
    }

private:
    std::vector<Card> cards;
};

#endif