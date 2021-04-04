#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <bitset>
#include <sstream>


int main()
{
    setlocale(LC_ALL, "Turkish");
    std::string text;
    std::string readOut;
    std::string path {"C:\\Users\\rahime\\Desktop\\kartaca"};
    for (const auto & entry : std::filesystem::directory_iterator(path))
    {

        std::bitset<32> txt;
        std::fstream ifs {entry.path()};
        while(std::getline(ifs, readOut));
        ifs.close();
        std::stringstream ss {readOut};
        while(ss >> txt)
            text += txt.to_ulong();
        std::cout << text << " ";
    }
    std::cout << '\n';
    return 0;
}