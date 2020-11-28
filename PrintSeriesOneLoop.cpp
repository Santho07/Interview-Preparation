//Print 1 2 3 4 5 6 7 8 9 10 9 8 7 6 5 4 3 2 1

#include<stdio.h>

int main(){

    for(int i=1; i<20; i++){
        int n = (i>10) ? 20-i : i;
        printf("%d ", n);
    }
    printf("\n");

    return 0;
}
