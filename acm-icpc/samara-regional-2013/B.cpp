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

long double e;
map<char, long double> qt;
string s;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> s;
  for(char c : s) qt[c]++;
  for(auto it : qt) e += it.second * it.second;
  e /= (long double) s.size();
  printf("%.12lf\n", (double) e);
	return 0;
}
