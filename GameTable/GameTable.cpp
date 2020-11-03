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

    gamers.emplace_back(new HumanPlayer(&packOfCards, "Ivan", 500));
    gamers.emplace_back(new HumanPlayer(&packOfCards));
    gamers.emplace_back(new Dealer(&packOfCards));

    bool fuckingC = false;
    while (true) {
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

        for (auto it : gamers) {
            // bet
            it->bet();
        }

        // show firsts 2 cards
        for (auto it : gamers) {
            it->showCards();
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
