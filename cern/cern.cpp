#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cern.in");
ofstream fout("cern.out");

int n, x, y, tile;

int main(){
  fin >> x >> y;
  fin >> n;
  for(int i = 1; i<=n; ++i){
    int a; fin >> a;
    if(x % a == 2 and (y % a) == 0) cout << "YES\n";
    else if(y % a == 2 and (x % a) == 0) cout << "YES\n";
    else if(x % a == 1 and (y-1 % a) == 0) cout << "YES\n";
    else if(y % a == 1 and (x-1 % a) == 0) cout << "YES\n";
    else cout << "NO\n";
  }

	return 0;
}

//Andrei Muntean, 2018

/*
int a; cin >> a;// cout << a;
if(a > x or a > y)
   {cout << "NO\n"; continue;}
int ur = x%a;
//cout << ur;
if(ur > 2) {cout << "NO\n"; continue;}
int lr = (y + ur-1) %a;
//cout << lr;
if(lr > 1) {cout << "NO\n"; continue;}
int ll = (x + lr+ur-1) % a;
//cout << ll;
if(ll > 1) {cout << "NO\n"; continue;}
int ul = (y + ll + ur-1) % a;
//cout << ul;
if ((x - ul + ur) % a != 0) {cout << "NO\n"; continue;}
cout << "YES\n";
*/
