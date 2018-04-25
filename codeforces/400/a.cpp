#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

string cand1, cand2;
int n;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> cand1 >> cand2;
  cin >> n;

  cout << cand1 << " " << cand2 << endl;
  for(int i=0; i<n; i++) {
    string s, t;
    cin >> s >> t;
    if(s == cand1) cand1 = t;
    else cand2 = t;
    cout << cand1 << " " << cand2 << endl;;
  }

	return 0;
}

