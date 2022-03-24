#include <bits/stdc++.h>
using namespace std;

// for set,map and heap we use function call operator loading

//6,4,3,2
//Last element in container will be the top element of heap
class custom{
    public:
    bool operator()(const int &a, const int &b){
        
        if(a>b)return true; // Min heap comparision because min element will be in the last
        
        return false;
    }
};
int main(){

	priority_queue<int,vector<int>,custom>pq;
    
    pq.push(2);
    pq.push(4);
    pq.push(3);
    pq.push(6);
    
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
