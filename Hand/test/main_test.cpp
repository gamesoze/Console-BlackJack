//
// Created by Konstantin on 10/31/2020.
//

#include "gtest/gtest.h"
#include "../Cards/Cards.h"
#include "Hand.h"


TEST(Hand_basic_test, UsageTest) {
    Cards pack;

    Hand left(&pack);


    int max = 0;

    for (int j = 0; j < 10000; ++j) {
        int sum = 0;
        for (int i = 0; i < 10; ++i) {
            sum = left.getScore();
        }
        left.addCard(true);

        if (max < sum) {
            max = sum;
        }
    }

    ASSERT_LE(max, 31);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}


