//
// Created by Konstantin on 10/29/2020.
//
#include "gtest/gtest.h"
#include "Cards.h"
#include <string>

TEST(ShuffleCards, UsageTest) {
    Cards pack;

    std::string firstCard = pack.getCard();

    int count3 = 0;
    for (int i = 0; i < 52 * 4 - 1; ++i) {
        if (firstCard == pack.getCard())
            count3++;
    }

    ASSERT_EQ(count3, 3);
}

TEST(ShuffleCards_1_3_NewRound, UsageTest) {
    Cards pack;

    for (int i = 0; i < (52 * 4) / 3 * 2 + 1; ++i) {
        pack.getCard();
    }

    // after 2/3 of pack and new round
    const std::string cardAfter23 = pack.getCard(true);

    int count3 = 0;
    for (int i = 0; i < 52 * 4 - 2; ++i) {
        if (cardAfter23 == pack.getCard()) {
            count3++;
        }
    }

    ASSERT_EQ(count3, 3);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}