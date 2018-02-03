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

bool isVowel(char c){ return (c <= 'z' and c >= 'a') or (c <= 'Z' and c >= 'A'); }

char typed(map<char,char> m, char c){
  if(isVowel(c)) return m[c];
  return c;
}

int main(){
	ios_base::sync_with_stdio(false);
  string firstLayout, secondLayout, text;
  map<char,char> mp;

  cin >> firstLayout >> secondLayout >> text;

  for(int i=0;i<26;++i){
    mp[firstLayout[i]] = secondLayout[i];
    mp[firstLayout[i] + 'A'-'a'] = secondLayout[i] + 'A'-'a';
  }

  for(char c : text) cout << typed(mp, c);
  cout << endl;

	return 0;
}

