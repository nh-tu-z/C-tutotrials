#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(){
		cout << "Constructor of parent class" << endl;
	}
	~Parent(){
			cout << "Deconstructor of parent class" << endl;
		}
};

class Child : public Parent
{
public:
	Child(){
		cout << "Constructor of child class" << endl;
	}
	~Child(){
		cout << "Deconstructor of child class" << endl;
	}
};
void swap (int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void insertionSort(int a[], int array_size)
{
	int i, j, last;
	for(i = 1; i < array_size; i++)
	{
		last = a[i];
		j = i;
		while((j>0)&&(a[j-1]>last))
		{
			a[j] = a[j-1];
			j--;
		}
		a[j] = last;
	}
}
void selectionSort(int a[], int array_size)
{
	for(int i = 0; i<array_size-1; i++)
	{
		int min = i;
		for(int j = i + 1; j<array_size;j++)
		{
			if(a[min] > a[j])
				min = j;
		}
		swap(a[i],a[min]);
	}
}
void bubbleSort(int a[], int array_size)
{
	for(int i=array_size-1; i>=0; i--)
	{
		for(int j = 0; j<i; j++)
		{
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
		}
	}
}
void foo_val(int* a) // pointer to int
{
    a = new int(5);
}

void foo_ref(int*& a) // reference to pointer to int
{
    a = new int(3);
}
int main()
{
	Child a;
	int c[10] = {4, 3, 2, 10, 1, 6,7 ,5 , 0,5};
	int array_size = *(&c+1) - c;
	int n = 42;
	int* p = &n;
	foo_val(p);
	cout << *p << endl; // still 42
	foo_ref(p);
	std::cout << *p << std::endl; // new value! 3
	bubbleSort(c, array_size);
	for(int i = 0; i < array_size; i++)
	{
		cout << c[i] << " ";
	}
	return 0;
}
