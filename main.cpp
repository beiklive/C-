#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<nlohmann/json.hpp>

int main(){
    nlohmann::json j;
    std::ifstream ifs("library.json");
    ifs >> j;

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
    return 0;
}