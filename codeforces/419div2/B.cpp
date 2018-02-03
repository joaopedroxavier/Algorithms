#include <bits/stdc++.h>

using namespace std;

//dale
#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll temp[N], admiss[N];
ll n, k, q;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n >> k >> q;
  for(int i=0;i<n;++i){
    int u, v;
    cin >> u >> v;
    temp[u]++, temp[v+1]--;
  }
  for(int i=1;i<N;++i) temp[i] += temp[i-1];
  for(int i=1;i<N;++i) if(temp[i] >= k) admiss[i] = 1;
  for(int i=1;i<N;++i) admiss[i] += admiss[i-1];

  for(int i=0;i<q;++i){
    int u, v;
    cin >> u >> v;
    cout << admiss[v] - admiss[u-1] << endl;
  }
	return 0;
}

