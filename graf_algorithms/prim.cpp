#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string graf = "graf2.txt";
    ifstream f(graf);

    if (!f.is_open())
    {
        cout << "file open error" << endl;
    }

    int maxim = 0, count = 0;
    int i;


    while (f >> i)
    {
        count++;
        if ((count % 3 != 0) && (i - 1 > maxim))
        {
            maxim = i - 1;
        }
    };

    int** arrayy = new int* [maxim + 1];
    for (int i = 0; i < maxim + 1; i++)
    {
        arrayy[i] = new int[i];
    }

    int* arrayyy = new int[count];

    f.close();

    ifstream file(graf);

    if (!file.is_open())
    {
        cout << "file open error" << endl;
    }

    int p, j = 0;

    while (file >> p)
    {
        arrayyy[j] = p;
        j++;
    };

    file.close();

    for (int i = 0; i < count - 2; i = i + 3)
    {
        arrayy[arrayyy[i] - 1][arrayyy[i + 1] - 1] = arrayyy[i + 2];
    };

    int n = maxim + 1;
    bool* visited = new bool[n];
    memset(visited, false, sizeof(bool) * n);
    visited[0] = true;
    for (int l = 0; l < n - 1; l++)
    {
        int minx = -1, miny = -1;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && arrayy[i][j] > 0 && (miny == -1 || arrayy[i][j] < arrayy[miny][minx]))
                    {
                        miny = i, minx = j;
                    }
                }
            }
        }

        visited[minx] = true;
        cout << miny + 1 << ' ' << minx + 1 << endl;
    };

    delete[] arrayyy;

    system("pause");

    for (int i = 0; i < maxim + 1; i++)
    {
        delete[] arrayy[i];
    }


    delete[] visited;
};
