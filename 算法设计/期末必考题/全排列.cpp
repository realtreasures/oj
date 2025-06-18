#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr={2,1,6};
    sort(arr.begin(),arr.end());
    int i=0;
    do{
        cout<<i++<<endl;
    }while(next_permutation(arr.begin(),arr.end()));
    return 0;
}