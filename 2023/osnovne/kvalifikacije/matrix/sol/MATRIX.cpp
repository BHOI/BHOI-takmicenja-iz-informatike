#include <iostream>
#include <vector>
using namespace std;
int main() {

 int n,m;
 cin>>n>>m;
 long long int k;
 cin>>k;
 vector< std::vector<long long int> >matrica(n, std::vector<long long int>(m) );
vector< std::vector<long long int> >sum1(n, std::vector<long long int>(m) );
vector< std::vector<long long int> >sum2(m, std::vector<long long int>(n) );
vector< std::vector<long long int> >pref1(n, std::vector<long long int>(m) );
 vector< std::vector<long long int> >pref2(m, std::vector<long long int>(n) );
 long long int res=0;
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
       cin>>matrica[i][j];
       if(j==0){
          sum1[i][j]=matrica[i][j];
       }else{
          sum1[i][j]=sum1[i][j-1]+matrica[i][j];
       }
       if(i==0){
          pref1[i][j]=sum1[i][j];
       }else{
          pref1[i][j]=pref1[i-1][j]+sum1[i][j];
       }
    }
 }
 for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
       if(j==0){
          sum2[i][j]=matrica[j][i];
       }else{
          sum2[i][j]=sum2[i][j-1]+matrica[j][i];
       }
       if(i==0){
          pref2[i][j]=sum2[i][j];
       }else{
          pref2[i][j]=pref2[i-1][j]+sum2[i][j];
       }
    }
 }
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      
          int l=1;
          int r=min(n-i,m-j);
      long long     int ans=min(n,m)+1;
          while(l<=r){
            long long  int mid=l+(r-l)/2;
           // cout<<mid<<endl;
             int x=i+mid-1;
             int y=j+mid-1;
          long long int mid1=mid*mid;
          long long int k1=k*mid1;
             int t1=0;
             if(y>=m or x>=n){
                t1++;
             }else{
                long long int sum1=0;
             long long int sum=pref1[x][y];
             if(i>0){
                sum=sum-pref1[i-1][y];
             }
             if(j>0){
            sum1=pref2[j-1][x];
            if(i>0){
               sum1=sum1-pref2[j-1][i-1];
            }
             }
             sum=sum-sum1;
             if(sum<k1){
                t1++;
             }
             }
             if(t1>0){
                l=mid+1;
             }else{
                ans=min(ans,mid);
                r=mid-1;
             }
            
          }
          if(ans!=(min(n,m)+1)){
          res=res+min(n-i,m-j)-ans+1;
          }
        //  cout<<res<<" "<<i<<" "<<j<<" "<<ans<<endl;
       }
    }
    cout<<res<<endl;
 }
 
