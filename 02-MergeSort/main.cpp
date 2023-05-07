#include <iostream>
#include <fstream>
#include <ctime>
#include <climits>
#include <windows.h>
using namespace std;

void printVector(int* vector, int vectorSize) {
    cout << "[ ";
    for(int i = 0; i < vectorSize; i++) {
        cout << vector[i] << " ";
    }
    cout << "]" << endl;
    cout << endl;
}

void merge(int* A, int p, int q, int r) {
    int infinity = INT_MAX;
    int n1 = q - p + 1; // number of elements in the first part
    int n2 = r - q; // number of elements in the second part

    int* L = new int[n1 + 1];
    int* R = new int[n2 + 1];

    for(int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    
    for(int j = 0; j < n2; j++) {
        R[j] = A[(q +  1) + j];
    }
    
    L[n1] = infinity; R[n2] = infinity;

    int i = 0;
    int j = 0;
    for(int k = p; k <= r; k++) {
        if(L[i] < R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSortAux(int *A, int p, int r) {
    if(p < r) {
        int q = (p + r)/2;
        mergeSortAux(A, p, q); // calls on the first half
        mergeSortAux(A, q + 1, r); // calls on the second half
        merge(A, p, q, r); // merge the sorted halves
    }
}

void mergeSort(int* vector, int vectorSize) {
    mergeSortAux(vector, 0, vectorSize - 1);
}

void addRandomNumbersToVector(int* vector, int vectorSize) {
    // The numbers will be different each time the program runs
    srand(time(NULL));
    for(int i = 0; i < vectorSize; i++) {
        vector[i] = rand() % 10000;
    }
}

int main() {
    // Creating the vector
    int n = 100;
    int* vector = new int[n];

    addRandomNumbersToVector(vector, n);
    printVector(vector, n);

    mergeSort(vector, n);
    printVector(vector, n);

    return 0;
}