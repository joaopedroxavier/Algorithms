#include <bits/stdc++.h>

using namespace std;

string sound, ans;
set<string> other;

int main(){
  int t;
  cin >> t;
  getline(cin, sound);
  while(t--){
    other.clear();
    ans.clear();

    getline(cin, sound);
    string info;
    while(1){
      getline(cin, info);
      if(info == "what does the fox say?") break;
      string s = info.substr(info.rfind(" ")+1);
      other.insert(s);
    }
    int last = 0;
    bool first = true;
    for(int i=0; i<(int)sound.size(); i++){
      if(sound[i] == ' '){
        string s = sound.substr(last, i-last);
        if(!other.count(s)){
          if(first) ans = ans + s, first = false;
          else ans = ans + " " + s;
        }
        last = i+1;
      }
    }
    string s = sound.substr(last, sound.size()-last);
    if(!other.count(s)) ans = ans + " " + s;
    cout << ans << endl;
  }
}
