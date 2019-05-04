#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long N, aux, opt, num, max;
    vector<int> v;
    cin >> N;
    aux = 0;
    while (aux < N){
        cin >> opt;
        if (opt == 1){
            cin >> num;
            v.push_back(num);
        }else if (opt == 2 ){
            v.pop_back();
        }else if (opt == 3){
            for(int i = 0; i < v.size(); ++i){
                max = (max < v[i])? v[i] : max;
            }
            cout << max << endl;
            max = 0;
        }
        ++aux;
    }

    return 0;
}
