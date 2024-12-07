# ifndef PARSEENTRY_H
# define PARSEENTRY_H

#include <string>
#include <vector>
#include <tuple>
#include <map>

#include <IParser.h>

using namespace std;

unique_ptr<ICommand> parseCommand(const string command);
#endif