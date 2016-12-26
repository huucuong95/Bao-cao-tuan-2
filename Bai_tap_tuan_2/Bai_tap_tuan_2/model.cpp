#include "model.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;


void model::tuychon(int chon)
{
	switch (chon)
	{
	case 1: them_sv(); break;
	case 2: capnhat_banghi(st, biendem); break;
	case 3: xoa_banghi(st, biendem); break;
	case 4: nhap_banphim(); break;
	case 5: tk_tongdiem(); break;
	case 6: tk_SBD(); break;
	case 7: tk_Ten(); break;
	case 9: view_SBD(); break;
	case 10: view_Ten(); break;
	case 11: view_Tongdiem(); break;
	case 12: luu_tk(); break;
	case 13: tong_thisinh(); break;
	case 14: tong_15(); break;
	case 15: tong_1520(); break;
	case 16: tong_2025(); break;
	case 17: tong_25(); break;
	default:
		cout << "vui long nhap dung";
	}
}
void model::them_sv()
{

	cout << "Nhap so sinh vien ban muon nhap:";
	int soluong;
	cin >> soluong;
	for (int i = 0; i < soluong; i++)
	{
	again:
		cout << "\nNhap SBD:";
		cin >> st[biendem].SBD;
		cin.ignore(1);
		if (search(st, st[biendem].SBD, biendem) != -1)
		{
			cout << "ID nay da ton tai \n"; goto again;
		}
		cout << "Nhap ten:";
		getline(cin, st[biendem].tensv);
		cout << "Nhap dia chi:";
		getline(cin, st[biendem].diachi);
		cout << "Nhap gioi tinh:";
		getline(cin, st[biendem].sex);
		fflush(stdin);
		toan:
		cout << "Nhap diem toan:";
		cin >> st[biendem].diemtoan;
		if (st[biendem].diemtoan < 0 || st[biendem].diemtoan>10)
		{
			cout << "diem toan bi nhap sai\n";
			goto toan;
		}
		ly:
		cout << "Nhap diem ly:";
		cin >> st[biendem].diemly;
		if (st[biendem].diemly < 0 || st[biendem].diemly>10)
		{
			cout << "diem ly bi nhap sai\n";
			goto ly;
		}
		hoa:
		cout << "Nhap diem hoa:";
		cin >> st[biendem].diemhoa;
		if (st[biendem].diemhoa < 0 || st[biendem].diemhoa>10)
		{
			cout << "diem hoa bi nhap sai\n";
			goto hoa;
		}
		st[biendem].tong = st[biendem].diemtoan + st[biendem].diemly + st[biendem].diemhoa;
		biendem++;
	}
}
int model::search(class sinhvien st[], string SBD, int biendem)
{
	int found = -1;
	for (int i = 0; i < biendem && found == -1; i++)
	{
		if (st[i].SBD == SBD) found = i;
		else found = -1;
	}
	return(found);
}
void model::capnhat_banghi(class sinhvien st[], int biendem)
{
	string a;
	int column_index;
	again:
	cout << "Nhap SBD:";
	cin >> a;
	int index = search(st, a, biendem);
	if (index != -1)
	{
		cout << "ban muon thay doi truong nao (1-6):";
		cout << "\n1, Ho va ten\n";
		cout << "2, Dia chi\n";
		cout << "3, Gioi tinh\n";
		cout << "4, Diem toan\n";
		cout << "5, Diem ly\n";
		cout << "6, Diem hoa\n";
		cout << "nhap tuy chon:";
		cin >> column_index;
		if (column_index == 1)
		{
			cout << "Nhap ten:";
			cin >> st[index].tensv;
		}
		else if (column_index == 2)
		{
			cout << "Nhap dia chi:";
			cin >> st[index].diachi;
		}
		else if (column_index == 3)
		{
			cout << "Nhap gioi tinh:";
			cin >> st[index].sex;
		}
		else if (column_index == 4)
		{
			cout << "Nhap diem toan:";
			cin >> st[index].diemtoan;
		}
		else if (column_index == 5)
		{
			cout << "Nhap diem ly:";
			cin >> st[index].diemly;
		}
		else if (column_index == 6)
		{
			cout << "Nhap diem hoa:";
			cin >> st[index].diemhoa;
		}
		else cout << "ban ghi ko hop le";
		st[index].tong = st[index].diemtoan + st[index].diemly + st[index].diemhoa;
	}
	else cout << "ban ghi ko ton tai, moi ban nhap lai\n"; 
}
void model::xoa_banghi(class sinhvien st[], int& biendem)
{
	string SBD;
	int index;
	if (biendem > 0)
	{
		cout << "Nhap SBD:";
		cin >> SBD;
		index = search(st, SBD, biendem);
		if (index != -1)
		{
			if (index == (biendem - 1))
			{
				clean(st, index);
				--biendem;
				cout << "ban ghi da bi xoa \n";
			}
			else
			{
				for (int i = index; i < biendem - 1; i++)
				{
					st[i] = st[i + 1];
					--biendem;
				}
			}
		}
		else cout << "ban ghi ko ton tai, kiem tra lai SBD va thu lai \n"; 

	}
	else cout << "khong ban ghi nao bi xoa";
}
void model::clean(class sinhvien st[], int index)
{
	st[index].SBD = "";
	st[index].tensv = "";
	st[index].diachi = "";
	st[index].sex = "";
	st[index].diemtoan = 0;
	st[index].diemly = 0;
	st[index].diemhoa = 0;
	st[index].tong = 0;
}
void model::nhap_banphim()
{
	string a;
	again:
	cout << "nhap duong dan:";
	cin >> a;
	fstream infile;
	infile.open(a);
	if (infile.fail()) {
		cout << "Duong dan sai, kiem tra va nhap lai\n"; goto again;
	}
	while (!infile.eof())
	{
		infile >> st[biendem].SBD;
		infile >> st[biendem].tensv;
		infile >> st[biendem].diachi;
		infile >> st[biendem].sex;
		infile >> st[biendem].diemtoan;
		infile >> st[biendem].diemly;
		infile >> st[biendem].diemhoa;
		infile >> st[biendem].tong;
		biendem++;
	}

	infile.close();
}
void model::tk_tongdiem()
{
	float a;
	int b = 0;
	cout << "nhap tong diem ma ban muon tim:";
	cin >> a;
	cout << left << setw(5) << "SBD" << setw(20) << "Ten" << setw(20) << "dia chi" << setw(15) << "Gioi tinh" << setw(15) << "Diem toan" << setw(15) << "Diem ly" << setw(15) << "Diem hoa" << setw(15) << "Tong";
	cout << "\n===============================================================================================================\n";
	for (int i = 0; i < biendem; i++)
	{
		if (a == st[i].tong)
		{
			cout << left << setw(5) << st[i].SBD << setw(20) << st[i].tensv << setw(20) << st[i].diachi << setw(15) << st[i].sex << setw(15) << st[i].diemtoan << setw(15) << st[i].diemly << setw(15) << st[i].diemhoa << setw(15) << st[i].tong;
			cout << "\n";
			b = b + 1;
		}
		else b = b;
	}
	if (b == 0) cout << "khong tim thay ket qua\n";
}

int model::tk_SBD()
{
	string a;
	int b = 0;
	cout << "nhap SBD ma ban muon tim:";
	cin >> a;
	cout << left << setw(5) << "SBD" << setw(20) << "Ten" << setw(20) << "dia chi" << setw(15) << "Gioi tinh" << setw(15) << "Diem toan" << setw(15) << "Diem ly" << setw(15) << "Diem hoa" << setw(15) << "Tong";
	cout << "\n===============================================================================================================\n";
	for (int i = 0; i < biendem; i++)
	{
		if (a == st[i].SBD)
		{
			cout << left << setw(5) << st[i].SBD << setw(20) << st[i].tensv << setw(20) << st[i].diachi << setw(15) << st[i].sex << setw(15) << st[i].diemtoan << setw(15) << st[i].diemly << setw(15) << st[i].diemhoa << setw(15) << st[i].tong;
			cout << "\n";
			b = b + 1;
		}
	}
	if (b == 0) cout << "khong tim thay ket qua\n";
	return 0;
}
void model::tk_Ten()
{
	string a;
	int b = 0;
	cout << "nhap ho va ten ma ban muon tim:";
	cin.ignore(1);
	getline(cin, a);
	cout << left << setw(5) << "SBD" << setw(20) << "Ten" << setw(20) << "dia chi" << setw(15) << "Gioi tinh" << setw(15) << "Diem toan" << setw(15) << "Diem ly" << setw(15) << "Diem hoa" << setw(15) << "Tong";
	cout << "\n===============================================================================================================\n";
	for (int i = 0; i < biendem; i++)
	{
		if (a == st[i].tensv)

		{
			cout << left << setw(5) << st[i].SBD << setw(20) << st[i].tensv << setw(20) << st[i].diachi << setw(15) << st[i].sex << setw(15) << st[i].diemtoan << setw(15) << st[i].diemly << setw(15) << st[i].diemhoa << setw(15) << st[i].tong;
			cout << "\n";
			b = b + 1;
		}
	}
	if (b == 0) cout << "khong tim thay ket qua\n";
}

void model::tk_Diem()
{
	float a;
	int b = 0;
	cout << "nhap Diem ma ban muon tim:";
	cin >> a;
	cout << left << setw(5) << "SBD" << setw(20) << "Ten" << setw(20) << "dia chi" << setw(15) << "Gioi tinh" << setw(15) << "Diem toan" << setw(15) << "Diem ly" << setw(15) << "Diem hoa" << setw(15) << "Tong";
	cout << "\n===============================================================================================================\n";
	for (int i = 0; i < biendem; i++)
	{
		if (a == st[i].diemtoan || a == st[i].diemly || a == st[i].diemhoa)
		{
			cout << left << setw(5) << st[i].SBD << setw(20) << st[i].tensv << setw(20) << st[i].diachi << setw(15) << st[i].sex << setw(15) << st[i].diemtoan << setw(15) << st[i].diemly << setw(15) << st[i].diemhoa << setw(15) << st[i].tong;
			cout << "\n";
			b = b + 1;
		}
	}
	if (b == 0) cout << "khong tim thay ket qua\n";
}
void model::luu_tk()
{

	int n;
	cout << "Chon tim kiem muon luu lai:";
	cout << "\n1. Tim kiem theo tong diem" << "\n";
	cout << "2. Tim kiem theo SBD" << "\n";
	cout << "3. Tim kiem theo Ho va ten" << "\n";
	cout << "4. Tim kiemn theo Diem mot trong 3 mon" << "\n";
	cout << "Nhap tuy chon:";
	cin >> n;
	if (n > 0 && n < 5) {
		switch (n)
		{
		case 1: luu_tong(); break;
		case 2: luu_SBD(); break;
		case 3: luu_hoten();  break;
		case 4: luu_diem();  break;
		default:
			break;
		}
	}
	else cout << "chon sai\n";
}
void model::luu_tong()
{
	int b = 0;
	float a;
	ofstream tongdiem("tongdiem.txt");
	cout << "nhap tong diem ma ban muon tim:";
	cin >> a;
	tongdiem << left << setw(5) << "SBD" << setw(20) << "Ten" << setw(20) << "dia chi" << setw(15) << "Gioi tinh" << setw(15) << "Diem toan" << setw(15) << "Diem ly" << setw(15) << "Diem hoa" << setw(15) << "Tong";
	tongdiem << "\n===============================================================================================================\n";
	for (int i = 0; i < biendem; i++)
	{
		if (a == st[i].tong)
		{
			tongdiem << left << setw(5) << st[i].SBD << setw(20) << st[i].tensv << setw(20) << st[i].diachi << setw(15) << st[i].sex << setw(15) << st[i].diemtoan << setw(15) << st[i].diemly << setw(15) << st[i].diemhoa << setw(15) << st[i].tong;
			tongdiem << "\n";
			b = b + 1;
		}
	}
	if (b == 0) tongdiem << "khong tim thay ket qua\n";
	tongdiem.close();
}
void model::luu_SBD()
{
	int b = 0;
	string a;
	ofstream SBD("SBD.txt");
	cout << "nhap SBD ma ban muon tim:";
	cin >> a;
	SBD << left << setw(5) << "SBD" << setw(20) << "Ten" << setw(20) << "dia chi" << setw(15) << "Gioi tinh" << setw(15) << "Diem toan" << setw(15) << "Diem ly" << setw(15) << "Diem hoa" << setw(15) << "Tong";
	SBD << "\n===============================================================================================================\n";
	for (int i = 0; i < biendem; i++)
	{
		if (a == st[i].SBD)
		{
			SBD << left << setw(5) << st[i].SBD << setw(20) << st[i].tensv << setw(20) << st[i].diachi << setw(15) << st[i].sex << setw(15) << st[i].diemtoan << setw(15) << st[i].diemly << setw(15) << st[i].diemhoa << setw(15) << st[i].tong;
			SBD << "\n";
			b = b + 1;
		}
	}
	if (b == 0) SBD << "khong tim thay ket qua\n";
	SBD.close();
}
void model::luu_hoten()
{
	int b = 0;
	string a;
	ofstream hoten("hoten.txt");
	cout << "nhap ho ten ma ban muon tim:";
	cin >> a;
	hoten << left << setw(5) << "SBD" << setw(20) << "Ten" << setw(20) << "dia chi" << setw(15) << "Gioi tinh" << setw(15) << "Diem toan" << setw(15) << "Diem ly" << setw(15) << "Diem hoa" << setw(15) << "Tong";
	hoten << "\n===============================================================================================================\n";
	for (int i = 0; i < biendem; i++)
	{
		if (a == st[i].tensv)
		{
			hoten << left << setw(5) << st[i].SBD << setw(20) << st[i].tensv << setw(20) << st[i].diachi << setw(15) << st[i].sex << setw(15) << st[i].diemtoan << setw(15) << st[i].diemly << setw(15) << st[i].diemhoa << setw(15) << st[i].tong;
			hoten << "\n";
			b = b + 1;
		}
	}
	if (b == 0) hoten << "khong tim thay ket qua\n";
	hoten.close();
}
void model::luu_diem()
{
	int b = 0;
	float a;
	ofstream diem("diem.txt");
	cout << "nhap diem ma ban muon tim:";
	cin >> a;
	diem << left << setw(5) << "SBD" << setw(20) << "Ten" << setw(20) << "dia chi" << setw(15) << "Gioi tinh" << setw(15) << "Diem toan" << setw(15) << "Diem ly" << setw(15) << "Diem hoa" << setw(15) << "Tong";
	diem << "\n===============================================================================================================\n";
	for (int i = 0; i < biendem; i++)
	{
		if (a == st[i].diemtoan || a == st[i].diemly || a == st[i].diemhoa)
		{
			diem << left << setw(5) << st[i].SBD << setw(20) << st[i].tensv << setw(20) << st[i].diachi << setw(15) << st[i].sex << setw(15) << st[i].diemtoan << setw(15) << st[i].diemly << setw(15) << st[i].diemhoa << setw(15) << st[i].tong;
			diem << "\n";
			b = b + 1;
		}
	}
	if (b == 0) diem << "khong tim thay ket qua\n";
	diem.close();
}
void model::view_SBD()
{
	if (biendem > 0) {
		cout << left << setw(5) << "SBD" << setw(20) << "Ten" << setw(20) << "dia chi" << setw(15) << "Gioi tinh" << setw(15) << "Diem toan" << setw(15) << "Diem ly" << setw(15) << "Diem hoa" << setw(15) << "Tong";
		cout << "\n===============================================================================================================\n";
		for (int i = 0; i < biendem; i++)
		{
			for (int j = 0; j < biendem; j++)
			{
				if (st[i].SBD < st[j].SBD)
				{
					sinhvien x = st[i];
					st[i] = st[j];
					st[j] = x;
				}
			}
		}
		for (int i = 0; i < biendem; i++)
		{
			cout << left << setw(5) << st[i].SBD << setw(20) << st[i].tensv << setw(20) << st[i].diachi << setw(15) << st[i].sex << setw(15) << st[i].diemtoan << setw(15) << st[i].diemly << setw(15) << st[i].diemhoa << setw(15) << st[i].tong;
			cout << "\n";
		}
	}
	else cout << "khong co sinh vien\n";
}

void model::view_Ten()
{
	if (biendem > 0) {
	cout << left << setw(5) << "SBD" << setw(20) << "Ten" << setw(20) << "dia chi" << setw(15) << "Gioi tinh" << setw(15) << "Diem toan" << setw(15) << "Diem ly" << setw(15) << "Diem hoa" << setw(15) << "Tong";
	cout << "\n===============================================================================================================\n";
	for (int i = 0; i < biendem; i++)
	{
		for (int j = 0; j < biendem; j++)
		{
			if (st[i].tensv < st[j].tensv)
			{
				sinhvien x = st[i];
				st[i] = st[j];
				st[j] = x;
			}
		}
	}
	for (int i = 0; i < biendem; i++)
	{
		cout << left << setw(5) << st[i].SBD << setw(20) << st[i].tensv << setw(20) << st[i].diachi << setw(15) << st[i].sex << setw(15) << st[i].diemtoan << setw(15) << st[i].diemly << setw(15) << st[i].diemhoa << setw(15) << st[i].tong;
		cout << "\n";
	}
	}
	else cout << "khong co sinh vien\n";
}
void model::view_Tongdiem()
{
	if (biendem > 0) {
	cout << left << setw(5) << "SBD" << setw(20) << "Ten" << setw(20) << "dia chi" << setw(15) << "Gioi tinh" << setw(15) << "Diem toan" << setw(15) << "Diem ly" << setw(15) << "Diem hoa" << setw(15) << "Tong";
	cout << "\n===============================================================================================================\n";
	for (int i = 0; i < biendem; i++)
	{
		for (int j = 0; j < biendem; j++)
		{
			if (st[i].tong < st[j].tong)
			{
				sinhvien x = st[i];
				st[i] = st[j];
				st[j] = x;
			}
		}
	}
	for (int i = 0; i < biendem; i++)
	{
		cout << left << setw(5) << st[i].SBD << setw(20) << st[i].tensv << setw(20) << st[i].diachi << setw(15) << st[i].sex << setw(15) << st[i].diemtoan << setw(15) << st[i].diemly << setw(15) << st[i].diemhoa << setw(15) << st[i].tong;
		cout << "\n";
	}
	}
	else cout << "khong co sinh vien\n";
}
void model::tong_thisinh()
{
	cout << "tong so thi sinh la: " << biendem << "\n";
}
void model::tong_15()
{
	int i = 0;
	for (int j = 0; j < biendem; j++)
	{
		if (st[j].tong <= 15)
		{
			i = i + 1;
		}
	}
	cout << "tong so thi sinh la: " << i << "\n";
}

void model::tong_1520()
{
	int i = 0;
	for (int j = 0; j < biendem; j++)
	{
		if (st[j].tong > 15 && st[j].tong <= 20)
		{
			i = i + 1;
		}
	}
	cout << "tong so thi sinh la: " << i << "\n";
}

void model::tong_2025()
{
	int i = 0;
	for (int j = 0; j < biendem; j++)
	{
		if (st[j].tong <= 25 && st[j].tong > 20)
		{
			i = i + 1;
		}
	}
	cout << "tong so thi sinh la: " << i << "\n";
}

void model::tong_25()
{
	int i = 0;
	for (int j = 0; j < biendem; j++)
	{
		if (st[j].tong > 25)
		{
			i = i + 1;
		}
	}
	cout << "tong so thi sinh la: " << i << "\n";
}