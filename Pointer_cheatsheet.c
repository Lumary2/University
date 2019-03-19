#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(){

int number=1;
int* Pnumber=&number;

printf("%p adress number \n",Pnumber);
printf("%d value of variable to which pointer points \n", *Pnumber);
printf("%p adress Pnumber \n\n", &Pnumber);

//---------------------------------

char name[8]="Jessica";
//points to first element of name[]and at the same
//time can address all buckets of the name[]
//with name[1]...
char* Pname=name; 

printf("%p Adress of name[0]\n",Pname);
printf("%p Adress of Pname\n",&Pname);
printf("%c Value of first char where Pname points to\n",*Pname); //or Pname[0]
printf("%c value of second char where Pname points to\n\n",Pname[1]);

//-----------------------------------

char nameMale[]="Benjamin";
//array of char pointers
char* P_name[5];
P_name[0]=nameMale;

printf("%p adress of pointer \n",P_name);
printf("%p adress of pointer\n",&P_name);
printf("%p adress of nameMale[0]\n",&nameMale[0]);
printf("%s value of variable to which pointer points\n",*P_name); 
printf("%s value of variable to which pointer points\n\n",P_name[0]);

//----------------------------------------
char nameFemale[]="Dorothee";
char nameFemale2[]="Sonja";

char* P_fname[5];
//array of char pointers pointing to P_fname
char** PP_fname[2];
P_fname[0]=nameFemale;
P_fname[1]=nameFemale2;

PP_fname[0]=P_fname;
PP_fname[1]=&P_fname[1];


printf("%p adress of PP_fname \n",PP_fname);
printf("%p adress of PP_fname\n",&PP_fname);
printf("%p adress of P_fname\n",&P_fname);
printf("%s value of variable to which pointer of P_fname[0] points\n",*PP_fname[0]); 
printf("%s value of variable to which pointer of P_fname[0] points\n",*PP_fname[1]); 




}