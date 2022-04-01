// ProblemC.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int* compress(int** matrix, int n, int m);

int* compress(int** matrix, int n, int m)
{
    int* ans = new int[3 * n];
    int counter = 0;
    for (unsigned i = 0; i < n; ++i) {
        int non_zeros = 0;
        for (unsigned j = 0; j < m; ++j)
            if (matrix[i][j] != 0) {
                ++non_zeros;
                if (non_zeros > 3) {
                    delete[] matrix;
                    delete[] ans;
                    return nullptr;
                }
                ans[counter] = matrix[i][j];
                ++counter;
            }
    }
    delete[] matrix;
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int* compressed = compress(a, n, m);

    if (!compressed) return 0;

    for (int i = 0; i < n * 3; i++)
        cout << compressed[i] << " ";
    cout << endl;

    delete[] compressed;
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
