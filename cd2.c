#include <stdio.h>
#include<stdlib.h>

int main() {
    FILE *fp1, *fp2;
    char c, d;

    fp1 = fopen("input.c", "r");
    fp2 = fopen("output.c", "w");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    while ((c = fgetc(fp1)) != EOF) {
        if (c == '/') {
            d = fgetc(fp1);
            if (d == '/') {
                while ((c = fgetc(fp1)) != '\n');
            } else if (d == '*') {
                do {
                    while ((c = fgetc(fp1)) != '*');
                } while ((c = fgetc(fp1)) != '/');
            } else {
                fputc(c, fp2);
                fputc(d, fp2);
            }
        } else {
            fputc(c, fp2);
        }
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
