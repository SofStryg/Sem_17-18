#include <thread>
#include <iostream>
#include <queue>
#include <future>
using namespace std;


void kas1(queue <string> *shoppers) {
    if (shoppers->size() > 0) {
        auto shopper = shoppers->front();
        shoppers->pop();
        cout << "Кассир 1 начала обслуживать " << shopper << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Кассир 1 обслужила " << shopper << endl;
        auto k1 = async(launch::async, kas1, shoppers);
    }
    return;
}
void kas2(queue <string> *shoppers) {
    if (shoppers->size() > 0) {
        auto shopper = shoppers->front();
        shoppers->pop();
        cout << "Кассир 2 начала обслуживать " << shopper << endl;
        this_thread::sleep_for(chrono::seconds(4));
        cout << "Кассир 2 обслужила " << shopper << endl;
        auto k2 = async(launch::async, kas2, shoppers);
    }
    return;
}
int main()
{
    setlocale(0, "");
    queue <string> shoppers;
    queue <string> *shoppers_ptr = &shoppers;
    shoppers.push("Саша");
    shoppers.push("Вася");
    shoppers.push("Саша");
    shoppers.push("Соня");
    shoppers.push("Даня");
    shoppers.push("Даниил");
    shoppers.push("Казанова");
    shoppers.push("Красавчик");
    shoppers.push("Просто кто-то");
    while (shoppers.size() > 0) {
        auto k1 = async(launch::async, kas1, shoppers_ptr);
        auto k2 = async(launch::async, kas2, shoppers_ptr);
    }
}
