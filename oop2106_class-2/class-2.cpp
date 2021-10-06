#include <iostream>
using namespace std;

/*
 * Đề bài

	Xây dựng lớp vận động viên VanDongVien gồm:

    Thuộc tính: hoten (chuỗi ký tự), tuoi (số nguyên), monthidau (chuỗi ký tự), cannang (số thực), chieucao (số thực).
    Phương thức:
        Thiết lập không tham số.
        Thiết lập 5 tham số
        Hủy bỏ
        Nạp chồng toán tử nhập >>
        Nạp chồng toán tử xuất <<
        Nạp chồng toán tử so sánh > (một vận động viên là lớn hơn nếu chiều cao lớn hơn,
        trong trường hợp chiều cao bằng nhau thì xét cân nặng lớn hơn)

	Xây dựng chương trình chính:

    Khai báo p là đối tượng lớp Vandongvien (sử dụng hàm thiết lập 5 tham số), hiển thị thông tin của p ra màn hình.
    Nhập vào một mảng gồm n vận động viên.
    Hiển thị danh sách đã nhập ra màn hình.
    Sắp xếp mảng đã nhập theo thứ tự tăng dần, hiển thị danh sách đã sắp ra màn hình.
 * */

class VanDongVien{
private:
	string hoten, monthidau;
	int tuoi;
	float cannang, chieucao;
public:
	VanDongVien();
	VanDongVien(string, int, string, float, float);
	~VanDongVien();
	void ShowInfo();
	// operator overloading
	friend istream &operator>> (istream &is, VanDongVien &obj);
	friend ostream &operator<< (ostream &os, VanDongVien &obj);
	bool operator > (const VanDongVien &obj);
};
VanDongVien::VanDongVien(){
	this->hoten = ' ';
	this->tuoi = 0;
	this->monthidau = ' ';
	this->cannang = 0;
	this->chieucao = 0;
}
VanDongVien::VanDongVien(string hoten, int tuoi, string monthidau, float chieucao, float cannang){
	this->hoten = hoten;
	this->tuoi = tuoi;
	this->monthidau = monthidau;
	this->chieucao = chieucao;
	this->cannang = cannang;
}
VanDongVien::~VanDongVien(){
	this->hoten = ' ';
	this->tuoi = 0;
	this->monthidau = ' ';
	this->cannang = 0;
	this->chieucao = 0;
}
void VanDongVien::ShowInfo(){
	cout << "=========================" << endl;
	cout << "Name: " << this->hoten << endl;
	cout << "Age: " << this->tuoi << endl;
	cout << "Weight: " << this->cannang << endl;
	cout << "Height: " << this->chieucao << endl;
	cout << "Participate: " << this->monthidau << endl;
}
istream &operator>> (istream &is, VanDongVien &obj){
	cin.ignore();
	cout << "Name: "; fflush(stdin); getline(is, obj.hoten);
	cout << "Participate: "; fflush(stdin); getline(is, obj.monthidau);
	cout << "Age: "; is >> obj.tuoi;
	cout << "Height: "; is >> obj.chieucao;
	cout << "Weight: "; is >> obj.cannang;
	return is;
}
ostream &operator<< (ostream &os, VanDongVien &obj){
	cout << "========Info========" << endl;
	cout << "Name: " << obj.hoten << endl;
	cout << "Age: " << obj.tuoi << endl;
	cout << "Height: " << obj.chieucao << endl;
	cout << "Weight: " << obj.cannang << endl;
	cout << "Participate: " << obj.monthidau << endl;
	return os;
}
bool VanDongVien::operator >(const VanDongVien &obj){
	if(this->chieucao > obj.chieucao)
		return true;
	else if (this->chieucao < obj.chieucao)
		return false;
	else if (this->cannang > obj.cannang)
		return true;
	else return false;
}
void swap (VanDongVien &a, VanDongVien &b){
	VanDongVien temp;
	temp = a;
	a = b;
	b = temp;
}
void bubbleSort(VanDongVien arr[], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i -1; j++){
			if(arr[j] > arr[j+1])
				swap(arr[j],arr[j+1]);
		}
	}
}
int main(){
	VanDongVien p("Ngo Hoai Tu",21,"Soccer",170.2,63.5);
	cout << p;

	cout << "Enter a number: "; int n; cin >> n;
	VanDongVien *arr = new VanDongVien[n];

	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << endl << endl;
	for(int i = 0; i < n; i++) cout << arr[i] << endl;

	cout << "Sort" << endl;
	bubbleSort(arr, n);
	for(int i = 0; i < n; i++) cout << arr[i] << endl;

	return 0;
}
