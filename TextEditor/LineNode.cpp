#include <iostream>
#include <string.h>
#include <editor.h>
#include <SString.h>
#include <LineNode.h>
#include <TextList.h>

using namespace std;

LineNode::LineNode()
{
    this->data = NULL;
    this->next = NULL;
}

LineNode::LineNode(SString &data)
{

    this->data = &data;
}

void LineNode::appendNextNode(LineNode &n)
{
    this->next = &n;
}

void LineNode::printLine()
{

    this->getData()->print();
}

SString *LineNode::getData()
{
    if (this->data != NULL)
    {
        return this->data;
    }
    else
        return new SString("empty");
}

LineNode *LineNode::getNext()
{

    return this->next;
}

void LineNode::setNext(LineNode *l)
{

    this->next = l;
}
