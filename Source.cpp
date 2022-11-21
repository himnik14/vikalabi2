#include <conio.h>
#include <windows.h>
#include <iostream>
#include <math.h>
#include <cstdio>
#include <vector>
using namespace std;
class Triangle 
{
	double side, firstAngle, secondAngle, sideTwo, sideThree;
public:
	Triangle();
	Triangle(double side, double firstAngle, double secondAngel);
	void SetSide(double side);
	void SetAngels(double firstAngle, double secondAngel);
	double GetSide();
	double GetFirstAngel();
	double GetSecondAngel();
	void ZoomTriangle();
	void ShowMediana();
	void SidesSize();
	double GetThirdAngel();
};
string Podobie(Triangle tr1, Triangle tr2) 
{
	if (tr1.GetFirstAngel() == tr2.GetFirstAngel() && tr1.GetSecondAngel() == tr2.GetSecondAngel())
		return "�������\n";
	else
		return "�� �������\n";
}
Triangle::Triangle()
{

}

Triangle::Triangle(double side, double firstAngle, double secondAngle) 
{
	if (side <= 0 || firstAngle <= 0 || secondAngle <= 0) {
		throw exception("������� ��� ���� �� ����� ���� ������ ��� ����� ����\n");
	}
	if (firstAngle + secondAngle >= 180) {
		throw exception("����� ���� ����� ������������ �� ����� ���� ������ ��� ������ 180 ��������\n");
	}
	this->firstAngle = firstAngle;
	this->side = side;
	this->secondAngle = secondAngle;
	sideTwo = (side * sin((secondAngle * 3.14) / 180)) / sin((GetThirdAngel() * 3.14) / 180);
	sideThree = (sideTwo * sin((firstAngle * 3.14) / 180)) / sin((secondAngle * 3.14) / 180);
}

double Triangle::GetFirstAngel()
{
	return firstAngle;
}
double Triangle::GetSecondAngel()
{
	return secondAngle;
}
double Triangle::GetSide()
{
	return side;
}
void Triangle::SetAngels(double firstAngle, double secondAngle)
{
	if (firstAngle <= 0 || secondAngle <= 0) {
		throw exception("���� �� ����� ���� ������ ��� ����� ����");
	}
	else if ((firstAngle + secondAngle) >= 180 ) {
		throw exception("����� ���� ����� ������������ �� ����� ���� ������ ��� ����� 180 ��������");
	}
	this->firstAngle = firstAngle;
	this->secondAngle = secondAngle;
}
void Triangle::SetSide(double side) 
{
	if (side <= 0 ) {
		throw exception("������� �� ����� ���� ������ ��� ����� ����");
	}
	this->side = side;
}
double Triangle::GetThirdAngel()
{
	return 180 - firstAngle - secondAngle;
}
void Triangle::SidesSize() 
{
	cout << "������� A: " << sideThree << "\n";
	cout << "������� B: " << sideTwo << "\n";
	cout << "������� C: " << side << "\n";
}
void Triangle::ZoomTriangle() // ���������� � ���� ��� ���� ���� ����� �����, ��� � ���������� � ���� ���
{
	cout << "���� �� ������ �������� ������� ������������, ������� �����.\n���� �� ������ ��������� �������, �� ������� ����� �� ������ �����.\n";
	double n;
	cin >> n;
	if (n > 0)
		side *= n;
	else if (n < 0)
		side = side * abs((1 / n)); // abs - ������ ����� 
	else
		side = side;
}
void Triangle::ShowMediana() 
{
	cout << "������� �� ������� A: " << 0.5 * sqrt(2 * pow(side, 2) + 2 * pow(sideTwo, 2) - pow(sideThree, 2)) << "\n";
	cout << "������� �� ������� B: " << (0.5) * sqrt(2*pow(sideThree, 2)+2*pow(side,2) - pow(sideTwo,2)) << "\n";
	cout << "������� �� ������� C: " << 0.5 * sqrt(2 * pow(sideThree, 2) + 2 * pow(sideTwo, 2) - pow(side, 2)) << "\n";
}




int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<Triangle> tr3;
	double firstAngle, secondAngle, side;
	for (int i = 0; i < 4; i++)
	{
		cout << "�������� " << i + 1 << " ������������..........\n";
		cout << "������� �������� ������� ������������: ";
		cin >> side;
		cout << "������� �������� �����:\n";
		cin >> firstAngle;
		cin >> secondAngle;
		try
		{
			tr3.push_back(Triangle(side, firstAngle, secondAngle));
		}
		catch (const std::exception& ex)
		{
			cout << ex.what();
		}
	}
	for (int i = 0; i < tr3.size(); i++)
	{
		cout << "����������� " << i + 1 << " ����� ���������:\n";
		tr3[i].ShowMediana();
		tr3[i].SidesSize();
	}
	int numberTriangle = 0; //����������� ��� ��������� ������� 
	for (int i = 0; i < tr3.size(); i++)
	{
		cout << "������������ "<< numberTriangle+1<< " � " << i+1 << " " << Podobie(tr3[numberTriangle], tr3[i]);
	}
}