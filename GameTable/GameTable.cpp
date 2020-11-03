//
// Created by Konstantin on 11/3/2020.
//
#include "../Player/HumanPlayer.h"
#include "../Player/Dealer.h"
#include "GameTable.h"
#include <iostream>
#include <string>
#include <typeinfo>

void GameTable::commonBlackJack() {
    // Gamers
    std::deque<Player *> gamers;

    Cards packOfCards;

    // Add gamers
    gamers.emplace_back(new HumanPlayer(&packOfCards, "Ivan", 500));
    gamers.emplace_back(new HumanPlayer(&packOfCards));
    gamers.emplace_back(new Dealer(&packOfCards));

    // skip \n after number
    bool fuckingC = false;

    while (true) {
        // buffer
        std::string exitString;
        std::cout << "\nPlay new game - press ENTER\nif you want to exit - write 'exit'\n";
        if (fuckingC) {
            std::cin.get();
        }
        std::getline(std::cin, exitString);
        if (exitString == "exit") {
            break;
        }
        fuckingC = true;

        // Bet
        for (auto it : gamers) {
            it->bet();
        }

        std::deque<Player *> playersWithBlackJack;

        // Show firsts 2 cards3
        for (auto it : gamers) {
            it->showCards();

            if (it->getScore() == 21 && typeid(*it) != typeid(Dealer)) {
                playersWithBlackJack.push_back(it);
            }
        }

        for (auto player : playersWithBlackJack) {

        }

        for (auto it : gamers) {
            while (!it->dialog()) { ;
            }
        }

        int scoresDealer;
        // show all cards
        for (auto it : gamers) {
            if (typeid(*it) == typeid(Dealer))
                scoresDealer = it->getScore();
            it->showCards();
        }

        // all wins
        if (scoresDealer > 21) {
            for (auto it : gamers) {
                if (it->getScore() <= 21) {
                    it->betAccrual(it->getPlayerBet());
                } else {
                    it->betAccrual(-it->getPlayerBet());
                }
            }
        } else {    // player wins if (21 > scorePlayer > scoreDealer)
            for (auto it : gamers) {
                if (it->getScore() > scoresDealer && it->getScore() <= 21) {
                    it->betAccrual(it->getPlayerBet());
                } else {
                    it->betAccrual(-it->getPlayerBet());
                }
            }
        }

        for (auto it : gamers) {
            it->refreshHand();
        }

    }

    // Clean
    for (auto it : gamers) {
        delete it;
    }
}
