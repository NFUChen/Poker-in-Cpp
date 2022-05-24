#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "hand.h"

class Player
{
public:
  std::string name;
  Hand current_hand;

  Player(std::string name)
  {
    this->name = name;
  }

  void receive_cards(std::vector<Card> cards)
  {
    std::vector<Card> current_hand = this->current_hand.cards;
    for (const Card &card : cards)
    {
      current_hand.push_back(card);
    }
    Hand new_hand(current_hand);
    this->current_hand = new_hand;
  }

  std::string best_hand()
  {
    return this->current_hand.hand_rank_name;
  }
  bool operator<(const Player &_other_player) const
  {
    return (this->current_hand < _other_player.current_hand);
  }
};

std::ostream &operator<<(std::ostream &stream, Player &_current_player)
{
  stream << "Player Name: " << _current_player.name << std::endl;
  stream << _current_player.current_hand << std::endl;
  stream << "Best Hand: " << _current_player.best_hand() << std::endl
         << std::endl;

  return stream;
}

#endif