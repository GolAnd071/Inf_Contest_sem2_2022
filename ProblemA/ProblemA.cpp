// ProblemA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ss, ll, l;
	cin >> n;
	vector<pair<int, int>> c(n);
	for (int i = 0; i < n; ++i) {
		cin >> ss >> ll;
		c[i] = make_pair(ss, ll);
	}
	sort(c.begin(), c.end(), [](const pair<int, int> a, const pair<int, int> b) { return a.first < b.first; });
	cin >> l;
	if (n == 0 || c[0].first >= l) {
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < n - 1; ++i)
		if (c[i + 1].first - c[i].first - c[i].second >= l) {
			cout << c[i].first + c[i].second << '\n';
			return 0;
		}
	if (30 - c[n - 1].first - c[n - 1].second >= l) {
		cout << c[n - 1].first + c[n - 1].second << '\n';
		return 0;
	}
	cout << "-1\n";
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
