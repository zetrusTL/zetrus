#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    bool NumNonBlank;
    bool MarkEndStr;
    bool NumAllBlank;
    bool squeeze;
    bool tab;
}flags;

void cat_file(FILE *file) {
    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        cat_file(stdin);
    } else {
        for (int i = 1; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                fprintf(stderr, "cat: %s: No such file or directory\n", argv[i]);
                continue;
            }
            cat_file(file);
            fclose(file);
        }
    }
    return 0;
}