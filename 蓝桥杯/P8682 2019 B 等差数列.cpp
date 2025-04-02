#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
//求最大公因数
int f(int x,int y){
	int r = x % y;
	while (r != 0) {
		x = y;
		y = r;
		r = x % y;
	}
    return y;
}
int main(){
    ll n;
    cin>>n;
    vector<int> arr(n);
    for(auto &it:arr){
        cin>>it;
    }
    int ele_max=arr[0];
    int min_val=arr[0];
    int max_val=arr[0];
    for(int i=1;i<n;i++){
        if(min_val>arr[i]){
            min_val=arr[i];
        }
        if(max_val<arr[i]){
            max_val=arr[i];
        }
        ele_max=f(arr[i],ele_max);
    }
    int ans=(max_val-min_val)/ele_max;
    cout<<ans+1<<endl;
    return 0;
}