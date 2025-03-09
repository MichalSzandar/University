#ifndef PASCALTRIANGLEROW_HPP
#define PASCALTRIANGLEROW_HPP
#include<vector>
#include<stdexcept>

class PascalTriangleRow
{
private:
    std::vector<int> rowGenerate(const int n) noexcept(false);
    std::vector<int> rowValues;
public:
    PascalTriangleRow(const int n) noexcept(false); // --> wykonaj wierszPascalaGenerate, throw ujemna throw poza zakresem 
    ~PascalTriangleRow() noexcept(true) = default;
    int elementInRow(const int n) const noexcept(false);
};

#endif