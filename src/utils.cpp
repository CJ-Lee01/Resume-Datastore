#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

namespace parsing {
  #include <string>
  #include <map>
  using namespace std;

  bool contains(map<string, string> tagsWithValues, const string& target) {
  return tagsWithValues.find(target) != tagsWithValues.end();
}

  bool containsOr(map<string, string> tagsWithValues, const string& target1, const string& target2) {
  return contains(tagsWithValues, target1) || contains(tagsWithValues, target2);
}
}

#endif