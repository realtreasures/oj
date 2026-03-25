#include<iostream>
using namespace std;

bool Is_run(int year){
    if(year%4==0&&year%100!=0||year%400==0){
        return true;
    }
    return false;
}

int month_run[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month_not_run[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    int weekday = 6;
    int ans = 0;
    for(int mo=6;mo<=12;mo++){
        for(int da=1;da<=month_run[mo];da++){
            weekday = (weekday+1)%7;
        }

    }
    for(int ye=2025;;ye++){
        if(Is_run(ye)){
            for(int mo=1;mo<=12;mo++){
                for(int da=1;da<=month_run[mo];da++){
                    
                    if(mo==6&&da==1&&weekday==6){
                        ans = ye;
                        break;
                    }
                    weekday = (weekday+1)%7;
                }
                if(ans!=0){
                    break;
                }
            }
        }
        else{
            for(int mo=1;mo<=12;mo++){
                for(int da=1;da<=month_not_run[mo];da++){
                    
                    if(mo==6&&da==1&&weekday==6){
                        ans = ye;
                        break;
                    }
                    weekday = (weekday+1)%7;
                }
                if(ans!=0){
                    break;
                }
            }
        }

        if(ans!=0){
            break;
        }
               
    }
    cout<<ans<<endl;
    return 0;
}