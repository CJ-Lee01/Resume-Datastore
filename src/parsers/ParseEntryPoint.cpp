#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <tuple> 
#include <memory>

#include <IParser.h>

using namespace std;

string removePrefix(const std::string& tag) {
    size_t pos = tag.find_first_not_of('-');
    if (pos == std::string::npos) {
        // If the entire string is made up of hyphens, return an empty string
        return "";
    }
    return tag.substr(pos);
}

// Throws ParseException if string is invalid.
tuple<string, string, map<string, string>, vector<string>> getCommandArgs(const string command) {
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
                tagsWithoutValues.push_back(removePrefix(tag));
                // Put the value back for the next iteration (as it's actually the next tag)
                ss.putback(' ');  // Put back the space
                for (int i = value.length() - 1; i >= 0; --i) {
                    ss.putback(value[i]);
                }
            } else {
                // If the value doesn't start with '-', store the tag-value pair
                tagsWithValues[removePrefix(tag)] = value;
            }
        } else {
            throw ParseException("Error: Unexpected token " + tag);
        }
    }
    return tuple(keyword, mainValue, tagsWithValues, tagsWithoutValues);
}

// May choose to change to another type later on...
// Throws ParseException if string is invalid.
unique_ptr<ICommand> parseCommand(const string command) {
    const tuple t = getCommandArgs(command);
    const string keyword = get<0>(t);
    const string mainValue = get<1>(t);
    const map<string, string> tagsWithValues = get<2>(t);
    const vector<string> tagsWithoutValues = get<3>(t);

    std::unique_ptr<ICommand> cmd = parseController(keyword, mainValue, tagsWithValues, tagsWithoutValues);
    return cmd;
}

void printResults(string keyword, string mainValue, map<string, string> tagsWithValues, vector<string> tagsWithoutValues) {
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
}
