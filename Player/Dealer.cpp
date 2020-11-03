//
// Created by Konstantin on 11/3/2020.
//

#include <iostream>
#include "Dealer.h"

void Dealer::showCards() {
    std::cout << "Dealer have card:\n " << hand.printHand().rdbuf();
}
