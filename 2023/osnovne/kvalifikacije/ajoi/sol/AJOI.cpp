#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ans[n]; //1 zlato 2 srebro 3 bronza 4 nista
	int broj[n];
	vector<pair<int,int> >v;
	for(int i=0;i<n;i++){
		int x1,x2,x3,x4,x5,x6;
		cin>>x1>>x2>>x3>>x4>>x5>>x6;
		v.push_back({x1+x2+x3+x4+x5+x6,i});
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	int s1=n/12;
	if(n%12!=0){
		s1++;
	}
	int s2=n/4;
	if(n%4!=0){
		s2++;
	}
	int s3=n/2;
	if(n%2!=0){
		s3++;
	}
	int t1=0;
	for(int i=0;i<n;i++){
		broj[v[i].second]=v[i].first;
	}
	for(int i=0;i<n;i++){
		if(i<s1){
			ans[v[i].second]=1;
			t1++;
		}
		if(i>=s1){
			if(v[i].first==v[i-1].first){
				ans[v[i].second]=1;
				t1++;
			}else{
				break;
			}
		}
	}
	for(int i=t1;i<n;i++){
			if(i<s2){
			ans[v[i].second]=2;
			t1++;
		}
		if(i>=s2){
			if(v[i].first==v[i-1].first){
				ans[v[i].second]=2;
				t1++;
			}else{
				break;
			}
		}
	}
	for(int i=t1;i<n;i++){
			if(i<s3){
			ans[v[i].second]=3;
			t1++;
		}
		if(i>=s3){
			if(v[i].first==v[i-1].first){
				ans[v[i].second]=3;
				t1++;
			}else{
				break;
			}
		}
	}
		for(int i=t1;i<n;i++){
		ans[v[i].second]=4;
	}
	for(int i=0;i<n;i++){
		cout<<"Ucenik"<<" "<<i+1<<":";

		if(ans[i]==4){
			cout<<"NE"<<endl;
		}else{
			cout<<"DA"<<" ";
			if(ans[i]==1){
				cout<<"zlato"<<endl;
			}else if(ans[i]==2){
				cout<<"srebro"<<endl;
			}else{
				cout<<"bronza"<<endl;
			}
		}
	}
}
