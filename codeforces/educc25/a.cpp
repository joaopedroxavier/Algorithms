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

string decode(string s) {
  string ans;
  int cnt=0;
  for(char c : s) {
    if(c == '0') {
      ans.push_back('0' + cnt);
      cnt = 0;
    }
    else cnt++;
  }
  ans.push_back('0' + cnt);
  return ans;
}

int n;
string s;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> s;
  cout << decode(s) << endl;
	return 0;
}

