#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    for(int i = 1; i <= n; ++i){
        string space(n-i,' ');
        string hash(i,'#');
        cout << space << hash << endl;
    }

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
