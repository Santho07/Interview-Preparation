#include<iostream>
#include<stack>
using namespace std;
string curr_page;
stack<string> st;

string moveBackword(){
    curr_page = st.top();
    st.pop();
    return curr_page;
}
void new_add(string new_page){
    st.push(curr_page);
    curr_page = new_page;
}
int main(){
    string s;
    while(cin>>s){
        if(s=="back") cout<<moveBackword()<<endl;
            else new_add(s);
    }
}

