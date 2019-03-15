#include <iostream>
#include <deque> 
using namespace std;

int findMax(deque<int> v){
    int max = v[0];
    for(int i = 0; i < v.size(); ++i){
        if(v[i] > max){
            max = v[i];
        }
    }
    return max;
}

void printKMax(int arr[], int n, int k){
	//Write your code here.
    int loops = n - k;
    int element = 0;
    int j = 0;
    int max = 0;
    deque<int> dq;

    //Initialize duque
    for(int i = 0; i < k; ++i){
        dq.push_back(arr[i]);
        if(arr[i] > max){
            max = arr[i];
        }
    }
    element = dq.size();

    //Print max
    if(loops != 0){
        cout << max << " ";
    }else {
        cout << max << endl;
    }
    while (j < loops){
        if(dq[0] == max){
            dq.pop_front();
            max = findMax(dq);
        } else {
            dq.pop_front();
        }
        
        dq.push_back(arr[element]);
        if (arr[element] > max) {
            max = arr[element];
        }
        cout << max << " ";
        ++element;
        ++j;
    }
    if (loops != 0){
        cout << endl;
    }
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++){
      		cin >> arr[i];
        }
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
