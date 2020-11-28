#include<stdio.h>


void printReverse(char s[]){

    int len = 0, cnt;

    char *r;

    while(s[len]!='\0') len++;

    int end = len, pos = 0;
    for(int i=len-1; i>=0; i--){
        if(s[i]==' '){
            for(int j=i+1; j<end; j++){
                r[pos++] = s[j];
            }
            r[pos++] = ' ';
            end = i;
        }
    }
    for(int i=0; i<end; i++) r[pos++] = s[i];
    r[pos] = '\0';

    printf("%s\n", r);
}

int main()
{
    char s[150];
    gets(s);

    printReverse(s);

    return 0;
}
