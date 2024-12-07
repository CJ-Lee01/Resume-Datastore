#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <tuple> 

using namespace std;

// May choose to change to another type later on...
tuple<string, string, map<string, string>, vector<string>> parseCommand(const string& command) {
    // Use a stringstream to parse the command
    stringstream ss(command);
    string keyword;
    string mainValue;

    // Extract the first part: the keyword
    ss >> keyword;

    // Try to extract the second part: the main value (which may be optional)
    if (!(ss >> mainValue) || mainValue[0] == '-') {
        // If reading fails or if the main value starts with '-', it means it's missing
        mainValue = "";
        ss.clear();
        ss.seekg(keyword.length(), ios::beg);  // Rewind to start parsing tags
    }

    // Map to store tag-value pairs and vector to store tags without values
    map<string, string> tagsWithValues;
    vector<string> tagsWithoutValues;

    string tag;
    string value;

    // Loop through the rest of the command to extract tags and values
    while (ss >> tag) {
        if (tag[0] == '-') {  // Check if it is a tag (starts with '-')
            ss >> value;
            if (value[0] == '-') {
                // If the value starts with '-', it means the tag has no value
                tagsWithoutValues.push_back(tag);
                // Put the value back for the next iteration (as it's actually the next tag)
                ss.putback(' ');  // Put back the space
                for (int i = value.length() - 1; i >= 0; --i) {
                    ss.putback(value[i]);
                }
            } else {
                // If the value doesn't start with '-', store the tag-value pair
                tagsWithValues[tag] = value;
            }
        } else {
            std::cerr << "Error: Unexpected token " << tag << " (tags should start with '-')" << std::endl;
            return;
        }
    }

    // Output the parsed command
    std::cout << "Keyword: " << keyword << endl;
    if (!mainValue.empty()) {
        std::cout << "Main value: " << mainValue << endl;
    } else {
        std::cout << "Main value: (none)" << endl;
    }
    std::cout << "Tags with values:" << endl;
    for (const auto& pair : tagsWithValues) {
        std::cout << "  " << pair.first << " : " << pair.second << std::endl;
    }
    std::cout << "Tags without values:" << endl;
    for (const auto& t : tagsWithoutValues) {
        std::cout << "  " << t << endl;
    }

    return {keyword, value, tagsWithValues, tagsWithoutValues};
}

