#include <unistd.h>
#include "web_serv.h"

int main() {
    /*auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;*/

    web_serv *aze = new web_serv();
    std::cout << "Server start\n Enter anything to stop" << std::endl;
    int a;
    std::cin >> a;
    aze->stop();


    return 0;
}