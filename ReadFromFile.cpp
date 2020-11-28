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
void FindSumFromFile(){
    string text;
    int sum = 0, num = 0;
    ifstream fileRead;
    fileRead.open("myfile.txt");

    while(fileRead>>num){
                // Move in row and find all integers
//        for (int i = 0; text[i] != '\0'; i++) {
//
//            // Find value of current integer
//            if (isdigit(text[i]))
//                num = 10 * num + (text[i] - '0');
//
//            // If other character, add it to the
//            // result
//            else {
//                sum += num;
//                num = 0; // and now replace
//                         // previous number with 0
//            }
    //  }
        sum += num;
        num = 0;
    }

    ofstream fileWrite;
    fileWrite.open("ans.txt");
    fileWrite<<sum;
    fileWrite.close();

    cout<<sum<<endl;
}
int main()
{
    IOS;

    ifstream fileRead ("myfile.txt");
    FindSumFromFile();


}
