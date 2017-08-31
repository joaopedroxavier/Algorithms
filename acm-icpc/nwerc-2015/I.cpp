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

pair<ll, ll> coord;

void doIT(ll n, char c){
  if(c == '0') return;
  if(c == '1') coord.first += n/2;
  if(c == '2') coord.second += n/2;
  if(c == '3') coord.first += n/2, coord.second += n/2;
}

int main(){
  string s;
  cin >> s;
  ll n = (1 << (s.size()));
  for(char c : s) doIT(n, c), n /= 2;
  cout << s.size() _ coord.first _ coord.second << endl;
	return 0;
}

