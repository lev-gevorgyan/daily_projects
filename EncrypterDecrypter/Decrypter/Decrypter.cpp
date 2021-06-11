#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include "../Encrypter/Cube/Cube.h"
#include "Decrypter.h"

std::string decrypter(const std::vector<std::unique_ptr<Cube>>& m_list)
{
    //test
    for (int j = 0; j < m_list.size(); ++j) {
        for (int i = 0; i < m_list[j]->m_rots.size(); ++i) {
            std::cout << m_list[j]->m_rots[i];
        }
        std::cout << std::endl;
    }

    std::string res;
    for (int i = 0; i < m_list.size(); ++i) {
        std::vector<char> cube(m_list[i]->m_cube);
        for (int j = m_list[i]->m_rots.size() - 1; j >= 0; --j) {
            if(m_list[i]->m_rots[j] == 'U')
            {
                std::swap(cube[0], cube[1]);
                std::swap(cube[0], cube[3]);
                std::swap(cube[0], cube[2]);
                std::swap(cube[4], cube[5]);
                std::swap(cube[4], cube[7]);
                std::swap(cube[4], cube[6]);
            }
            if(m_list[i]->m_rots[j] == 'D')
            {
                std::swap(cube[0], cube[2]);
                std::swap(cube[0], cube[3]);
                std::swap(cube[0], cube[1]);
                std::swap(cube[4], cube[6]);
                std::swap(cube[4], cube[7]);
                std::swap(cube[4], cube[5]);
            }
            if(m_list[i]->m_rots[j] == 'L')
            {
                std::swap(cube[0], cube[1]);
                std::swap(cube[1], cube[5]);
                std::swap(cube[4], cube[5]);
                std::swap(cube[2], cube[3]);
                std::swap(cube[3], cube[7]);
                std::swap(cube[6], cube[7]);
            }
            if(m_list[i]->m_rots[j] == 'R')
            {
                std::swap(cube[1], cube[5]);
                std::swap(cube[1], cube[0]);
                std::swap(cube[0], cube[4]);
                std::swap(cube[3], cube[7]);
                std::swap(cube[3], cube[2]);
                std::swap(cube[2], cube[6]);
            }
        }
        for (int j = 0; j < m_list[i]->m_cube.size(); ++j) {
            res += cube[j];
        }
    }
    return res;
}