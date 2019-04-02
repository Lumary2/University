#include "I_FileStructure.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
     FILE *fptr;
     fptr=fopen("database.json","w");

    initializeIndexArray();

    object Object1 = {1, "Lisa", "Teichstraße 2"};

    object Object2 = {2, "Hans", "Gartenstraße 2"};

    object* Pob1=&Object1;
    object* Pob2=&Object2;


    addToFileStructure(Pob1,calcHash(Pob1));

    addToFileStructure(Pob2,calcHash(Pob2));

    writeAllToFile(fptr);
  
    

     findStruct(2);

    fclose(fptr);


    return 0;

}