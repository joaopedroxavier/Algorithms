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

int n, ans;
int one[N], zero[N], b[N];
map<int, int> pref;
string s;

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n;
  cin >> s;

  int i=1;
  pref[0] = 0;
  for(char c : s) {
    one[i] = one[i-1] + (c == '1');
    zero[i] = zero[i-1] + (c == '0');
    b[i] = one[i] - zero[i];

    if(!pref.count(b[i])) pref[b[i]] = i;
    else ans = max(ans, i - pref[b[i]]);

    i++;
  }

  printf("%d\n", ans);
	return 0;
}

