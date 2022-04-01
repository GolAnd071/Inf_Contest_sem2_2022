// ProblemE.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

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
    unsigned l = 0, r = 359;
    while (r - l > 2) {
        unsigned m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        uint32_t res1 = get_results(m1), res2 = get_results(m2);
        if (res1 < res2)
            l = m1;
        else
            r = m2;
    }
    std::cout << l << ' ' << get_results(l) << '\n';
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
