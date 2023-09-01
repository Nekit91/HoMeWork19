#include<iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int del(int a, int b) {
    if (b == 0) {
        return a;
    }
    return del(b, a % b);
}

int mirror_number(int num) {
    int mirror = 0;
    while (num > 0) {
        mirror = mirror * 10 + num % 10;
        num /= 10;
    }
    return mirror;
}

int findAndSort(int arr[], int length, int N) {
    int index = -1;
    for (int i = 0; i < length; i++) {
        if (arr[i] == N) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        std::sort(arr + index + 1, arr + length);
    }
    return index;
}

void fillArray(int* arr1, int length2, int A, int B) {
    srand(time(NULL));

    for (int i = 0; i < length2; i++) {
        arr1[i] = rand() % (B - A + 1) + A;
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    int num1, num2;
    std::cout << "Задача1:\nВведите два числа: ";
    std::cin >> num1 >> num2;
    int result = del(num1, num2);
    std::cout << "Наибольший общий делитель: " << result << std::endl;

    int num;
    std::cout << "Задача2:\nВведите число: ";
    std::cin >> num;
    int mirroredNum = mirror_number(num);
    std::cout << "Отраженное число: " << mirroredNum << std::endl;

    int arr[] = { 5, 2, 7, 4, 9, 6, 1, 8, 3 };
    int length = sizeof(arr) / sizeof(arr[0]);
    int N = 2;
    int index = findAndSort(arr, length, N);
    if (index != -1) {
        std::cout << "Первая позиция числа " << N << ": " << index << std::endl;
        std::cout << "Массив после сортировки: ";
        for (int i = 0; i < length; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Элемент " << N << " не найден" << std::endl;
    }

    int length2;
    int A, B;
    std::cout << "Введите длину массива: ";
    std::cin >> length2;
    std::cout << "Введите начало диапазона: ";
    std::cin >> A;
    std::cout << "Введите конец диапазона: "; \
        std::cin >> B;

    int* arr1 = new int[length2];

    fillArray(arr, length2, A, B);

    std::cout << "Случайные числа в диапазоне [" << A << ", " << B << "]:" << std::endl;
    for (int i = 0; i < length2; i++) {
        std::cout << arr1[i] << " ";
        std::cout << std::endl;
    }

    return 0;
}