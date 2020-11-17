//
// Created by Konstantin on 11/3/2020.
//

#ifndef CONSOLE_BLACKJACK_GAMETABLE_H
#define CONSOLE_BLACKJACK_GAMETABLE_H

#include "../Player/Player.h"


class GameTable {
public:
    // main
    static void commonBlackJack();

    static void addPlayers(std::deque<Player *> &gamers);

    static bool mainSwitch();

    static bool findNotRisk(Player *gamer, const std::deque<Player *> &playersWhoDecidedNotRisk);

private:
    static Player *ptr_dealer;
    static Cards *ptr_cards;
};


#endif //CONSOLE_BLACKJACK_GAMETABLE_H
