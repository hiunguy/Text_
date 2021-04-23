#include <iostream>
#include<fstream>
using namespace std;


void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

   
    if (l < n && arr[l] > arr[largest])
        largest = l;

   
    if (r < n && arr[r] > arr[largest])
        largest = r;

  
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
        clock_t start, end;
        double time_use;
        start = clock();
        heapSort(a, n);
        end = clock();
        time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
        cout << time_use;
        fi.close();
        return 0;

}