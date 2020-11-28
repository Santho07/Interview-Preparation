#include <stdio.h>

bool IsPalindrome(int n){

    if(n<0 || n%10==0 && n!=0) return false;
    int rev = 0, org = n;
    while(n!=0){
        rev = rev*10 + n%10;
        n/=10;
    }
    return org==rev;
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("%d ", IsPalindrome(n));

}
