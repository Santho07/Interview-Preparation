#include<iostream>
using namespace std;
string reverseString(string s){
    int len = s.length();
    for(int i=0; i<len/2; i++){
        char tmp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = tmp;
    }
    return s;
}
string add(string s1, string s2){
    string temp;
    if(s2.length()>s1.length()){ //make sure s1 is bigger
        temp = s2;
        s2 = s1;
        s1 = temp;
    }
    s1 = reverseString(s1);
    s2 = reverseString(s2);
    temp = "";
    int carry = 0;
    int n1 = s1.length(), n2 = s2.length();

    for(int i=0; i<n2; i++){
        int sum = (s1[i]-'0') + (s2[i]-'0') + carry;
        temp += (sum%10+'0');
        carry = sum/10;
    }
    for(int i=n2; i<n1; i++){ //add remaining of s1 to temp
        int sum = (s1[i]-'0')+carry;
        temp += (sum%10 + '0');
        carry = sum/10;
    }
    if(carry) temp += (carry+'0');
    temp = reverseString(temp);

    return temp;
}
string subtract(string s1, string s2){
    string temp;
    if(s2.length()>s1.length()){ //make sure s1 is bigger
        temp = s2;
        s2 = s1;
        s1 = temp;
    }
    s1 = reverseString(s1);
    s2 = reverseString(s2);
    temp = "";
    int carry = 0;
    int n1 = s1.length(), n2 = s2.length();

    for(int i=0; i<n2; i++){
        int sub = (s1[i]-'0')-(s2[i]-'0')-carry;
        if(sub<0){
            sub = sub + 10;   //122-8; 2-8 = -6; -6+10 = 4, carry = 1;
            carry = 1;
        }
        else carry = 0;
        temp += (sub + '0');
    }
    for(int i=n2; i<n1; i++){
        int sub = s1[i] - '0' - carry;
        if(sub<0){
            sub = sub + 10;
            carry = 1;
        }
        else carry = 0;
        temp += (sub+'0');
    }
    temp = reverseString(temp);
    return temp;
}
int main(){
    string s1, s2, result;
    cin>>s1>>s2;

    result = add(s1, s2);
    cout<<"addition: "<<result<<endl;
    result = subtract(s1, s2);
    cout<<"subtract: "<<result<<endl;
}
