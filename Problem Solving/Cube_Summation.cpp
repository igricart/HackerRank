#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    typedef vector<int> v1d;
    typedef vector<v1d> v2d;
    typedef vector<v2d> v3d;
    v3d v(1, v2d(1, v1d(1, 0)));

    int cases;
    cin >> cases;
    while (cases != 0){
      //cout << "Case: " << cases << endl;
      int size, q, x, y, z, value;
      string str;

      cin >> size >> q;
      v.resize(size+1, v2d(size+1, v1d(size+1)));

      while (q > 0) {
        cin >> str;
        if (str == "UPDATE") {
          cin >> x >> y >> z >> value;
          v[x][y][z] = value;
          //cout << "Update: " << v[x][y][z] << endl;
        } else if (str == "QUERY") {
          int x_set[2];
          int y_set[2];
          int z_set[2];
          int i = 0;
          long long int sum = 0;

          cin >> x_set[0] >> y_set[0] >> z_set[0] >> x_set[1] >> y_set[1] >>
              z_set[1];

          //Optimize loop reordering nested loop
          int v1 = x_set[1] - x_set[0];
          int v2 = y_set[1] - y_set[0];
          int v3 = z_set[1] - z_set[0];
          
          for(int i = x_set[0]; i <= x_set[1]; ++i){
              for(int j = y_set[0]; j <= y_set[1]; ++j){
                  for(int k = z_set[0]; k <= z_set[1]; ++k){
                      sum += v[i][j][k];
                  }
              }
          }
          cout << sum << endl;
        }
        --q;
      }
      --cases;
      v.clear();
    }
    return 0;
}
