# Split
Function that splits a string given a delimiter. Accepts input as first param and splits the content based on the the second param. If no second param is supplied then it will split on any whitespace character.  This function is overloaded to be more functional, which means there is quite a bit of code duplication. I've included generics to convert output to any templated type.
# How to build
https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/build/how-to-create-a-cpp-project-from-existing-code.md

## References
*[https://www.cplusplus.com/reference/regex/regex_search/](https://www.cplusplus.com/reference/regex/regex_search/)

## Author
Jeffrey S. Rankin
-[http://jsrankin.com](http://jsrankin.com)
-[admin@jsrankin.com](admin@jsrankin.com)

```cpp
int main()
{
    std::string s("this subject has a submarine as a subsequence");
    
    std::cout << "String example: \n\t" << s << '\n';
    std::cout << "Split on 'sub':" << '\n';
    
    auto strExample = Split(s, "sub");
    
    for (auto it = strExample.cbegin(); it != strExample.cend(); ++it) {
        std::cout << *it << '\n';
    }
    
    std::cout << std::endl;
    return 0;
}
```
