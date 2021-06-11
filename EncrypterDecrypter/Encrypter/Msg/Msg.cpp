#include <iostream>

#include "Msg.h"

Msg::Msg(const std::string &msg) {
    size_t count = msg.size() / 8;
    size_t rest{msg.size() - count * 8};

    for (int i = 1; i <= count; ++i) {
        std::string tmp;
        for (int j = 8 * (i-1); j < 8 * i; ++j) {
            tmp += msg[j];
        }
        m_list.push_back(std::make_unique<Cube>(tmp));
    }
    if(rest){
        std::string tmp;
        for (int i = 0; i < rest; ++i) {
            tmp += msg[8 * count + i];
        }
        m_list.push_back(std::make_unique<Cube>(tmp));
    }

    //for test
    for (int i = 0; i < m_list.size(); ++i) {
        for (int j = 0; j < m_list[i]->m_cube.size(); ++j) {
            std::cout << m_list[i]->m_cube[j];
        }
    }
    std::cout << std::endl;
}