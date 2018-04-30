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

char flag[N][N];
int n, m;

bool check(int x0, int y0, int x1, int y1){
  for(int i=x0;i<=x1;++i) for(int j=y0;j<=y1;++j) if(flag[i][j] != flag[x0][y0]) return false;
  return true;
}

bool threeused(int hor){
  if(hor) return (flag[0][0] != flag[n/3][0]) and (flag[0][0] != flag[2*(n/3)][0]) and (flag[n/3][0] != flag[2*(n/3)][0]);
  else return (flag[0][0] != flag[0][m/3]) and (flag[0][0] != flag[0][2*(m/3)]) and (flag[0][m/3] != flag[0][2*(m/3)]);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin >> flag[i][j];
  if(n%3 == 0){
    if(check(0, 0, n/3-1, m-1) and check(n/3, 0, 2*(n/3)-1, m-1) and check(2*(n/3), 0, n-1, m-1) and threeused(1)){
      cout << "YES" << endl;
      return 0;
    }
  }
  if(m%3 == 0){
    if(check(0, 0, n-1, m/3-1) and check(0, m/3, n-1, 2*(m/3)-1) and check(0, 2*(m/3), n-1, m-1) and threeused(0)){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}

