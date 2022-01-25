#pragma once

#include <string>
#include <set>
#include <iostream>
#include <vector>

// ranks: 1, 2, 3, ... 10, K, Q, J
// suits: clubs, diamonds, hearts, spades

enum class CardSuit { begin, clubs = begin, diamonds, hearts, spades, end };
enum class CardRank { begin = 1, ace = begin, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, end };

struct Card {
	CardRank rank;
	CardSuit suit;

};

class Comparator {
public:
	bool operator() (Card const& lhs, Card const& rhs) const {
		return lhs.suit < rhs.suit || (lhs.suit == rhs.suit && lhs.rank < rhs.rank);
	}
};

bool operator< (Card const& lhs, Card const& rhs);

std::ostream& operator << (std::ostream& os, Card const& c);

bool operator < (Card const& lhs, Card const& rhs);
unsigned operator + (Card const& lhs, Card const& rhs);


//using DeckOfCards = std::set<Card/*, Comparator*/>;

// because we want to shuffle the deck, we will use a vector
using DeckOfCards = std::vector<Card>;


DeckOfCards make_standard_deck();

std::ostream& operator<< (std::ostream& os, Card const& c);

using PlayerHand = std::vector<Card>;
