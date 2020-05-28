// PL_labs_lab_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Вариант 20

#define _WIN32_WINNT 0x0501
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <windows.h>
#include <math.h>
#include <ctime>
#include <conio.h>
#include <tchar.h>
#include <stdlib.h>

using namespace std;

//http://www.yotx.ru/#!1/3_h/ubWwf7Wwf7Rgzhf23/aP9g/2DfT0qt7W9tb@yt70B3wHvQrd39g30SDbuxc8p4PN1iPG5dXuzub@0DBg==
double func_1(double x)
{
    double y = 1 / (pow(x, 2) + 2 * x + 1);
    return y;
}

//http://www.yotx.ru/#!1/3_h/ubWwf7Wwf7Rgzhf23/aP9g/2DfT0qt7V@A99Z39g/2STTsxs4p4/F0i/G4dXmxu7@1DwQ=
double func_2(double x)
{
    double y = 3 * pow(x, 2);
    return y;
}

void main()
{
    setlocale(LC_ALL, "RU");
    cout << "Вывод графиков" << endl;
    int start_step;
    int end_step;
    float count_step;

    cout << "Введите начало отрезка" << endl;
    cin >> start_step;

    cout << "Введите конец отрезка" << endl;
    cin >> end_step;

    cout << "Введите шаг" << endl;
    cin >> count_step;

    system("cls");

    HWND hwnd;
    wchar_t Title[200];
    GetConsoleTitle(Title, 1024); // Узнаем имя окна
    hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна
    RECT rc;
    GetClientRect(hwnd, &rc);
    int iWidth = rc.right;
    int iHeight = rc.bottom;
    HDC hdc = GetDC(hwnd);    // Получаем контекст для рисования
    HWND hWnd = GetConsoleWindow();
    hdc = GetDC(hWnd);
    HPEN p1, p2 = CreatePen(PS_SOLID, 2, RGB(155, 40, 0)); // Создаем красное перо
    p1 = (HPEN)SelectObject(hdc, p2);  // Заносим красное перо в контекст рисования
    int x = 0, y = 0, R = iWidth / 2;
    double fi = 0;

    COLORREF color = RGB(255, 25, 100);
    x = 0;
    for (float i = -10; i <= 10; i += 0.05)
    {
        MoveToEx(hdc, x, 50, NULL);
        LineTo(hdc, x + iWidth, 50);

        MoveToEx(hdc, 200, y, NULL);
        LineTo(hdc, 200, y + iHeight);

        x++;
    }

    x = 0;
    for (float i = start_step; i <= end_step; i += count_step)
    {
        double func_y_1 = func_1(i);
        double func_y_2 = func_2(i);
        SetPixel(hdc, x, 50 + func_y_2, RGB(248, 244, 255));
        SetPixel(hdc, x, 50 + func_y_1, RGB(100, 150, 55));
        x += 1;
    }

    SelectObject(hdc, p1);   // Возвращаем старое перо
    ReleaseDC(hwnd, hdc);    // Освобождаем контекст рисования
    DeleteObject(p2);       // Удаляем созданное перо
    _getch();
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
