#include <iostream>
#include <cstring>
using namespace std;

class DynamicArray {
private:
	int size;
	int capacity;
	int *storage;
public:
	DynamicArray();
	DynamicArray(int);
	~DynamicArray();
	void setCapacity(int);
	void ensureCapacity(int);
	void pack();
	void trim();
	void rangeCheck(int);
	void set(int, int);
	int get(int);
	void removeAt(int);
	void insertAt(int, int);
	void print();
};
DynamicArray::DynamicArray(){
	capacity = 10;
	size = 0;
	storage = new int[capacity];
}
DynamicArray::DynamicArray(int capacity){
	this->capacity = capacity;
	size = 0;
	storage = new int[capacity];
}
void DynamicArray::setCapacity(int newCapacity){
	int *newStorage = new int[newCapacity];
	memcpy(newStorage, storage, sizeof(int)*size);
	capacity = newCapacity;
	delete[] storage;
	storage = newStorage;
}
void DynamicArray::ensureCapacity(int minCapacity){
	if(minCapacity > capacity){
		int newCapacity = (capacity*3)/2 + 1; //dont know why is c*3/2 + 1
		if(newCapacity < minCapacity){
			newCapacity = minCapacity;
		}
		setCapacity(newCapacity);
	}
}
void DynamicArray::pack(){
	if(size <= capacity){
		int newCapacity = (size*3)/2 + 1;
		setCapacity(newCapacity);
	}
}
void DynamicArray::trim(){
	int newCapacity = size;
	setCapacity(newCapacity);
}
void DynamicArray::rangeCheck(int index){
	if(index < 0 || index >= size){
		throw "Index out of bounds!";
	}
}
void DynamicArray::set(int index, int value){
	rangeCheck(index);
	storage[index] = value;
}
int DynamicArray::get(int index){
	rangeCheck(index);
	return storage[index];
}
void DynamicArray::insertAt(int index, int value){
	if(index<0 || index>size){
		throw "Index out of bounds!";
	}

	ensureCapacity(size+1);

	int moveCount = size - index;
	if(moveCount!=0){
		memmove(storage + index + 1, storage + index, sizeof(int)*moveCount);
	}
	storage[index] = value;
	size++;
}
void DynamicArray::removeAt(int index){
	rangeCheck(index);
	int moveCount = size - index - 1;
	if(moveCount > 0)
		memmove(storage + index, storage + index + 1, sizeof(int) * moveCount);
	size--;
	pack();
}
void  DynamicArray::print(){
	for(int i = 0; i < this->size; i++){
		cout << storage[i] << " ";
	}
}
DynamicArray::~DynamicArray(){
	delete[] storage;
}
/*  */
class Node{
public:
	int data;
	Node* link;
	Node(){
		this->link = NULL;
	}
	Node(int data){
		this->data = data;
		this->link = NULL;
	}
};
/*  */
class LinkedList{
private:
	int count;
	Node *head;
public:
	LinkedList();
	int InsertNode(Node*,int);
	int DeleteNode(Node*, Node*);
	int Search(int, Node*, Node*);
	void Traverse();
	void Clear();
	~LinkedList();

};
LinkedList::LinkedList(){
	this->head = NULL;
	this->count = 0;
}
int LinkedList::InsertNode(Node* pPre, int value){
	Node* pNew = new Node();
	if(pNew == NULL) //check memory overflow
		return 0;
	pNew->data = value;
	if(pPre==NULL){
		//Adding at the beginning or into empty list
		pNew->link = this->head;
		this->head = pNew;
	}
	else {
		//Adding in the middle or at the end
		pNew->link = pPre->link;
		pPre->link = pNew;
	}
	this->count++;
	return 1;
}
int LinkedList::DeleteNode(Node* pPre, Node* pLoc){
	int result = pLoc->data;
	if(pPre == NULL){
		this->head = pLoc->link;
	}
	else {
		pPre->link = pLoc->link;
	}

	this->count--;
	delete pLoc;
	return result;
}
int LinkedList::Search(int value, Node* &pPre, Node* &pLoc){
	pPre = NULL;
	pLoc = this->head;
	while(pLoc != NULL && pLoc->data != value){
		pPre = pLoc;
		pLoc = pLoc->link;
	}

	return (pLoc != NULL);
}
void LinkedList::Traverse(){
	Node* p = this->head;
	while(p != NULL){
		//add process data here!
		p = p->link;
	}
}
void LinkedList::Clear(){
	Node* temp;
	while(this->head != NULL){
		temp = this->head;
		this->head = this->head->link;
		delete temp;
	}
}
LinkedList::~LinkedList(){
	Clear();
}
int main(){
	cout << "Dynamic Array" <<endl;
	DynamicArray *arrlist = new DynamicArray(10);
	arrlist->insertAt(0, 16);
	//
	arrlist->print();
	return 0;
}
