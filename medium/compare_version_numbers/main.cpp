#include <bits/stdc++.h>  
using namespace std;

int compare_version(string version1, string version2) {
  
  int l1 = version1.length(), l2 = version2.length(), res = 0, idx1 = 0, idx2 = 0;

  for (int i = 0; i < max(l1, l2); i ++) {
    
    string curr1, curr2;
    while (idx1 < l1 && version1[idx1] != '.') 
      curr1.push_back(version1[idx1++]);
   
    if (idx1 < l1) idx1 ++;

    while (idx2 < l2 && version2[idx2] != '.')
      curr2.push_back(version2[idx2++]);

    if (idx2 < l2) idx2 ++;

    int f = 0, s = 0;

    if (curr1.length() > 0) f = stoi(curr1);

    if (curr2.length() > 0) s = stoi(curr2);

    if (f < s) return -1;
    else if (f > s) return 1;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string version1, version2;
    cin >> version1 >> version2;

    int res = compare_version(version1, version2);
    cout << res << endl;
  }

  return 0;
}
