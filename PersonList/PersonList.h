#ifndef DAILY_PROJECTS_PERSONLIST_H
#define DAILY_PROJECTS_PERSONLIST_H

#include <vector>
#include <tuple>
#include <string>

void Print(std::vector<std::tuple<std::string,std::string,std::string> >);
void Switch(size_t&,
            char&,
            std::vector<std::tuple<std::string,std::string, std::string> >&,
            std::string&,
            std::string&,
            std::string&
            );
#endif //DAILY_PROJECTS_PERSONLIST_H