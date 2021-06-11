#ifndef DAILY_PROJECTS_CUBE_H
#define DAILY_PROJECTS_CUBE_H

#include <vector>
#include <string>

class Cube {
public:
    //std::vector<char> m_cube{0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<char> m_cube{'*', '*', '*', '*', '*', '*', '*', '*'};
    std::vector<char> m_rots;
private:
    std::vector<char> m_allRots{'U', 'D', 'L', 'R'};
    int random(int min, int max);
    void getRots(const std::vector<char>&, std::vector<char>&);
    void rotate(const std::vector<char>&, std::vector<char>&);
public:
    Cube(const std::string&);
    //std::vector<char> getCube() { return m_cube; }
};

#endif //DAILY_PROJECTS_CUBE_H