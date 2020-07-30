
#include <iostream>
#include "http-server.h"
#include "https-server.h"
#include "http-handlers.h"
#include <unordered_map>
using namespace Web;

int main() {
    int port = 9966, threads = 4;
    // HTTP server runs in port 12345 HTTP, enable 4 threads
    std::cout << "Server starting at port: " + to_string(port) << std::endl;
    //Server<HTTPS> server(9966, threads);
    //start_server<Server<HTTPS>>(server);

    Server<HTTP> server(port, threads);
    start_server<Server<HTTP>>(server);

    return 0;
}