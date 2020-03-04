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

using namespace std;

BOOL Line(HDC hdc, int x1, int y1, int x2, int y2) {
    MoveToEx(hdc, x1, y1, NULL);
    return LineTo(hdc, x2, y2);
}

string makeLine(int n) {
    string str = "";
    for (int i = 0; i < n; i++) {
        str += "-";
    }
    return str;
}

int main() {
    system("color f0");

    cout << makeLine(19);

    printf("\n| x\t|y=3x^2|\n");

    cout << makeLine(19);
    for (float x = -M_PI + 0.3f; x <= M_PI; x += 1.0f) {
        printf("\n|");
        if (x > 0)
            printf(" ");
        printf("%.2f\t|", x);
        if ((3 * pow(x, 2)) > 0)
            printf(" ");
        double f = (3 * pow(x, 2));
        printf("%.2f\t  |", f);

    }

    //printf("\n| %.2f\t|%.2f\t  |", Pi, tanh(Pi)); 
    cout << "\n" << makeLine(19);

    int x = 400;
    int y = 200;
    double a = 1;
    int b = 2;

    cout << '\t';
    cout << '\t';
    cout << '\t';
    cout << '\t';
    cout << '1';
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << '\t';
    cout << '\t';
    cout << '\t';
    cout << '\t';
    cout << "          - 1";
    cout << '\t';
    cout << '0';
    cout << "       1";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;


    cout << '\t';
    cout << '\t';
    cout << '\t';
    cout << '\t';
    cout << '\t';
    cout << '\t';
    cout << "-1";
    
    srand ( time(NULL) );
    HWND hWnd = GetConsoleWindow();
    HDC hDc = GetDC(hWnd);

    COLORREF color = RGB(0, 0, 0);
    HPEN pen = CreatePen(PS_SOLID, 1, color);
    SelectObject(hDc, pen);
    Line(hDc, x, 0, x, 2 * y);
    Line(hDc, 100, y, 2 * x, y);


    COLORREF c2 = color;
    SetPixel(hDc, x + 1, 2, color);
    SetPixel(hDc, x + 2, 3, color);
    SetPixel(hDc, x + 3, 4, color);

    SetPixel(hDc, x - 1, 2, color);
    SetPixel(hDc, x - 2, 3, color);
    SetPixel(hDc, x - 3, 4, color);

    SetPixel(hDc, 2 * x - 2, y - 1, color);
    SetPixel(hDc, 2 * x - 3, y - 2, color);
    SetPixel(hDc, 2 * x - 4, y - 3, color);

    SetPixel(hDc, 2 * x - 2, y + 1, color);
    SetPixel(hDc, 2 * x - 3, y + 2, color);
    SetPixel(hDc, 2 * x - 4, y + 3, color);

    for (int i = 100; i < 600; i += 50) {
        Line(hDc, i, y - 2, i, y + 2);
    }
    for (int i = 0; i < y * 2; i += 45) {
        Line(hDc, x - 2, i + 19, x + 2, i + 19);
    }
    for (int i = 100; i < 800; i += 4) {
        Line(hDc, i, 110, i + 2, 110);
    }
    for (int i = 100; i < 800; i += 4) {
        Line(hDc, i, 290, i + 2, 290);
    }
    for (double x1 = -250; x1 < 250; x1++) {
        double y1 = 3 * pow(x1, 2);
        SetPixel(hDc, x1 + x, y - y1, color);
    }

    int xD;
    cin >> xD;

    ReleaseDC(hWnd, hDc);
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
