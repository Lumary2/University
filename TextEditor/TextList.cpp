#include <iostream>
#include <string.h>
#include <editor.h>
#include <SString.h>
#include <LineNode.h>
#include <TextList.h>

using namespace std;

//problem: nodes not added to head. runner not on right position

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

    while (runner != footer)
    {

        runner->getData()->print();
        cout << endl;
        runner = runner->getNext();
    }

    //überarbeiten, nur für test
    /*this->runner->getData()->print();

    this->runner->getNext()->getData()->print();*/
}

void TextList::setRunner(int i)
{

    //we want the runner to be on the last
    //node with text.
    for (int j = i - 1; j != i; j++)
    {
        cout << "move runner" << endl;
        this->runner = runner->getNext();
    }
}

LineNode *TextList::getRunner()
{

    return runner;
}

int TextList::numberOfLines()
{

    return numOflines;
}
