
%{
#include<stdio.h>
%}

%%
[0-9]+          { printf("Digits:%s\n",yytext);}
[a-zA-Z]+       { printf("Alphabets:%s\n",yytext);}
.               {  }
%%

int yywrap() {}
int main() {
yylex();
return 0;
}
