// PL_labs_lab_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Вариант 20

#include <iostream>

struct BookStruct
{
    std::string Author;
    std::string Name;
    int year;
};

void print_BookStruct(BookStruct book)
{
    std::cout << "Автор: " << book.Author << "\tНазвание: " << book.Name << "\tГод издания: " << book.year << ";" << std::endl;
}

BookStruct* sort_asc_by_author(BookStruct* arr)
{
    int t = 1;
    BookStruct tmp;

    for (int j = 0; j < sizeof(arr); j++)
    {
        for (int i = j; i < sizeof(arr); i++)
        {
            t = arr[i].Author < arr[t].Author ? i : t;
        }

        tmp = arr[j];
        arr[j] = arr[t];
        arr[t] = tmp;
    }
    
    return arr;
}

int main()
{
    setlocale(LC_ALL, "russian");

    BookStruct* library = new BookStruct[4];

    library[0] = { "James", "Sea of world", 2000 };
    library[1] = { "Robert", "People of Mars", 1998 };
    library[2] = { "AOspa", "Med", 2012 };
    library[3] = { "Picard", "Picard in space", 2020 };


    for (size_t i = 0; i < sizeof(library); i++)
    {
        print_BookStruct(library[i]);
    }

    std::cout << std::endl;

    library = sort_asc_by_author(library);

    for (size_t i = 0; i < sizeof(library); i++)
    {
        print_BookStruct(library[i]);
    }

    std::cout << std::endl;
    std::cout << "Список книг после 2000 года издания" << std::endl;

    for (size_t i = 0; i < sizeof(library); i++)
    {
        if (library[i].year > 2000)
            print_BookStruct(library[i]);
    }
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
