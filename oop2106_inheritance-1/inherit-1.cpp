#include <iostream>
using namespace std;

class People{
private:
	string name, address;
	int age;
public:
	People();
	~People();
	void set();
	void get();
};
People::People(){
	this->name = "";
	this->address = "";
	this->age = 0;
}
People::~People(){
	this->name = "";
	this->address = "";
	this->age = 0;
}
void People::set(){
	cout << "===Add Info===" << endl;
	cout << "Name: "; fflush(stdin); getline(cin, this->name);
	cout << "Age: "; cin >> this->age;
	cin.ignore();
	cout << "Address: "; fflush(stdin); getline(cin, this->address);
}
void People::get(){
	cout << "===Show Info===" << endl;
	cout << "Name: " << this->name << endl;
	cout << "Age: " << this->age << endl;
	cout << "Address: " << this->address << endl;
}

class Student : public People{
private:
	string id;
	float math, physics, chemistry;
public:
	Student();
	~Student();
	void set();
	void get();
	float gpa();
};
Student::Student(){
	id = "";
	math = physics = chemistry = 0.0f;
}
Student::~Student(){
	id = "";
	math = physics = chemistry = 0.0f;
}
void Student::set(){
	People::set();
	cout << "ID: "; cin >> this->id;
	cout << "Math Score: "; cin >> this->math;
	cout << "Physics Score: "; cin >> this->physics;
	cout << "Chemistry Score: "; cin >> this->chemistry;
}
void Student::get(){
	People::get();
	cout << "ID: " << this->id << endl;
	cout << "Math Score: " << this->math << endl;
	cout << "Physics Score: " << this->physics << endl;
	cout << "Chemistry Score: " << this->chemistry << endl;
}
float Student::gpa(){
	return (this->math + this->physics + this->chemistry)/3;
}
int main() {
	Student tuz;
	tuz.set();
	tuz.get();
	cout << "GPA: " << tuz.gpa() << endl;
	return 0;
}
