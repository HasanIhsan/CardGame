#include "Card.hpp"
#include <vector>
#include <cassert>

const std::vector<std::string> suits = { "Clubs","Diamonds","Hearts","Spades" };
const std::vector<std::string> ranks = { "","Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King" };



CardRank& operator ++(CardRank& rank) {
	assert(rank < CardRank::end);
	++(int&)rank;
	return rank;
}

CardSuit& operator ++(CardSuit& suit) {
	assert(suit < CardSuit::end);
	++(int&)suit;
	return suit;
}


bool operator < (Card const& lhs, Card const& rhs) {
	return lhs.rank < rhs.rank || (lhs.rank == rhs.rank && lhs.suit < rhs.suit);
}



unsigned operator + (Card const& lhs, Card const& rhs) {
	int lhv = lhs.rank >= CardRank::ten ? 10 : int(lhs.rank);
	int rhv = rhs.rank >= CardRank::ten ? 10 : int(rhs.rank);
	return lhv + rhv;
}

DeckOfCards make_standard_deck() {
	DeckOfCards d;

	for (CardSuit suit = CardSuit::begin; suit < CardSuit::end; ++suit) {
		for (CardRank rank = CardRank::begin; rank < CardRank::end; ++rank) {
			//d.insert(Card({ rank, suit }));
			d.push_back(Card({ rank, suit }));
		}
	}

	return d;
}

std::ostream& operator<< (std::ostream& os, Card const& c) {
	//switch (c.rank) {
	//case CardRank::ace:
	//	os << "Ace";
	//	break;
	//case CardRank::two:
	//	os << "Two";
	//	break;
	//	// list rest of ranks
	//default:
	//	os << "Unknown";
	//}

	//os << "-of-";

	//switch (c.suit) {
	//case CardSuit::clubs:
	//	os << "clubs";
	//	break;
	//case CardSuit::diamonds:
	//	os << "diamonds";
	//	break;
	//	// list rest of suits
	//default:
	//	os << "Unknown";
	//}

	os << ranks[(int)c.rank] << "-of-" << suits[(int)c.suit];
	return os;
}