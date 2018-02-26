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
ll p[60];

set<string> variables;
set<string> v;

string neg(string s) {
  string ans;
  if(s[0] == '~') {
    ans = s[1];
  }
  else {
    ans = ans + '~';
    ans = ans + s[0];
  }
  return ans;
}

int main(){
  freopen("boolean.in", "r", stdin);
  freopen("boolean.out", "w", stdout);

  cin >> s;

  p[0] = 1;
  for(int i=1; i<60; i++) p[i] = p[i-1] * 2;

  for(int i=0; i<(int)s.size(); i++) {
    char c = s[i];
    if(c != '|') {
      if(c == '~') {
        string nstring = s.substr(i, 2);
        string ss = s.substr(i+1, 1);
        variables.insert(nstring);
        v.insert(ss);
        i++;
      }
      else {
        string nstring = s.substr(i, 1);
        string ss = s.substr(i, 1);
        variables.insert(nstring);
        v.insert(ss);
      }
    }
  }

  bool alwaystrue = false;
  for(auto p : variables) {
    if(variables.count(neg(p))) {
      alwaystrue = true;
      break;
    }
  }

  printf("%lld\n", alwaystrue ? p[v.size()] : p[v.size()] - 1);

	return 0;
}

