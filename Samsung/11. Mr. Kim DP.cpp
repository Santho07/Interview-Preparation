#include <bits/stdc++.h>

using namespace std;

int dp[12][1 << 11];  // bitmask with max 11 bits
int x[12], y[12];  //  5<= N <= 10 , home, office

int n;

int calc(int p, int mask) {
    if(p == 0 && mask == 0) return 0; // Base case - reached home and visited all customers
    else if(p == 0) return 1e9;

    // When recursion hits base case (home + all traversed), to eliminate other base
    // case (home + not all traversed), we need to return higher value -- thus 1e9

     dp[p][mask]=1e9;

    for (int i = n; i >=0 ; --i) {
        if (mask & (1 << i)) {                      // Check if ith bit is 1
            int dist = abs(x[p] - x[i]) + abs(y[p] - y[i]);
             dp[p][mask] = min( dp[p][mask], calc(i, mask ^ (1 << i)) + dist);    // toggle the ith bit to indicate this bit as visited
        }
    }
    return  dp[p][mask];
}

int main() {
    std::ios::sync_with_stdio(false);

    for (int i = 1; i <= 10; ++i) {

        cin>>n;
        cin>>x[0]>>y[0];
        cin>>x[n+1]>>y[n+1];

        for (int j = 1; j <= n; ++j) {
            cin>>x[j]>>y[j];
        }

        memset(dp, -1, sizeof dp);

        int mask = (1 << (n + 1)) - 1; // n+1 bits representing n customers and office- starting point

        cout<<"Case #"<< i <<": "<< calc(n + 1, mask); // Sending end point- home

    }
    return 0;
}
/* Proof Of Concept------------------------------------------------------------------------------

                     calc(n+1, 1111............1) // destination , initially all bit is 1- means not visited
                     /                      \
     min of |       calc(n,0111.......1)    calc(n-1,10111....1)   ....          calc(0,11......0)
                   /                   \
    min of |      calc(n-1, 0011....1)      ...  // If ith bit is not 1, recursive call won't take place
                     .
                     .
                     .
                   /
    min of |     calc(0, 0000....0)  ...

*/
