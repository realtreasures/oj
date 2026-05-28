// #include<bits/stdc++.h>

// using namespace std;

// int a[30];

// int main(){
//     int k;
//     cin>>k;
//     memset(a,0,sizeof(a));
//     for(int m=k+1;;m++){
//         int count=1;
//         int flag=0;
//         bool ok=true;
//         for(int i=1;;){
//             if(!ok) break;
//             if(a[i]==1){
//                 i=(i+1)%(2*k);
//                 if(i==0){
//                     i=2*k;
//                 }
//                 continue;
//             }
//             if(count==m){
//                 if(i<=k){
//                     ok=false;
//                     break;
//                 }
//                 else{
//                     a[i]=1;
//                     count=0;
//                     flag++;
//                 }
//             }
//             if(flag==k){
//                 break;
//             }
//             count++;
//             i=(i+1)%(2*k);
//             if(i==0){
//                 i=2*k;
//             }
//         }
//         if(flag==k&&ok){
//             cout<<m<<endl;
//             break;
//         }
//         memset(a,0,sizeof(a));
//     }
//     return 0;


// }
//上面的超时了，下面的更简单

#include<bits/stdc++.h>

using namespace std;

int main(){

    int k;
    cin>>k;
   
    for(int m=k+1;;m++){
        int tide=0;
        int flag=1;
        for(int i=0;i<k;i++){
            tide=(tide+m-1)%(2*k-i);
            if(tide<k){
                break;
            }
            if(i==k-1){
                flag=0;
                break;
            } 
        }
        if(flag==0){
            cout<<m<<endl;
            break;
        }
    }
    return 0;
    

}