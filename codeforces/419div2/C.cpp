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
const int N=1e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int grid[N][N];
int grid2[N][N];
int modrow[N];
int n, m;
vi row, col;
bool flag;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n >> m;
  if(m < n) flag = true, swap(n, m);
  if(flag) for(int j=1;j<=m;++j) for(int i=1;i<=n;++i){
    cin >> grid[i][j];
  }
  else for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
    cin >> grid[i][j];
  }

  //row
  for(int i=1;i<=n;++i){
    int num = INF;
    for(int j=1;j<=m;++j) num = min(num, grid[i][j]);
    if(num > 0){
      modrow[i] = num;
      for(int k=0;k<num;++k) row.pb(i);
    }
    for(int j=1;j<=m;++j) grid2[i][j] += num;
  }
  //column
  for(int j=1;j<=m;++j){
    int num = INF;
    for(int i=1;i<=n;++i){
      num = min(num, grid[i][j] - modrow[i]);
    }
    if(num > 0){
      for(int k=0;k<num;++k) col.pb(j);
      for(int i=1;i<=n;++i) grid2[i][j] += num;
    }
  }
  //check
  bool ans = true;
  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
//      cout << grid2[i][j] << ' ';
      if(grid[i][j] != grid2[i][j]) ans = false;
    }
//    cout << endl;
  }

  if(!ans) cout << -1 << endl;
  else{
    cout << row.size() + col.size() << endl;
    for(int i : row) cout << ((!flag) ? "row " : "col ") << i << endl;
    for(int j : col) cout << ((!flag) ? "col " : "row ") << j << endl;
  }
	return 0;
}

