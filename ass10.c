/*Use the enum week as defined in the slides, use a global defined array of Week items with some
fix size N where N is defined as a symbolic constant.
Write 2 functions, the first which reads a number of strings and convert them to the
corresponding enum value and sequential stores this in your global defined array, the second
functions sequential gets the gobal array items and prints the corresponding strings.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 7

enum week
{
    Mon,
    Tue,
    Wed,
    Thur,
    Fri,
    Sat,
    Sun
};
typedef enum week Week;

char *weekStrings[] = {
    "Mon",
    "Tue",
    "Wed",
    "Thur",
    "Fri",
    "Sat",
    "Sun"};

Week items[N];

int read()
{

    //weekitemsIndexcount
    int w=-1;
    
    for (size_t i = 0; i < N; i++)
    {
        char itemToChange[N];

        fgets(itemToChange, N, stdin);
      

        //fgets saves EOL at end of char array,
        //so we need to replace it with \0.
        for (size_t k = 0; k < N; k++)
        {
            if (itemToChange[k] == '\n')
            {
                itemToChange[k] = '\0';
            }
        }

        int j = 0;
        do
        {
            
            if (strcmp(itemToChange, weekStrings[j]) == 0)
            {
                w++;
                printf("%s", "equal");
            

           switch (j)
           {  
               case 0:
            
                   items[w]=Mon;
                   break;

                case 1:
                   items[w]=Tue;
                   break;

                   case 2:
                   items[w]=Wed;
                   break;

                   case 3:
                   items[w]=Thur;
                   break;

                   case 4:
                   items[w]=Fri;
                   break;

                   case 5:
                   items[w]=Sat;
                   break;

                   case 6:
                   items[w]=Sun;
                   break;


           
               default:
                   break;
           }

            }

            j++;
        } while (j<N);

        
    }
    return 0;
}

int print()
{

    for (size_t i = 0; i < N; i++)
    {
        if(items[i]==Mon){
        printf("Mon");
        }
        else if (items[i]==Tue){
        printf("Tue");
        }
        else if (items[i]==Wed){
        printf("Wed");
        }
        else if (items[i]==Thur){
        printf("Thur");
        }
        else if (items[i]==Fri){
        printf("Fri");
        }
        else if (items[i]==Sat){
        printf("Sat");
        }
        else if (items[i]==Sun){
        printf("Sun");
        }
    }

    return 0;
}

int main()
{

    read();

    print();

    return 0;
}
