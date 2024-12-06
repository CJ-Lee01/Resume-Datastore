#include <iostream>
#include <sstream>
#include <map>
#include <string>


void parseCommand(const std::string& command) {
    // Use a stringstream to parse the command
    std::stringstream ss(command);
    std::string keyword;
    std::string mainValue;

    // Extract the first part: the keyword
    ss >> keyword;

    // Try to extract the second part: the main value (which may be optional)
    if (!(ss >> mainValue) || mainValue[0] == '-') {
        // If reading fails or if the main value starts with '-', it means it's missing
        mainValue = "";
        ss.clear();
        ss.seekg(keyword.length(), std::ios::beg);  // Rewind to start parsing tags
    }

    // Map to store tag-value pairs
    std::map<std::string, std::string> tags;

    std::string tag;
    std::string value;

    // Loop through the rest of the command to extract tags and values
    while (ss >> tag) {
        if (tag[0] == '-') {  // Check if it is a tag (starts with '-')
            if (ss >> value) {
                tags[tag] = value; // Store it in the map
            } else {
                std::cerr << "Error: Missing value for tag " << tag << std::endl;
                return;
            }
        } else {
            std::cerr << "Error: Unexpected token " << tag << " (tags should start with '-')" << std::endl;
            return;
        }
    }

    // Output the parsed command
    std::cout << "Keyword: " << keyword << std::endl;
    if (!mainValue.empty()) {
        std::cout << "Main value: " << mainValue << std::endl;
    } else {
        std::cout << "Main value: (none)" << std::endl;
    }
    std::cout << "Tags and values:" << std::endl;
    for (const auto& pair : tags) {
        std::cout << "  " << pair.first << " : " << pair.second << std::endl;
    }
}

