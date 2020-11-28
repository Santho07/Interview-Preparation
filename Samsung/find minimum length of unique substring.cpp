#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int i,i1,j,j1,k,len,length,flag=0,count=0;
    string str;
    cin>>str;
    length=str.length();

    for(len=1;len<length && flag==0 ; len++)
    {
        for(i=0;i<length-len;i++)
        {
            i1=i;
            for(j=i+len;j<length-len;j++)
            {
                j1=j;
                for(k=0;k<len;k++)
                {
                    if(str[i1]!=str[j1])
                    {
                        break;

                    }
                    i1++;
                    j1++;
                }
                if(i1==i+len && j1==j+len)
                {
                    flag=1;
                    count++;
                }
            }
        }
    }
    cout<<len<<" "<<count<<endl;
    return 0;
}
