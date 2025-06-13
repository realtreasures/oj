#include<bits/stdc++.h>
using namespace std;
int s,m,t,fla,step;
int main(){
	cin>>m>>s>>t;
	for(int i=1;i<=t;i++){
		if(m>=10){
			m-=10;
			fla+=60;
			step+=17;
		}
		else{
			if(fla>step){
				step=fla;
			}
			step+=17;
			m+=4;
		}
		if(max(step,fla)>=s){
			cout<<"Yes"<<endl<<i<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl<<max(fla,step)<<endl;
	return 0;
}