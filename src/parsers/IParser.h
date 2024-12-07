#include <string>
#include <vector>
#include <map>

#include "../data/CommandResult.h"
#include "../exception/ParseException.h"

using namespace std;

class ICommand {
  public:
  virtual CommandResult execute();
};

ICommand parseController(string keyword, string mainValue, map<string, string> tagsWithValues, vector<string> tagsWithoutValues);