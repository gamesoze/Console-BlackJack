//
// Created by Konstantin on 11/1/2020.
//

#include "Player.h"
#include "string"
#include "../Hand/Hand.h"
#include "HumanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(Cards *ptr_cards, std::string name, double money) {
    this->name = name;
    this->money = money;

    this->hand = Hand(ptr_cards);
}

HumanPlayer::HumanPlayer(Cards *ptr_cards) {
    this->name = "Anonymous";
    this->money = 500;

    Hand hand(ptr_cards);
}

void HumanPlayer::dialog() {
    std::cout << "Player [" << name << "] have " << hand.getScore()
              << " and cards:\n" << hand.printHand().rdbuf();

    if (hand.getScore() > 21) {
        isPassed = true;
        return;
    } else {
        std::cout << "Add card?\n";

        int userChoice;
        do {
            std::cout << "0 - No (Pass) 1 - Yes (hit me)\n";
            std::cin >> userChoice;
        } while (userChoice > 1 || userChoice < 0);

        if (userChoice == 1) {
            hand.addCard();
            std::cout << "\nPlayer [" << name << "] have " << hand.getScore()
                      << " and cards:\n" << hand.printHand().rdbuf();
            isPassed = true;
            return;
        } else {
            return;
        }
    }
}

bool HumanPlayer::bet() {
    std::cout << "\nHow many u want bet?\n You have: " << this->money;
    std::cin <<
}
