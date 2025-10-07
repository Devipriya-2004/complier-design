#include <stdio.h>
#include <string.h>

int main() {
    char gram[100], part1[50], part2[50], modifiedGram[50], newGram[50];
    int i, j = 0, k = 0, pos = 0;

    printf("Enter Production : A->");
    fgets(gram, sizeof(gram), stdin);
    gram[strcspn(gram, "\n")] = '\0'; // remove newline

    // Split into two parts at '|'
    for (i = 0; gram[i] != '|' && gram[i] != '\0'; i++, j++)
        part1[j] = gram[i];
    part1[j] = '\0';

    for (j = ++i, i = 0; gram[j] != '\0'; j++, i++)
        part2[i] = gram[j];
    part2[i] = '\0';

    // Find common prefix
    for (i = 0; part1[i] != '\0' && part2[i] != '\0'; i++) {
        if (part1[i] == part2[i]) {
            modifiedGram[k++] = part1[i];
            pos = i + 1;
        } else {
            break;
        }
    }

    // Build new production for X
    for (i = pos, j = 0; part1[i] != '\0'; i++, j++)
        newGram[j] = part1[i];

    newGram[j++] = '|';

    for (i = pos; part2[i] != '\0'; i++, j++)
        newGram[j] = part2[i];

    newGram[j] = '\0';

    modifiedGram[k++] = 'X';
    modifiedGram[k] = '\0';

    printf("\nA->%s", modifiedGram);
    printf("\nX->%s\n", newGram);

    return 0;
}

