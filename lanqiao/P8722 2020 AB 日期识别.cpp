#include<bits/stdc++.h>

using namespace std;

//识别月份，并返回整数表示
int identification(string s){
    if(s=="Jan")
    return 1;
    else if(s=="Feb")
    return 2;
    else if(s=="Mar")
    return 3;
    else if(s=="Apr")
    return 4;
    else if(s=="May")
    return 5;
    else if(s=="Jun")
    return 6;
    else if(s=="Jul")
    return 7;
    else if(s=="Aug")
    return 8;
    else if(s=="Sep")
    return 9;
    else if(s=="Oct")
    return 10;
    else if(s=="Nov")
    return 11;
    else
    return 12;
}

//求天数
int computerday(string day){
    int a=day[0]-'0';
    int b=day[1]-'0';
    return a*10+b;
}
int main(){
    string s;
    cin>>s;
    int len;
    len=s.size();
    string day=s.substr(len-2);
    string month=s.substr(0,len-2);
    cout<<identification(month)<<' '<<computerday(day)<<endl;
    return 0;
}
