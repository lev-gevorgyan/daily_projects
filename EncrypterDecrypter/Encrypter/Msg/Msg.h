#ifndef DAILY_PROJECTS_MSG_H
#define DAILY_PROJECTS_MSG_H

#include <memory>

#include "../Cube/Cube.h"

class Msg {
public:
    std::vector<std::unique_ptr<Cube>> m_list;
public:
    Msg(const std::string&);
    //std::vector<std::unique_ptr<Cube>> getList(){ return m_list; }
};

#endif //DAILY_PROJECTS_MSG_H