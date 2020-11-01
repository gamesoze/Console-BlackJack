//
// Created by Konstantin on 11/1/2020.
//

#include "string"

#include "HumanPlayer.h"


HumanPlayer::HumanPlayer() {
    this->name = "Anonymous";
    this->money = 0;
}

HumanPlayer::HumanPlayer(std::string name, double money) {
    this->name = name;
    this->money = money;
}

void HumanPlayer::pass() {

}
