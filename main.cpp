#include <iostream>
using namespace std;

// function to print array
void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

// function to merge two arrays
// first array: array[l_idx..m]
// second array: array[m+1..r_idx]
void merge(int array[], int l_idx, int middle_idx, int r_idx) {
    int size_l = middle_idx - l_idx + 1;
    int size_r = r_idx - middle_idx;

    // define divided arrays left/right
    int array_l[size_l], array_r[size_r];
    for (int i = 0; i < size_l; i++) {
        array_l[i] = array[l_idx + i];
    }
    for (int j = 0; j < size_r; j++) {
        array_r[j] = array[middle_idx + 1 + j];
    }

    // merge left and right arrays
    int i = 0; // index of left array
    int j = 0; // index of right array
    int k = l_idx; // index of merged array
    while (i < size_l && j < size_r) {
        if (array_l[i] <= array_r[j]) {
            array[k] = array_l[i];
            i++;
        }
        else {
            array[k] = array_r[j];
            j++;
        }
        k++;
    }

    // copy remaining elements of left array
    while (i < size_l) {
        array[k] = array_l[i];
        i++;
        k++;
    }

    // copy remaining elements of right array
    while (j < size_r) {
        array[k] = array_r[j];
        j++;
        k++;
    }
}

// function to sort array by merge sort algorithm
// input1: input array
// input2: index from left
// input3: index from right
void merge_sort(int array[], int l_idx, int r_idx) {
    if (l_idx >= r_idx) {
        return;
    }
    int middle_idx = (l_idx + r_idx - 1)/2;
    merge_sort(array, l_idx, middle_idx);
    merge_sort(array, middle_idx+1, r_idx);
    merge(array, l_idx, middle_idx, r_idx);
}

int main() {
    int array[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Input array: ";
    print_array(array, size);

    merge_sort(array, 0, size - 1);

    cout << "\nSorted array: ";
    print_array(array, size);

    return 0;
}
