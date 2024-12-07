#include <exception>
#include <string>

class ParseException: std::exception {
    private:
std::string msg;
  public:
  
  ParseException(std::string message) {
    this->msg = message;
  }
  virtual std::string what() {
    return this->msg;
  }
};