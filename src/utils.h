#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

namespace parsing {
  #include <string>
  #include <map>
  using namespace std;

  bool contains(map<string, string> tagsWithValues, const string& target);

  bool containsOr(map<string, string> tagsWithValues, const string& target1, const string& target2);
}

#endif