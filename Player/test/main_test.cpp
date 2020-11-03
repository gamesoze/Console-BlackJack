//
// Created by Konstantin on 11/1/2020.
//
#include "gtest/gtest.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "Cards.h"
#include <deque>
#include <iostream>


TEST(Player, UsageTest) {


}


int main() {
    // Gamers
    std::deque<Player *> gamers;

    Cards packOfCards;

    gamers.emplace_back(new HumanPlayer(&packOfCards));
    gamers.emplace_back(new HumanPlayer(&packOfCards));

    for (auto it : gamers) {
        // bet
        it->bet();
    }

    for (auto it : gamers) {
        // bet
        it->showCards();
    }



    // Clean
    for (auto it : gamers) {
        delete it;
    }
}
