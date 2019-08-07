#include <iostream>
#include <functional>
using namespace std;

enum option {ascending, descending};

template <typename T, option select>
void bubbleSort(T arr[], int n) {
	bool isSwapped = false;
	function<bool(T, T)> predicate;
	
	switch(select) {
		case ascending: 
			predicate = [](T x, T y) {
				return x > y ? true : false;
			};
			break;
		case descending:
			predicate = [](T x, T y) {
				return x < y ? true : false;
			};
			break;
		default:
			break;
	}
	
	//Algorithm
	for(int i = 0; i < n - 1; i++) {
		isSwapped = false;
		for(int j = 0; j < n - i - 1; j++) {
			if(predicate(arr[j], arr[j + 1])) {
				T temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				isSwapped = true;
			}
		}
		if(!isSwapped) break;
	}
	
	//Output
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}


int main() {
	
	int a[] = {41, 20, 51, 24, 99, 11, 2, 1};
	bubbleSort<int, ascending>(a, 8);
	return 0;
}
