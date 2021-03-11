#include <bits/stdc++.h>

#include "bubble_sort.hpp"
#include "count_sort.hpp"

using namespace std;

template <class T>
double TimeMyFunction(vector <T> to_check, void (*function_to_check)(vector<T>&))
{
    vector <T> real_solution = to_check;
    sort(real_solution.begin(), real_solution.end());

    try {
        auto before = chrono::high_resolution_clock::now();
        function_to_check(to_check);
        auto after = chrono::high_resolution_clock::now();

        auto duration = after - before;

        double time_to_sort = chrono::duration_cast<chrono::milliseconds>(duration).count();

        if (real_solution != to_check) {
            // Nu a sortat ca lumea!
            return 1e9;
        }

        return time_to_sort;
    }
    catch (...) {
        return 1e9;
    }
}

int main()
{
    int N = 1000;

    vector <int> v(N);
    iota(v.begin(), v.end(), 0);

    mt19937 rnd(time(0));
    
    shuffle(v.begin(), v.end(), rnd);
    
    cout << "Time to sort with bubblesort: " << TimeMyFunction(v, BubbleSort) << "ms\n";
    return 0;
}