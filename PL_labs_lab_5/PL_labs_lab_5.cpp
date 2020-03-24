// PL_labs_lab_5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Вариант 20

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

void init_f1()
{
    std::cout << "Введите текст содержащий символы: ! и :" << std::endl;
    std::string hello_message;
    std::getline(std::cin, hello_message);

    std::ofstream out_stream;
    out_stream.open("F1.txt");
    if (out_stream.is_open())
    {
        out_stream << hello_message << std::endl;
    }
}

std::string read_file(std::string file_name)
{
    std::string data, out_str;

    std::ifstream in(file_name);
    if (in.is_open())
    {
        while (getline(in, data))
        {
            out_str += data;
        }
    }
    in.close();

    return out_str;
}

void save_f2(std::string str)
{
    std::ofstream out_stream;
    out_stream.open("F2.txt");
    if (out_stream.is_open())
    {
        out_stream << str << std::endl;
    }
}

std::string replace(std::string str)
{
    int c_dot = 0;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '!')
        {
            str[i] = '.';
        }
        else if (str[i] == ':')
        {
            str.replace(i, 1, "...");
        }
    }

    return str;
}

int main()
{
    setlocale(LC_ALL, "russian");

    init_f1();
    
    std::string text = read_file("F1.txt");
    std::cout << "Текст из файла F1:\n" << text << std::endl;

    text = replace(text);

    save_f2(text);
    text = read_file("F2.txt");

    std::cout << "Текст из файла F2:\n" << text << std::endl;

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
