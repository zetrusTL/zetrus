#ifndef CAT_FLAGS_H
#define CAT_FLAGS_H

void CatSetTable (const char *table[]);
void CatSetEnd(const char *table[static 256]);
void CatSetTab (const char *table[static 256]);
void SetNonPrintble(const char *table[static 256]);
#endif