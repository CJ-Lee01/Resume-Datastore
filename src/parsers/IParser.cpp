#include <string>
#include <vector>
#include <map>

#include "../data/CommandResult.h"
#include "vocabulary.h"

using namespace std;
class ICommand {
  public:
  virtual CommandResult execute() = 0;
};

class DummyCommand: public ICommand {
    public:
    string tag;
    DummyCommand(string t) {
        this->tag = tag
    }
    CommandResult execute() {
        return ErrorResult(exception(), "Test err:" + this->tag);
    }
};

ICommand& parseController(string keyword, string mainValue, map<string, string> tagsWithValues, vector<string> tagsWithoutValues) {
    if (keyword == vocab::ADD_CMD_KEYWORD) {
        return DummyCommand(keyword);
    } else if (keyword == vocab::RM_CMD_KEYWORD) {
        return DummyCommand(keyword);
    } else if (keyword == vocab::UPDATE_CMD_KEYWORD) {
        return DummyCommand(keyword);
    } else if (keyword == vocab::CLEAN_CMD_KEYWORD) {
        return DummyCommand(keyword);
    } else if (keyword == vocab::HELP_CMD_KEYWORD) {
        return DummyCommand(keyword);
    } else if (keyword == vocab::EXIT_CMD_KEYWORD) {
        return DummyCommand(keyword);
    } else {
        return DummyCommand(keyword);
    }
}