#include<bits/stdc++.h>
using namespace std;
int m,s,t,fla,run;//分别代表闪现距离，跑步距离
int main(){
	cin>>m>>s>>t;//读入; 
	for(int i=1;i<=t;i++){//时间; 
		
		if(m>=10)m-=10,fla+=60,run+=17;//蓝够了就闪,另一边跑步;
		else{if(fla>run)run=fla;//在最优的基础上跑; 
			m+=4,run+=17;}//回蓝,另一边跑步; 

		if(max(fla,run)>=s){
			printf("Yes\n%d\n",i);return 0;} //出去了 
	}
	cout<<"No"<<endl<<max(fla,run)<<endl;//没出去 
	return 0;
}