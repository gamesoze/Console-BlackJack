//
// Created by Konstantin on 10/31/2020.
//

#include "../Cards/Cards.h"
#include "Rools.h"

// Return score
int Rools::getScore(const std::deque<std::string> &input) {
    // Sum score
    int score = 0;

    // count Ace
    int countAce = 0;

    for (const auto &str : input) {
        // Split string
        std::string face = str.substr(0, str.find(' '));
        // std::string suit = input[str].substr(input[str].find(" ") + 1);

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

    // Check Aces
    if (countAce * 11 + score > 21) {
        score += countAce;
    } else {
        score += countAce * 11;
    }

    return score;
}

int Rools::getScore(std::string input) {
    // Sum score
    int score = 0;

    // count Ace
    int countAce = 0;

    // Split string
    std::string face = input.substr(0, input.find(' '));
    // std::string suit = input[i].substr(input[i].find(" ") + 1);

    // 2 to 2   4 to 4 etc
    if (face.size() < 2) {
        score += std::stoi(face);
        return score;
    }

    if (face == "Ace") {
        return 11;
    }

    // 10 King Queen Jack
    score += 10;
    return score;
}
