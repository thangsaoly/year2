#include <iostream>

using namespace std;

// Insert an element into the array at the specified position
void put(double *p_array, int inx, double value, int &n, int size) {
    // Check if the index is valid
    if(inx < 0 || inx > n || n >= size) {
        cout << "Out of bound!" << endl;
        return;
    }
    
    // Move elements at and after the index one position back
    for(int i = n; i > inx; i--) {
        p_array[i] = p_array[i-1];
    }
    
    // Insert the new value at the specified position
    p_array[inx] = value;
    
    // Increase the array length
    n++;
}

// Delete the element at the specified position in the array
void deleteElement(double *p_array, int inx, int &n) {
    // Check if the index is valid
    if(inx < 0 || inx >= n) {
        cout << "Out of bound!" << endl;
        return;
    }
    
    // Move elements after the index one position forward
    for(int i = inx; i < n-1; i++) {
        p_array[i] = p_array[i+1];
    }
    
    // Decrease the array length
    n--;
}

int main() {
    double array[100] = {5, 4, 3, 2, 1}; // Initial array as in the slide
    int n = 5; // Initial number of elements
    double *p_array = array;
    
    // Print the initial array
    cout << "Initial array:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Value: " << *(p_array+i) << endl;
    }
    cout << endl;
    
    // Insert 10 at index 2
    put(array, 2, 10, n, 100);
    
    // Print the array after insertion
    cout << "After inserting 10 at index 2:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Value: " << *(p_array+i) << endl;
    }
    cout << endl;
    
    // Delete the element at index 1
    deleteElement(array, 1, n);
    
    // Print the array after deletion
    cout << "After deleting element at index 1:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Value: " << *(p_array+i) << endl;
    }
    
    return 0;
}