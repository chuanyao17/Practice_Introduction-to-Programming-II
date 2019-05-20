#include <iostream>


using namespace std;
class Node{
public:
    int latency;
    int bandwidth;
    bool exist;
    bool existBand;

    Node():latency(0),bandwidth(0),exist(false),existBand(false){}
friend class buildings;
};
class buildings{
public:
    int numofBuildings;
    Node** input;
    int** check;
    Node* output;
    int* waitList;

    buildings(int n){
        numofBuildings = n;
        input = new Node*[n];
        check = new int*[n];
        output = new Node[n];
        waitList = new int[n];
        for(int i=0;i<n;i++){
            input[i]= new Node[n];
            check[i]= new int[n];
        }
        for(int i=0;i<n;i++){
            output[i].latency=0;
            output[i].bandwidth=0;
            output[i].exist=false;
            output[i].existBand=false;
            waitList[i]=0;
            for(int j=0;j<n;j++){
                input[i][j].bandwidth=0;
                input[i][j].latency=0;
                check[i][j]=0;
            }
        }
    }
    ~buildings(){
        for(int i=0;i<numofBuildings;i++){
            delete []input[i];
            delete []check[i];
        }
        delete []input;
        delete []check;
        delete []output;
        delete []waitList;
        numofBuildings=0;
    }
    void runcheck(){
        int vertex=0;
        int c=0;
        output[0].exist=true;
        while(true){
            for(int i=1;i<=check[vertex][0];i++){
                int dest=check[vertex][i];
                if(!output[dest].exist){
                    waitList[c++]=dest;
                }
                int addPoint=output[vertex].latency+input[vertex][dest].latency;
                if(!output[dest].exist){
                   output[dest].latency=addPoint;
                   output[dest].exist=true;
                }
                else{
                    if(output[dest].latency>addPoint){
                        output[dest].latency=addPoint;
                    }
                }
            }
            if(c==0)break;
            else{
                int mini=output[waitList[0]].latency;
                int pick=0;
                for(int i=1;i<c;i++){
                    if(output[waitList[i]].latency<mini){
                        mini=output[waitList[i]].latency;
                        pick=i;
                    }
                }
                vertex=waitList[pick];
                for(int i=pick;i<c-1;i++){
                    waitList[i]=waitList[i+1];
                }
                c--;
            }
        }
        vertex=0;
        output[0].existBand=true;
        while(true){
            for(int i=1;i<=check[vertex][0];i++){
                int dest=check[vertex][i];
                if(!output[dest].existBand){
                    waitList[c++]=dest;
                }
                int addPoint2;
                if(vertex!=0){
                    if(input[vertex][dest].bandwidth>output[vertex].bandwidth)addPoint2=output[vertex].bandwidth;
                    else addPoint2=input[vertex][dest].bandwidth;
                }
                if(vertex==0){
                    output[dest].bandwidth=input[vertex][dest].bandwidth;
                    output[dest].existBand=true;
                }
                else if(!output[dest].existBand){
                   output[dest].bandwidth=addPoint2;
                   output[dest].existBand=true;
                }
                else{
                    if(output[dest].bandwidth<addPoint2){
                        output[dest].bandwidth=addPoint2;
                    }
                }
            }
            if(c==0)break;
            else{
                int maxi=output[waitList[0]].bandwidth;
                int pick=0;
                for(int i=1;i<c;i++){
                    if(output[waitList[i]].bandwidth>maxi){
                        maxi=output[waitList[i]].bandwidth;
                        pick=i;
                    }
                }
                vertex=waitList[pick];
                for(int i=pick;i<c-1;i++){
                    waitList[i]=waitList[i+1];
                }
                c--;
            }
        }
    }
};

int main()
{
    int n,m, source, destination, minLatency, maxBandwith;
    int i;
    cin >> n >> m;
    if(n<2)return 0;
    buildings a(n);
    int count;
    for(i=0;i<m;i++){
        cin >> source >> destination >> minLatency >> maxBandwith;
        a.input[source][destination].latency = minLatency;
        a.input[source][destination].bandwidth = maxBandwith;
        count = ++a.check[source][0];
        a.check[source][count]=destination;
    }
    a.runcheck();
    for(i=1;i<n;i++){
        cout<<i<<" ";
        if(a.output[i].exist){
            cout<<a.output[i].latency;
        }
        else{
            cout<<"inf";
        }
        cout<<" ";
        if(a.output[i].existBand){
            cout<<a.output[i].bandwidth;
        }
        else{
            cout<<"0";
        }
        cout<<endl;
    }
    return 0;
}

