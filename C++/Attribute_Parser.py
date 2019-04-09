#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
    public:
        string name;
        string value;
        string tag;
        vector <Node> child;
        Node(string tag, string n, string v){
            name = n;
            value = v;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector <Node> hrml;
    int N = 0, Q = 0;

    cin >> N >> Q;

    for (int i = 0; i <= N; ++i){
        string str;
        int find, find_n, find_v;
        getline(cin, str);

        // Inser new tag
        if (str[str.length()-2] == '"'){
            // Tag name
            find = str.find(' ');
            string tag = str.substr(1, find - 1);
            // Attribute name
            find_n = str.find('=');
            string n = str.substr(find + 1, find_n - find - 1);
            // Attribute value
            find_v = str.find('"');
            string v = str.substr(find_v + 1, str.length()- find_v - 3);

            Node node(tag, n, v);
            hrml.push_back(node);

        }else if (str[1] == '/'){
            cout << "Next insertion on another vector" << endl;
        }
    }

    return 0;
}
