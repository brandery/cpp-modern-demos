#include <regex>
#include <iostream>
using namespace std;


int main() {
    std::string fnames[] = { "foo.txt", "test", "a0.txt", "bar.txt", "AAA.txt" };
    std::regex base_regex("([a-z]+)\\.txt");
    for(auto && item : fnames){
        if (std::regex_match(item, base_regex)) {
            cout << item << "\n";
        }
    }

    std::smatch base_match;
    for (const auto& fname : fnames) {
        if (std::regex_match(fname, base_match, base_regex)) {
            // std::smatch 的第一个元素匹配整个字符串
            // std::smatch 的第二个元素匹配了第一个括号表达式
            if (base_match.size() == 2) {
                std::cout << fname << "sub-match[0]: " << base_match[0].str() << " sub-match[1]: " << base_match[1].str() << std::endl;
            }
        }
    }
}
