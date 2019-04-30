#include <iostream>
#include <string.h>
#include <editor.h>
#include <SString.h>
#include <LineNode.h>
#include <TextList.h>

using namespace std;

//problem:  runner not on right position?

TextList::TextList()
{

    this->header = new LineNode();
    this->footer = new LineNode();
    this->header->setNext(footer);
    this->runner = header;
    numOflines = 0;
}

void TextList::appendLine(SString &s)
{
    //to append a line we have to create a new LineNode
    //with the SString and append it to the node
    //where the runner points to. How?

    LineNode *n = (new LineNode(s));
    n->setNext(footer);
    setRunner(numberOfLines());
    (this->runner)->appendNextNode(*n);
    numOflines++;
}

void TextList::printAll()
{
    runner = header->getNext()->getNext();

    while (runner != footer)

    {

        runner->getData()->print();
        cout << endl;
        runner = runner->getNext();
    }
}

void TextList::insertLine(SString &s, int n)
{

    LineNode *no = new LineNode(s);
    this->setRunner(n);
    no->setNext(this->runner);

    this->setRunner(n - 1);
    this->runner->appendNextNode(*no);
}

void TextList::setRunner(int i)
{
    runner = header;
    //we want the runner to be on the last
    //node with text.
    for (int j = 0; j != i; j++)
    {
        this->runner = runner->getNext();
    }
}

LineNode *TextList::getRunner()
{

    return runner;
}

LineNode *TextList::getHeader()
{

    return header;
}

LineNode *TextList::getFooter()
{

    return footer;
}

int TextList::numberOfLines()
{

    return numOflines;
}
