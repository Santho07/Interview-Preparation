#include <stdio.h>
#include <string.h>
void align()
{
    int width = 80;
    char str[] = "Hello world";
    int length = sizeof(str) - 1;  // Discount the terminal '\0'
    int pad = (length >= width) ? 0 : (width - length) / 2;

    printf("%*.*s%s\n", pad, pad, " ", str);
}
void alignEx(){
    int width = 80;
    char str[81];
    for (int i = 1; i <= width; i++)
    {
        memset(str, 'a', i);
        str[i] = '\0';
        int length = i;
        int pad = ((width - length)) / 2;
        for(int i=0; i<pad; i++) printf(" ");
        printf("%s\n", str);
    }
}
int main(void)
{
    align();
    int width = 80;
    int i;
    char str[] = "Hello World";
    int length = sizeof(str)-1;  // Discount the terminal '\0'
    int pad = (width - length)/2;
    for(int i=0; i<pad; i++) printf(" ");
    printf("%s\n", str);
    printf("%*s\n", width, str);
//    alignEx();
}
