#include <bits/stdc++.h>

using namespace std;

// Summary:
// Author : Luciano Barreira
// Lang : GNU C++11
// Time : 15ms
// Memory : 2100 KB

struct pt{
  int x,y;
};

int main (){
  pt points[3];
  for (int i = 0; i < 3 ; ++i){
    scanf ("%d %d", &points[i].x, &points[i].y);
  }
  cout << 3 << endl;
  for (int i = 0 ; i < 3 ; ++i){
    cout << (points[(i+1)%3].x + points[(i+2)%3].x - points[i].x) << " ";
    cout << (points[(i+1)%3].y + points[(i+2)%3].y - points[i].y) << endl;
  }
  return 0;
}

