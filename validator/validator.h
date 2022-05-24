#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "../card.h"
#include <vector>
class Validator
{
public:
    virtual std::string name() = 0;
    virtual bool is_valid() = 0;
    virtual std::vector<Card> valid_cards() = 0;
};

#endif