#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    int x = 0, n, i = 0, j = 0;
    void *mypointer, *T4Tutorials_address[50];
    char T4Tutorials_Array2[50], T4Tutorials_Array3[50], c, ch;

    printf("Input the expression ending with $ sign:\n");

    // Read expression until '$'
    while ((c = getchar()) != '$')
    {
        T4Tutorials_Array2[i] = c;
        i++;
    }

    n = i - 1;

    printf("\nGiven Expression: ");
    for (i = 0; i <= n; i++)
        printf("%c", T4Tutorials_Array2[i]);

    printf("\n\nSymbol Table Display\n");
    printf("----------------------------------\n");
    printf("Symbol\t\tAddress\t\tType\n");
    printf("----------------------------------\n");

    for (j = 0; j <= n; j++)
    {
        c = T4Tutorials_Array2[j];

        // Identifier (alphabet)
        if (isalpha(c))
        {
            mypointer = malloc(sizeof(char)); // allocate 1 byte for each symbol
            T4Tutorials_address[x] = mypointer;
            T4Tutorials_Array3[x] = c;
            printf("%c\t\t%p\tidentifier\n", c, mypointer);
            x++;
        }
        // Operator
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=')
        {
            mypointer = malloc(sizeof(char));
            T4Tutorials_address[x] = mypointer;
            T4Tutorials_Array3[x] = c;
            printf("%c\t\t%p\toperator\n", c, mypointer);
            x++;
        }
    }

    printf("----------------------------------\n");
    return 0;
}

