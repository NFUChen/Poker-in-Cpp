#ifndef NOCARDVALIDATOR_H
#define NOCARDVALIDATOR_H

#include "validator.h"
#include "../card.h"
#include <string>
#include <vector>

class NoCardValidator : public Validator
{
public:
  NoCardValidator(std::vector<Card> cards)
  {
    this->cards = cards;
  }
  std::string name() override
  {
    return "No Cards";
  }
  bool is_valid() override
  {
    return this->cards.empty();
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