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
        std::cout << "Dealer have " << Rools::getScore(hand.getHand().at(0))
                  << " and card:\n" << "Card [0] " << hand.getHand().at(0);
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

bool Dealer::dialog() {
    if (score < 17) {
        hand.addCard();
        score = hand.getScore();
        return false;
    } else {
        return true;
    }
}
