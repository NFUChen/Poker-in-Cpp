
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
#include <iostream>
#include <string>
#include <vector>
#include "card.h"
using namespace std;

void test_no_cards()
{

    vector<Card> cards;
    NoCardValidator val(cards);
    cout << boolalpha;
    cout << "No Cards: " << val.is_valid() << endl;
}

void test_high_card()
{
    Card card1("2", "Clubs");
    Card card2("3", "Hearts");
    vector<Card> cards = {card1, card2};
    HighCardValidator val(cards);
    cout << "High Card: " << val.is_valid() << endl;
    for (Card card : val.valid_cards())
    {
        cout << card;
    }
    cout << "-------------" << endl;
}

void test_pair()
{

    Card card1("2", "Clubs");
    Card card2("2", "Hearts");
    vector<Card> cards = {card1, card2};
    PairValidator val(cards);
    cout << "Pair: " << val.is_valid() << endl;
    for (Card card : val.valid_cards())
    {
        cout << card;
    }
    cout << "-------------" << endl;
}

void test_two_pairs()
{

    Card card1("2", "Clubs");
    Card card2("2", "Hearts");
    Card card3("4", "Clubs");
    Card card4("4", "Hearts");
    vector<Card> cards = {card1, card2, card3, card4};
    TwoPairValidator val(cards);
    cout << "Two Pair: " << val.is_valid() << endl;
    for (Card card : val.valid_cards())
    {
        cout << card;
    }
    cout << "-------------" << endl;
}

void test_three_of_a_kind()
{

    Card card1("2", "Clubs");
    Card card2("2", "Hearts");
    Card card3("2", "Diamonds");
    Card card4("5", "Hearts");
    Card card5("6", "Hearts");
    vector<Card> cards = {card2, card1, card3, card5, card4};
    ThreeOfAKindValidator val(cards);
    cout << "Three of A Kind: " << val.is_valid() << endl;
    for (Card card : val.valid_cards())
    {
        cout << card;
    }
    cout << "-------------" << endl;
}
void test_straight()
{

    Card card1("2", "Clubs");
    Card card2("3", "Hearts");
    Card card3("4", "Clubs");
    Card card4("5", "Hearts");
    Card card5("6", "Hearts");
    Card card6("7", "Hearts");
    vector<Card> cards = {card2, card1, card3, card5, card4, card6};
    StraightValidator val(cards);
    cout << "Straight: " << val.is_valid() << endl;
    for (Card card : val.valid_cards())
    {
        cout << card;
    }
    cout << "-------------" << endl;
}

void test_flush()
{
    Card card1("2", "Clubs");
    Card card2("3", "Clubs");
    Card card3("4", "Clubs");
    Card card4("5", "Clubs");
    Card card5("6", "Clubs");
    vector<Card> cards = {card2, card1, card3, card5, card4};
    FlushValidator val(cards);
    cout << "Flush: " << val.is_valid() << endl;
    for (Card card : val.valid_cards())
    {
        cout << card;
    }
    cout << "-------------" << endl;
}

void test_full_house()
{
    Card card1("2", "Clubs");
    Card card2("2", "Clubs");
    Card card3("2", "Clubs");
    Card card4("3", "Clubs");
    Card card5("3", "Clubs");
    vector<Card> cards = {card2, card1, card3, card5, card4};
    FullHouseValidator val(cards);
    cout << "Full House: " << val.is_valid() << endl;
    for (Card card : val.valid_cards())
    {
        cout << card;
    }
    cout << "-------------" << endl;
}

void test_four_of_a_kind()
{
    Card card1("2", "Clubs");
    Card card2("2", "Clubs");
    Card card3("2", "Hearts");
    Card card4("2", "Clubs");
    Card card5("3", "Clubs");
    vector<Card> cards = {card2, card1, card3, card5, card4};
    FourOfAKindValidator val(cards);
    cout << "Four of A Kind: " << val.is_valid() << endl;
    for (Card card : val.valid_cards())
    {
        cout << card;
    }
    cout << "-------------" << endl;
}

void test_straight_flush()
{
    Card card1("2", "Clubs");
    Card card2("3", "Clubs");
    Card card3("4", "Clubs");
    Card card4("5", "Clubs");
    Card card5("6", "Clubs");
    Card card6("7", "Clubs");
    vector<Card> cards = {card2, card1, card3, card5, card4, card6};
    StraightFlushValidator val(cards);
    cout << "Straight Flush: " << val.is_valid() << endl;
    for (Card card : val.valid_cards())
    {
        cout << card;
    }
    cout << "-------------" << endl;
}

void test_royal_flush()
{

    Card card1("2", "Spades");
    Card card2("10", "Clubs");
    Card card3("Jack", "Clubs");
    Card card4("Queen", "Clubs");
    Card card5("King", "Clubs");
    Card card6("Ace", "Clubs");
    Card card7("Ace", "Diamonds");

    vector<Card> cards = {card2, card1, card3, card5, card4, card6, card7};
    RoyalFlushValidator val(cards);
    cout << "Royal Flush: " << val.is_valid() << endl;
    for (Card card : val.valid_cards())
    {
        cout << card;
    }
    cout << "-------------" << endl;
}

int main()
{
    test_no_cards();
    test_high_card();
    test_pair();
    test_two_pairs();
    test_three_of_a_kind();
    test_straight();
    test_flush();
    test_full_house();
    test_four_of_a_kind();
    test_straight_flush();

    test_royal_flush();

    return 0;
}
