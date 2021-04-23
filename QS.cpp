#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;



void quickSort(int a[], int l, int r)
{
	int p = a[(l + r) / 2];
	int i = l, j = r;
	while (i < j)
	{
		while (a[i] < p)
		{
			i++;
		}
		while (a[j] > p)
		{
			j--;
		}
		if (i <= j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r)
	{
		quickSort(a, i, r);
	}
	if (l < j)
	{
		quickSort(a, l, j);
	}
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
    clock_t start,end ;
    double time_use;
    start = clock();
    quickSort(a, 0, n - 1);
    end = clock();
    time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << time_use;
    fi.close();
    return 0;
}




 
