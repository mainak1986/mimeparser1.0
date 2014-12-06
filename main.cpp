#include <iostream>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include "parserCore/parser.h"
#include "parserCore/parserException.h"

int main(int argc, const char* argv[]){
  if(argc==1 || argc>3) {
    std::cout << "run as folows:\nParser 1 - for input from standart input.\n"
      << "2 file - for input from provided file" << std::endl;
    return 0;
  }
  MimeParser parser;
  std::ifstream myfile;
  bool inFile = false;
  if(argc == 2 ) {
    if(atoi(argv[1])!=1){
      std::cout << "Invalid input. For help run Parser without parameters." << std::endl;
      return 0;
    }
    inFile = false;
  }
 
  if(argc == 3) {
    if(atoi(argv[1])!=2){
      std::cout << "Invalid input. For help run Parser without parameters." << std::endl;
      return 0;
    }
    myfile.open(argv[2]);
    if (myfile.is_open())
    {
      inFile = true;
    }
    
  }
   
  try{
    if(inFile)
      parser.parseInput(myfile);
    else
      parser.parseInput(std::cin);
    parser.printTree(std::cout);
  }
  catch (ParserException& e) {
    std::cout << e.what() << std::endl;
    if(myfile.is_open()){
      myfile.close();
    }
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    if(myfile.is_open()){
      myfile.close();
    }
  }
  
  if(myfile.is_open()){
    myfile.close();
  }
  return 0;
}
