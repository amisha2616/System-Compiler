%option noyywrap
%{
	#include<stdio.h>
	int space=0;
	int tab=0;
	int number=0;
	int sentence=0;
	int word=0;
	int character =0;
	
%}

%%
[' '] {space++;}
[\t] {tab++;}
[0-9]+ {number++;}
[a-zA-Z0-9]+    { ++word; character += yyleng; }
[.]+ {sentence++;}

%%
int main()
{
FILE*ptr;
ptr=fopen("Test.txt","r");
yyin=ptr;
yylex();   
printf("\nNumber of Words %d",word);
printf("\nNumber of Number %d",number);
printf("\nNumber of spaces %d",space);
printf("\nNumber of sentence %d",sentence);
printf("\nNumber of Tab %d",tab);
printf("\nNumber of Character %d",character);
getch();
return 0;
}