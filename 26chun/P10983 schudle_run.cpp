#include<iostream>

using namespace std;

int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int ans=0;
    int weekday=3;
    for(int i=1;i<=12;i++){
        for(int j=1;j<=mon[i];j++){
            if(i%10==1||i/10==1){
                ans+=5;
            }
            else if(j%10==1||j/10==1){
                ans+=5;
                
            }
            else if(weekday==1){
                ans+=5;
            }
            else{
                ans+=1;
            }
            weekday=(weekday+1)%7;
        }
    }
    cout<<ans<<endl;
    return 0;
}