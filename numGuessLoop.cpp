// Copyright (c) 2026 Your Name All rights reserved.
//
// Created by: Vova M
// Date: November17 2026
// This program asks the user to guess a random number using a break statement.

#include <iostream>
#include <random>
#include <string>

int main() {
    // this function uses a break statement
    int correctNumber;
    std::string userGuessString;
    int userGuessInt;

    // generate random number
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 9);
    correctNumber = idist(rgen);

    // input, process & output
    while (true) {
        std::cout << "Guess a number between 0 and 9: ";
        std::cin >> userGuessString;

        try {
            userGuessInt = std::stoi(userGuessString);

            if (userGuessInt == correctNumber) {
                std::cout << "You guessed correctly!" << std::endl;
                break;
            } else {
                std::cout << userGuessInt
                          << " is not the right number. Try again!"
                          << std::endl;
            }
        } catch (std::invalid_argument) {
            std::cout << userGuessString
                      << " is not a valid number. Please try again."
                      << std::endl;
        }
    }
}
