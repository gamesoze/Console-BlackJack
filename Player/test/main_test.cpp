//
// Created by Konstantin on 11/1/2020.
//
#include "gtest/gtest.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "Dealer.h"
#include "Cards.h"
#include <deque>
#include <iostream>

int main() {
    // Gamers
    std::deque<Player *> gamers;

    Cards packOfCards;

    gamers.emplace_back(new HumanPlayer(&packOfCards, "Ivan", 500));
    gamers.emplace_back(new HumanPlayer(&packOfCards));
    gamers.emplace_back(new Dealer(&packOfCards));

    for (auto it : gamers) {
        // bet
        it->bet();
    }

    // show firsts 2 cards
    for (auto it : gamers) {
        it->showCards();
    }


    for (auto it : gamers) {
        while (!it->dialog()) { ;
        }
    }

    // show all cards
    for (auto it : gamers) {
        it->showCards();
    }




    // Clean
    for (auto it : gamers) {
        delete it;
    }

    return 0;
}
