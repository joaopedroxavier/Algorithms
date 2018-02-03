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

string s;

int main(){
  ios_base::sync_with_stdio(false);
  cin >> s;

  int ans = INF;
  for(char p='a'; p<='z'; p++) if(s.find(p) != string::npos) {
    int ma = 0, last = 0, first = 0;
    for(int i=0; i<(int)s.size(); i++) {
      if(s[i] == p) {
        if(!first) first = i + 1;
        ma = max(ma, i - last), last = i;
      }
    }
    ma = max(ma, first);
    ma = max(ma, (int) s.size() - last);
    ans = min(ans, ma);
  }

  printf("%d\n", ans);

  return 0;
}

