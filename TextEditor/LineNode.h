#ifndef _LineNode_H
#define _LineNode_H
#include <SString.h>

class LineNode
{

private:
  LineNode *next;
  SString *data;

public:
  LineNode();
  LineNode(SString &data);
  LineNode *getNext();
  void appendNextNode(LineNode &n);
  void printLine();

  void setNext(LineNode *l);

  SString *getData();
};

#endif