#include <iostream>
#include <string.h>
#include <editor.h>
#include <SString.h>
#include <LineNode.h>
#include <TextList.h>
#include <SString.h>

using namespace std;

int main()
{

    //create instance of editor named e
    Editor e();
    TextList t;

    SString test("test");
    SString sonne("sonne");
    SString mond("mond");
    SString stern("stern");

    t.appendLine(test);
    t.appendLine(sonne);
    t.appendLine(mond);
    t.appendLine(stern);

    t.printAll();
}