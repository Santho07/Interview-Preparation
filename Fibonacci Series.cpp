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
void GenerateFibonacci(int n){
    int fib[n+5];
    fib[0] = 0;
    fib[1] = 1;
    int i = 1;
    while(fib[i]<=n){
        i++;
        fib[i] = fib[i-1] + fib[i-2];
    }
    for(int j=0; j<i; j++) printf("%d ", fib[j]);

    putchar('\n');


}
int main()
{
    IOS;
    int n;

    cin>>n;
    GenerateFibonacci(n);

}
