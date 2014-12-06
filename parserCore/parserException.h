#include <stdexcept>

class ParserException : public std::runtime_error {

public:
  ParserException(const char* text) : std::runtime_error(text) {
  }
};
