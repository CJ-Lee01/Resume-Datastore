#include <iostream>
#include <sstream>
#include <map>
#include <string>


void parseCommand(const std::string& command) {
    // Use a stringstream to parse the command
    std::stringstream ss(command);
    std::string keyword;
    ss >> keyword;  // Extract the first word as the keyword

    // Map to store tag-value pairs
    std::map<std::string, std::string> tags;

    std::string tag;
    std::string value;

    // Loop through the rest of the command to extract tags and values
    while (ss >> tag) {
        if (tag[0] == '-') {  // Check if it is a tag (starts with '-')
            ss >> value;       // Get the value associated with the tag
            tags[tag] = value; // Store it in the map
        } else {
            std::cerr << "Error: Unexpected token " << tag << " (tags should start with '-')" << std::endl;
            return;
        }
    }

    // Output the parsed command
    std::cout << "Keyword: " << keyword << std::endl;
    std::cout << "Tags and values:" << std::endl;
    for (const auto& pair : tags) {
        std::cout << "  " << pair.first << " : " << pair.second << std::endl;
    }
}

