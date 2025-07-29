#include <stdio.h>

int main() {
    for (int i = 0; i != 256; i++){
        if(i!= 0 && !(i % 10)) 
            printf("\n");
        
        else 
            printf(" ");
            printf("\"");
            switch (i) {
                case '\n':
                printf("\\n");
                break; case '\t':
                printf("\\t");
                break; case '\v':
                printf("\\v");
                break; case '\b':
                printf("\\b");
                break; case '\r':
                printf("\\r");
                break; case '\'' :
                printf("\\'");
                 break; case '\"' :
                printf("\\\"");
                 break; case '\\' :
                printf("\\");
                default:
                if (i < 32)
                    printf("\\0%o", i);
                else if( i > '~')
                    printf("\\x%x", i);
                else 
                    printf("%c", i);

        }
        printf("\",");
    }
}
