#include<iostream>
using namespace std;
int an;
void calculateDiff(int comp[],int n)
{
	int maxa=0,mina=1000;
	for(int i=0;i<n;i++)
	{
		maxa = max(maxa,comp[i]);
		mina = min(mina,comp[i]);
	}
	an = min(an,maxa-mina);
}
void calculateTotal(int end,int curr,int oil[],int comp[],int n,int m,int compNo)
{
	if((curr+1)%m==end)
	{
		for(int j = compNo;j<n;j++)
		{
			comp[j]+=oil[curr];
			calculateDiff(comp,n);
			comp[j]-=oil[curr];
		}
		return;
	}
	if(compNo==n)
		return;
	comp[compNo]+=oil[curr];
	calculateTotal(end,(curr+1)%m,oil,comp,n,m,compNo);
	calculateTotal(end,(curr+1)%m,oil,comp,n,m,compNo+1);
	comp[compNo]-=oil[curr];
	calculateTotal(end,curr,oil,comp,n,m,compNo+1);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        an = 10000;
        scanf("%d%d",&n,&m);
        int oil[m];
        for(int i=0;i<m;i++)
            scanf("%d",&oil[i]);
        int comp[n];
        for(int i=0;i<n;i++)
            comp[i]=0;

        for(int i=0;i<m;i++)
        {
            calculateTotal(i,i,oil,comp,n,m,0);
        }
        printf("%d",an);
    }

	return 0;
}
