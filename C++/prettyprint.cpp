#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
    // A solution
    string strA = to_string(A);
    string hexa("0x");
    int i=1;
    // Truncate
    strA = strA.substr(0, strA.find('.'));
    A = stod(strA);
    // Find highest power of 16 in range 
    for(;i < A; i *= 16){}
    i /= 16;
    // Calculate hexadecimal form
    for(;i > 1; i /= 16){
        hexa += to_string((int)A / i);
        A = (int)A % i;
    }
    hexa += to_string((int)A);
    cout << hexa << endl;

    // B solution
    int n_undersc;
    int two_digits, another_numbers;
    char signal;
    string strB = to_string(B);
    string strB_reduc(strB.substr(0, strB.find('.') + 3));
    int size_full = strB.size();
    int size_reduc = strB_reduc.size();

    B = stod(strB_reduc);
    another_numbers = stoi(strB.substr(strB.find('.')+3));

    //Round up decision
    i = 1;
    for(int j = 0; j < size_full - size_reduc; j++){i*=10;}
    if(another_numbers > i/2)
        B += 0.01;

    //Underscore array
    n_undersc = 15 - strB_reduc.size() - 1;
    string str_undersc(n_undersc, '_');

    //Signal
    if (B > 0){
        signal = '+';
    }else{
        signal = '-';
    }

    //Final B
    strB = str_undersc + signal + to_string(B);
    cout << strB.substr(0,15) << endl;

    // C Solution
    string strC = to_string(C);
    int size_strC = strC.size();
    int left_side = strC.find('.');
    int right_side = size_strC - left_side;
    string sc_notation;
    // TO DO - Subtract the left side from C in order to obtain all decimals 

    cout << strC << " " << size_strC << " " << left_side << " " << right_side << endl;
    if (left_side > 10){
        sc_notation = "E+" + to_string(left_side - 1);
    }else {
        sc_notation = "E+0" + to_string(left_side - 1);
    }
	}
	return 0;

}
