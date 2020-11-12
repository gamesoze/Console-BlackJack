//
// Created by Konstantin on 11/3/2020.
//
#include "../Player/HumanPlayer.h"
#include "../Player/Dealer.h"
#include "GameTable.h"
#include <iostream>
#include <string>
#include <typeinfo>

Player *GameTable::ptr_dealer;
Cards *GameTable::ptr_cards;

void GameTable::commonBlackJack() {
    ptr_dealer = nullptr;
    // Gamers
    std::deque<Player *> gamers;

    addPlayers(gamers);

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

        // Show firsts 2 cards (1 for dealer)
        for (auto it : gamers) {
            it->showCards();
        }

        bool isDealerHas1011 = ptr_dealer->getScore() >= 10;


        std::deque<Player *> playersWhoDecidedRisk;
        // draw phase
        for (auto it : gamers) {
            // when player has 21 and dealer maybe has 21
            if (it != ptr_dealer && it->getScore() == 21 && isDealerHas1011) {
                // true     == risk
                // false    == pick up bet
                if (it->dialog(isDealerHas1011)) {
                    playersWhoDecidedRisk.push_back(it);
                }
            } else {
                // communication with the player while he is not pass
                while (!it->dialog()) { ;
                }
            }
        }

        // show all cards
        int scoresDealer;
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
                    // small flag
                    bool isFoundRisk = false;
                    // find risk man
                    for (auto risk : playersWhoDecidedRisk) {
                        if (risk == it) {
                            it->betAccrual(it->getPlayerBet() * 3 / 2);
                            isFoundRisk = true;
                            break;
                        }
                    }
                    // if not found
                    if (!isFoundRisk) {
                        it->betAccrual(it->getPlayerBet());
                    }
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

void GameTable::addPlayers(std::deque<Player *> &gamers) {
    // add pack of cards
    ptr_cards = new Cards;

    // Add gamers
    gamers.emplace_back(new HumanPlayer(ptr_cards, "Ivan", 500));
    gamers.emplace_back(new HumanPlayer(ptr_cards));
    gamers.emplace_back(new Dealer(ptr_cards));

    for (auto gamer: gamers) {
        if (typeid(*gamer) == typeid(Dealer)) {
            ptr_dealer = gamer;
        }
    }

    if (ptr_dealer == nullptr) {
        std::cerr << "GAMETABLE::ADDPLAYER::NO DEALER!";
        exit(-1);
    }
}