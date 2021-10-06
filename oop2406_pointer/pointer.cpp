#include <iostream>
using namespace std;

/*
 * write a program that declares and initializes an array with the first 50 odd (as in not even)
 * numbers. Output the numbers from the array ten to a line using pointer notation and then output
 * them in reverse order, also using pointer notation.
 * */
void showArr(int a[], int array_size){
	for(int i = 0; i < array_size; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
void insertionSort(int a[], int array_size){
	int i, j, last;
	for(i = 1; i < array_size; i++){
		last = a[i];
		j = i;
		while ((j > 0) && (a[j-1] > last)) {
			a[j] = a[j-1];
			j = j - 1;
		}
		a[j] = last;
		showArr(a, array_size);
	}
}
int main(){
	int a[8] = {4, 3, 2, 10, 12, 1, 5, 6};
	insertionSort(a, 8);
	return 0;
}
