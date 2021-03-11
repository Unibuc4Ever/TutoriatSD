#include <bits/stdc++.h>

#include "count_sort.hpp"

using namespace std;


template <>
void CountSort<int>(vector <int>& v)
{
    int v_min = 1e9;
    int v_max = -1e9;
    for (auto i : v)
        v_min = min(v_min, i), v_max = max(v_max, i);

    if (v_max - v_min > 1e8)
        throw runtime_error("Range too wide for countsort!");
    
    vector <int> frc(v_max - v_min + 1);
    for (auto i : v)
        frc[i - v_min]++;

    v.clear();
    for (int i = 0; i < (int)frc.size(); i++)
        while (frc[i]--)
            v.push_back(i + v_min);
}

template <class T>
void CountSort(vector <T>& v)
{
    throw runtime_error("Can't countsort on non-integer values!");
}