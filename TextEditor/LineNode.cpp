#include <iostream>
#include <string.h>
#include <editor.h>
#include <SString.h>
#include <LineNode.h>
#include <TextList.h>

using namespace std;

LineNode::LineNode()
{
}

LineNode::LineNode(SString &data)
{

    this->data = &data;
}

void LineNode::appendNextNode(LineNode &n)
{
    this->next = &n;
}

SString *LineNode::getData()
{

    return this->data;
}

LineNode *LineNode::getNext()
{

    return this->next;
}

void LineNode::setNext(LineNode *l)
{

    this->next = l;
}
