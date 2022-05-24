#ifndef GAMEROUND_H
#define GAMEROUND_H

#include <vector>
#include <algorithm>
#include "card.h"
#include "player.h"
#include "deck.h"

class GameRound
{
public:
  std::vector<Player> players;
  Deck deck;
  GameRound(std::vector<Player> players)
  {
    this->players = players;
  }

  void play()
  {
    // shuffle the deck
    shuffle_cards();
    // pass cards to every players in the game
    deal_n_cards_to_players(5);
    sort_players();
    visualize_current_round();
  }

private:
  void shuffle_cards()
  {
    this->deck.shuffle_deck();
  }
  void deal_n_cards_to_players(int n)
  {
    for (Player &player : this->players)
    {
      std::vector<Card> cards_dealt = this->deck.remove_cards(n);
      player.receive_cards(cards_dealt);
    }
  }
  void sort_players()
  {
    std::sort(this->players.begin(), this->players.end());
  }

  void visualize_current_round()
  {
    for (Player &player : this->players)
    {
      std::cout << player;
    }
  }
};

#endif