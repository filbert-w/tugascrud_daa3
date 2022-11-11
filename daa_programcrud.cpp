#include <iostream>
using namespace std;

struct Mahasiswa {
	int no;
	string nama;
	string nim;
	string tgl_lahir;
	string matakuliah;
};

int pos = 0;
string ulang;

Mahasiswa dataMahasiswa[10];

void tampil(){
	if(pos != 0){
		cout << "no.\tNama\tNIM\tTgl lahir\tMata kuliah\n";
		for(int a=0;a<pos;a++){
			cout << a+1 <<"\t"<<dataMahasiswa[a].nama<<"\t"<<dataMahasiswa[a].nim<<"\t"<<dataMahasiswa[a].tgl_lahir<<"\t";
			cout << dataMahasiswa[a].matakuliah<<endl;
		}
	} else {
		cout << "Data kosong\n";
	}
}

void buat(){
	system("cls");
	if(pos<10){
		tampil();
	cin.ignore();
	cout << "Nama: "; getline(cin, dataMahasiswa[pos].nama);
	cout << "NIM: "; getline(cin, dataMahasiswa[pos].nim);
	cout << "Tanggal lahir: "; getline(cin, dataMahasiswa[pos].tgl_lahir);
	cout << "Mata kuliah: "; getline(cin, dataMahasiswa[pos].matakuliah);
	pos++;
	system("cls");
	tampil();
	} else {
		do {
			cout << "Data penuh\n";
			cout << "Isikan y untuk kembali: ";
			cin >> ulang;
		} while(ulang == "y");
	}
}

void edit(){
	tampil();
	int ubah;
	cout << "no yang ingin diubah: ";
	cin >> ubah;
	cin.ignore();
	cout << "Nama: "; getline(cin, dataMahasiswa[ubah-1].nama);
	cout << "NIM: "; getline(cin, dataMahasiswa[ubah-1].nim);
	cout << "Tanggal lahir: "; getline(cin, dataMahasiswa[ubah-1].tgl_lahir);
	cout << "Mata kuliah: "; getline(cin, dataMahasiswa[ubah-1].matakuliah);
	tampil();
}

void hapus(){
	tampil();
	int hps;
	cout << "no yang ingin dihapus: ";
	cin >> hps;
	for(int a=hps-1;a<pos;a++){
		dataMahasiswa[a].nama = dataMahasiswa[a+1].nama;
		dataMahasiswa[a].nim = dataMahasiswa[a+1].nim;
		dataMahasiswa[a].tgl_lahir = dataMahasiswa[a+1].tgl_lahir;
		dataMahasiswa[a].matakuliah = dataMahasiswa[a+1].matakuliah;
	}
	pos--;
	system("cls");
	tampil();
}

int main(){
	int input;

	do{
	system("cls");
	cout << "Program CRUD" << endl;
	cout << "==============" << endl;
	cout << "1. Create" << endl;
	cout << "2. Read" << endl;
	cout << "3. Update" << endl;
	cout << "4. Delete" << endl;
	cout << "5. Selesai" << endl;
	cout << "==============" << endl;
	cout << "Pilihan (1-5) : ";
	cin >> input;
	
	switch(input){
		case 1:
			do {
				buat();
				cout << "Ulang? (y/n): ";
				cin >> ulang;
			} while(ulang == "y");
			break;
		case 2:
			do {
				system("cls");
				tampil();
				cout << "Ulang? (y/n): ";
				cin >> ulang;
			} while(ulang == "y");
			break;
		case 3:
			do {
				system("cls");
				edit();
				cout << "Ulang? (y/n): ";
				cin >> ulang;
			} while(ulang == "y");
			break;
		case 4:
			do {
				system("cls");
				hapus();
				cout << "Ulang? (y/n): ";
				cin >> ulang;
			} while(ulang == "y");
			break;
		case 5:
			cout << "Program selesai" << endl;
			break;
		default:
			cout << "Pilihan tidak ditemukan" << endl;
			break;
	}
	} while (input != 5);
}
