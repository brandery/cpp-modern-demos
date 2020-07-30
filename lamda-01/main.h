

void reference(std::string&& str) {
    std::cout << "is: 右值" << std::endl;
}
void reference(std::string& str) {
    std::cout << str << " is: 左值" << std::endl;
}
template <typename T>
void pass(T&& v) {
    std::cout << "**************************************************" << std::endl;
    std::cout << "              普通传参: ";
    reference(v);
    std::cout << "       std::move 传参: ";
    reference(std::move(v));
    std::cout << "    std::forward 传参: ";
    reference(std::forward<T>(v));
    std::cout << "static_cast<T&&> 传参: ";
    reference(static_cast<T&&>(v));
}