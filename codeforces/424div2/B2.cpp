#include <iostream>
#include <map>
#include <string>

using namespace std;

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
