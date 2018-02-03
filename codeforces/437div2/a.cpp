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

int n; string s;
int fl[2];

int main(){
  cin >> n >> s;

  char cur = s[0];
  for(char c : s) {
    if(c != cur) {
      if(cur == 'F' and c == 'S') fl[0]++;
      else fl[1]++;
    }
    cur = c;
  }

  printf("%s\n", fl[1] > fl[0] ? "YES" : "NO");

	return 0;
}

