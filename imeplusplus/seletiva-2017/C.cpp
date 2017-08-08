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
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int cnt[N];
int n, a, m;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n >> a;
  for(int i=0;i<n;++i){
    int u;
    cin >> u;
    if(cnt[u] >= cnt[a]) cnt[u]++;
    if(cnt[a] > cnt[m]){ cout << -1 << endl; return 0; }
    else if(cnt[u] > cnt[m]) m = u;
  }
  cout << m << endl;
	return 0;
}

