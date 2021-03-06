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

int HumanPlayer::dialog(bool isDealerHas1011) {
    score = hand.getScore();

    std::cout << "\n######################################\n";
    std::cout << "Player [" << name << "] have " << score
              << " and cards:\n" << hand.printHand().rdbuf();

    if (score < 21) {

        if (score > 11 || score < 10) {
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
            // double down
        } else {
            std::cout << "Add card?\t You can double down\n";

            int userChoice;
            do {
                std::cout << "0 - No (Pass) 1 - Yes (hit me) 2 - double down\n";
                std::cin >> userChoice;
            } while (userChoice > 2 || userChoice < 0);

            if (userChoice == 1) {
                hand.addCard();
                score = hand.getScore();
                std::cout << "\nPlayer [" << name << "] have " << score
                          << " and cards:\n" << hand.printHand().rdbuf();
                std::cout << "######################################\n";
                return false;
            } else if (userChoice == 0) {
                std::cout << "######################################\n";
                return true;
            } else {
                hand.addCard();
                score = hand.getScore();
                std::cout << "\nPlayer [" << name << "] have " << score
                          << " and cards:\n" << hand.printHand().rdbuf();
                std::cout << "######################################\n";
                return 2;
            }
        }
    } else if (score > 21) {
        std::cout << "You lose :(\n######################################\n\n";
        return true;
    } else if (score == 21) {
        if (isDealerHas1011) {
            std::cout << "The dealer can have blackjack. You can pick up your bet\n";

            // check for bullshit
            int userChoice;
            do {
                std::cout << "0 - Pick up your bet\n1 - Continue playing\n";
                std::cin >> userChoice;
            } while (userChoice > 1 || userChoice < 0);

            return userChoice == 1;
        }
        std::cout << "Lucky day :)\n######################################\n\n";
        return true;
    }
}

void HumanPlayer::bet(bool isDouble) {
    if (!isDouble) {
        do {
            std::cout << "\n######################################\nPlayer: " << name;
            std::cout << "\nHow many u want bet?\tYou have: "
                      << this->money << "\n";
            std::cin >> playerBet;
            std::cout << "######################################\n";
        } while (playerBet > money || playerBet < 0);
    } else {
        playerBet *= 2;
    }
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
    outputResultMessage(playerBet);
}

const double HumanPlayer::getPlayerBet() const {
    return playerBet;
}

void HumanPlayer::refreshHand() {
    hand.refresh();
}

void HumanPlayer::outputResultMessage(double bet) {
    std::cout << "\n######################################\n";
    std::cout << "Player [" << name << "] ";
    if (bet > 0) {
        std::cout << "win " << bet << std::endl;
    } else if (bet < 0) {
        std::cout << "lose " << -bet << std::endl;
    } else {
        std::cout << "returned the bet " << std::endl;
    }
    std::cout << "######################################\n";
}

int HumanPlayer::getScoresBeforeShowdown() const {
    return 0;
}
