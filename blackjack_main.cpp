
#include "Card.hpp"

#include <random>
#include <algorithm>

int blackjack_add(Card const& lhs, Card const& rhs) {
	auto sum = lhs + rhs;
	if (lhs.rank == CardRank::ace || rhs.rank == CardRank::ace)
		sum += 10;

	return sum;
}

int main() {
	// card (suit, color, rank)
	// deck (collection of cards)
	Card c;
	c.rank = CardRank::seven;
	c.suit = CardSuit::clubs;

	auto deck = make_standard_deck();

	for (auto c : deck) {
		std::cout << c << std::endl;
	}


	std::random_device rd;
	shuffle(deck.begin(), deck.end(), rd);


	// deal three hands
	std::vector<PlayerHand> hands(3);
	int constexpr NCARDS = 2;
	for (int i = 0; i < NCARDS; ++i)
		for (auto& hand : hands) {
			hand.push_back(deck.back());
			deck.pop_back();
		}

	// sort the hands
	for (auto& hand : hands)
		sort(hand.begin(), hand.end());


	// find the winner
	for (auto hand : hands) {
		std::cout << blackjack_add(hand.front(), hand.back()) << " = ";
		std::cout << hand.front() << " + " << hand.back() << std::endl;
		std::cout << hand.front() << " + " << hand.back() << std::endl;
	}
}

