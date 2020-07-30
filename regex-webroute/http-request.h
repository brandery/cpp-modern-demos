#ifndef HTTP_REQUEST 
#define HTTP_REQUEST

#include <map>
#include <unordered_map>
#include <functional>
#include <string>
#include <regex>

typedef std::map<
    std::string, std::unordered_map<std::string, std::function<void(std::ostream&, Request&)>>
> resource_type;

struct Request {
    // request method, POST, GET; path; HTTP version
    std::string method, path, http_version;
    // use smart pointer for reference counting of content
    std::shared_ptr<std::istream> content;
    // hash container, key-value dict
    std::unordered_map<std::string, std::string> header;
    // use regular expression for path match
    std::smatch path_match;
};

#endif // !HTTP_REQUEST 