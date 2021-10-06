#include <iostream>

using namespace std;
/**/
template<class ItemType> class Node {
private:
	ItemType data;
	Node<ItemType>* next;
public:
	Node(){
		this->next = NULL;
	}
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};
/**/
template<class List_ItemType>class Stack{
private:
	int count;
	Node<List_ItemType>* top;
public:
	Stack();
	~Stack();
	void Clear();
	int pushStack(List_ItemType);
	List_ItemType popStack(List_ItemType);
};
template<class List_ItemType> Stack<List_ItemType>::Stack(){
	this->count = 0;
	this->top = NULL;
}
template<class List_ItemType> void Stack<List_ItemType>::Clear(){

}
template<class List_ItemType> Stack<List_ItemType>::~Stack(){
	this->Clear();
}
template<class List_ItemType> int Stack<List_ItemType>::pushStack(List_ItemType data){
	Node<List_ItemType>* pNew = new Node<List_ItemType>();
	if(pNew == NULL) //overflow
		return 0;
	pNew->data = data;
	pNew->next = this->top;
	this->top = pNew;
	this->count++;
	return 1;
}
template<class List_ItemType> int Stack<List_ItemType>::popStack()
int main(){
	cout << "hello world";
	return 0;
}
