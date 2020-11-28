
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
void GeneratePrimes(int N){
    bool flag[N+1] = {0};
    int primes[N];
    int idx = 0;

    for(int i=2; i<=N; i++){
        if(flag[i]==0){
            primes[idx++] = i;
            for(int j=i*i; j<=N; j+=i){
                flag[j] = 1;
            }
        }
    }
    for(int i=0; i<idx; i++){
        printf("%d ", primes[i]);
    }
    putchar('\n');

}
int main()
{
    IOS;
    int n;
    cin>>n;
    GeneratePrimes(n);


}
