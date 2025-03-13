#include <iostream>
#include <cmath>

using namespace std;

// 1 a

// O(1) stala
// T=c1*O(1)+n*c2*O(1)+c3*O(1)=n
int Max(int n, int tablica[]) {
    int max = tablica[0];  //zlozonosc O(1)

    for (int i = 0; i < n; i++) {
        if (tablica[i] > max) {
            max = tablica[i]; // Złożoność O(1)
        }
    }

    return max; //zlozonosc O(1)
}

// 1b 

// O(n log n)
// w pesymistycznych sytuacjach O(n2)  (np. gdy pivot jest zawsze minimalnym lub maksymalnym elementem)
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {  // Złożoność O(n)
            i++;
            swap(arr[i], arr[j]); // Złożoność O(n)
        }
    }
    swap(arr[i + 1], arr[high]); // Złożoność O(n)
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
       
        int pi = partition(arr, low, high); // Złożoność O(n)

     
        quickSort(arr, low, pi - 1); // Złożoność T(n/2) jedna z części będzie miała co najmniej połowę elementów, a druga część może być pusta.
        quickSort(arr, pi + 1, high); // Złożoność T(n/2)
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}




int main() {
    /*const int size1 = 10;  
    int tablica[size1] = { 11, 12, 13, 14, 9, 0 ,8  }; 

   cout<< Max(size1, tablica);*/

   int arr[] = { 12, 4, 5, 6, 7, 3, 1, 15 };
   int n = sizeof(arr) / sizeof(arr[0]);

   std::cout << "Given array: ";
   printArray(arr, n);

   quickSort(arr, 0, n - 1);  // Złożoność O(n log n)

   std::cout << "Sorted array: ";
   printArray(arr, n);





    return 0;



}