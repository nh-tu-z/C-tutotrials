#include <iostream>
using namespace std;
/* Tìm giá trị lớn nhất trong ba số của kiểu số bất kì */
template <class type> type findMax(type *ar, size_t size){
	type max = ar[0];
	for(size_t i = 1; i < size; i++){
		if(max < ar[i]) max = ar[i];
	}
	return max;
}
template <class val> val* maxColMinRow(val m[][4], size_t x, size_t y, size_t row, size_t col){
 val result[2];
 val max = m[0][col], min = m[row][0];
 //max
 for(size_t i = 1; i < y; i++){
	 if(max < m[i][col]) max = m[i][col];
 }
 //min
 for(size_t j = 1; j < x; j++){
	 if(min > m[row][j]) min = m[row][j];
 }
 result[0] = max;
 result[1] = min;
 return result;
}
int main() {
	int xint[] = {1, 5, 10, 12, 4, 3};
	float xfloat[] = {1.2f, 1.5f, 3.14f, 0.5f, -1.5f};
	int array[5][4] = {
			{1, 3, 2, 5},
			{2, 7, 5, 3},
			{4, 10, 5, 3},
			{2, 0, 1, 9},
			{1, 6 , 1, 1}
	};
	cout << "Max (Int) is: " << findMax<int>(xint,sizeof(xint)/sizeof(int)) << endl;
	cout << "Max  (Float) is: " << findMax<float>(xfloat,sizeof(xfloat)/sizeof(float)) << endl;

	//
	int *ptr;
	ptr = maxColMinRow<int>(array, 5, 4, 2, 2);
	return 0;
}
