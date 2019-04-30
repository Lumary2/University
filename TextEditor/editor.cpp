#include <iostream>
#include <string.h>
#include <editor.h>
#include <fstream>
#include <SString.h>
#include <TextList.h>

using namespace std;

Editor::Editor(){

};

/*opens text file and reads data into internal
linked list*/
void Editor::start()
{
    TextList t;

    ifstream infile;
    infile.open("test.txt");

    string text;

    SString *text2;
    SString x;
    //content of linkedlist gets overwritten by
    //next item.how to solve?
    //first line doesnt get printed
    while (getline(infile, text))
    {

        x = text.data();
        text2 = &x;
        t.appendLine(*text2);
    }

    char eingabe = 'b';
    //when 2times append, first input gets overwritten
    SString textinp("b");

    while (eingabe != 'q')
    {
        int number;

        cout << "*" << endl;
        cin >> eingabe;
        switch (eingabe)
        {

        case ('a'):
            cin >> textinp.getString();
            t.appendLine(textinp);
            break;

        case ('p'):
            t.printAll();
            break;

        case ('i'):
            cout << "enter line number" << endl;
            cin >> number;
            cout << "enter text" << endl;
            cin >> textinp.getString();

            //t.insertLine(textinp, number);
            break;

        case ('s'):
            //write linked list to file
            ofstream outfile("test.txt");

            LineNode *runner = t.getRunner();
            runner = t.getHeader()->getNext()->getNext();

            while (runner != t.getFooter())

            {
                outfile << runner->getData()->getString() << endl;

                runner = runner->getNext();
            }

            outfile.close();

            break;
        }
    }
}
