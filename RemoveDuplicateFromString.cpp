#include<bits/stdc++.h>
#define IOS             ios::sync_with_stdio(0); cin.tie(0);
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

void RemoveDuplicates(char s[]){

    int n = 0;
    while(s[n]!='\0') n++;

    bool dup[130] = {false};

    for(int i=0; i<n; i++){
        if(dup[s[i]]==false){
            printf("%c", s[i]);
            dup[s[i]] = true;
        }
    }
    return;
}

int main()
{
    IOS;
    char s[100];

    gets(s);

    RemoveDuplicates(s);
}
