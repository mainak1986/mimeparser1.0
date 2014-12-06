#include <vector>
#include <string>
#include <ostream>

class MimeTree {
  MimeTree *m_parent;
  std::vector<MimeTree*> m_tree;
  std::string m_content;
  std::string m_type;
  
public:
  MimeTree();
  MimeTree(std::string content, std::string type);
  ~MimeTree();

  MimeTree* addChild();
  MimeTree* addChild(std::string content, std::string type);

  MimeTree* getChildAt(int i);
  MimeTree* getLastChild();

  MimeTree* getParent();

  int numberOfNodes();

  void printTree(std::ostream &stream);

  std::string getContent();
  std::string getType();
  
  void setContent(std::string content);
  void contentAppendLine(std::string line);
  void setType(std::string type);
  bool isTypeSet();
private:
  MimeTree(MimeTree *parent, std::string content, std::string type);
  void printTree(std::ostream &stream, int depth);
  void printPadded(std::ostream &stream, std::string str, int depth, bool type=false);
  std::string generatePadding(int depth);
  void setParent(MimeTree *parent);
  void addChild(MimeTree *node);
};
