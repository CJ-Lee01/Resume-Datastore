# ifndef PARSEENTRY_H
# define PARSEENTRY_H

#include <string>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

tuple<string, string, map<string, string>, vector<string>> parseCommand(const std::string& command);
#endif