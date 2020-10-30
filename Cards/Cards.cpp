//
// Created by Konstantin on 10/29/2020.
//

#include <random>
#include <iostream>
#include <algorithm>
#include <chrono>
#include "Cards.h"

#define NUMBER_PACK_OF_CARDS 4
// Must be divisible by 4
#define NUMBER_CARDS_IN_PACK 52

// Init and shuffle
Cards::Cards() {
    checkAndInit();

    shuffle();
}

// Check define
void Cards::checkAndInit() {
    if (NUMBER_CARDS_IN_PACK % 4 == 0 && NUMBER_CARDS_IN_PACK > 0 && NUMBER_PACK_OF_CARDS > 0) {
        for (int i = 0; i < NUMBER_PACK_OF_CARDS; ++i) {
            for (const auto &suits : suitsName) {
                for (const auto &face : faceName) {
                    packCards.push_back(face + " " + suits);
                }
            }
        }
    } else {
        std::cerr << "CARDS::WRONG INPUT";
    }
}


void Cards::shuffle() {
    // for "real" RANDOM
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine randomEngine(seed);

    std::shuffle(packCards.begin(), packCards.end(), randomEngine);
}

void Cards::printPack() {
    for (auto &packCard : packCards) {
        std::cout << packCard << " \n";
    }
}

const std::string Cards::getCard(bool isBeginRound) {
    // Check for begin of round
    if (isBeginRound) {
        // Check for the number of remaining cards
        if (packCards.size() <= static_cast<int>(NUMBER_PACK_OF_CARDS * NUMBER_CARDS_IN_PACK / 3)) {
            packCards.clear();
            checkAndInit();
            shuffle();

            return getCard();
        }
    }

    std::string card = packCards.at(0);
    packCards.pop_front();
    return card;
}

