#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "util.h"
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game_round.h"
#include "validator/pair_validator.h"
#include "validator/straight_validator.h"
using namespace std;

int main()
{

  Player p1 = Player("William");
  Player p2 = Player("Bryan");
  Player p3 = Player("Tina");

  vector<Player> players = {p1, p2, p3};
  GameRound game = GameRound(players);
  game.play();

  return 0;
}