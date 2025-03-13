#include <iostream>

using namespace std;




void bubbleSort(int arr[], int n) {
    bool swapped;

    do {
        swapped = false;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
               swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
        --n;
    } while (swapped);
}




void selekcjaSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}




void Shell_sort(int t[], int N) {
    int h, i, j, x;

    for (h = 1; h < N; h = 3 * h + 1);

    h /= 9;
    if (!h) h++;

    for (; h > 0; h /= 3) {
        for (j = h; j < N; ++j) {
            x = t[j];

            for (i = j - h; i >= 0 && x < t[i]; i -= h) {
                t[i + h] = t[i];
            }

            t[i + h] = x;
        }
    }
}



int main() {



    int array[] = {64, 25, 12, 22, 11};
    int size = sizeof(array) / sizeof(array[0]);


    

    cout << "Tablica przed posortowaniem: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    bubbleSort(array, size);

    cout << "Tablica po posortowaniu babelkowym: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

	return 0;
}
