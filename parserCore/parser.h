#include <string>
#include "mimeTree.h"
#include <vector>

class MimeParser {
  MimeTree *mimeTree;

  MimeTree *parent;
  MimeTree *currentNode;
  bool lastType;
  std::vector<std::string> boundaries;

public:
	MimeParser();
  ~MimeParser();
  void parseInput(std::istream &stream);

  void printTree(std::ostream &stream);

private:
  void parseLine(std::string line);

  bool parseBoundary(std::string line);
  int checkBoundary(std::string boundary);

  std::string trim(std::string str);
  
};
