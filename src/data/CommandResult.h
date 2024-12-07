#include <exception>
#include <string>
#include <iostream>

class CommandResult {
  public:
  virtual void print();
};

class ErrorResult: CommandResult {
  private:
  std::exception err;
  std::string msg;
  
  public:
  ErrorResult(std::exception err, std::string msg);

  void print();
};
