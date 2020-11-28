#include<iostream>
using namespace std;
#define MAX 100
int arr[MAX];
int visited[MAX];
int tdistance=99999;
int cnt = 0;
void calc_min(int n,int distance,int rem,int pindex,int cars,int ins, int g_or_d)
{
    int i;
    if(cars==n)
    {
        if(tdistance>distance)
        {
            tdistance=distance;

            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(visited[j]==i) printf("%d ", j);
                }
            }
            printf("\nHere %d \n\n", distance);
        }
        return;
    }
    if(rem<=0) return;
    if(ins==0 && g_or_d==0)
    {
    int k;
        for(k=1;k<=n;k++)
        {
            if(!visited[k] &&arr[k]==1)
            {
                visited[k]=cars+1;
                //go to next gas car
                calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),rem-1,k,cars+1,0,0);
                //go to gas station
                calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),rem-1,k,cars+1,1,0);
                //go to diesel station
                calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),rem-1,k,cars+1,2,0);

                visited[k]=0;
            }
        }
    }
    if(ins==0 && g_or_d==1)
    {
        int k;
        for(k=n;k>=1;k--)
        {
            if(!visited[k] && arr[k]==2)
            {
                visited[k]= cars+1;
                //go to next gas car
                calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),rem-1,k,cars+1,0,1);
                //go to gas station
                calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),rem-1,k,cars+1,1,1);
                //go to diesel station
                calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),rem-1,k,cars+1,2,1);
                visited[k]=0;
            }
        }
    }
    if(ins==1)
    {
        //fill gas and recall
        calc_min(n,distance+(pindex-0),2,0,cars,0,0);
    }
    if(ins==2)
    {
        //fill diesel and recall
        calc_min(n,distance+((n+1)-pindex),2,n+1,cars,0,1);
    }

}
int main(){
    int t, n, i, j;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }
       calc_min(n,0,2,0,0,0,0);
       if( tdistance==99999){
            calc_min(n,n+1,2,n+1,0,0,1);
       }
       cout<<"Distance :"<<tdistance<<endl;
       tdistance=99999;
    }
}
