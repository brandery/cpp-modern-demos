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
            // std::smatch �ĵ�һ��Ԫ��ƥ�������ַ���
            // std::smatch �ĵڶ���Ԫ��ƥ���˵�һ�����ű��ʽ
            if (base_match.size() == 2) {
                std::cout << fname << "sub-match[0]: " << base_match[0].str() << " sub-match[1]: " << base_match[1].str() << std::endl;
            }
        }
    }
}
