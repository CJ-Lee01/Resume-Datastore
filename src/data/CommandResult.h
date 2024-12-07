#include <exception>
#include <string>
#include <iostream>

class CommandResult {
  public:
  virtual void print();
};

class ErrorResult: public CommandResult {
  private:
  std::exception err;
  std::string msg;
  
  public:
  ErrorResult(std::exception err, std::string msg);
  void print();
};



class SuccessResult: public CommandResult {
  private:
  std::string msg;

  public:
  SuccessResult(std::string msg);
  void print();
};