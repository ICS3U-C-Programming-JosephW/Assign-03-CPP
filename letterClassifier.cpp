// Copyright (c) 2025. Joseph Wondimagnehu. All rights reserved.
//
// Created by: Joseph Wondimagnehu
// Date: Apr. 16, 2025
/* This program determines whether a letter of the English
alphabet entered by the user is a consonant, vowel,
or semivowel. It also allows the user to find extra
information about a particular letter by displaying
phonetic symbols and examples if desired. */

/* Include the iostream library and others for
extra functionalities used in this program. */
#include <algorithm>
#include <array>
#include <iostream>

// Runs the main function.
int main() {
    /* Initialize constant arrays for input 
    error detections and displaying information. */
    const std::array<std::string, 26> ENGLISH_LETTERS = {
        "a", "b", "c", "d", "e", "f", "g", "h", "i",
        "j", "k", "l", "m", "n", "o", "p", "q", "r",
        "s", "t", "u", "v", "w", "x", "y", "z"
    },
    PHONETIC_SYMBOLS = {
        "/ˈeɪ/", "/ˈbiː/", "/ˈsiː/", "/ˈdiː/", "/ˈiː/",
        "/ˈɛf/", "/ˈdʒiː/", "/eɪtʃ/", "/ˈaɪ/", "/ˈdʒeɪ/",
        "/ˈkeɪ/", "/ˈɛl/", "/ˈɛm/", "/ˈɛn/", "/ˈoʊ/", 
        "/ˈpiː/", "/ˈkjuː/", "/ˈɑːr/", "/ˈɛs/", "/ˈtiː/",
        "/ˈjuː/", "/ˈviː/", "/ˈdʌb.əlˈjuː/", "/ˈɛks/",
        "/ˈwaɪ/", "/ˈziː/ or /ˈzɛd/" 
    },
    EXAMPLE_WORDS = {
        "ate", "bean", "cow", "deed", "ever",
        "friend", "gene", "house", "ice", "jam",
        "kangaroo", "lid", "make", "new", "one",
        "pen", "queue", "rain", "stumble", "tea",
        "under", "vary", "well", "xylophone",
        "yarn", "zebra",
    };

    // Initialize constant strings for text escape codes.
    const std::string LIGHT_GREEN = "\033[1;32m",
    LIGHT_CYAN = "\033[1;36m",
    LIGHT_PURPLE = "\033[1;35m",
    LIGHT_RED = "\033[1;31m",
    DARK_GRAY = "\033[1;30m",
    LIGHT_BLUE = "\033[1;34m",
    LIGHT_YELLOW = "\033[1;33m",
    WHITE = "\033[0m",
    BOLD = "\033[1m";

    /* Declare the base and lowercase string 
    variables for user input. */
    std::string userLetter, lowercaseUserLetter;
    std::string userDisplayType, lowercaseUserDisplayType;
   
    // Declare the integer variables for user input.
    int showPhoneticSymbolInt, showPhoneticExampleInt;

    // Display a greeting message to the user.
    std::cout << "\n" << LIGHT_PURPLE << "Hello, user! This is a program "
    << "designed to determine whether " << "an entered\n" << "letter "
    << "from the English alphabet is a consonant, vowel, or\n"
    << "semivowel, with extra examples and modes for more information."
    << WHITE << "\n";

    // Construct an infinite while loop for the letter input.
    while (true) {
        // Ask the user to enter a letter.
        std::cout << DARK_GRAY << "Enter a letter from a-z or A-Z:" 
        << WHITE << "\n";

        // Store the input into the user letter variable.
        std::getline(std::cin, userLetter);

        /* Prepare the size of the lowercase string
        to match the size of the user's letter input. */
        lowercaseUserLetter.resize(userLetter.size());

        /* Convert the user's desired letter into lowercase. 
        Use std::transform to account for invalid letters. */
        std::transform(userLetter.begin(), userLetter.end(),
        lowercaseUserLetter.begin(),
        [](char scannedChar) { return std::tolower(scannedChar); });

        /* Checks if the lowercase form of the letter
        entered is a letter of the English alphabet. */
        if (std::find(ENGLISH_LETTERS.begin(), ENGLISH_LETTERS.end(), lowercaseUserLetter)
        != ENGLISH_LETTERS.end()) {
            // Break the infinite loop.
            break;
        }
        else {
        // Otherwise, they did not enter a valid letter.
        /* Display to the user that they must enter
        a valid letter of the English alphabet. */
            std::cout << "\n" << LIGHT_RED << userLetter << " is not a valid " 
            << "letter of the English alphabet. Please enter a letter from a-z or A-Z."
            << WHITE << "\n";
        }
    }

    /* Construct an infinite while loop for the display input.
    while (true) {
        
    } */
}
