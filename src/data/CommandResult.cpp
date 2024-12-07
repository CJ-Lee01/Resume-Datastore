#include <exception>
#include <string>
#include <iostream>

class CommandResult {
  public:
  virtual void print() = 0;
};

class ErrorResult: CommandResult {
  private:
  std::exception err;
  std::string msg;
  
  public:
  ErrorResult(std::exception err, std::string msg) {
    this->err = err;
    this->msg = msg;
  }

  void print() {
    std::cout << this->msg << std::endl;
  }
};
