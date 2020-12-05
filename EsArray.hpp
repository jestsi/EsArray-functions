#pragma once
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>


class EsArray{
    public:
#pragma region Конструкторы
        EsArray(int *arr, int size) {
            if (size > 0) {
                this->arr = arr;
                this->size = size;
            } else 
                std::cerr << "size minimum 1" << std::endl;
            srand(time(NULL));
        }

        EsArray(int size_arr) { 
            size = size_arr;
            arr = new int[size]{};
        }

        EsArray(const EsArray &other) {
            this->size = other.size;
            this->arr = new int[this->size]{};
        
        }
#pragma endregion

#pragma region Методы
        void copy_to_array(EsArray &in_copy_arr) {
            in_copy_arr.size = this->size;

            delete [] in_copy_arr.arr;

            in_copy_arr.arr = new int[this->size];

            for (int i = 0; i < this->size; i++) {
                in_copy_arr.arr[i] = this->arr[i];
            }
        }

        void copy_to_array(int *in_copy_arr) {
            delete [] in_copy_arr;
            in_copy_arr = new int[this->size];
            for (int i = 0; i < this->size; i++) {
                in_copy_arr[i] = arr[i];
            }
        }

        void showArray() {
            for (int i = 0; i < size; i++) {
                std::cout << arr[i] << ' ';
            }
            std::cout << std::endl;
        }

        void fillArray() {
            for (int i = 0; i < size; i++) {
                arr[i] = rand()%10;
            }
        }

        void push_end(const int value) {
            int *newArr = new int[this->size+1];
            
            for (int i = 0; i < this->size; i++) {
                newArr[i] = arr[i];
            }
            newArr[this->size] = value;

            this->size++;

            delete [] arr;
            arr = newArr;
        }

        void push_begin(const int value) {
            int *newArr = new int[this->size+1];
            newArr[0] = value;
            
            for (int i = 1; i < this->size; i++) {
                newArr[i] = arr[i];
            }

            this->size++;

            delete [] arr;
            arr = newArr;
        }

        void pop_end() {
            size--;
            int *temp_arr = new int[size];
            for (int i = 0; i < size; i++) {
                temp_arr[i] = arr[i];
            }
            delete [] arr;
            arr = temp_arr;
        }

        void pop_begin() {
            size--;
            int *temp_arr = new int[size];
            temp_arr[0] = arr[1];
            for (int i = 1; i < size; i++) {
                temp_arr[i] = arr[i];
            }
            delete [] arr;
            arr = temp_arr;
        }
#pragma endregion

#pragma region Перегрузки операторов
        bool operator == (const EsArray &other) {
            if (size == other.size) {
                for (int i = 0; i < size; i++) {
                    if (arr[i] != other.arr[i]) return 0;
                }
                return 1;
            } else return 0;
        }

        bool operator != (const EsArray &other) {
            if (size == other.size) {
                for (int i = 0; i < size; i++) {
                    if (arr[i] != other.arr[i]) return 1;
                }
                return 0;
            } else return 1;
        }

        int operator [] (int index) {
          if (index <= size && index > -1) {
            return arr[index];
          } else {
            std::cerr << (" \033[31mNot find value in \033[0m" + std::to_string(index) + "!") << std::endl;
            exit(1);
          }
        }

        EsArray &operator = (const EsArray &other) {
            if (this->arr != nullptr)
                delete [] this->arr;

            this->size = other.size;

            this->arr = new int[this->size];
            
            for (int i = 0; i < size; i++) {
                this->arr[i] = other.arr[i];
            }
            return *this;
        }

#pragma endregion

        ~EsArray() {
            delete [] arr;
            arr = nullptr;
        }
    private:
        int *arr;
        int size;
};