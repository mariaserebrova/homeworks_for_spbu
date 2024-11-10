#include <iostream>
#include <fstream>
#include <windows.h>
#include <cmath>
using namespace std;

static int arr[33];

int function(char ch)
{
    if ((int)ch != 32)
    {
        if (((int)ch >= -64) && ((int)ch <= -33))
        {
            arr[abs((int)ch + 32)] = arr[abs((int)ch + 32)] + 1;
        };

        if (((int)ch >= -32) && ((int)ch <= -1))
        {
            arr[abs((int)ch)] = arr[abs((int)ch)] + 1;
        };

    }
    else
    {
        arr[33] = arr[33] + 1;
    };


    return 0;
};

void hash2(string name)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream f;
    f.open("text.txt");

    if (!f.is_open())
    {
        cout << "file opening error";
    };

    char che;

    while (f.get(che))
    {
        function(che);
    };
    f.close();

    for (int i = 32; i > 0; i--)
    {
        cout << char(-1 * i) << " " << arr[i] << endl;
    };

    cout << " " << " " << arr[33] << endl;
}

int main()
{
    /*SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream f;
    f.open("text.txt");

    if (!f.is_open())
    {
        cout << "file opening error";
    };

    char che;

    while (f.get(che))
    {
        function(che);
    };
    f.close();

    for (int i = 32; i > 0; i--)
    {
        cout << char(-1 * i) << " " << arr[i] << endl;
    };

    cout << " " << " " << arr[33] << endl;*/

    string name = "text.txt";

    hash2(name);

};
