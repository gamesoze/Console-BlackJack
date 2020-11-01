//
// Created by Konstantin on 10/31/2020.
//

#include "gtest/gtest.h"
#include "../Cards/Cards.h"
#include "Hand.h"


TEST(Hand_basic_test, UsageTest) {
    Cards pack;

    Hand left(&pack);

    for (int i = 0; i < 100000; ++i) {
        left.addCard();
    }

    ASSERT_LE(left.getScore(), 40);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}


