#include<iostream>
using namespace std;
bool checkAbbreviation(string s1, string s2){
    int l = s1.length();
    string abbr;
    abbr += s1[0];
    for(int i=1; i<l; i++){
        if(s1[i]==' ' && i+1<l) abbr+=s1[i+1];
    }
    if(s2==abbr) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    checkAbbreviation(s1, s2);
}
