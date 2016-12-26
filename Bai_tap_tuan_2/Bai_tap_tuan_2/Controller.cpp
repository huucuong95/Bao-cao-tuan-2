#include<iostream>
#include"model.h"
#include"view.h"
#include"Controller.h"
using namespace std;
void main()
{
	char confirm;
	int n;
	view a;
	model b;
	do
	{
	a.Menu();
	cout << "nhap vao tuy chon:";
	cin >> n;
	b.tuychon(n);
	cout << "Nhap y hoac Y de tiep tuc:";
	cin >> confirm;
	} while (confirm == 'y' || confirm == 'Y');
}