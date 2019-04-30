#ifndef _TextList_H
#define _TextList_H
#include <LineNode.h>
#include <SString.h>

class TextList
{

private:
  LineNode *header;
  LineNode *footer;
  LineNode *runner;
  int numOflines;

  void setRunner(int i);

public:
  TextList();
  void appendLine(SString &s);
  void printAll();
  int numberOfLines();
  void insertLine(SString &s, int n);

  LineNode *getRunner();
  LineNode *getHeader();
  LineNode *getFooter();
};

#endif