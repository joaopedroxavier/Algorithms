//
//
//
//
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const ld EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

string grid[5];

int dist(int x1, int y1, int x2, int y2){
	return abs(y2 - y1) + abs(x2 - x1);
}

ii avg(int x1, int y1, int x2, int y2){
	return mp((x1+x2)/2, (y1+y2)/2);
}

ii next(int x1, int y1, int x2, int y2){
	return mp(x2+abs(x2-x1), y2+abs(y2-y1));
}

bool ans = false;

int main(){
	ios::sync_with_stdio(false);
	for(int i=0;i<4;++i) cin >> grid[i];
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			if(grid[i][j] == 'x'){
				if(i<2){
					if(grid[i+1][j] == 'x' and grid[i+2][j] == '.') ans = true; 
					if(grid[i+1][j] == '.' and grid[i+2][j] == 'x') ans = true; 
					if(j<2){									
						if(grid[i+1][j+1] == '.' and grid[i+2][j+2] == 'x') ans = true; 
						if(grid[i+1][j+1] == 'x' and grid[i+2][j+2] == '.') ans = true;
					}
					else{
						if(grid[i+1][j-1] == 'x' and grid[i+2][j-2] == '.') ans = true;
						if(grid[i+1][j-1] == '.' and grid[i+2][j-2] == 'x') ans = true;
					}
				}
				if(j<2){
					if(grid[i][j+1] == 'x' and grid[i][j+2] == '.') ans = true; 
					if(grid[i][j+1] == '.' and grid[i][j+2] == 'x') ans = true; 
					if(i<2){
						if(grid[i+1][j+1] == '.' and grid[i+2][j+2] == 'x') ans = true; 
						if(grid[i+1][j+1] == 'x' and grid[i+2][j+2] == '.') ans = true;
					}
					if(i>=2){
						if(grid[i-1][j+1] == 'x' and grid[i-2][j+2] == '.') ans = true;
						if(grid[i-1][j+1] == '.' and grid[i-2][j+2] == 'x') ans = true;
					}
				}
				if(j>=2){
					if(grid[i][j-1] == 'x' and grid[i][j-2] == '.') ans = true; 
					if(grid[i][j-1] == '.' and grid[i][j-2] == 'x') ans = true;
					if(i<2){
						if(grid[i+1][j-1] == '.' and grid[i+2][j-2] == 'x') ans = true; 
						if(grid[i+1][j-1] == 'x' and grid[i+2][j-2] == '.') ans = true;
					}
					else{
						if(grid[i-1][j-1] == 'x' and grid[i-2][j-2] == '.') ans = true;
						if(grid[i-1][j-1] == '.' and grid[i-2][j-2] == 'x') ans = true;
					}
				}
				if(i>=2){
					if(grid[i-1][j] == 'x' and grid[i-2][j] == '.') ans = true; 
					if(grid[i-1][j] == '.' and grid[i-2][j] == 'x') ans = true;
					if(j<2){
						if(grid[i-1][j-1] == '.' and grid[i-2][j-2] == 'x') ans = true; 
						if(grid[i-1][j-1] == 'x' and grid[i-2][j-2] == '.') ans = true;
					}
					else{
						if(grid[i-1][j-1] == 'x' and grid[i-2][j-2] == '.') ans = true;
						if(grid[i-1][j-1] == '.' and grid[i-2][j-2] == 'x') ans = true;
					}
				}
			}
		}
	}
	cout << ((ans) ? "YES" : "NO") << endl;
	return 0;
}

