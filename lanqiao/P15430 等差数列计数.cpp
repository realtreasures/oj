#include<iostream>

using namespace std;

int main(){
    int i=1;
    int ans=0;
    for(;i<=2025;i++){
        for(int step=1;;step++){
            if(i+step*2<=2025){
                ans++;
            }
            else{
                break;
            }
        }
    }
    ans*=2;
    cout<<ans<<endl;
    return 0;
}