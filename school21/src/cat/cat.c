#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>

#include "CatFlags.h"
//int getopt_long(int argc, shar *conts argv[]),     //чтобы понять какой флаг был передан
//      conts char *optstring,
//      const struct option *longopts, int *longindex);

typedef struct {
    bool NumNonBlank;
    bool MarkEndStr;
    bool NumAllBlank;
    bool squeeze;
    bool tab;
    bool printNonPrintable;
} Flags;

Flags read_flags(int argc, char *argv[]) {
    struct option longOptions[] = {
        {"number-nonblank", 0, NULL, 'b'},
        {"number", 0, NULL, 'n'},
        {"squeeze-blank", 0, NULL, 's'},
        {NULL, 0, NULL, 0} //getopt будет перебирать массив и тут поймет, что он закончен, т/к/ все 0
    };
    int flagCurrent = getopt_long(argc, argv, "bevEnstT", longOptions, NULL);
    Flags flags = {false, false, false, false, false, false}; 
    for(;flagCurrent != -1;
    flagCurrent = getopt_long(argc, argv, "bevEnstT", longOptions, NULL)) {
        switch (flagCurrent) {
            break; case 'b' :
            flags.NumNonBlank = true;
            break; case 'e' :
            flags.MarkEndStr = true; 
            flags.printNonPrintable = true;
            case 'v' :
            break; case 'E' :
            flags.MarkEndStr = true;
            break; case 'n' :
            flags.NumAllBlank = true;
            break; case 's' :
            flags.squeeze = true;
            break; case 't' :
            flags.printNonPrintable = true;
            flags.tab = true;
            break; case 'T' :
            flags.tab = true;
        }
    }
    return flags;
}

/* void cat_file(FILE *file) {
    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }
} */
void CatFile(FILE *file, Flags flags, const char *table[static 256]){
    int c = 0;
    int last;
    (void) last; 
    (void) flags;
    while (fread(&c, 1, 1, file) > 0) {  //посимвольно читаем из буфера в с
        printf("%s", table[c]);
    }
}

int main(int argc, char *argv[]) {
    Flags flags = read_flags(argc, argv);
    const char *table[256];
    CatSetTable(table);
    if (flags.NumNonBlank)
        printf("number nonblank lines\n");
    if (flags.MarkEndStr)
        CatSetEnd(table);
    if (flags.NumAllBlank)
        printf("num all blank\n");
    if (flags.squeeze)
        printf("squeeze\n");
    if (flags.tab)
        CatSetTab(table);
    if (flags.printNonPrintable) {
        SetNonPrintble(table);
    }

        CatFile(stdin,flags, table);
    return 0;
}