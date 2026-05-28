

#include <bits/stdc++.h>
using namespace std;

struct node{
    double distance;
    double price;
};

double findmin(double s,vector<node> a,vector<double> dist_cha,int r, double l){
    
    if(r==0){
        return 0;
    }
    int pos;
    int min_price=INT_MAX;
    for(int i=0;i<=r;i++){
        if(a[i].price<min_price){
            min_price=a[i].price;
            pos=i;
        }
    }
    return findmin(s,a,dist_cha,pos,l)+((a[r].distance-a[pos].distance))/l*min_price;


}


int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定

    
    double s,c,l,p0;
    int n;
    cin>>s>>c>>l>>p0>>n;

    vector<node> city(n);
    for(int i=0;i<n;i++){
        cin>>city[i].distance>>city[i].price;
    }
    int max_dis=l*c;
    sort(city.begin(),city.end(),[](node a,node b){
        return a.distance<b.distance;
    });

    vector<double> dist_cha(n);
    for(int i=1;i<n;i++){
        dist_cha[i]=city[i].distance-city[i-1].distance;
        if(dist_cha[i]>max_dis){
            cout<<"No Solution"<<endl;
            return 0;
        }
    }
    cout<<findmin(s,city,dist_cha,n-1,l)<<endl;


    return 0;
}