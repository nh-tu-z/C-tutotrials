#include <iostream>
using namespace std;



/*
 * Đề bài:

Xây dựng lớp Phanso gồm:

    Thuộc Tính: tuso, mauso.
    Phương thức:
        Hàm Khởi Tạo Không Tham Số, Hàm Hủy
        Nhập , Xuất
        Cong(), Tru(), Nhan(), Chia()

Tính Tổng, Hiệu, Tích, Thương 2 phân số obj1 và obj2 rồi in kết quả ra màn hình
 */
class Phanso {
private:
	//properties
	int tuso, mauso;
public:
	//Constructor
	Phanso(){
		tuso = 0;
		mauso = 1;
		cout <<"Phanso Constructor!!!" << endl;
	}
	//Deconstructor
	~Phanso(){
//		tuso = 0;
//		mauso = 1;
//		cout <<"Phanso Deconstructor!!!" << endl;
	}

	//Method
	void set(){
		cout << "Nhap tu so: ";
		cin >> this->tuso;
		cout << "Nhap mau so:";
		cin >> this->mauso;
	}
	void get(){
		cout << this->tuso << "/" << this->mauso << endl;
	}
	//============
	Phanso sum(Phanso obj1, Phanso obj2){
			Phanso obj3;
			obj3.tuso = obj1.tuso * obj2.mauso + obj1.mauso * obj2.tuso;
			obj3.mauso = obj1.mauso * obj2.mauso;
			return obj3;
		}
		Phanso sub(Phanso obj1, Phanso obj2){
			Phanso obj3;
			obj3.tuso = obj1.tuso * obj2.mauso - obj1.mauso * obj2.tuso;
			obj3.mauso = obj1.mauso * obj2.mauso;
			return obj3;
		}
		Phanso mul(Phanso obj1, Phanso obj2){
			Phanso obj3;
			obj3.tuso = obj1.tuso * obj2.tuso;
			obj3.mauso = obj1.mauso * obj2.mauso;
			return obj3;
		}
		Phanso div(Phanso obj1, Phanso obj2){
			Phanso obj3;
			obj3.tuso = obj1.tuso * obj2.mauso;
			obj3.mauso = obj1.mauso * obj2.tuso;
			return obj3;
		}
};

int main(){
	Phanso obj1, obj2, obj3;
	obj1.set();
	obj1.get();
	obj2.set();
	obj2.get();
	obj3 = obj3.mul(obj1, obj2);
	obj3.get();
	return 0;
}
