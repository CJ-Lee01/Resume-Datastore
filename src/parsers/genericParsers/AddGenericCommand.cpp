#include <string>
#include <map>
#include <vector>

#include "../IParser.h"
#include "../vocabulary.h"

using namespace std;

bool contains(map<string, string> tagsWithValues, const string& target) {
  return tagsWithValues.find(target) != tagsWithValues.end();
}

bool containsOr(map<string, string> tagsWithValues, const string& target1, const string& target2) {
  return contains(tagsWithValues, target1) || contains(tagsWithValues, target2);
}

ICommand generateAddCommand(string mainValue, map<string, string> tagsWithValues, vector<string> tagsWithoutValues) {
  if (containsOr(tagsWithValues, vocab::TYPE_FULL_TAG, vocab::TYPE_SHORT_TAG)) {

  } else if (containsOr(tagsWithValues, vocab::KEYWORD_FULL_TAG, vocab::KEYWORD_SHORT_TAG)) {
    /* code */
  } else {

  }
  
}