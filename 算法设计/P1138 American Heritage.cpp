
//给出前序和中序遍历，求后序遍历
#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef struct node{
    char c;//保存奶牛编号
    struct node* left;
    struct node* right;
}node,*Bitree;

//递归函数
void Post_list(vector<int> root,string mid_list,Bitree t,int r,int start,int end){
    t->c=mid_list[root[r]];
    Post_list(root,mid_list,t->left,++r,start,root[r]-1);
    Post_list(root,mid_list,t->right,)

}

int main(){
    Bitree t;
    vector<int> root(10000);
    string pre_list,mid_list;
    cin>>pre_list>>mid_list;
    t=new node;
    
    for(int i=0;i<pre_list.length();i++){
        int r=mid_list.find(pre_list[i]);
        root[i]=r;
    }
}