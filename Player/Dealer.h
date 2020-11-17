//
// Created by Konstantin on 11/3/2020.
//

#ifndef CONSOLE_BLACKJACK_DEALER_H
#define CONSOLE_BLACKJACK_DEALER_H

#include "Player.h"

class Dealer : public Player {
public:
    explicit Dealer(Cards *ptr_cards);

    // until < 17
    bool dialog(bool isDealerHas1011 = false) override;

    void bet() override {};

    int getScore() const override { return score; }

    void betAccrual(double playerBet) override { money += playerBet; }

    const double getPlayerBet() const override { return 0.0; }

    void refreshHand() override;

    void showCards() override;

    int getScoresBeforeShowdown() const;

private:
    // for first open cards
    bool isFirst = true;

    void outputResultMessage(double bet) override {}

    int scoresBeforShowdown;
};


#endif //CONSOLE_BLACKJACK_DEALER_H
