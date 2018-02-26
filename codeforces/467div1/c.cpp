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
const int N=2e3+5;
const int M=30;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n;
string s, t;


void shift(string &v, int k) {
  string a, b;

  for(int i=1; i<=k; i++) b.push_back(v[n-i]);
  for(int i=0; i<n-k; i++) a.push_back(v[i]);

  v.clear();
  for(char i : b) v.pb(i);
  for(char i : a) v.pb(i);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  cin >> s >> t;
  string auxs = s, auxt = t;

  sort(auxs.begin(), auxs.end());
  sort(auxt.begin(), auxt.end());

  if(auxs != auxt) return printf("-1\n"), 0;

  vector<int> ans;
  for(int i=1; i<=n; i++) if(s[n-i] == t[0]) {
    ans.pb(i-1);
    shift(s, i-1);
    break;
  }

  for(int p=1; p<n; p++) {
    for(int i=p+1; i<=n; i++) if(s[n-i] == t[p]) {
      ans.pb(i-1);
      shift(s, i-1);
      ans.pb(1);
      shift(s, 1);
      ans.pb(n);
      shift(s, n);
      break;
    }
  }

  cout << ans.size() << endl;
  for(auto p : ans) cout << p << " " ;
  cout << endl;

	return 0;
}

