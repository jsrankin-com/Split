
// ************************EIGHTY CHARACTER CODING AREA*************************// LANDSCAPE COMMENT SECTION LENGTH

#include "split.h"

template <class T>
void PrintVector(std::vector<T>& v)
{
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

int main() 
{
    std::cout << "Input data:\n";
    const std::string commaData = "12.0,12.5,13.0,13.5,14.0";
    const std::string spaceData = "12.0 12.5 13.0 13.5 14.0";
    std::cout << commaData << '\n' << spaceData << std::endl;

    std::cout << "Vector<string> data:" << std::endl;
    std::vector<std::string> commaVec = Split(commaData, ',');
    std::vector<std::string> spaceVec = Split(spaceData);
    PrintVector(commaVec);
    PrintVector(spaceVec);

    std::cout << "Vector<int> data:" << std::endl;
    auto commaNum = Split<int>(commaData, ',');
    PrintVector(commaNum);
    std::cout << "Vector<double> data:" << std::endl;
    auto spaceNum = Split<double>(spaceData);
    PrintVector(spaceNum);

    
    std::string s("this subject has a submarine as a subsequence");
    std::cout << "\nString example: \n\t" << s << std::endl;
    std::cout << std::endl;
    std::cout << "Split on 'sub':" << std::endl;
    auto strExample = Split(s, "sub");
    std::cout << "\t";
    PrintVector(strExample);
    std::cout << std::endl;

    std::cout << "Regex matching words beginning with 'sub':" << std::endl;
    std::regex e("\\b(sub)([^ ]*)");   // matches words beginning by "sub"
    auto regex = Split(s, e);
    std::cout << "\t";
    PrintVector(regex);
    std::cout << std::endl;
    std::cout << "\nPress ENTER key to continue...";
    std::cin.get();
    std::cout << std::endl;
    return 0;
}

/*
References:
https://www.cplusplus.com/reference/regex/regex_search/

Author:
    Jeffrey S. Rankin
    http://jsrankin.com
    admin@jsrankin.com
*/
