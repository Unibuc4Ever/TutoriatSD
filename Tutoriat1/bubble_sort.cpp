#include "bubble_sort.hpp"

#include <bits/stdc++.h>

using namespace std;


void BubbleSort(vector <int>& v)
{
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i + 1 < (int)v.size(); i++) 
            if (v[i] > v[i + 1])
                swap(v[i], v[i + 1]), sorted = false;
    }
}