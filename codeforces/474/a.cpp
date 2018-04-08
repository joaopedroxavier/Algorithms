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

int a, b, c;
string s, t;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  cin >> s;
  t = s;
  sort(t.begin(), t.end());
  if(s != t) return printf("NO\n"), 0;

  for(char p : s) {
    if(p == 'a') a++;
    if(p == 'b') b++;
    if(p == 'c') c++;
  }

  cout << (((a and b) and (a == c or b == c)) ? "YES" : "NO") << endl;
	return 0;
}

