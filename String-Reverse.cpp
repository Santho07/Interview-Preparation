#include<bits/stdc++.h>
#define pb              push_back
#define mkp             make_pair
#define all(a)          a.begin(), a.end()
#define rall(a)         a.rbegin(), a.rend()
#define maximum(a)      *max_element(all(a))
#define minimum(a)      *min_element(all(a))
#define MAX             (int)2e5+7
using namespace std;
typedef long long LL;
typedef pair<int, int> pi;
typedef pair<LL, LL> pill;
char* reverse_string(char* s){
    int i = 0, len = 0;

    while(s[len]!='\0') len++;

    for(i=0; i<len/2; i++){
        char temp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = temp;
    }
    return s;

}
int main()
{
    char s[100];
    fgets(s, 100, stdin);
    char* ss = reverse_string(s);
    puts(ss);

}
