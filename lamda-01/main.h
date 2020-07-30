

void reference(std::string&& str) {
    std::cout << "is: ��ֵ" << std::endl;
}
void reference(std::string& str) {
    std::cout << str << " is: ��ֵ" << std::endl;
}
template <typename T>
void pass(T&& v) {
    std::cout << "**************************************************" << std::endl;
    std::cout << "              ��ͨ����: ";
    reference(v);
    std::cout << "       std::move ����: ";
    reference(std::move(v));
    std::cout << "    std::forward ����: ";
    reference(std::forward<T>(v));
    std::cout << "static_cast<T&&> ����: ";
    reference(static_cast<T&&>(v));
}