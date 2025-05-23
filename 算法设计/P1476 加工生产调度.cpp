#include<bits/stdc++.h>

using namespace std;

/*
你有 n 个产品，每个产品必须先在车间 A 加工，再在车间 B 加工。每个产品的在 A 和 B 的加工时间分别是 A[i], B[i]。
目标是找一个加工顺序，使得从第一个产品开始加工到最后一个产品在 B 车间也加工完的总时间最小。

将所有产品分成两组：
如果 A[i] <= B[i]，将产品 i 放到前面组。
如果 A[i] > B[i]，将产品 i 放到后面组。
对前面组按 A[i] 升序排列，对后面组按 B[i] 降序排列。
组合这两个排好序的组：前面组 + 后面组，即为最优加工顺序。

时间计算

遍历排序后的产品顺序，对每个产品：
A 车间处理当前任务，timeA += A[i]
B 车间等待 A 完成当前任务，然后开始处理：timeB = max(timeB, timeA) + B[i]
*/
int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    vector<int> B(n);
    vector<int> task_front;
    vector<int> task_end;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cin>>B[i];
    }

    for(int i=0;i<n;i++){
        if(A[i]<=B[i]){
            task_front.push_back(i);
        }
        else{
            task_end.push_back(i);
        }
    }
    sort(task_front.begin(),task_front.end(),[&](int i,int j){
        return A[i]<A[j];
    });

    sort(task_end.begin(),task_end.end(),[&](int i,int j){
        return B[i]>B[j];
    });

    //顺序合并
    vector<int> merged(n);
    int i=0;
    for(auto &it:task_front){
        merged[i++]=it;
    }
    for(auto &it:task_end){
        merged[i++]=it;
    }

    int timeA=0;
    int timeB=0;
    for(auto &it:merged){
        timeA+=A[it];
        timeB=max(timeA,timeB)+B[it];
    }
    cout<<timeB<<endl;
    return 0;

}