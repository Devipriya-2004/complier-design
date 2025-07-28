%{
#include <stdio.h>
int count = 0;  // Counter for all operators
%}

%%
"=="|"+="|"-="|"*="|"/="|"="      { printf("Assignment Operator: %s\n", yytext); count++; }
[\+\-\*/]                        { printf("Arithmetic Operator: %s\n", yytext); count++; }
[ \t\n]                          { /* Ignore whitespace */ }
.                                { /* Ignore other characters */ }
%%

int yywrap() {
    return 1; // Indicates end of input
}

int main() {
    yylex(); // Start lexical analysis
    printf("Total Operators Found: %d\n", count);
    return 0;
}

