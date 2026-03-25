#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int s=20230610,t=1,sum;
int main(){
	while(sum+(1+t)*t/2<s) sum+=(1+t)*t/2,t++;
	cout<<t-1;//最后答案会比实际的高度大1，所以要减去1
}
