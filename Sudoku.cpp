#include <iostream>
#include <locale>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

#include "Game.hpp"

// -----
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <string>
#include <concepts>
#include <cstddef>
// -----


template <class T>
concept Numeric = std::integral<T> || std::floating_point<T>; // ограничение типов 

template <Numeric T>
long double mean(const std::vector<T>& v) {
    if (v.empty()) return 0.0L;

    long double sum = 0.0L;
    for (T x : v) sum += x;

    return sum / v.size();
}

int main() {
	setlocale(LC_ALL, ".UTF8");

	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);


    // Временный пример
    // -----
    std::vector<int> a{ 1, 2, 3, 4 };
    auto m1 = mean(a);

    std::map<std::string, int> score{
        {"Ann", 10}, {"Bob", 5}, {"Carl", 12}
    };

    // find (по ключу)
    auto itBob = score.find("Bob");
    if (itBob != score.end()) itBob->second += 3;

    // find_if (по условию на value)
    auto itHigh = std::find_if(score.begin(), score.end(),
        [](auto const& kv) { return kv.second >= 10; });

    // any_of (есть ли кто-то с нулём?)
    bool hasZero = std::any_of(score.begin(), score.end(),
        [](auto const& kv) { return kv.second == 0; });

    //std::cout << "hasZero=" << hasZero << "\n";



    std::vector<int> v{ 7, 3, 9, 6, 1, 8, 2, 5, 4 };

    // sort()
    std::sort(v.begin(), v.end());

    // find / find_if
    auto it3 = std::find(v.begin(), v.end(), 3);
    auto itGt5 = std::find_if(v.begin(), v.end(), [](int x) { return x > 5; });

    // any_of
    bool hasEven = std::any_of(v.begin(), v.end(), [](int x) { return x % 2 == 0; });

    // copy / copy_if
    std::vector<int> copyAll(v.size());
    std::copy(v.begin(), v.end(), copyAll.begin());

    std::vector<int> onlyEven;
    onlyEven.resize(v.size()); // выделим максимум; потом обрежем по итератору
    auto outEnd = std::copy_if(v.begin(), v.end(), onlyEven.begin(),
        [](int x) { return x % 2 == 0; });
    onlyEven.erase(outEnd, onlyEven.end());
	// -----
	
	Game startGame;
}
