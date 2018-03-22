#define x first
#define y second
#define pii pair<int, int>
#include <bits/stdc++.h>
using namespace std;

long double angle(pair<int,int> p1, pair<int,int> p2){
	 return (atan2(p1.y - p2.y, p1.x - p2.x) * 180 / 3.14);
}

int main() {
	pii a = {0,0};
  pii b = {-1,-1};
  cout << angle(a,b); /// b fata de a
	return 0;
}
