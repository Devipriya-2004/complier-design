%{
#include <stdio.h>
#include <ctype.h>
%}

%%
[A-Z]    { putchar(tolower(yytext[0])); }
[a-z]    { putchar(yytext[0]); }
[ \t\n]  { putchar(yytext[0]); }
%%

int yywrap() {
	return 1;
}

int main() {
    yylex();
    return 0;
}

