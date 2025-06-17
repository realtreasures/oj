#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    vector<int> x;
    for(int i=0;i<=5;i++){
        x.push_back(i);
    }
    for(auto it:x){
        cout<<it<<endl;
    }
    cout<<(lower_bound(x.begin(),x.end(),4)-x.begin())<<(upper_bound(x.begin(),x.end(),4)-x.begin())<<endl;
    return 0;
}