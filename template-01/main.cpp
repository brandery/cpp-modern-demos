#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;


template <typename Key, typename Value, typename F>
void update(std::map<Key, Value>& m, F foo) {
    for(auto& iter : m) {
        iter.second = foo(iter.first);
    }
}

int main() {
    std::map<std::string, long long int> m{
        {"a", 1},
        {"b", 2},
        {"c", 3}
    };
    update(m, [](const std::string& key) {
        return std::hash<std::string>{}(key);
    });
    
    for (auto&& [key, val] : m) {
        std::cout << key << ":" << val << std::endl;
    }
}