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
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

map<int, stack<int>> m;
vi a, b;
int n;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i=0;i<n;i++){
    int u;
    cin >> u;
    a.pb(u);
  }
  for(int i=0;i<n;i++){
    int u;
    cin >> u;
    b.pb(u);
    m[u].push(i);
  }
  sort(a.begin(), a.end(), [](int p, int q){ return p > q; });
  vi c(n);
  for(int i=0;i<n;i++){
    auto it = m.begin();
    c[(it->second).top()] = a[i];
    (it->second).pop();
    if((it->second).empty()) m.erase(it);
  }
  for(int i : c) cout << i << ' ';
  cout << endl;
	return 0;
}

