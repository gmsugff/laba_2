#include"sortapp.h"

void sortapp::bubble(int* &arr, int& length)
{
    for (int i = 0; i <length; i++) {
        for (int j = 0; j < length-1; j++) {
            if (arr[j] > arr[j + 1]) {
                int b = arr[j]; // создали дополнительную переменную
                arr[j] = arr[j + 1]; // меняем местами
                arr[j + 1] = b; // значения элементов
            }
        }
    }

    cout << "Массив в отсортированном виде: "<<endl;
}

void sortapp::choice(int* &arr, int &length)
{
    int min = 0; // для записи минимального значения
    int buf = 0; // для обмена значениями 

    /*********** Начало сортировки **************/
    for (int i = 0; i < length; i++)
    {
        min = i; // запомним номер текущей ячейки, как ячейки с минимальным значением
        // в цикле найдем реальный номер ячейки с минимальным значением
        for (int j = i + 1; j < length; j++)
            min = (arr[j] < arr[min]) ? j : min;
        // cделаем перестановку этого элемента, поменяв его местами с текущим
        if (i != min)
        {
            buf = arr[i];
            arr[i] = arr[min];
            arr[min] = buf;
        }
    }
    /*********** Конец сортировки **************/

    for (int i = 0; i < length; i++){ //Вывод отсортированного массива
        cout << arr[i] << '\t';
    cout << endl;
}
}

void sortapp::insert(int*& arr, int &length)
{
    for (int i = 1; i < length; i++)
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) // пока j>0 и элемент j-1 > j, x-массив int
            swap(arr[j - 1], arr[j]);        // меняем местами элементы j и j-1
}

void sortapp::counting(int* &arr, int& length)
{
    int k = *max_element(arr, arr + length) + 1;

    int* count = new int[k]();
    for (int i = 0; i < length; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i < k; i++) {
        count[i] += count[i - 1];
    }

    int* output = new int[length];
    for (int i = length - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < length; i++) {
        arr[i] = output[i];
    }

    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }

    delete[] count;
    delete[] output;
}

void sortapp::digtal(int* &arr, int &length)
{
    // Находим максимальное значение в массиве
    int maxElement = arr[0];
    for (int i = 1; i < length; ++i) {
        maxElement = std::max(maxElement, arr[i]);
    }

    // Создаем массив для подсчета количества встреч каждого элемента
    int* count = new int[maxElement + 1]();

    // Заполняем массив подсчета
    for (int i = 0; i < length; ++i) {
        count[arr[i]]++;
    }

    // Сортируем массив
    int index = 0;
    for (int i = 0; i <= maxElement; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Освобождаем память, выделенную для массива count
    delete[] count;
}