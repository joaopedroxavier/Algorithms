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

string st;
int k;

bool check(int l, int r) {
  string s, t;
  for(int i=l; i<=r; i++) {
    s = s + st[i];
    t = t + st[i];
  }

  reverse(s.begin(), s.end());
  return s == t;
}

int main(){
  cin >> st >> k;

  bool ans = true; int n = (int) st.size();
  if(n % k != 0) return cout << "NO" << endl, 0;

  k = n/k;
  for(int i=0; i+k <= n; i+=k) {
    ans = ans and check(i, i+k-1);
  }

  cout << (ans ? "YES" : "NO") << endl;

	return 0;
}

