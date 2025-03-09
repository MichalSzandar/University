#include<iostream>
#include"PascalTriangleRow.hpp"

int main(const int argc, const char* const argv[])
{
    if(argc < 2)
    {
        std::cerr<<"brak argumentow. Podaj wiersz trojkata pascala, "<<
         "nastepnie kolejne wartosci to wartosci z tego wiersza ktore chcesz uzyskac";
        return 0;
    }

    PascalTriangleRow* row;

    try
    {
        row = new PascalTriangleRow(std::stoi(argv[1]));
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "zla dana. Podano: "<<argv[1]
        <<", a oczekiwano liczby calkowitej" << '\n';
        return 0;
    }
    catch(const std::domain_error& e)
    {
        std::cerr<<e.what()<<'\n';
        return 1;
    }
    catch(const std::length_error& e)
    {
        std::cerr<<e.what()<<'\n';
        return 1;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr<<"wartosc wykracza poza dozwolony zakres zmiennej int. Podano: "
        <<argv[1]<<'\n';
        return 1;
    }

    for (size_t i = 2; i < static_cast<size_t>(argc); i++)
    {
        try
        {
            std::cout<<row->elementInRow(std::stoi(argv[i]))<<'\n';
        }
        catch(const std::domain_error& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(const std::invalid_argument& e)
        {
            std::cerr<<"zla dana. Podano: "<<argv[i]
            <<", a oczekiwano liczby calkowitej" << '\n';
        }
        catch(const std::out_of_range& e)
        {
            std::cerr<<"wartosc wykracza poza dozwolony zakres zmiennej int. Podano: "
            <<argv[i]<<'\n';
        }
        
    }
    
    row->~PascalTriangleRow();
    return 0;
}