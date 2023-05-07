#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
using namespace std;

void insertionSort(int* vector, int vectorSize) {
    // See the algorithm as a game of
    int j, newCard;
    for(int i = 1; i < vectorSize; i++) {
        newCard = vector[i];
        j = i - 1;
        while(j >= 0 && vector[j] > newCard) {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = newCard;
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

void addRandomNumbersToVector(int* vector, int vectorSize) {
    // The numbers will be different each time the program runs
    srand(time(NULL));
    for(int i = 0; i < vectorSize; i++) {
        vector[i] = rand() % 10000;
    }
}

int main() {
    // Creating the vector
    int vectorSize = 100;
    int* vector = new int[vectorSize];

    addRandomNumbersToVector(vector, vectorSize);
    printVector(vector, vectorSize);

    insertionSort(vector, vectorSize);
    printVector(vector, vectorSize);

    return 0;
}