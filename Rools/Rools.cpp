//
// Created by Konstantin on 10/31/2020.
//

#include "../Cards/Cards.h"
#include "../Hand/Hand.h"
#include <map>
#include "Rools.h"

int Rools::getScore(const std::deque<std::string> &input) {
    // Sum score
    int score = 0;

    // count Ace
    int countAce = 0;

    for (int i = 0; i < input.size(); ++i) {
        // Split string
        std::string face = input[i].substr(0, input[i].find(" "));
        // std::string suit = input[i].substr(input[i].find(" ") + 1);

        // 2 to 2   4 to 4 etc
        if (face.size() < 2) {
            score += std::stoi(face);
            continue;
        }

        if (face == "Ace") {
            countAce++;
            continue;
        }

        // 10 King Queen Jack
        score += 10;
    }

    if (countAce * 11 + score > 21) {
        score += countAce;
    } else {
        score += countAce * 11;
    }

    return score;
}
