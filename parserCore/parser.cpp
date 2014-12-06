#include "parser.h"
#include "parserException.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

MimeParser::MimeParser() {
	mimeTree = NULL;
  parent = NULL;
  currentNode = NULL;
  lastType = false;
}

MimeParser::~MimeParser() {
  if (mimeTree != NULL)
    delete mimeTree;
}

void MimeParser::parseInput(std::istream &stream) {
  if (mimeTree != NULL)
    delete mimeTree;
  boundaries.clear();
  mimeTree = new MimeTree();
  parent = mimeTree;
  currentNode = mimeTree;
  std::string line;
  bool goodLine;
  do{
    std::getline(stream, line);
    if ((goodLine=stream.good())) {
      parseLine(line);
    }
    else {
      break;
    }
  } while (goodLine);
  if (parent != mimeTree)
    throw ParserException("The input has invaild tree structure.");
}

void MimeParser::printTree(std::ostream &stream) {
  if (mimeTree == NULL)
    stream << "No input parsed." << std::endl;
  else
    mimeTree->printTree(stream);
}

void MimeParser::parseLine(std::string line) {
  //type
  if (line.find("Content-Type:") == 0 && !currentNode->isTypeSet()) {
    currentNode->setType(line.substr(14, line.size() - 14)); // Content-Type: multipart/mixed; --we don't need space 
    lastType = true;
    return;
  }

  //boundary
  if (lastType) {
    lastType = false;
    if (parseBoundary(line))
      return;
  }

  lastType = false;

  switch (checkBoundary(line))
  {
  case 0:
    currentNode->contentAppendLine(line);
    break;
  case 1:
    currentNode = parent->addChild();
    break;
  case 2:
    boundaries.pop_back();
    //last part in input
    if (parent->getParent() == NULL)
      return;
    parent = parent->getParent();
    if ((currentNode = parent->getLastChild()) == NULL)
      throw ParserException("Misformed end boundary in input.");
    break;
  default:
    throw ParserException("Parser error: Cannot identifie boundary.");
    break;
  }
}

int MimeParser::checkBoundary(std::string boundary) {
  if (boundaries.empty())
    return 0;
  std::string lastBoundary = boundaries.back();
  std::size_t found = boundary.find(lastBoundary);
  if (found == 0) {
    std::string rest = trim(boundary.substr(lastBoundary.size()));
    
    //start of next part
    if (rest.size() == 0)
      return 1;
    //end of multipart 
    if (rest.compare("--") == 0)
      return 2;
  }
  return 0;
}

std::string MimeParser::trim(std::string str) {
  str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
  return str;
}

//TODO: check if substring between start and "boundary" is only white space
bool MimeParser::parseBoundary(std::string line) {
  std::size_t found = line.find("boundary=\"");
  if (found != std::string::npos) {
    std::string boundaryBegin = trim(line.substr(0, found));
    if(boundaryBegin.size()!=0)
      return false;
    std::size_t boundaryEnd = line.find("\"", found + 10);
    std::size_t len = boundaryEnd - (found + 10);
    if (boundaryEnd == std::string::npos)
      throw ParserException("Misformed boundary (no end).");
    std::cout << line << std::endl;
    if ((trim(line.substr(boundaryEnd+1, line.size()-boundaryEnd-1))).size()!=0)
      throw ParserException("Misformed boundary (characters after boundary).");
    if (len == 0)
      throw ParserException("Boundary length is zero.");

    boundaries.push_back("--" + line.substr(found + 10, len));
    return true;
  }
  return false;
}
