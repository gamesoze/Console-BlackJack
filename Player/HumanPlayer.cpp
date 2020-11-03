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

    // TODO fix this shit
    hand = *(new Hand(ptr_cards));
}

bool HumanPlayer::dialog() {
    score = hand.getScore();
    std::cout << "\n######################################\n";
    std::cout << "Player [" << name << "] have " << score
              << " and cards:\n" << hand.printHand().rdbuf();

    if (score > 21) {
        std::cout << "You lose :(\n######################################\n\n";
        return true;
    } else {
        std::cout << "Add card?\n";

        int userChoice;
        do {
            std::cout << "0 - No (Pass) 1 - Yes (hit me)\n";
            std::cin >> userChoice;
        } while (userChoice > 1 || userChoice < 0);

        if (userChoice == 1) {
            hand.addCard();
            score = hand.getScore();
            std::cout << "\nPlayer [" << name << "] have " << score
                      << " and cards:\n" << hand.printHand().rdbuf();
            std::cout << "######################################\n";
            return false;
        } else {
            std::cout << "######################################\n";
            return true;
        }
    }
}

void HumanPlayer::bet() {
    do {
        std::cout << "\n######################################\nPlayer: " << name;
        std::cout << "\nHow many u want bet?\tYou have: "
                  << this->money << "\n";
        std::cin >> playerBet;
        std::cout << "######################################\n";
    } while (playerBet > money || playerBet < 0);
}

void HumanPlayer::showCards() {
    score = hand.getScore();
    std::cout << "Player [" << name << "] have " << score
              << " and cards:\n" << hand.printHand().rdbuf();
}

int HumanPlayer::getScore() const {
    return score;
}

void HumanPlayer::betAccrual(double playerBet) {
    money += playerBet;
}

const double HumanPlayer::getPlayerBet() const {
    return playerBet;
}

void HumanPlayer::refreshHand() {
    hand.refresh();
}
