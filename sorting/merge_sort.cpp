#include <iostream>
using namespace std;

template <typename T>
void merge_sort(T* arr1, T* arr2, T* arr3, int  n, int  m, int summary)
{
    for (int i = 0; i < n;)
    {
        for (int j = 0; j < m;)
        {
            T minim = 0;
            if ((arr1[i] - arr2[j]) < 0)
            {
                minim = arr1[i];
                i++;
                for (int k = 0; k < summary;k++)
                {
                    if (k != (summary - 1))
                    {
                        arr3[i + j - 1] = minim;
                    }
                    else
                    {
                        arr3[summary - 1] = minim;
                    }
                }

            }
            else {
                minim = arr2[j];
                j++;
                for (int k = 0; k < summary; k++)
                {
                    if (k != (summary - 1))
                    {
                        arr3[i + j - 1] = minim;
                    }
                    else
                    {
                        arr3[summary - 1] = minim;
                    }
                }
            }



        }
    }
}

int main()
{

    double first_arr[] = {5.64, 6.76, 9.08};
    double second_arr[] = {2, 5, 7, 9, 12};

    double final_arr [8];

    merge_sort <double>(first_arr, second_arr, final_arr, 3, 5, 8);

    for (int i = 0; i < 8; i++)
    {
        cout << final_arr[i] << endl;
    }
}
