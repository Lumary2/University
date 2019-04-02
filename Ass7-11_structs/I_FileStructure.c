#include "I_FileStructure.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void initializeIndexArray()
{
    Index = (theindex *)malloc(sizeof(theindex));
    for (int i = 0; i < Index_Size; i++)
    {
        Index->arrays[i] = (array *)malloc(sizeof(array));
        Index->overflow = (array *)malloc(sizeof(array));
    }
}

void addToFileStructure(object *o, int index)
{
    //search for free position
    for (int i = 0; i < 5; i++)
    {

        if (Index->arrays[index]->objects[i] == NULL)
        {
            printf("hi");
            Index->arrays[index]->objects[i] = o;
            printf("\n");
            break;
        }

        /* code */
        else
        {

            addToOverflow(o);
            break;
        }
    }

    /* code */
}

void addToOverflow(object *o)
{

    for (int i = 0; i < 5; i++)
    {
        if (Index->overflow->objects[i] == NULL)
        {
            Index->overflow->objects[i] = o;
            break;
        }
        /* code */
    }
}

char *findStruct(int id)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("i: %d j: %d\n", i, j);
            if (Index->arrays[i]->objects[j] != NULL && Index->arrays[i]->objects[j]->id == id)
            {
                printf("name for id is: %s", Index->arrays[i]->objects[j]->name);
                return Index->arrays[i]->objects[j]->name;
            }

            else if (Index->overflow->objects[j] != NULL && Index->overflow->objects[j]->id == id)
            {
                printf("name for id is: %s", Index->overflow->objects[j]->name);
                return Index->overflow->objects[j]->name;
            }
        }
        /* code */
    }
    return NULL;
}

void deleteStruct(int id)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("i: %d j: %d\n", i, j);
            if (Index->arrays[i]->objects[j] != NULL && Index->arrays[i]->objects[j]->id == id)

            {
                Index->arrays[i]->objects[j] = NULL;
            }

            else if (Index->overflow->objects[j] != NULL && Index->overflow->objects[j]->id == id)
            {

                Index->overflow->objects[j] = NULL;
            }
        }
        /* code */
    }
}

void writeAllToFile(FILE *fptr)
{
    int writeCount = 0;
    fprintf(fptr, "{\n\"user\": [\n");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            if (Index->arrays[i]->objects[j] != NULL)
            {
                printf("writing from bucket: %d  %d\n", i, j);
                //insert commas, makes sure that theres no comma at end of array.
                if (writeCount > 0)
                {
                    fprintf(fptr, ",\n");
                }

                fprintf(fptr, "{ \"name\":\"%s\",\n", Index->arrays[i]->objects[j]->name);
                fprintf(fptr, " \"adress\":\"%s\",\n", Index->arrays[i]->objects[j]->address);
                fprintf(fptr, " \"id\":%d\n}", Index->arrays[i]->objects[j]->id);
                writeCount++;
            }

            /* code */
        }

        if (Index->overflow->objects[i] != NULL)
        {
            printf("writing from overflow bucket: %d\n", i);
            //insert commas, makes sure that theres no comma at end of array.
            if (writeCount > 0)
            {
                fprintf(fptr, ",\n");
            }

            fprintf(fptr, "{ \"name\":\"%s\",\n", Index->overflow->objects[i]->name);
            fprintf(fptr, " \"adress\":\"%s\",\n", Index->overflow->objects[i]->address);
            fprintf(fptr, " \"id\":%d\n}", Index->overflow->objects[i]->id);
            writeCount++;
        }
    }

    fprintf(fptr, "\n]\n}");
}

int calcHash(object *o)
{

    int ascii = (o->name[0]) + (o->name[1]);
    // take ascii values of name of o and use %5
    int hash = ascii % 3;

    printf("hash: %d\n", hash);

    return hash;
}

void freeAll()
{

    for (size_t i = 0; i < Array_Size; i++)
    {
        free(Index->arrays[i]);
    }

    free(Index->overflow);
    free(Index);
}
