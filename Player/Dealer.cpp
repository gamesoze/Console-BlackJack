//
// Created by Konstantin on 11/3/2020.
//

#include <iostream>
#include <sstream>
#include <string>
#include "../Rools/Rools.h"
#include "Dealer.h"

void Dealer::showCards() {
    score = Rools::getScore(hand.getHand());
    if (isFirst) {
        scoresBeforShowdown = Rools::getScore(hand.getHand().at(0));
        std::cout << "Dealer have " << scoresBeforShowdown
                  << " and card:\n" << "Card [1] " << hand.getHand().at(0);
        isFirst = false;
    } else {
        std::cout << "Dealer have " << score
                  << " and card:\n" << hand.printHand().str();
    }
}

Dealer::Dealer(Cards *ptr_cards) {
    this->name = "Dealer";
    this->money = 0;

    // TODO fix this shit
    hand = *(new Hand(ptr_cards));
}

int Dealer::dialog(bool isDealerHas1011) {
    if (score < 17) {
        hand.addCard();
        score = hand.getScore();
        return false;
    } else {
        return true;
    }
}

int Dealer::getScoresBeforeShowdown() const {
    return scoresBeforShowdown;
}

void Dealer::refreshHand() {
    // refresh pack cards
    hand.addCard(true);
    // refresh hand
    hand.refresh();

    this->isFirst = true;
}
