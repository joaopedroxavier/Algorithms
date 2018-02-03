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
const int N=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m, bell[N][N];
map<ll, int> sz;
string s[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> m >> n;
  for(int i=0; i<n; i++) {
    cin >> s[i];
  }

  bell[1][1] = 1;
  for(int i=2; i<=m; i++) {
    bell[i][1] = bell[i-1][i-1];
    for(int j=2; j<=i; j++) {
      bell[i][j] = (bell[i][j-1] + bell[i-1][j-1]) % MOD;
    }
  }

  for(int j=0; j<m; j++) {
    ll mask = 0;
    for(int i=0; i<n; i++) if(s[i][j] == '1') mask |= ((ll)1<<i);
    sz[mask]++;
  }

  ll ans = 1;
  for(auto it : sz) {
    ll cnt = it.second;
    ans = (ans * bell[cnt][cnt]) % MOD;
  }

  cout << ans << endl;

	return 0;
}

