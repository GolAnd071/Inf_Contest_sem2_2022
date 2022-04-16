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

// If we have increasing segment first, reverse input of the function
uint32_t getRes(uint32_t ch, uint32_t arr[], bool rev = false)
{
    uint32_t bad_val = static_cast<uint32_t>(-1);
    uint32_t f = (arr[ch] == bad_val ? get_results(rev ? 359 - ch : ch) : arr[ch]);
    arr[ch] = f;
    return f;
}

void detect()
{
    // Memoization
    uint32_t a[360];
    const uint32_t bad_val = static_cast<uint32_t>(-1);
    for (size_t i = 0; i < 360; ++i)
        a[i] = bad_val;
    size_t l = 0, r = 359, m = l + (r - l) / 2;
    uint32_t f0 = getRes(0, a);
    uint32_t f359 = getRes(359, a);
    // Determine function type
    bool rev = false;
    if (f359 < f0)
        rev = true;
    f0 = getRes(0, a, rev);
    f359 = getRes(359, a, rev);
    uint32_t fm = getRes(m, a, rev);
    // Binary search
    while (r - l > 1) {
        m = l + (r - l) / 2;
        fm = getRes(m, a, rev);
        if (fm < f0)
            l = m;
        else {
            size_t m1 = m - 1;
            uint32_t fm1 = getRes(m1, a, rev);
            if (fm > fm1)
                l = m;
            else
                r = m1;
        }
    }
    uint32_t fl = getRes(l, a, rev);
    uint32_t fr = getRes(r, a, rev);
    if (fl >= fm && fl >= fr)
        std::cout << fl << ' ' << (rev ? 359 - l : l) << '\n';
    else if (fm >= fl && fm >= fr)
        std::cout << fm << ' ' << (rev ? 359 - m : m) << '\n';
    else
        std::cout << fr << ' ' << (rev ? 359 - r : r) << '\n';
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
