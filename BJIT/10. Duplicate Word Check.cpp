#include<iostream>
using namespace std;
char words[100][100];
#define Max (int)1e5+7
int arr[Max];

int findDuplicate(int n){
    int dupCount = 0;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; words[i][j]; j++){
            sum += ((words[i][j]*(j+1))%Max); //Hashing
        }
        arr[sum]++;
        if(arr[sum]>1) {
            dupCount++;
            words[i][0] = '\0';
        }
    }
    return dupCount;
}
int generateWords(char s[]){
    int i = 0, len = 0;
    while(s[i++]!='\0') len++;

    int n = 0, m = 0, start = 0;
    for(i=0; i<len; i++){
        if(s[i]==' '){
            m = 0;
            for(int j=start; j<i; j++){
                words[n][m++] = s[j];
            }
            words[n][m] = '\0';
            start = i+1;
            n++;
        }
    }
    m = 0;
    for(int j=start; j<len; j++){
        words[n][m++] = s[j];
    }
    words[n][m] = '\0';

    return n+1;
}
int main(){
    char s[1000];
    gets(s);
    int n = generateWords(s);
    for(int i=0; i<n; i++){
        printf("%s ", words[i]);
    }
    cout<<endl;
    cout<<findDuplicate(n)<<endl;
    for(int i=0; i<n; i++){
        if(words[i][0]!='\0') printf("%s ", words[i]);
    }
    cout<<endl;
}

