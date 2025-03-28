#include<iostream>
#include<set>

using namespace std;
int main(){
    //存直线
    set<pair<int,int>> lines;
    //存交点
    set<pair<double,double>> points;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        int b;
        cin>>a>>b;
        lines.insert({a,b});
    }
    auto it=lines.begin();    
    for(;it != lines.end();it++){
        for(auto it2=next(it);it2!=lines.end();it2++){
            int k1=it->first;
            int b1=it->second;
            int k2=it2->first;
            int b2=it2->second;
            if(k1!=k2){
                double x=(double)((b2-b1)*1.0)/((k1-k2)*1.0);
                double y=k1*(x*1.0)+b1;
                points.insert({x,y});
            }
        }
    }
    int num_l=lines.size();
    int num_p=points.size();
    cout<<lines.size()<<points.size()<<endl;
    cout<<num_l+num_p<<endl;
}