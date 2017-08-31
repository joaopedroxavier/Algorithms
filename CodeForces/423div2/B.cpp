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

int main(){
	ios_base::sync_with_stdio(false);
  int n, m, ans = 0;
  char sheet[N][N];
  bool onlyWhite = true;

  cin >> n >> m;
  int up = n, down = 0, left = m, right = 0;
  for(int i=0;i<n;++i) for(int j=0;j<m;++j){
    cin >> sheet[i][j];
    if(sheet[i][j] == 'B'){
      onlyWhite = false;
      up = min(up, i), down = max(down, i);
      left = min(left, j), right = max(right, j);
    }
  }

  if(onlyWhite){ cout << 1 << endl; return 0; }

  for(int i=up;i<=down;++i) for(int j=left;j<=right;++j) ans += (sheet[i][j] == 'W');

  if(right-left > down-up){
    int comp = right-left - (down-up);
    if(n-1-down+up >= comp) ans += (right-left+1)*comp; 
    else ans = -1;
  }
  if(down-up > right-left){
    int comp = down-up - (right-left);
    if(m-1-right+left >= comp) ans += (down-up+1)*comp;
    else ans = -1;
  }

  cout << ans << endl;
	return 0;
}
