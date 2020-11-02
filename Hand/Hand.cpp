//
// Created by Konstantin on 10/31/2020.
//
#include "../Cards/Cards.h"
#include "../Rools/Rools.h"
#include <queue>
#include <string>
#include <sstream>
#include "Hand.h"

// Give 2 cards in Hand
Hand::Hand(Cards *ptr_cards) {
    // Draw 2 cards
//    hand.push_back(ptr_cards->getCard());
//    hand.push_back(ptr_cards->getCard());

    // Copy pointer
    this->ptr_cards = ptr_cards->copyPointer();
}

Hand::Hand() {
    // Create new pack of cards
    this->ptr_cards = new Cards;

    // add 2 start cards
//    hand.push_back(ptr_cards->getCard());
//    hand.push_back(ptr_cards->getCard());
}

bool Hand::addCard() {
    if (score < 21) {
        hand.push_back(ptr_cards->getCard());
        setScore();
        return true;
    } else {
        return false;
    }
}

Hand::~Hand() {
    delete ptr_cards;
}

int Hand::getScore() {
    return score;
}

void Hand::setScore() {
    score = Rools::getScore(hand);
}

const std::stringstream Hand::printHand() const {
    std::stringstream ss_hand;


    for (int i = 0; i < hand.size(); ++i) {
        ss_hand << "Card [" << std::to_string(i) << "] " << hand[i] << "\n";
    }

    return ss_hand;
}

void Hand::test() {
    ptr_cards->printPack();
}



