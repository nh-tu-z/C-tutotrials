#include <iostream>

using namespace std;

class Color{
protected:
	string TenMau, MaMau;
public:
	Color();
	Color(string, string);
	~Color();
	friend istream &operator>>(istream &is, Color &obj){
		cout << "=== Color Operator Overloading ===" << endl;
		cout << "Add a color name: "; fflush(stdin); getline(is, obj.TenMau);
		cout << "Add a color code: "; fflush(stdin); getline(is, obj.MaMau);
		return is;
	}
	friend ostream &operator<<(ostream &os, Color &obj){
		cout << "=== Show Color Info ===" << endl;
		cout << "Color Name: " << obj.TenMau << endl;
		cout << "Color Code: " << obj.MaMau << endl;
		return os;
	}
	string getTenMau();
};
Color::Color(){
	TenMau = MaMau = "";
}
Color::Color(string TenMau, string MaMau){
	this->TenMau = TenMau;
	this->MaMau = MaMau;
}
Color::~Color(){
	TenMau = MaMau = "";
}
string Color::getTenMau(){
	return this->TenMau;
}
/*==============================*/
class Point{
protected:
	int x, y;
public:
	Point();
	Point(int, int);
	~Point();
	friend istream &operator >> (istream &is, Point &obj){
		cout << "=== Add a Point ===" << endl;
		cout << "Add X coordinate: "; is >> obj.x;
		cout << "Add Y coordinate: "; is >> obj.y;
		return is;
	}
	friend ostream &operator << (ostream &os, Point &obj){
		cout << "=== Show Point ===" << endl;
		cout << "Point is: (" << obj.x << ", " << obj.y << ")" << endl;
		return os;
	}
	bool isCheoChinh();
};
Point::Point(){
	x = y = 0;
}
Point::Point(int x, int y){
	this->x = x;
	this->y = y;
}
Point::~Point(){
	x = y = 0;
}
bool Point::isCheoChinh(){
	if(this->x == this->y){
		return true;
	}
	else return false;
}
/*======================*/
class Pixel : public Color, public Point{
public:
	Pixel();
	Pixel(string, string, int, int);
	~Pixel();
	friend istream &operator>>(istream &is, Pixel &obj){
		cout << "== Add a pixel ===" << endl;
		cout << "X coordinate: "; is >> obj.x;
		cout << "Y coordinate: "; is >> obj.y;
		cin.ignore();
		cout << "Color Name: "; fflush(stdin); getline(is, obj.TenMau);
		cout << "Color Code: "; fflush(stdin); getline(is, obj.MaMau);
		return is;
	}
	friend ostream &operator<<(ostream &os, Pixel &obj){
		cout << "== Show a pixel ==" << endl;
		cout << "Point is: (" << obj.x << ", " << obj.y << ")" << endl;
		cout << "Pixel Color: " << obj.TenMau << endl;
		cout << "Color Code: " << obj.MaMau << endl;
		return os;
	}
	bool checkPixel();
};
Pixel::Pixel(){
	TenMau = MaMau = "";
	x = y = 0;
}
Pixel::Pixel(string TenMau, string MaMau, int x, int y){
	this->TenMau = TenMau;
	this->MaMau = MaMau;
	this->x = x;
	this->y = y;
}
Pixel::~Pixel(){
	TenMau = MaMau = "";
	x = y = 0;
}
bool Pixel::checkPixel(){
	if((this->TenMau == "Green") && Point::isCheoChinh()){
		return true;
	}
	else return false;
}
int main(){
	cout << "Enter a number of pixel: "; int n; cin >> n;
	Pixel *arr = new Pixel[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << "All the pixels: " << endl;
	for(int i = 0; i < n; i++) cout << arr[i];
	cout << "Check Pixels:  " << endl;
	for(int i = 0; i < n; i++){
		if(arr[i].checkPixel()){
			cout << arr[i];
		}
	}
	return 0;
}
