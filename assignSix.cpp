// Copyright (c) 2022 Noah Ouellette All rights reserved.
//
// Created by: Noah Ouellette
// Created on: Jan. 29, 2022
// This program uses to arrays to detect all of the perfect square numbers
// inputted by a user and can also display a border around an inputted sentence

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <array>
int longestWord = 0;

// This function determines which number in an array is the longest
int findLongestWord(std::string word) {
    if (word.length() > longestWord) {
        longestWord = word.length();
    }
    return longestWord;
}


// This function calculates if a number is a perfect square
double calculatePerfectSquare(double userNum) {
    double remain;
    double square;
    square = sqrt(userNum);
    remain = remainder(userNum, square);
    return remain;
}


// This function determines what question the user wants to pick, gets the
// user input, and makes sure that the input is valid
int main() {
    std::string userChoice;
    std::string numberOfNumbers;
    std::string num;
    std::string userSymbol;
    std::string root;
    std::string sentenceLengthString;
    std::string playAgain;
    std::string userSentence;
    std::string finalString = " \n";
    const int NUMM = 100;
    int numberOfNumbersInt;
    int numInt;
    int rootNum;
    int sentenceLength;
    int longestW;
    int spaces;
    int userArray[NUMM];
    int squareArray[NUMM];
    std::string words[NUMM];
    float calcRemainder;
    // Display the intro message
    std::cout << "Welcome!\n";
    std::cout << "This program can determine perfect square numbers\n";
    std::cout << "and also creates customizable ";
    std::cout << "borders around inputted text.\n";
    sleep(2);
    std::cout << " \n";
    // Ask the user what question they want to pick
    do {
        std::cout << "What would you like to do first?\n";
        std::cout << "Perfect Squares (S)\n";
        std::cout << "Text Borders (B)\n";
        std::cout << "S/B : ";
        std::cin >> userChoice;
        // Check if the user input is for the perfect squares
        if (userChoice == "S" || userChoice == "s") {
            std::cout << "________________________________________";
            std::cout << "________________________\n";
            std::cout << "You chose to determine the perfect ";
            std::cout << "squares in a list.\n";
            std::cout << " \n";
            sleep(2);
            do {
                // Ask user for how many numbers they want
                std::cout << "How many numbers would you like on your list? : ";
                std::cin >> numberOfNumbers;
                // Make sure that the input is valid
                try {
                    numberOfNumbersInt = std::stoi(numberOfNumbers);
                    if (numberOfNumbersInt > 0) {
                        break;
                    } else {
                        // Error message if user number is 0 or below
                        std::cout << "Your input must be greater than 0\n";
                    }
                } catch (std::invalid_argument) {
                    // Error message if input is not a number
                    std::cout << "Your input must be a whole number.\n";
                }
            } while (playAgain != "n");
            std::cout << " \n";
            for (int counter = 0; counter < numberOfNumbersInt; counter++) {
                // Ask the user for numbers to add to the list
                std::cout << "Enter a number to add to the list: ";
                std::cin >> num;
                // Make sure that the input is valid
                try {
                    numInt = std::stoi(num);
                    if (numInt > 0) {
                        // If the number is valid add it to the array
                        userArray[counter] = numInt;
                        // Call a function to determine if the number
                        // is a perfect square
                        calcRemainder = calculatePerfectSquare(numInt);
                        // If there is no remainder it is a perfect square
                        if (calcRemainder == 0) {
                            squareArray[0] = numInt;
                            rootNum = sqrt(numInt);
                            root = std::to_string(rootNum);
                            finalString += num + " = " + root +
                                         " * " + root + " \n";
                        }
                    } else {
                        // Error message if the input is negative
                        std::cout <<"Your input must be positive.\n";
                        numberOfNumbersInt += 1;
                    }
                } catch (std::invalid_argument) {
                    std::cout << "Your input must be a number\n";
                    numberOfNumbersInt += 1;
                }
            }
            std::cout << " \n";
            std::cout << "___________________________________________";
            std::cout << "_____________________\n";
            // Print all of the perfect squares
            std::cout << "Out of all of your inputs, these numbers ";
            std::cout << "are perfect squares: \n";
            std::cout << finalString;
            std::cout << " \n";
            std::cout << "Would you like to use this program again? y/n: ";
            std::cin >> playAgain;
            if (playAgain == "y" || playAgain == "Y" || playAgain == "Yes") {
                std::cout << "____________________________________________";
                std::cout << "____________________\n";
                std::cout << " \n";
                std::cout << " \n";
                continue;
            } else {
                break;
            }
        } else if (userChoice == "B" || userChoice == "b") {
            std::cout << "______________________________________";
            std::cout << "__________________________\n";
            std::cout << "You chose to create a customizable ";
            std::cout << "border around text.\n";
            std::cout << " \n";
            sleep(2);
            std::cout << "This part of the program can make a ";
            std::cout << "border around text.\n";
            std::cout << " \n";
            sleep(1.5);
            // Ask the user to enter their sentence
            std::cout << "How long do you want your sentence to be? : ";
            std::cin >> sentenceLengthString;
            std::cout << "Enter the symbol that you'd like to use : ";
            std::cin >> userSymbol;
            do {
                try {
                    sentenceLength = std::stoi(sentenceLengthString);
                    break;
                } catch (std::invalid_argument) {
                    std::cout << "Your input must be an integer.\n";
                }
            } while (playAgain != "n");

            for (int counter = 0; counter < sentenceLength; counter++) {
                std::cout << "Enter your sentence one word at a time: ";
                std::cin >> userSentence;
                words[counter] = userSentence;
            }
            std::cout << " \n";
            for (int counter = 0; counter < sentenceLength; counter++) {
                longestW = findLongestWord(words[counter]);
            }
            for (int counter = 0; counter < (longestW + 2); counter++) {
                std::cout << userSymbol;
            }
            std::cout << " \n";
            for (int counter = 0; counter < sentenceLength; counter++) {
                if (words[counter].length() != longestW) {
                    spaces = longestW - words[counter].length();
                    std::cout << userSymbol << words[counter];
                    for (int count = 0; count < spaces; count++) {
                        std::cout << " ";
                    }
                    std::cout << userSymbol << " \n";
                } else {
                    std::cout << userSymbol << words[counter];
                    std::cout << userSymbol <<" \n";
                }
            }
            for (int counter = 0; counter < (longestW + 2); counter++) {
                std::cout << userSymbol;
            }
            std::cout << " \n";
            std::cout << " \n";
            std::cout << " \n";
            std::cout << "Would you like to use this program again? y/n: ";
            std::cin >> playAgain;
            if (playAgain == "y" || playAgain == "Y" || playAgain == "Yes") {
                std::cout << "_________________________________";
                std::cout << "_______________________________\n";
                std::cout << " \n";
                std::cout << " \n";
                continue;
            } else {
                break;
            }
        } else {
            std::cout << "You must pick either 'S' or 'B' \n";
        }
    } while (playAgain != "n");
}
