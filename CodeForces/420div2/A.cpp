#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=5e1+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int grid[N][N];
bool good[N][N];
int n;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i=0;i<n;++i) for(int j=0;j<n;++j) cin >> grid[i][j];
  for(int i=0;i<n;++i) for(int j=0;j<n;++j){
    if(grid[i][j] == 1) good[i][j] = true;
    for(int x=0;x<n;++x) for(int y=0;y<n;++y){
      if(x == i and y == j) continue;
      else if(grid[i][y] + grid[x][j] == grid[i][j]) good[i][j] = true;
    }
  }
  bool ans = true;
  for(int i=0;i<n;++i) for(int j=0;j<n;++j) if(!good[i][j]) ans = false;
  cout << ((ans) ? "Yes" : "No") << endl;

	return 0;
}

