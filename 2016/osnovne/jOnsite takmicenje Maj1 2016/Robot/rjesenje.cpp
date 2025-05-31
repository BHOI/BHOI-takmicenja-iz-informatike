#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<fstream>
#include<utility>

using namespace std;

#define mp make_pair
#define pb push_back
#define	xx first
#define yy second

const int INF = 1 << 29;
typedef long long lint;
typedef pair < int, int > tacka;

set<pair<int,int> >stones;
map<char,pair<int,int> > dir;

int main ()
{
    dir['S']=make_pair(-1,0);
    dir['Z']=make_pair(0,-1);
    dir['J']=make_pair(1,0);
    dir['I']=make_pair(0,1);
    ios_base::sync_with_stdio(false);
    int gridSize;
    cin>>gridSize;
    int numStones;
    cin>>numStones;
    int a,b;
    for(int i=0;i<numStones;i++){
        cin>>a>>b;
        stones.insert(make_pair(a,b));
    }
    pair<int,int> loc;
    cin>>loc.first>>loc.second;
    char where;
    int amount;
    int result=0;
    while(true){
        cin>>where>>amount;
        if(where=='K')break;
        for(int i=0;i<amount;i++){
            loc.first+=dir[where].first;
            loc.second+=dir[where].second;
            if(loc.first<1)loc.first=1;
            if(loc.first>gridSize)loc.first=gridSize;
            if(loc.second<1)loc.second=1;
            if(loc.second>gridSize)loc.second=gridSize;
            if(stones.count(loc)){
                result++;
                stones.erase(stones.find(loc));
            }
        }
    }
    cout<<result<<endl;
	return 0;
}
