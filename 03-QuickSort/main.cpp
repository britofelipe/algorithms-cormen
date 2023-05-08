#include <iostream>
#include <fstream>
#include <ctime>
#include <climits>
#include <windows.h>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* A, int p, int r) {
    int pivot = A[r];
    int i = p - 1;
    for(int j = p; j < r; j++) {
        if(A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i + 1;
}

void quickSortAux(int* A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSortAux(A,p,q-1);
        quickSortAux(A,q+1,r);
    }
}

void quickSort(int* vector, int vectorSize) {
    quickSortAux(vector, 0, vectorSize - 1);
}

void addRandomNumbersToVector(int* vector, int vectorSize) {
    // The numbers will be different each time the program runs
    srand(time(NULL));
    for(int i = 0; i < vectorSize; i++) {
        vector[i] = rand() % 10000;
    }
}

void printVector(int* vector, int vectorSize) {
    cout << "[ ";
    for(int i = 0; i < vectorSize; i++) {
        cout << vector[i] << " ";
    }
    cout << "]" << endl;
    cout << endl;
}

int main() {
    // Creating the vector
    int n = 100;
    int* vector = new int[n];

    addRandomNumbersToVector(vector, n);
    printVector(vector, n);

    quickSort(vector, n);
    printVector(vector, n);

    return 0;
}