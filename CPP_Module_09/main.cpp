#include <iostream>
#include <map>
#include <string>

int main() {
    // Создание std::map
    std::map<int, std::string> myMap;
    myMap[1] = "one";
    myMap[2] = "two";
    myMap[3] = "three";
    myMap[4] = "four";

    // Задание ключа для поиска
    int key = 3;

    // Поиск с использованием lower_bound
    auto it = myMap.lower_bound(key);

    // Проверка результата поиска
    if (it != myMap.end()) {
        std::cout << "Found key: " << it->first << ", value: " << it->second << std::endl;
    } else {
        std::cout << "Key not found" << std::endl;
    }

    return 0;
}