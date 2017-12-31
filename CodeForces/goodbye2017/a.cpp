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

bool vowel(char c) { return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'; }
bool number(char c) { return c <= '9' and c >= '0'; }

int main(){
  cin >> s;
  int ans = 0;
  for(char c : s) {
    ans += (vowel(c) or (number(c) and (c-'0')%2 == 1));
  }
  cout << ans << endl;

	return 0;
}

