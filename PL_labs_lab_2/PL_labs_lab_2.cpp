// PL_labs_lab_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Вариант 20

#include <iostream>

int find_min_in_matrix(int** matrix, int size)
{
    int min = 0;

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            min = std::fmin(matrix[i][j], min);
        }
    }

    return min;
}

void prinM(int** matrix, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

int** delete_line_and_column(int** matrix, int size, int line, int column)
{
    int x = 0;
    int** output_matrix = new int* [size - 1];

    for (int i = 0; i < size; ++i)
    {
        output_matrix[i] = new int[size -1];
        int y = 0;
        
        if (i != line) 
        {
            for (int j = 0; j < size; ++j) 
            {
                if (j != column) {
                    output_matrix[x][y] = matrix[i][j];
                    ++y;
                }
            }
            ++x;
        }
    }

    return output_matrix;
}

int** manual_fill_matrix(int size)
{
    int** matrix_of_num = new int* [size];

    for (size_t i = 0; i < size; i++)
    {
        matrix_of_num[i] = new int[size];

        for (size_t j = 0; j < size; j++)
        {
            std::cout << "Set element: ";
            std::cin >> matrix_of_num[i][j];
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;

    return matrix_of_num;
}

int main()
{
    setlocale(LC_ALL, "russian");
    int matrix_size, column_ind;

    std::cout << "Set matrix size: ";
    std::cin >> matrix_size;

    int** matrix_of_num = manual_fill_matrix(matrix_size);

    prinM(matrix_of_num, matrix_size);

    //Find min
    int min = find_min_in_matrix(matrix_of_num, matrix_size);

    //Find position
    int col_ind, row_ind;

    for (size_t i = 0; i < matrix_size; i++)
    {
        for (size_t j = 0; j < matrix_size; j++)
        {
            if (matrix_of_num[i][j] == min)
            {
                col_ind = j;
                row_ind = i;
            }
        }
    }
    std::cout << "Min num in matrix: "<< min << "; position: ["<< row_ind << "; "<< col_ind <<"]" << std::endl;

    matrix_of_num = delete_line_and_column(matrix_of_num, matrix_size, row_ind, col_ind);

    prinM(matrix_of_num, matrix_size - 1);
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
