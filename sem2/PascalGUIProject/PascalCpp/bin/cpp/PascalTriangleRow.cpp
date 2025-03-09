#include"PascalTriangleRow.hpp"

std::vector<int> PascalTriangleRow::rowGenerate(const int n) 
{
    if(n<0)
        throw std::domain_error("liczba poza zakresem. Podano: " 
        + std::to_string(n) + ". oczekiwano liczby naturalnej");

    std::vector<int> row;
    row.push_back(1);

    if(n==0)
        return row;
    
    std::vector<int> prevRow = rowGenerate(n-1);

    for (int i = 1; i < prevRow.size(); i++)
    {
        int curr = prevRow[i-1] + prevRow[i];
        if(curr<0)
            throw std::length_error("wartosci w rzedzie "+ std::to_string(n)
            +" wykraczaja poza maksymalny zakres zmiennej int");
        row.push_back(curr);
    }
    row.push_back(1);
    return row;
}

PascalTriangleRow::PascalTriangleRow(const int n)
{
    rowValues = rowGenerate(n);
}

int PascalTriangleRow::elementInRow(const int n) const
{
    if(n<0  || n>rowValues.size()-1)
        throw std::domain_error("liczba spoza zakresu. Podano: "+std::to_string(n)+
        ". Oczekiwano liczbe z zakresu: <0;"+std::to_string(rowValues.size()-1)+">");
    
    return rowValues[n];
}