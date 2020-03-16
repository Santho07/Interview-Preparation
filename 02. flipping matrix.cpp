/*problem: A binary matrix of nxm was given,
you have to toggle any column k number of times so that
you can get the maximum number of rows having all 1’s.*/

/* https://stackoverflow.com/questions/7116438/algorithms-question-flipping-columns */
/*
The actual algorithm for doing this depends on
 whether or not we are allowed to flip the same column twice.
 If we aren't, then a candidate row is one that has exactly k zeros in it.
 If we can flip the same column multiple times, then this is a bit trickier.
 To make the row all ones, we would need to convert each zero to a one,
 then would need to keep spending the remaining flips flipping the same
 column twice to avoid changing any one to a zero. This is true if the
  difference between k and the number of zeros in the row is a nonnegative even number.
*/
#include<iostream>
using namespace std;
#define Max (int)1e6+7
int Hash[Max];
int pow(int b, int n){
    int res = 1;
    for(int i=1; i<=n; i++) res*=b;

    return res;
}
int main(){
    int n, m, k;
    cin>>n>>m>>k;
    int A[20][20] = {0};

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>A[i][j];
        }
    }
//    int hash_size=1;
//    for(int i=1; i<=20; i++){
//        cout<<i<<" "<<hash_size<<endl;
//        hash_size*=2;
//    }
    int MaxVal = 0;
    for(int i=0; i<n; i++){
        int key = 0;
        int countZero = 0;
        for(int j=0; j<m; j++){
            key += (A[i][j]*pow(2, j));
            if(A[i][j]==0) countZero+=1;
        }

        if((k-countZero)%2==0 && (k-countZero)>=0){
            Hash[key]++;
            if(Hash[key]>MaxVal){
                MaxVal = Hash[key];
            }
        }
    }
    cout<<MaxVal<<endl;
}
