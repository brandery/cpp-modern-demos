#ifndef HTTP_SERVER_H
#define	HTTP_SERVER_H

#include "http-server-base.h"

namespace Web {
    typedef boost::asio::ip::tcp::socket HTTP;
    template<>
    class Server<HTTP> : public ServerBase<HTTP> {
    public:
        // use port, thread number to construct web server
        // http server is much simple than https since it doesn't need to initial config file
        Server(unsigned short port, size_t num_threads = 1) : ServerBase<HTTP>::ServerBase(port, num_threads) {};
    private:
        // implement accept() method
        void accept() {
            // create a new socket for current connection
            // shared_ptr is used for passing temporal object to anonymous function
            // socket will be deduce as type of std::shared_ptr<HTTP>
            auto socket = std::make_shared<HTTP>(m_io_service);

            acceptor.async_accept(*socket, [this, socket](const boost::system::error_code& ec) {
                // establish a connection
                accept();
                // if no error
                if (!ec) process_request_and_respond(socket);
            });
        }
    };
}
#endif	/* HTTP_SERVER_H */