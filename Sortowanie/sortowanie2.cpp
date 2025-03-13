#include <iostream>

using namespace std;

//kopcowanie

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// quick sort 

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//merge 

void merge(int t[], int l, int g, int r) {

    int h = g - l + 1; // Rozmiar tablicy u
    int m = r - g;     // Rozmiar tablicy v

    int* u = new int[h]; // Tablica pomocnicza
    int* v = new int[m]; // Tablica pomocnicza

    // Kopiuj do tablicy u z tablicy t
    copy(t + l, t + l + h, u);

    // Kopiuj do tablicy v z tablicy t
    copy(t + g + 1, t + g + 1 + m, v);

    int i = 0, j = 0;

    for (int k = l; i < h && j < m; ++k) {
        // Scalaj wyniki z tablic u i v do t
        if (u[i] < v[j]) {
            t[k] = u[i];
            ++i;
        }
        else {
            t[k] = v[j];
            ++j;
        }
    }

    // Skopiuj pozosta?? cz??? z tablicy u/v do t
    if (i < h) {
        copy(u + i, u + h, t + l + h);
    }
    else {
        copy(v + j, v + m, t + l + h);
    }

    delete[] u;
    delete[] v;
}

void mergeSort(int t[], int l, int r) {
    if (l < r) {
        int g = l + (r - l) / 2;
        mergeSort(t, l, g);
        mergeSort(t, g + 1, r);
        merge(t, l, g, r);
    }
}

int main() {


    int array[] = { 64, 25, 12, 22, 11 };
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Heap Sort: ";
    heapSort(array, size);
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
