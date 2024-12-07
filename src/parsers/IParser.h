#include "../data/CommandResult.h"

class IParser {
  public:
  virtual CommandResult execute();
};