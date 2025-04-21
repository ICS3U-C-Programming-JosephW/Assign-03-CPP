// Copyright (c) 2025. Joseph Wondimagnehu. All rights reserved.
//
// Created by: Joseph Wondimagnehu
// Date: Apr. 16, 2025
/* This program determines whether a letter of the English
alphabet entered by the user is a consonant, vowel,
or semivowel. It also allows the user to find extra
information about a particular letter by displaying
phonetic symbols and examples if desired. */

/* Include the iostream library and others for input,
output, and other functions used in this program. */
#include <algorithm>
#include <array>
#include <iostream>
#include <string>

// Runs the main function.
int main() {
    /* Initialize constant string arrays for input 
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
    variables for user input management. */
    std::string userLetter, lowercaseUserLetter;
    std::string userDisplayType, lowercaseUserDisplayType;

    /* Declare the suffix of the letter place, only 
    needed if the user display type is complex. */
    std::string letterPlaceSuffix;

    /* Declare the choice variables as strings
    for user input. */
    std::string showPhoneticSymbolStr, showPhoneticExampleStr;

    /* Also, declare the choice variables as integers 
    for conversion. */
    int showPhoneticSymbolInt, showPhoneticExampleInt;

    /* Declare the letter place and corresponding index
    as integers for accessing array data. */
    int letterPlace, correspondingIndex;

    /* Declare the uppercase letter as a character for easier
    conversion between a string. Used to display the user's
    chosen letter as a noun, which is grammatically correct. */
    char uppercaseUserLetter;

    // Display a greeting message to the user.
    std::cout << "\n" << LIGHT_PURPLE << "Hello, user! This is a program "
    << "designed to determine whether " << "an entered\n" << "letter "
    << "from the English alphabet is a consonant, vowel, or\n"
    << "semivowel, with extra examples and modes for more information."
    << WHITE << "\n\n";

    // Construct an infinite while loop for the letter input.
    while (true) {
        // Ask the user to enter a letter.
        std::cout << DARK_GRAY << "Enter a letter from a-z or A-Z:"
        << WHITE << "\n";

        // Store the input into the user letter variable.
        std::getline(std::cin, userLetter);

        /* Prepare the size of the lowercase letter to 
        match the size of the user's base letter input. */
        lowercaseUserLetter.resize(userLetter.size());

        /* Convert the user's desired letter into lowercase. 
        Use std::transform to account for invalid letters. */
        std::transform(userLetter.begin(), userLetter.end(),
        lowercaseUserLetter.begin(),
        [](char scannedChar) { return std::tolower(scannedChar); });

        /* Checks if the lowercase form of the letter
        entered is a letter of the English alphabet. */
        if (std::find(ENGLISH_LETTERS.begin(), ENGLISH_LETTERS.end(),
        lowercaseUserLetter) != ENGLISH_LETTERS.end()) {
            // Break the infinite loop.
            break;
        } else {
        // Otherwise, they did not enter a valid letter.
        /* Display to the user that they must enter
        a valid letter of the English alphabet. */
            std::cout << "\n" << LIGHT_RED << userLetter << " is not a valid "
            << "letter of the English alphabet.\nPlease enter a letter from "
            << "a-z or A-Z." << WHITE << "\n\n";
        }
    }

    // Construct an infinite while loop for the display input.
    while (true) {
        // Ask the user for their desired display type.
        std::cout << "\n" << LIGHT_CYAN
        << "Enter a display type " << "for the letter.\n"
        << R"(Choices are "simple" (less detailed answer), and "complex")"
        << " (more detailed answer):" << WHITE << "\n";

        // Store the input into the user display type variable.
        std::getline(std::cin, userDisplayType);

        /* Prepare the size of the lowercase user display type to 
        match the size of the user's base display type. */
        lowercaseUserDisplayType.resize(userDisplayType.size());

        /* Convert the user's chosen display type into lowercase.
        std::transform is always needed in this case. */
        std::transform(userDisplayType.begin(), userDisplayType.end(),
        lowercaseUserDisplayType.begin(),
        [](char scannedChar) { return std::tolower(scannedChar); });

        /* Check if the lowercase form of "simple"
        or "complex" was the entered display type. */
        if (lowercaseUserDisplayType == "simple"
        || lowercaseUserDisplayType == "complex") {
            // Break the infinite loop.
            break;
        } else {
            // Otherwise, they did not enter a valid display type.
            // Display to the user that they must enter a valid choice.
            std::cout << "\n" << LIGHT_RED << userDisplayType << " is not "
            << "a valid choice.\n" << "Please enter either simple or "
            << "complex for the display type." << WHITE << "\n";
        }
    }

    /* Construct an infinite while loop
    for the phonetic symbol choice input. */
    while (true) {
        /* Ask the user if they want a phonetic symbol for 
        their desired letter. */
        std::cout << "\n" << LIGHT_YELLOW << "Do you want a phonetic symbol "
        << "to be displayed for the sound your letter makes?\n"
        << "Choices are 0 for no and 1 for yes:" << WHITE << "\n";

        /* Store the input into the string form of the phonetic 
        symbol variable. */
        std::getline(std::cin, showPhoneticSymbolStr);

        /* Try to validate and proceed with the
        user's choice for a phonetic symbol. */
        try {
            // Attempt to convert the entered string into an integer.
            showPhoneticSymbolInt = std::stoi(showPhoneticSymbolStr);

            /* Check if the user entered 0 for no or 1 for yes
            for the phonetic symbol. */
            if (showPhoneticSymbolInt == 0
            || showPhoneticSymbolInt == 1) {
                /* Construct a nested infinite while loop 
                for the phonetic example choice input. */ 
                while (true) {
                    /* Ask the user if they want a phonetic
                    example word for their desired letter. */
                    std::cout << "\n" << LIGHT_BLUE
                    << "Do you want a phonetic "
                    << "word to be displayed as an example "
                    << "relating to your chosen letter?\n"
                    << "Choices are 0 for no and 1 for yes:"
                    << WHITE << "\n";

                    /* Store the input into the string 
                    form of the example variable. */
                    std::getline(std::cin, showPhoneticExampleStr);

                    /* Try to validate and proceed with the
                    user's choice for a phonetic example.*/
                    try {
                        /* Attempt to convert the entered 
                        string into an integer. */ 
                        showPhoneticExampleInt =
                        std::stoi(showPhoneticExampleStr);

                        /* Check if the user entered 0 for no
                        or 1 for yes for the phonetic example. */
                        if (showPhoneticExampleInt == 0
                        || showPhoneticExampleInt == 1) {
                            // Break the inner infinite while loop.
                            break;
                        } else {
                            /* Otherwise, the user entered an integer
                            out of range for the example choice. */
                            /* Display to the user that they must enter 0 
                            for no or 1 for yes for the phonetic example. */
                            std::cout << "\n" << LIGHT_RED
                            << showPhoneticExampleInt << " is out of range "
                            << "for choices.\nPlease enter either 0 "
                            << "for no or 1 for yes." << WHITE << "\n";
                        }
                    }

                    /* Runs if std::stoi() could not convert the user's 
                    string input into an integer for the example choice. */
                    catch (std::invalid_argument) {
                        /* Display to the user that they need to enter
                        a valid integer for the example choice. */
                        std::cout << "\n" << LIGHT_RED << showPhoneticExampleStr
                        << " is not a valid integer.\n "
                        << "Please enter a valid integer." << WHITE << "\n";
                    }
                }
                // Break the outer infinite while loop.
                break;
            } else {
                /* Otherwise, the user entered an integer out of range
                for the symbol choice. */
                /* Display to the user that they must enter 0 
                for no or 1 for yes for the phonetic symbol. */
                std::cout << "\n" << LIGHT_RED << showPhoneticSymbolInt
                << " is out of range for choices.\nPlease enter either 0 "
                << "for no or 1 for yes." << WHITE << "\n";
            }
        }
        /* Runs if std::stoi() could not convert the user's 
        string input into an integer for the symbol choice. */
        catch (std::invalid_argument) {
            /* Display to the user that they need to enter
            a valid integer for the symbol choice. */
            std::cout << "\n" << LIGHT_RED << showPhoneticSymbolStr
            << " is not a valid integer.\nPlease enter a valid integer."
            << WHITE << "\n";
        }
    }

    /* Determine the place of the lowercase chosen letter in the
    English alphabet by finding its index in the array of English
    letters and adding it by 1. */
    letterPlace = std::distance(ENGLISH_LETTERS.begin(),
    std::find(ENGLISH_LETTERS.begin(), ENGLISH_LETTERS.end(),
    lowercaseUserLetter)) + 1;

    // Check if the letter place ends in 1 and does not end in 11.
    if ((letterPlace % 10 == 1) && (letterPlace % 100 != 11)) {
        // Set the letter place suffix to "st."
        letterPlaceSuffix = "st";
    } else if ((letterPlace % 10 == 2) && (letterPlace % 100 != 12)) {
        /* Otherwise, check if the letter place ends in 2 
        and does not end in 12. */
        // Set the letter place suffix to "nd."
        letterPlaceSuffix = "nd";
    } else if ((letterPlace % 10 == 3) && (letterPlace % 100 != 13)) {
        /* Otherwise, check if the letter place ends in 3 
        and does not end in 13. */
        // Set the letter place suffix to "rd."
        letterPlaceSuffix = "rd";
    } else {
        /* Otherwise, it has to be "th." 
        That is the only other suffix. */
        // Set the letter place suffix to "th."
        letterPlaceSuffix = "th";
    }

    /* Convert the user's chosen letter to uppercase.
    The user's letter is a single-character string, 
    so indexing it makes it a character. */
    uppercaseUserLetter = std::toupper(userLetter[0]);

    /* Use a switch statement with the user's chosen letter in
    lowercase to determine if it is a consonant, vowel, 
    or semivowel along with the user's display type.
    Converted into a character for it to be used in
    the switch statement. */
    switch (lowercaseUserLetter[0]) {
        // The vowel cases.
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            /* Check if the user display type 
            in lowercase is "simple." */
            if (lowercaseUserDisplayType == "simple") {
                /* Display to the user that their
                letter in uppercase is a vowel. */
                std::cout << "\n" << LIGHT_PURPLE << "The letter "
                << uppercaseUserLetter << " is a vowel." << WHITE
                << "\n";
            }

            /* Check if the user display type 
            in lowercase is "complex." */
            if (lowercaseUserDisplayType == "complex") {
                /* Display to the user that their letter in
                uppercase is a vowel with more information. */
                std::cout << "\n" << BOLD << "The letter "
                << uppercaseUserLetter << ", the "
                << letterPlace << letterPlaceSuffix
                << " letter of the " << "English alphabet, "
                << "is a vowel.\nVowels are speech sounds made "
                << "with little to no closure of the vocal tract."
                << WHITE << "\n";
            }
            /* Break the switch statement to escape it 
            and prevent executing other cases. */
            break;

        // The semivowel cases.
        case 'w':
        case 'y':
            /* Check if the user display type 
            in lowercase is "simple." */
            if (lowercaseUserDisplayType == "simple") {
                /* Display to the user that their
                letter in uppercase is a semivowel. */
                std::cout << "\n" << LIGHT_PURPLE << "The letter "
                << uppercaseUserLetter << " is a semivowel." << WHITE
                << "\n";
            }

            /* Check if the user display type 
            in lowercase is "complex." */
            if (lowercaseUserDisplayType == "complex") {
                /* Display to the user that their letter in
                uppercase is a semivowel with more information. */
                std::cout << "\n" << BOLD << "The letter "
                << uppercaseUserLetter << ", the " << letterPlace
                << letterPlaceSuffix << " letter of the English "
                << "alphabet, is a semivowel.\nSemivowels are special "
                << "speech sounds that share some characteristics of a "
                << "vowel and a consonant." << WHITE << "\n";
            }
            /* Break the switch statement to escape it 
            and prevent executing other cases. */
            break;

        /* Default cases must be consonants since 
        the vowels and semivowels were covered. */
        default:
            /* Check if the user display type 
            in lowercase is "simple." */
            if (lowercaseUserDisplayType == "simple") {
                /* Display to the user that their
                letter in uppercase is a consonant. */
                std::cout << "\n" << LIGHT_PURPLE << "The letter "
                << uppercaseUserLetter << " is a consonant."
                << WHITE << "\n";
            }

            /* Check if the user display type 
            in lowercase is "complex." */
            if (lowercaseUserDisplayType == "complex") {
                /* Display to the user that their letter in
                uppercase is a consonant with more information. */
                std::cout << "\n" << BOLD << "The letter "
                << uppercaseUserLetter << ", the " << letterPlace
                << letterPlaceSuffix << " letter of the English "
                << "alphabet, is a consonant.\nConsonants are "
                << "speech sounds made with some or complete "
                << "closure of the vocal tract." << WHITE << "\n";
            }
            /* Break the switch statement to escape it 
            and prevent executing other cases. */
            break;
    }

    /* Set the corresponding index to the place of the letter
    subtracted by one to revert back to array indexes. */
    correspondingIndex = letterPlace - 1;

    /* Check if the user wanted a phonetic symbol
    to be displayed based on the letter. */
    if (showPhoneticSymbolInt == 1) {
        /* Set the corresponding symbol to the corresponding 
        index of the phonetic symbol array. */
        std::string correspondingPhoneticSymbol =
        PHONETIC_SYMBOLS[correspondingIndex];

        /* Display to the user the phonetic 
        symbol for the letter when said alone. */
        std::cout << "\n" << LIGHT_CYAN <<
        "The phonetic notation for the letter "
        << uppercaseUserLetter << " when said in isolation is "
        << correspondingPhoneticSymbol << "." << WHITE << "\n";
    }

    /* Check if the user wanted a phonetic example
    word to be displayed based on the letter. */
    if (showPhoneticExampleInt == 1) {
        /* Set the corresponding symbol to the corresponding 
        index of the example words array. */
        std::string correspondingExampleWord =
        EXAMPLE_WORDS[correspondingIndex];

        /* Display to the user a word that uses
        the letter they chose in uppercase. */
        std::cout << "\n" << DARK_GRAY << "One example of a word "
        "that uses the letter " << uppercaseUserLetter << " is "
        << correspondingExampleWord << "." << WHITE << "\n";
    }

    // Finally, thank the user for using this program.
    std::cout << "\n" << LIGHT_GREEN << "Thanks for using this program!"
    << WHITE << "\n";
}
