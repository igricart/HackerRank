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
        int round_term;
        double decimals;
        string sc_notation, after_comma, str_aux;
        after_comma = strC.substr(1, strC.find('.')-1) + strC.substr(strC.find('.') + 1);
        sc_notation = strC[0];
        sc_notation.append(".");
        double after_comma_double;
        /*
        // Define size and work on decimals after 9th position
        if (after_comma.size() > 9){
            after_comma_double = stod(after_comma)/1000000000;
            str_aux = after_comma.substr(9);
            round_term = stoi(str_aux);
            i = 1;
            for (int j = 0; j < str_aux.size(); j++) {
                i *= 10;
            }
            if (round_term > i / 2)
                after_comma_double += 1/100000000;
        } else{
            i = 1;
            for (int j = 0; j < after_comma.size(); j++) {
                i *= 10;
            after_comma_double = stod(after_comma) / i;
            }
        }
        // TO DO - Subtract the left side from C in order to obtain all decimals
        cout << "sc_notation: " << after_comma << endl;
        cout << strC << " " << size_strC << " " << left_side << " " << right_side << endl;
        */
        if (left_side > 10){
            sc_notation += after_comma + "E+" + to_string(left_side - 1);
        }else {
            sc_notation += after_comma + "E+0" + to_string(left_side - 1);
        }
        cout << sc_notation << endl;
	}
	return 0;

}
