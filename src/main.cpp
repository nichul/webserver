#include <boost/asio.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;

const std::string response =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "Connection: close\r\n"
    "\r\n"
    "<html><body><h1>Welcome to Boost.Asio Web Server!</h1></body></html>";

void handle_connection(tcp::socket socket) {
    try {
        // 요청 데이터를 받는 버퍼
        char buffer[1024] = {0};
        socket.read_some(boost::asio::buffer(buffer));

        // 요청 처리 후 응답 전송
        boost::asio::write(socket, boost::asio::buffer(response));
    } catch (std::exception& e) {
        std::cerr << "Connection error: " << e.what() << std::endl;
    }
}

int main() {
    try {
        // Boost.Asio 서비스 객체
        boost::asio::io_context io_context;

        // TCP 서버 소켓을 열고 포트를 바인딩
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8080));
        std::cout << "Server running on http://localhost:8080" << std::endl;

        while (true) {
            // 클라이언트 연결 대기 및 수락
            tcp::socket socket(io_context);
            acceptor.accept(socket);

            // 연결 처리
            handle_connection(std::move(socket));
        }
    } catch (std::exception& e) {
        std::cerr << "Server error: " << e.what() << std::endl;
    }

    return 0;
}
