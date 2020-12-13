//
// Created by Konstantin on 11/3/2020.
//
#include "../Player/HumanPlayer.h"
#include "../Player/Dealer.h"
#include "GameTable.h"
#include <iostream>
#include <string>
#include <typeinfo>
// for numeric_limits
#include<limits>
// for <streamsize>
#include<ios>
#include <stdlib.h>

Player *GameTable::ptr_dealer;
Cards *GameTable::ptr_cards;

void GameTable::commonBlackJack() {
    ptr_dealer = nullptr;
    // Gamers
    std::deque<Player *> gamers;

    addPlayers(gamers);

    while (true) {
        if (mainSwitch()) {
            break;
        }

        // Bet
        for (auto it : gamers) {
            it->bet();
        }

        // Show firsts 2 cards (1 for dealer)
        for (auto it : gamers) {
            it->showCards();
        }

        // Only ÒÓÇ
        bool isDealerHas1011 = ptr_dealer->getScoresBeforeShowdown() >= 11;

        std::vector<Player *> playersWhoDecidedDouble;
        std::vector<Player *> playersWhoDecidedNotRisk;
        // draw phase
        for (auto gamer : gamers) {
            if (gamer->getScore() > 11 ||
                gamer->getScore() < 10 ||
                gamer == ptr_dealer) {
                // communication with the player while he is not pass
                while (!gamer->dialog());

            } else {
                int status = gamer->dialog();
                if (!status) {
                    while (!status) {
                        status = gamer->dialog();
                        if (status == 2) {
                            gamer->bet(true);
                        }
                    }
                } else if (status == 2) {
                    gamer->bet(true);
                }

            }

            // when player has 21 and dealer maybe has 21
            if (gamer != ptr_dealer &&
                gamer->getScore() == 21 &&
                isDealerHas1011) {
                // true     == risk
                // false    == pick up bet
                if (!gamer->dialog(isDealerHas1011)) {
                    playersWhoDecidedNotRisk.push_back(gamer);
                }
            }
        }

        // show all cards
        for (auto it : gamers) {
            it->showCards();
        }
        int scoresDealer = ptr_dealer->getScore();

        if (scoresDealer > 21) {

            // all wins
            for (auto gamer : gamers) {
                if (gamer->getScore() == 21) {
                    if (!findNotRisk(gamer, playersWhoDecidedNotRisk)) {
                        gamer->betAccrual(gamer->getPlayerBet() * 3 / 2);
                    }
                } else if (gamer->getScore() < 21) {
                    gamer->betAccrual(gamer->getPlayerBet());
                } else {
                    gamer->betAccrual(-gamer->getPlayerBet());
                }
            }

            // player wins if (21 > scorePlayer > scoreDealer)
        } else {

            // scoreDealer <= 21
            for (auto gamer : gamers) {

                if (gamer->getScore() > scoresDealer) {
                    if (gamer->getScore() == 21) {
                        if (!findNotRisk(gamer, playersWhoDecidedNotRisk)) {
                            gamer->betAccrual(gamer->getPlayerBet() * 3 / 2);
                        }
                    } else if (gamer->getScore() < 21) {
                        gamer->betAccrual(gamer->getPlayerBet());
                    } else {
                        gamer->betAccrual(-gamer->getPlayerBet());
                    }

                } else if (gamer->getScore() == 21 && scoresDealer == 21) {
                    if (!findNotRisk(gamer, playersWhoDecidedNotRisk)) {
                        gamer->betAccrual(-gamer->getPlayerBet());
                    }
                } else {
                    gamer->betAccrual(-gamer->getPlayerBet());
                }
            }

        }

        for (auto it : gamers) {
            it->refreshHand();
        }

        // discards the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //system("cls");
    }

    // Clean
    for (auto it : gamers) {
        delete it;
    }

    delete ptr_cards;
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

// skip \n after number
bool GameTable::mainSwitch() {
    // buffer
    std::string exitString;
    std::cout << "\nPlay new game - press ENTER\nif you want to exit - write 'exit'\n";

    std::getline(std::cin, exitString);
    if (exitString == "exit") {
        return true;
    }
    return false;
}

bool GameTable::findNotRisk(Player *gamer,
                            const std::vector<Player *> &playersWhoDecidedNotRisk) {
    for (auto notRisk : playersWhoDecidedNotRisk) {
        if (notRisk == gamer) {
            // nothing
            gamer->betAccrual(0);
            return true;
        }
    }
    return false;
}