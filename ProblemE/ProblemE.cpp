// ProblemE.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>

uint32_t get_results(uint32_t channel)
{
    static uint32_t calls = 0;
    calls++;
    if (calls > 25) return static_cast<uint32_t>(-1);

    static uint32_t min = 10, max = 255760;
    static uint32_t min_channel = 50, max_channel = 250;
    static uint32_t zero = 100000;

    if (channel <= min_channel)
        return static_cast<uint32_t>(zero - channel * ((double)zero - min) / min_channel);
    if (channel <= max_channel)
        return static_cast<uint32_t>(min + ((double)channel - min_channel) * ((double)max - min) / ((double)max_channel - min_channel));
    if (channel <= 360)
        return static_cast<uint32_t>(max - ((double)channel - max_channel) * ((double)max - zero) / ((double)360 - max_channel));
    return static_cast<uint32_t>(-1);
}

void detect()
{
    uint32_t a[360];
    const uint32_t bad_val = static_cast<uint32_t>(-1);
    for (size_t i = 0; i < 360; ++i)
        a[i] = bad_val;
    size_t l = 0, r = 359, m = l + (r - l) / 2;
    uint32_t f0 = (a[0] == bad_val ? get_results(0) : a[0]);
    a[0] = f0;
    uint32_t fm = (a[m] == bad_val ? get_results(m) : a[m]);
    a[m] = fm;
    while (r - l > 1) {
        m = l + (r - l) / 2;
        fm = (a[m] == bad_val ? get_results(m) : a[m]);
        a[m] = fm;
        if (fm < f0)
            l = m;
        else {
            size_t m1 = m - 1;
            uint32_t fm1 = (a[m1] == bad_val ? get_results(m1) : a[m1]);
            a[m1] = fm1;
            if (fm > fm1)
                l = m;
            else
                r = m1;
        }
    }
    uint32_t fl = (a[l] == bad_val ? get_results(l) : a[l]);
    a[l] = fl;
    uint32_t fr = (a[r] == bad_val ? get_results(r) : a[r]);
    a[r] = fr;
    if (fl > fm && fl > fr)
        std::cout << l << ' ' << fl << '\n';
    else if (fm > fl && fm > fr)
        std::cout << m << ' ' << fm << '\n';
    else
        std::cout << r << ' ' << fr << '\n';
}

int main() {
    detect();
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
