#include "mimeTree.h"
#include "parserException.h"

MimeTree::MimeTree() {
  m_parent = NULL;
}

MimeTree::MimeTree(std::string content, std::string type) {
  m_parent = NULL;
  setContent(content);
  setType(type);
}

MimeTree::MimeTree(MimeTree *parent, std::string content, std::string type) {
  setParent(parent);
  setContent(content);
  setType(type);
}

MimeTree::~MimeTree() {
  for(int i=0; i<numberOfNodes(); ++i)
    delete getChildAt(i);
}

MimeTree* MimeTree::addChild() {
  MimeTree *newNode = new MimeTree();
  newNode->setParent(this);
  addChild(newNode);
  return newNode;
}

MimeTree* MimeTree::addChild(std::string content, std::string type) {
  MimeTree *newNode = new MimeTree(this, content, type);
  addChild(newNode);
  return newNode;
}

void MimeTree::addChild(MimeTree *node) {
  m_tree.push_back(node);
}

MimeTree* MimeTree::getChildAt(int i) {
  if(i<0 || i>numberOfNodes()-1)
    throw ParserException("Node index out of bounds!");
  return m_tree[i];
}

MimeTree* MimeTree::getLastChild() {
  if (m_tree.empty())
    return NULL;
  return m_tree.back();
}

void MimeTree::printTree(std::ostream &stream) {
  printTree(stream, 0);
}

void MimeTree::printTree(std::ostream &stream, int depth) {
  printPadded(stream, m_type, depth, true);
  printPadded(stream, m_content, depth);
  for(int i=0; i<numberOfNodes(); ++i)
    getChildAt(i)->printTree(stream, depth+1);
}

std::string MimeTree::generatePadding(int depth) {
  std::string padding;
  for (int i = 0; i < depth; ++i) {
    padding += "--";
  }
  return padding;
}

void MimeTree::printPadded(std::ostream &stream, std::string str, int depth, bool type) {
  std::string padding = generatePadding(depth);

  std::size_t last = 0, found = str.find("\n");
  while (found != std::string::npos) {
    std::size_t len = found - last;
    stream << padding << str.substr(last, len) << std::endl;
    last = found+1;
    found = str.find("\n",last);
  }
  if (type) 
    stream << padding << "Content-Type: " << str.substr(last) << std::endl;
  else
    stream << padding << str.substr(last) << std::endl;
}

void MimeTree::setParent(MimeTree* parent) {
   m_parent = parent;
}

MimeTree* MimeTree::getParent() {
  return m_parent;
}

std::string MimeTree::getContent() {
  return m_content;
}

std::string MimeTree::getType() {
  return m_type;
}

bool MimeTree::isTypeSet() {
  if (m_type.size())
    return true;
  return false;
}

void MimeTree::setContent(std::string content) {
  m_content = content + "\n";
}

void MimeTree::contentAppendLine(std::string line) {
  m_content += line + "\n";
}

int MimeTree::numberOfNodes() {
  return m_tree.size();
}

void MimeTree::setType(std::string type) {
  if (type.size() == 0)
    throw ParserException("Misformed type.");
  m_type = type;
}
