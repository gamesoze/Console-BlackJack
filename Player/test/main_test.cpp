//
// Created by Konstantin on 11/1/2020.
//
#include "gtest/gtest.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "Cards.h"
#include "Hand.h"
#include <deque>
#include <vector>
#include <iostream>


TEST(Player, UsageTest) {
    // Gamers
    std::deque<Player *> gamers;

    Cards packOfCards;

    gamers.emplace_back(new HumanPlayer(&packOfCards));
    gamers.emplace_back(new HumanPlayer(&packOfCards));
    gamers.emplace_back(new HumanPlayer(&packOfCards));
    gamers.emplace_back(new HumanPlayer(&packOfCards));

    for (auto it : gamers) {
        // bet

        it->dialog();
    }


    // Clean
    for (auto it : gamers) {
        delete it;
    }
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
