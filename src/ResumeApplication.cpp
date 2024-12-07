#include <iostream>
#include <string>

#include "parsers/ParseEntryPoint.h"
#include "parsers/IParser.h"

void resumeApplication() {
    std::string userInput;

    while (true) {
        // Prompt the user for input
        std::cout << "Please enter some text (type 'exit' to quit): ";
        std::getline(std::cin, userInput); // Read the entire line of input

        // Check if the user wants to exit
        if (userInput == "exit") {
            break;
        }

        // Echo the user input back
        // type is ICommand.
        auto command = parseCommand(userInput); // compiler pls help me
        if (command) {
            command->execute();
        } else {
            std::cerr << "Command could not be found.";
        }
    }

    std::cout << "Goodbye!" << std::endl;
}
