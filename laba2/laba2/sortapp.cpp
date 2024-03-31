#include"sortapp.h"

void sortapp::bubble(int* &arr, int& length)
{
    for (int i = 0; i <length; i++) {
        for (int j = 0; j < length-1; j++) {
            if (arr[j] > arr[j + 1]) {
                int b = arr[j]; // ������� �������������� ����������
                arr[j] = arr[j + 1]; // ������ �������
                arr[j + 1] = b; // �������� ���������
            }
        }
    }

    cout << "������ � ��������������� ����: "<<endl;
}

void sortapp::choice(int* &arr, int &length)
{
    int min = 0; // ��� ������ ������������ ��������
    int buf = 0; // ��� ������ ���������� 

    /*********** ������ ���������� **************/
    for (int i = 0; i < length; i++)
    {
        min = i; // �������� ����� ������� ������, ��� ������ � ����������� ���������
        // � ����� ������ �������� ����� ������ � ����������� ���������
        for (int j = i + 1; j < length; j++)
            min = (arr[j] < arr[min]) ? j : min;
        // c������ ������������ ����� ��������, ������� ��� ������� � �������
        if (i != min)
        {
            buf = arr[i];
            arr[i] = arr[min];
            arr[min] = buf;
        }
    }
    /*********** ����� ���������� **************/

    for (int i = 0; i < length; i++){ //����� ���������������� �������
        cout << arr[i] << '\t';
    cout << endl;
}
}

void sortapp::insert(int*& arr, int &length)
{
    for (int i = 1; i < length; i++)
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) // ���� j>0 � ������� j-1 > j, x-������ int
            swap(arr[j - 1], arr[j]);        // ������ ������� �������� j � j-1
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
    // ������� ������������ �������� � �������
    int maxElement = arr[0];
    for (int i = 1; i < length; ++i) {
        maxElement = std::max(maxElement, arr[i]);
    }

    // ������� ������ ��� �������� ���������� ������ ������� ��������
    int* count = new int[maxElement + 1]();

    // ��������� ������ ��������
    for (int i = 0; i < length; ++i) {
        count[arr[i]]++;
    }

    // ��������� ������
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

    // ����������� ������, ���������� ��� ������� count
    delete[] count;
}