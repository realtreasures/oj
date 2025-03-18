#include<bits/stdc++.h>
using namespace std;

//读取函数
int readtime(){
    int h1,h2,m1,m2,s1,s2;
    int day=0;
    scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
    if(getchar()==' ')
        scanf("(+%d)",&day);
    return ((day*86400+h2*3600+m2*60+s2)-(h1*3600+m1*60+s1));
}
int main(){
    int n;//记录个数
    cin>>n;
    for(int i=0;i<n;i++){
        int time=(readtime()+readtime())/2;
        printf("%02d:%02d:%02d\n",time/3600,time%3600/60,time%60);
    }
    return 0;
}
