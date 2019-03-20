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
                char hex_A[] = {
                    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
                }; 
                string strA = to_string(A);
                string hexa;
                int i = 1;
                int n;
                // Truncate
                strA = strA.substr(0, strA.find('.'));
                A = stoi(strA);
                while ((int)A != 0) {
                  hexa += hex_A[((int)A % 16)];
                  A /= 16;
        }
        n = hexa.length();
        for (int i = 0; i < n / 2; i++){
            swap(hexa[i], hexa[n - i - 1]);
        }
        hexa = "0x" + hexa;
        cout << left << hexa << endl;

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
        if(another_numbers >= i/2)
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
        int round_term;
        double decimals;
        string sc_notation, after_comma;
        after_comma = strC.substr(1, strC.find('.')-1) + strC.substr(strC.find('.') + 1);
        after_comma.append(9 - after_comma.size(),'0');
        sc_notation = strC[0];
        sc_notation.append(".");
        double after_comma_double;
        
        if (left_side > 10){
            sc_notation += after_comma + "E+" + to_string(left_side - 1);
        }else {
            sc_notation += after_comma + "E+0" + to_string(left_side - 1);
        }
        cout << sc_notation << endl;
	}
	return 0;

}
