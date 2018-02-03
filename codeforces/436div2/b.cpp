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

set<char> vowels;
string s;
int ans, n;

bool isUpper(char c) { return c <= 'Z' and c >= 'A' ; }

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  cin >> s;
  for(char c : s) {
    if(isUpper(c)) ans = max(ans, (int) vowels.size()), vowels.clear();
    else vowels.insert(c);
  }

  cout << max(ans, (int) vowels.size()) << endl;

	return 0;
}

