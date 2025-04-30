#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

namespace SortLibrary 

{template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};


template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
    const unsigned int n = v.size();

    for(unsigned int i = 0; i < n - 1; i++)
    {    for(unsigned int  j= 0; j < n-1; j++)
        {
            if(v[j] > v[j+1])
            {  
                T tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }

        }

        
    }
}



template<Sortable T>
void Ordinamento(std::vector<T>& v, int n, int i)
{
    int maggiore = i;
    int sinistro = 2 * i + 1;
    int destro = 2 * i + 2;

    if (sinistro < n && v[sinistro] > v[maggiore])
        maggiore = sinistro;

    if (destro < n && v[destro] > v[maggiore])
        maggiore = destro;

    if (maggiore != i)
    {
        std::swap(v[i], v[maggiore]);
        Ordinamento(v, n, maggiore);
    }
}

template<Sortable T>
void HeapSort(std::vector<T>& v)
{
    int n = v.size();

    // Costruzione del max-heap
    for (int i = n / 2 - 1; i >= 0; --i)
        Ordinamento(v, n, i);

    // Estrazione degli elementi dal heap
    for (int i = n - 1; i > 0; --i)
    {
        std::swap(v[0], v[i]);
        Ordinamento(v, i, 0);
    }
}


template<Sortable T>
void HeapSort1(std::vector<T>& v)
{
    const unsigned int n = v.size();

    make_heap(v.begin(), v.end()); 

    for(size_t j=0; j<n; j++)
        
        pop_heap(v.begin(), v.end() - j);               
}


}
