#include <string>
#include <map>
#include <vector>

#include "../IParser.h"
#include "../../data/ResumeData.h"

using namespace std;

class AddComponentCommand: public ICommand {
  private:
  string type;
  bool important = false;
  
  public:
  AddComponentCommand(string mainValue, map<string, string> tagsWithValues, vector<string> tagsWithoutValues) {}

};