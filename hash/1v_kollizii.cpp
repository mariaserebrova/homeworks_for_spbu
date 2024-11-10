﻿#include <iostream>
#include <fstream>
#include <windows.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

class integer {
private:
	int* a;
public:
	integer();
	integer(const integer&);
	integer(int);
	~integer();
	int& operator[] (int) const;
	int length() const;
	void LevelUp();
	bool operator > (const integer&) const;
	bool operator < (const integer&) const;
	bool operator == (const integer&) const;
	bool operator >= (const integer&) const;
	bool operator <= (const integer&) const;
	friend istream& operator >> (istream&, integer&);
	friend ostream& operator << (ostream&, integer&);
	integer  operator + (const integer&) const;
	integer  operator * (const integer&) const;
	integer  operator - (const integer&) const;
	integer  operator / (const integer&) const;
	integer  operator % (const integer&) const;
	integer& operator +=(const integer&);
	integer& operator = (const integer&);
	integer& operator -=(const integer&);
	integer& operator *=(const integer&);
	integer& operator /=(const integer&);
};

const int N = 1000;
const int LL = 10;

integer::integer() {
	a = new int[N];
	for (int i = 0; i < N; ++i)
		a[i] = 0;
}

integer::integer(const integer& second) {
	a = new int[N];
	for (int i = 0; i < N; ++i)
		a[i] = second[i];
}

integer::integer(int noun) {
	a = new int[N];
	long long int ten = 1;
	for (int i = 0; i < LL; ++i) {
		a[i] = (noun / ten) % 10;
		ten = ten * 10;
	}
	for (int i = LL; i < N; ++i)
		a[i] = 0;
}

integer::~integer() {
	delete[]a;
}

int integer::length() const {
	int i = N - 1;
	while (a[i] == 0 && i > 0) i--;
	return i + 1;
}

int& integer::operator[](int i) const {
	return a[i];
}

bool integer::operator == (const integer& second) const {
	for (int i = 0; i < N; ++i)
		if (a[i] != second[i]) return false;
	return true;
}

bool integer::operator > (const integer& second) const {
	for (int i = N - 1; i >= 0; --i) {
		if (a[i] > second[i]) return true;
		if (a[i] < second[i]) return false;
	}
	return false;
}

bool integer::operator < (const integer& second) const {
	for (int i = N - 1; i >= 0; --i) {
		if (a[i] > second[i]) return false;
		if (a[i] < second[i]) return true;
	}
	return false;
}

bool integer::operator >= (const integer& second) const {
	return *this > second || *this == second;
}

bool integer::operator <= (const integer& second) const {
	return *this < second || *this == second;
}

ostream& operator << (ostream& out, integer& first) {
	int i = N - 1;
	while (i >= 0 && first[i] == 0)
		i--;
	if (i == -1) cout << 0;
	else
		for (int j = i; j >= 0; --j)
			out << first[j];
	return out;
}

istream& operator >> (istream& sin, integer& first) {
	char c;
	char buff[N];
	int i = 0;
	while (c = getchar()) {
		if (c == ' ' || c == '\0' || c == '\n' || c == '\t')
			break;
		buff[i] = c;
		i++;
	}
	bool b = false;
	for (int j = 0; j < i; ++j) {
		if (buff[i - j - 1] == '-')
			b = true;
		else
			first[j] = (int)buff[i - j - 1] - (int)'0';
	}
	if (b == true)
		first[first.length() - 1] *= -1;
	return sin;
}

integer integer::operator + (const integer& second) const {
	integer c, one = *this, two = second;
	int sum;

	if (*this > 0 && second < 0) {
		two[two.length() - 1] *= -1;
		return one - two;
	}
	if (*this < 0 && second > 0) {
		one[one.length() - 1] *= -1;
		return two - one;
	}

	bool b = false;
	if (*this < 0 && second < 0) {
		one[one.length() - 1] *= -1;
		two[two.length() - 1] *= -1;
		b = true;
	}

	for (int i = 0; i < N - 1; ++i) {
		sum = one[i] + two[i] + c[i];
		c[i] = sum % 10;
		c[i + 1] = sum / 10;
	}
	if (b == true)
		c[c.length() - 1] *= -1;
	return c;
}

integer integer::operator * (const integer& second) const {
	integer c, one = *this, two = second;
	bool check = false;

	if (*this < 0 && second > 0) {
		one[one.length() - 1] *= -1;
		check = true;
	}
	if (second < 0 && *this > 0) {
		two[two.length() - 1] *= -1;
		check = true;
	}
	if (*this < 0 && second < 0) {
		one[one.length() - 1] *= -1;
		two[two.length() - 1] *= -1;
	}

	for (int i = 0; i < N / 2; ++i)
		for (int j = 0; j < N / 2 - 1; ++j)
			c[i + j] = c[i + j] + one[i] * two[j];

	for (int i = 0; i < N - 1; ++i) {
		c[i + 1] = c[i + 1] + c[i] / 10;
		c[i] = c[i] % 10;
	}

	if (check == true)
		c[c.length() - 1] *= -1;
	return c;
}

integer& integer::operator = (const integer& second) {
	if (this == &second) return *this;
	for (int i = 0; i < N; ++i)
		a[i] = second[i];
	return *this;
}

integer integer::operator - (const integer& second) const {
	integer c;
	bool choose = false;

	if (*this < 0 && second < 0) {
		integer tempfirst = *this;
		integer tempsecond = second;
		tempfirst[length() - 1] *= -1;
		tempsecond[second.length() - 1] *= -1;
		integer Return = tempfirst + tempsecond;
		Return[Return.length() - 1] *= -1;
		return Return;
	}

	if (second < 0 && *this > 0) {
		integer temp = second;
		temp[temp.length() - 1] *= -1;
		return temp + *this;
	}
	if (second > 0 && *this < 0) {
		integer temp = *this;
		temp[temp.length() - 1] *= -1;
		return temp + *this;
	}

	integer one = *this, two = second;
	if (*this < second) {
		swap(one, two);
		choose = true;
	}

	for (int i = 0; i < N - 1; ++i) {
		c[i] = c[i] + 10 + one[i] - two[i];
		c[i + 1] = (c[i] >= 10) ? 0 : -1;
		c[i] = c[i] % 10;
	}

	int i = N - 1;
	while (c[i] != 0) {
		c[i] = 0;
		i--;
	}

	if (choose == true)
		c[c.length() - 1] *= -1;
	return c;
}

integer& integer::operator -= (const integer& second) {
	integer a = *this - second;
	return a;
}

void integer::LevelUp()
{
	for (int i = length(); i >= 1; i--)
		a[i] = a[i - 1];
}

integer integer::operator / (const integer& second) const
{
	integer res;
	integer curValue;
	integer one = *this, two = second;
	bool check = false;

	if (*this < 0 && second > 0) {
		one[one.length() - 1] *= -1;
		check = true;
	}
	if (*this > 0 && second < 0) {
		two[two.length() - 1] *= -1;
		check = true;
	}

	for (int i = one.length() - 1; i >= 0; i--)
	{
		curValue.LevelUp();
		curValue[0] = one.a[i];

		int x = 0;
		int l = 0, r = 10;
		while (l <= r)
		{
			int m = (l + r) >> 1;
			integer cur = two * m;
			if (cur <= curValue)
			{
				x = m;
				l = m + 1;
			}
			else
				r = m - 1;
		}
		res[i] = x;
		curValue = curValue - two * x;
	}

	int pos = length();
	while (pos >= 0 && !res[pos])
		pos--;
	if (check == true)
		res[res.length() - 1] *= -1;
	return res;
}

integer& integer::operator /= (const integer& second) {
	integer a = *this / second;
	return a;
}

integer integer::operator % (const integer& second) const {
	return *this - (*this / second) * second;
}




int randomNumber(int min, int max)
{
	srand(time(NULL));

	int num = min + rand() % (max - min + 1);
	this_thread::sleep_for(chrono::nanoseconds(2500000000));
	return num;
}

static integer p = 1;

integer f2(char ch)
{

	if (((((int)ch >= -64) && ((int)ch <= -1)) || ((int)ch == 32)) && ((int)ch != 0))
	{
		p = p * abs((int)ch);
	};

	return p;
};


static int arr[33];

int f1(char ch)
{

	if (((int)ch >= -64) && ((int)ch <= -33))
	{
		arr[abs((int)ch + 32)] = arr[abs((int)ch + 32)] + 1;
	};

	if (((int)ch >= -32) && ((int)ch <= -1))
	{
		arr[abs((int)ch)] = arr[abs((int)ch)] + 1;
	};

	return 0;
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string filename = "Старик и море.txt";

	ifstream f;
	f.open(filename);
	int min = 0, max = 0;
	char ge;
	while (f.get(ge))
	{
		max++;
	};
	f.close();
	max = max - 100;
	f.close();


	ifstream file;
	file.open(filename);

	int n;
	cin >> n;
	int consta;
	cin >> consta;
	int** general{ new int* [n] {} };
	for (unsigned i{}; i < n; i++)
	{
		general[i] = new int[33] {};
	};

	integer* generalanother = new integer[n]{};

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 33; j++)
		{
			general[i][j] = 0;
		};
	};

	for (int j = 0; j < n; j++)
	{
		int number;
		number = randomNumber(min, max);
		file.seekg(number, ios_base::beg);
		char ge;
		int count = 1;
		p = 1;

		while (count < consta)
		{
			file.get(ge);
			f1(ge);
			cout << ge;
			count++;
		};
		cout << endl;
		for (int i = 32; i > 0; i--)
		{
			general[j][i] = arr[i];
		};

		for (int g = 0; g < 33; g++)
		{
			arr[g] = 0;
		};

		integer ei = 1;
		count = 1;
		file.seekg(number, ios_base::beg);

		while (count < consta)
		{
			file.get(ge);
			ei = f2(ge);
			count++;
		};

		generalanother[j] = ei;
	};

	int flag = 0;
	for (int one = 0; one < n - 1; one++)
	{
		int sum1 = 0;

		for (int b = 0; b < 33; b++)
		{
			if (general[one][b] != 0)
			{
				sum1++;
			};
		};
		if (sum1 != 0)
		{


			for (int two = one + 1; two < n; two++)
			{
				int sum2 = 0;

				for (int variant = 0; variant < 33; variant++)
				{
					if ((general[one][variant] == general[two][variant]) && ((general[one][variant] != 0) && (general[two][variant] != 0)))
					{
						sum2++;
					};
				};
				if (sum2 == sum1)
				{
					flag++;
					for (int p = 0
						; p < 33; p++)
					{
						general[two][p] = 0;
					}
				};
			};
		};
	};

	cout << endl << "number of collisions with frequency: " << flag;

	int unic = 0;
	for (int first = 0; first < n - 1; first++)
	{
		for (int second = first + 1; second < n; second++)
		{
			if (generalanother[first] == generalanother[second])
			{
				unic++;
			};
		};
	};

	cout << endl << "the number of collisions with multiplication in ASCII: " << unic;

	file.close();
	for (unsigned l{}; l < n; l++)
	{
		delete[] general[l];
	}
	delete[] general;
	delete[] generalanother;
};
