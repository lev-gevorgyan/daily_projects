#include <ctime>
#include <algorithm>

#include "Cube.h"

int Cube::random(int min, int max) {
    static bool first = true;
    if (first)
    {
        srand( std::time(nullptr) );
        first = false;
    }
    return min + rand() % (( max + 1 ) - min);
}

Cube::Cube(const std::string & s) {
    for(size_t ix{}; ix < s.size(); ++ix)
        m_cube[ix] = s[ix];
    getRots(m_allRots, m_rots);
    rotate(m_rots, m_cube);
}

void Cube::getRots(const std::vector<char> & allRots, std::vector<char> & rots) {
    int count{random(1, 4)};
    for(size_t ix{}; ix < count; ++ix)
        rots.push_back(allRots[random(0, 3)]);
}

void Cube::rotate(const std::vector<char> & rots, std::vector<char> & cube) {
    for(size_t ix{}; ix < rots.size(); ++ix)
    {
        if(rots[ix] == 'U')
        {
            std::swap(cube[0], cube[2]);
            std::swap(cube[0], cube[3]);
            std::swap(cube[0], cube[1]);
            std::swap(cube[4], cube[6]);
            std::swap(cube[4], cube[7]);
            std::swap(cube[4], cube[5]);
        }
        if(rots[ix] == 'D')
        {
            std::swap(cube[0], cube[1]);
            std::swap(cube[0], cube[3]);
            std::swap(cube[0], cube[2]);
            std::swap(cube[4], cube[5]);
            std::swap(cube[4], cube[7]);
            std::swap(cube[4], cube[6]);
        }
        if(rots[ix] == 'L')
        {
            std::swap(cube[1], cube[5]);
            std::swap(cube[1], cube[0]);
            std::swap(cube[0], cube[4]);
            std::swap(cube[3], cube[7]);
            std::swap(cube[3], cube[2]);
            std::swap(cube[2], cube[6]);
        }
        if(rots[ix] == 'R')
        {
            std::swap(cube[0], cube[1]);
            std::swap(cube[1], cube[5]);
            std::swap(cube[4], cube[5]);
            std::swap(cube[2], cube[3]);
            std::swap(cube[3], cube[7]);
            std::swap(cube[6], cube[7]);
        }
    }
}