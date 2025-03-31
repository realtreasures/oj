#include<iostream>
#include<set>
#include<cmath>
struct node{
    float k,b;
} nodes[100005];
using namespace std;
int main(){
    //存直线
    set<pair<float,float>> lines;
    

    //答案
    int ans=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        float a;
        float b;
        cin>>a>>b;
        lines.insert({a,b});
    }

    //坐标
    int m=0;
    for(auto it=lines.begin();it!=lines.end();it++){
        nodes[m++]={(*it).first,(*it).second};
    }
    for(int i=0;i<m;i++){
        //存交点
        set<pair<double,double>> points;

        for(int j=0;j<i;j++){
            float k1=nodes[i].k;
            float b1=nodes[i].b;
            float k2=nodes[j].k;
            float b2=nodes[j].b;
            if(k1!=k2){
                double x=(double)((b2-b1)*1.0)/((k1-k2)*1.0);
                double y=k1*(x*1.0)+b1;
                points.insert({x,y});
            }
        }
        ans+=(points.size()+1);
    }
    cout<<ans+1<<endl;
}