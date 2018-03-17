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

vector<string> ball;
map<string, int> val;
int n, reds;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  val["red"]    = 1;
  val["yellow"] = 2;
  val["green"]  = 3;
  val["brown"]  = 4;
  val["blue"]   = 5;
  val["pink"]   = 6;
  val["black"]  = 7;

  cin >> n;
  for(int i=0; i<n; i++) {
    string s;
    cin >> s;
    if(s == "red") reds++;
    else ball.push_back(s);
  }

  sort(ball.begin(), ball.end(), [](string a, string b){ return val[a] > val[b]; });

  if(ball.empty()) return cout << 1 << endl, 0;

  int sum = 0;
  for(string s : ball) {
    sum += val[s];
  }

  int ans = reds + reds * val[ball[0]] + sum;

  cout << ans << endl;
	return 0;
}

