// PL_labs_lab_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Варинт 20: Даны натуральные числа n, a1..,an. Определить количество членов
// последовательности a1.., an:
// а) являющихся нечетными числами;
// 

#include <iostream>
#include <ctime>

void count_and_prin_multiple_by_and_not_by(int* arr, int size)
{
    int multiple_num_count = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 3 == 0 && arr[i] % 5 != 0)
        {
            multiple_num_count++;
        }
    }


    std::cout << "Количество элементов последовательности, где числа являются кратнми трем и не кратными пяти: " << multiple_num_count << "" << std::endl;
}

void count_odd(int* arr, int size)
{
    int odd_number_count = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0)
        {
            odd_number_count++;
        }
    }

    std::cout << "Количество элементов последовательности, где числа являются нечетными: " << odd_number_count << "" << std::endl;
}

int main()
{
    setlocale(LC_ALL, "russian");
    int array_size, ind;

    std::cout << "Set array size: ";
    std::cin >> array_size;

    int* array_of_num = new int[array_size];

    std::srand(time(NULL));

    for (int i = 0; i < array_size; i++)
    {
        int value;

        std::cout << "Input elem of array" << std::endl;
        std::cin >> value;

        array_of_num[i] = value;
    }

    for (size_t i = 0; i < array_size; i++)
    {
        std::cout << "Elemetn of array [" << i << "]: " << array_of_num[i] << "\t" << std::endl;
    }

    count_odd(array_of_num, array_size);
    count_and_prin_multiple_by_and_not_by(array_of_num, array_size);

    system("pause");
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
