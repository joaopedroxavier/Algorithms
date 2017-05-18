//
//
//
//
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e6;

int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};
char x[] = {'a','b','c','d','e','f','g','h'};
int t[12][12];
int main(){
		queue<ii> bfs;
		int x1,x2,y1,y2,n;
		char a,b;
		cin >> n;
		for(int k=0;k<n;++k){
			memset(t,0,sizeof(t));
			scanf(" %c%d %c%d", &a,&y1,&b,&y2);
			x1 = a-'a'+2;
			x2 = b-'a'+2;
			y1 = y1+1;
			y2 = y2+1;
			for(int i=0;i<2;++i)	for(int j=0;j<12;++j)	t[i][j] = 1;
			for(int i=0;i<2;++i)	for(int j=0;j<12;++j) t[j][i] = 1;
			for(int i=10;i<12;++i)	for(int j=0;j<12;++j) t[i][j] = 1;
			for(int i=10;i<12;++i)	for(int j=0;j<12;++j) t[j][i] = 1;
			bfs.push(mp(x1,y1));
			t[x1][y1] = 1;
			while(!bfs.empty()){
				ii u = bfs.front();
				if(u.first==x2 and u.second==y2) break;
				for(int i=0;i<8;++i){
					if(!t[u.first+dx[i]][u.second+dy[i]]){
						bfs.push(mp(u.first+dx[i],u.second+dy[i]));
						t[u.first+dx[i]][u.second+dy[i]] = 1+t[u.first][u.second];
					}
				}
				bfs.pop();
			}
			while(!bfs.empty()) bfs.pop();
			cout << t[x2][y2]-1 << endl;
		}
		return 0;
}

