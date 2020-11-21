#include <cstdlib>
#include <iostream>
#include <ctime>

void pop(int *&arr, int &size, int value) {
    size--;
    int *new_arr = new int[size];


    for (int i = 0; i < size; i++) {
        if (i != value) {
            new_arr[i] = arr[i];
        }   
    }

    delete [] arr;
    arr = new_arr;

}

void ShowArray(const int* const arr, const int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void FillArray(int* const arr, const int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand()%10;
    }
}

void copy_array(const int* const orig_arr, int* copy_arr, const int size) {
    delete [] copy_arr;
    copy_arr = new int[size];
    for (int i = 0; i < size; i++) {
        copy_arr[i] = orig_arr[i];
    }
}

void push_back(int *&arr, int &size,const int value) {
    int *newArr = new int[size+1];
    
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = value;

    size++;

    delete [] arr;
    arr = newArr;
}

void pop_back(int *&arr, int &size) {
    size--;
    int *newArr = new int[size];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    delete [] arr;
    arr = newArr;
}

int strlen_me(char *str) {
    int str_size = 0;
    while (str[str_size] != '\0') {
        str_size++;
    }
    return str_size;
}