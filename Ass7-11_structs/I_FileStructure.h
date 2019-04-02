#ifndef I_FileStructure_H
#define I_FileStructure_H
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define Index_Size 5
#define Array_Size 5


//Crud = create,read,update, delete. Here only crd
FILE*fptr;

typedef struct object{

int id;
char *name;
char *address;

}object;



typedef struct array{

object* objects[Array_Size];

}array;


typedef struct theindex{

array* arrays[Index_Size];
array* overflow;

}theindex;




theindex* Index;

void initializeIndexArray();



void addToFileStructure(object *o, int index);

void addToOverflow(object *o);



char* findStruct(int id);


void deleteStruct(int id);

void writeAllToFile(FILE*fptr);

int calcHash(object* o);









#endif