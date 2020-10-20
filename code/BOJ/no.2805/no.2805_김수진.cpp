#include<iostream>
#include<vector>
#include<algorithm>

//2805 

using namespace std;

int N, M;
vector<long long> tree;
long long res = 0;

long long bs(long long start, long long end){
    if(start>end)
        return res;
    long long mid = (start+end) /2;
    
    long long sum = 0;
    for(int i=00; i<tree.size(); i++){
        if(tree[i]>mid)
            sum += (tree[i]-mid);
    }
    if(sum >= M){
        start = mid +1;
        res = max(res,mid);
    }else
    {
        end = mid-1;
    }
    return bs(start,end);

}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int a; 
        cin >> a;
        tree.push_back(a);
    }
    sort(tree.rbegin(), tree.rend());
    int mx = tree[0];
    
    long long answer = bs(0,mx);

    cout << answer;
}
