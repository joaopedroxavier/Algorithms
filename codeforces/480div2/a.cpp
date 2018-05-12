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

string s;
int cntl, cntp;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  cin >> s;
  for(char c : s) {
    if(c == '-') cntl++;
    else cntp++;
  }

  if(cntp == 0 or cntl % cntp == 0) printf("YES\n");
  else printf("NO\n");

	return 0;
}

