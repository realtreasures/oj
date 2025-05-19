#include<bits/stdc++.h>

using namespace std;

//辗转相除求最大公约数
int gcd(int a,int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

}