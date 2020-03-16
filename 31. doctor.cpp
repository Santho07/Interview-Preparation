/*
samsung-interview-questions0
of 0 votes
0
Answers
A Doctor travels from a division to other division where divisions are connected like a graph(directed graph)
and the edge weights are the probabilities of the doctor going from that division to other connected division
but the doctor stays 10mins at each division now there will be given time and had to find the division
in which he will be staying by that time and is determined by finding division which has high probability.
Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division
in which he will be there, the edges starting point, end point, probability.
Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and
the traveling time is not considered and during that 10min at 10th min he will be in next division, so be careful
2
6 10 40
1 2 0.3
1 3 0.7
3 3 0.2
3 4 0.8
2 4 1
4 5 0.9
4 4 0.1
5 6 1.0
6 3 0.5
6 6 0.5

6 10 10
1 2 0.3
1 3 0.7
3 3 0.2
3 4 0.8
2 4 1
4 5 0.9
4 4 0.1
5 6 1.0
6 3 0.5
6 6 0.5

Test Case #1 Output: 6  0.774000
Test Case #2 Output: 3 0.700000
*/

/*
you find the probability of reaching every node after 40 mins by multiplying each probability in the path.
Now there can be multiple paths by which end node is the same.
Just add the probability for those paths for each end point.
Later find the max from all end nodes.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
#define MaxNode 1000
double graph[MaxNode][MaxNode];
double answer[MaxNode];
int nodes, edges, time;

void reset(int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            graph[i][j] = 0.0;
        }
        answer[i] = 0.0;
    }

}
void dfs(int time, int currNode, double p){
    if(time<=0){
        answer[currNode] += p;
        return;
    }
    for(int i=1; i<=nodes; i++){
        if(graph[currNode][i]!=0){
            p *= graph[currNode][i];
            dfs(time-10, i, p);
            p/= graph[currNode][i];
        }
    }
}
int main(){
    int T;
    cin>>T;

    for(int t=1; t<=T; t++){
        cin>>nodes>>edges>>time;
        reset(nodes);
        int start, stop; double p;
        for(int i=0; i<edges; i++){
            cin>>start>>stop>>p;
            graph[start][stop] = p;
        }
        int startNode = 1;
        double startProb = 1.0;
        dfs(time, startNode, startProb);

        double finalP = -1.0;
        int finalNode = 0;

        for(int i=1; i<=nodes; i++){
            if(answer[i]>finalP) {
                finalP = answer[i];
                finalNode = i;
            }
        }
        cout<<finalP<<endl;

        printf("Case %d: %d %f\n", t, finalNode, finalP);
//        cout<<fixed<<setprecision(6);
//        cout<<"Case "<<t<<": "<<finalNode<<" "<<finalP<<endl;
    }
    return 0;
}
