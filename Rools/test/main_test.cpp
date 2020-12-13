//
// Created by Konstantin on 10/31/2020.
//
#include "gtest/gtest.h"
#include "Rools.h"
#include <deque>

TEST(Rools_basic_test, UsageTest) {

    std::deque<std::string> hand;
    hand.emplace_back("2 abc");
    hand.emplace_back("3 abc");

    int score = Rools::getScore(hand);

    ASSERT_EQ(score, 5);
}

TEST(Rools_test_with_ace, UsageTest) {

    std::deque<std::string> hand;
    hand.emplace_back("2 abc");
    hand.emplace_back("Ace abc");

    int score = Rools::getScore(hand);

    ASSERT_EQ(score, 13);
}

TEST(Rools_test_with_2_ace, UsageTest) {

    std::deque<std::string> hand;
    hand.emplace_back("2 abc");
    hand.emplace_back("Ace abc");
    hand.emplace_back("Ace abc");

    int score = Rools::getScore(hand);

    ASSERT_EQ(score, 4);
}

TEST(Rools_BlackJack, UsageTest) {

    std::deque<std::string> hand;
    hand.emplace_back("10 abc");
    hand.emplace_back("Ace abc");

    int score = Rools::getScore(hand);

    ASSERT_EQ(score, 21);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
