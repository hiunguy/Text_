#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

int cmpfunc(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{

    static int a[1000000];
    int n = 1000000;

    fstream fi;
    fi.open("File.txt", ios::in);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        fi >> a[i];
    }
    int size = sizeof(a) / sizeof(0);
    clock_t start, end;
    double time_use;
    start = clock();
    qsort(a, n, sizeof(float), cmpfunc);
    end = clock();
    time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << time_use;
    fi.close();
    return 0;

}