#include <string>
#include <vector>
#include <map>
#include <memory>

#include "../data/CommandResult.h"
#include "../exception/ParseException.h"

using namespace std;

class ICommand {
  public:
  virtual CommandResult execute() = 0;
};

unique_ptr<ICommand> parseController(string keyword, string mainValue, map<string, string> tagsWithValues, vector<string> tagsWithoutValues);