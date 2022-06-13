#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <chrono>
#include<nlohmann/json.hpp>

int main(){
    
    auto startTime = std::chrono::system_clock::now();
    auto endTime = std::chrono::system_clock::now();


    nlohmann::json j = []
    {
        std::ifstream ifs("library.json");
        return nlohmann::json::parse(std::string{ (std::istreambuf_iterator<char>(ifs)),(std::istreambuf_iterator<char>()) });
    }();

    std::string py;
    std::cout << "Please input pinyin: ";
    std::cin >> py;
    for(auto k : j.items()){
        if(k.key().substr(0, py.length()) == py){
            std::cout << "Pinyin: " << k.key() << std::endl;
            std::cout << "Meaning: " << k.value()[0] << std::endl;
            std::cout << "===============================" << std::endl;
        }
    }
    std::cout << "time:" << std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count() << "ms"<< std::endl;
    return 0;
}