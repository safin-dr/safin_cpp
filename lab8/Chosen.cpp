#include <iostream>

using namespace std;

void Merge(int *A, int first, int last) {
    int mid, start, final;
    int *new_arr = new int[100];
    mid = (first + last) / 2;
    start = first;
    final = mid + 1;

    for (int j = first; j <= last; j++)
        if ((start <= mid) && ((final > last) || (A[start] < A[final]))) {
            new_arr[j] = A[i];
            start++;
            }
        else {
            new_arr[j] = A[final];
            final++;
        }

  for (int j = first; j <= last; j++)
    A[j] = new_arr[j];
  delete[] new_arr;
};

void MergeSort(int *A, int first, int last) {
    if (first < last) {
        MergeSort(A, first, (first + last) / 2);
        MergeSort(A, (first + last) / 2 + 1, last);
        Merge(A, first, last);
    }
}

void main() {
    setlocale(LC_ALL, "Rus");
    int i, n;
    int *A = new int[100];
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> A[i];

    MergeSort(A, 1, n);
    for (i = 1; i <= n; i++)
        cout << A[i] << " ";
    delete[] A;
    system("pause>>void");
}
