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

char c[N];
int n;

bool special(int p) {
  if(p >= n-2) return false;
  set<char> s;
  for(int i=0; i<3; i++) s.insert(c[p+i]);
  return s.size() == 3;
}

char counter(int p) {
  if(special(p)) return 'C';
  if(c[p] == 'R') return 'S';
  if(c[p] == 'B') return 'K';
  else return 'H';
}

int main(){
  scanf("%s", c);
  n = strlen(c);

  string ans;
  for(int i=0; i<n; i++) {
    ans += counter(i);
    if(special(i)) i += 2;
  }

  printf("%s\n", ans.c_str());

	return 0;
}

