#pragma once
#include<iostream>
#include<string>
using namespace std;
class model
{
public:
	class sinhvien
	{
	public:
		string SBD;
		string tensv;
		string diachi;
		string sex;
		float diemtoan;
		float diemly;
		float diemhoa;
		float tong;
	};
	int biendem = 0;
	sinhvien st[50];
	void tuychon(int n);
	void them_sv();
	int search(class sinhvien st[], string SBD, int biendem);
	void capnhat_banghi(class sinhvien st[], int biendem);
	void xoa_banghi(class sinhvien st[], int& biendem);
	void clean(class sinhvien st[], int index);
	void nhap_banphim();
	void tk_tongdiem();
	int tk_SBD();
	void tk_Ten();
	void tk_Diem();
	void luu_tk();
	void luu_tong();
	void luu_SBD();
	void luu_hoten();
	void luu_diem();
	void view_SBD();
	void view_Ten();
	void view_Tongdiem();
	void tong_thisinh();
	void tong_15();
	void tong_1520();
	void tong_2025();
	void tong_25();

};

