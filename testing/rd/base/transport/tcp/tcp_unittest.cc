#include "gtest/gtest.h"
#include "base/transport/tcp/tcp_client.h"
#include "base/transport/tcp/tcp_server.h"
#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

TEST(Tcp, test) {
    static int port = 23274;

    static std::mutex mutex;
    static std::mutex mutex2;
    static std::condition_variable cv;
    static std::condition_variable cv2;
    static bool server_ready = false;
    static bool write_ready = false;
    static std::string data("11");

    std::thread server([] {
        TcpServer *server = new TcpServer(port);
        {
            std::lock_guard<std::mutex> lock(mutex);
            server->Listen();
            server_ready = true;
            cv.notify_all();
        }
        
        TcpSocket socket;
        ASSERT_EQ(server->Accept(&socket), 0);
        std::cout << "Accept" << std::endl;

        {
            std::lock_guard<std::mutex> lock(mutex2);
            ASSERT_EQ(socket.Write((uint8_t*)data.c_str(), data.length()), data.length());
            write_ready = true;
            cv2.notify_all();

        }
    });

    std::thread client([]{
        uint8_t buf[32] = {};
        TcpSocket socket;
        TcpClient *client = new TcpClient();

        {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock, []{return server_ready;});
        }

        ASSERT_EQ(client->Connect("127.0.0.1", port, &socket), 0);
        std::cout << "Connect" << std::endl;

        {
            std::unique_lock<std::mutex> lock(mutex);
            cv2.wait(lock, []{return write_ready;});
            
            int32_t bytes = socket.Read(buf, sizeof(buf));
            ASSERT_GT(bytes, 0);
            
            std::string recv_data((char*)buf, bytes);
            ASSERT_EQ(data, recv_data);
        }
        
        std::cout << data << std::endl;
    });

    server.join();
    client.join();
}
