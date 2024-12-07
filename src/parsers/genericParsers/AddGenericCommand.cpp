#include <string>
#include <map>
#include <vector>
#include <memory>

#include "../IParser.h"
#include "../vocabulary.h"
#include "../../utils.h"

using namespace std;

unique_ptr<ICommand> generateAddCommand(string mainValue, map<string, string> tagsWithValues, vector<string> tagsWithoutValues) {
  if (parsing::containsOr(tagsWithValues, vocab::TYPE_FULL_TAG, vocab::TYPE_SHORT_TAG)) {

  } else if (parsing::containsOr(tagsWithValues, vocab::KEYWORD_FULL_TAG, vocab::KEYWORD_SHORT_TAG)) {
    /* code */
  } else {

  }
  
}