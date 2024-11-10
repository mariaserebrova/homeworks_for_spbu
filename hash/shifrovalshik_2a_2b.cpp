
#include <iostream>
#include <fstream>
using namespace std;

void shifr(string old_name, string new_name)
{
    string str;
    ifstream fin;
    fin.open(old_name);
    int k = 0;
    if (!fin.is_open())
    {
        cout << "file open error" << endl;
    }
    else
    {

        char ch;


        while (fin.get(ch))
        {
            str += ch;
            k += 1;
        }


    }


    /*for (int i = 0; i < k; i++)
    {
        cout << (char)((int)str[i] + 1);
    }*/

    ofstream fout;

    fout.open(new_name);

    if (!fout.is_open())
    {
        cout << "file open error";
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            fout << (char)((int)(str[i] + 10));
        }
    }
}

void deshifr(string new_name, string old_name)
{
    string str;
    ifstream fin;
    fin.open(new_name);
    int k = 0;
    if (!fin.is_open())
    {
        cout << "file open error" << endl;
    }
    else
    {

        char ch;


        while (fin.get(ch))
        {
            str += ch;
            k += 1;
        }


    }


    /*for (int i = 0; i < k; i++)
    {
        cout << (char)((int)str[i] + 1);
    }*/

    ofstream fout;

    fout.open(old_name);

    if (!fout.is_open())
    {
        cout << "file open error";
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            fout << (char)((int)(str[i] - 10));
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    ofstream fout;

    fout.open("text.txt");

    if (!fout.is_open())
    {
        cout << "file open error";
    }
    else
    {
        fout << " ";
    }

    /*ifstream fin;
    string str;
    string name = "text.txt";
    fin.open(name);
    int k = 0;
    if (!fin.is_open())
    {
        cout << "file open error" << endl;
    }
    else
    {

        char ch;


        while (fin.get(ch))
        {
            str += ch;
            k += 1;
        }


    }
    cout << k<< "\n";

    for (int i = 0; i < k; i++)
    {
        cout << (char)((int)str[i]+10);
    }*/

    string old_name = "text2.txt";
    string new_name = "text_shifr_vivod.txt";
    string nachalo = "text_deshifr_vivod.txt";

    shifr(old_name, new_name);

    deshifr(new_name, nachalo);



}
