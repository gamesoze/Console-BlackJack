//
// Created by Konstantin on 11/3/2020.
//

#include <iostream>
#include <sstream>
#include <string>
#include "../Rools/Rools.h"
#include "Dealer.h"

void Dealer::showCards() {
    if (isFirst) {
        score = Rools::getScore(hand.getHand().at(0));
        std::cout << "Dealer have " << score
                  << " and card:\n" << "Card [0] " << hand.getHand().at(0);
        isFirst = false;
    } else {
        score = Rools::getScore(hand.getHand());
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

bool Dealer::dialog(bool isDealerHas1011) {
    if (score < 17) {
        hand.addCard();
        score = hand.getScore();
        return false;
    } else {
        return true;
    }
}
