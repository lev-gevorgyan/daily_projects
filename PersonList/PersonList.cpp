#include <iostream>

#include "PersonList.h"

void Print(std::vector<std::tuple<std::string, std::string, std::string> > lines)
{
    for (size_t ix{0}; ix < lines.size(); ++ix) {
        std::cout << std::get<0>(lines.at(ix)) << '\t';
        std::cout << std::get<1>(lines.at(ix)) << '\t';
        std::cout << std::get<2>(lines.at(ix)) << '\n';
    }
}

void Switch(size_t& ix,
            char& command, std::vector<std::tuple<std::string, std::string, std::string> >& lines,
            std::string& name, std::string& street, std::string& phone)
{
    switch (command) {
        case 'H':
            std::cout << ":::::Enter H for help, A for add, R for remove, P for print, B for END:::::";

            std::cout << "Enter Command: ";
            std::cin >> command;

            Switch(ix, command, lines, name, street, phone);
            break;
        case 'A':
            std::cout << "Enter Name: ";
            std::cin >> name;
            std::cout << std::endl;

            std::cout << "Enter Street: ";
            std::cin >> street;
            std::cout << std::endl;

            std::cout << "Enter Phone: ";
            std::cin >> phone;

            lines.emplace_back(std::make_tuple(name, street, phone));

            std::cout << "Enter Command: ";
            std::cin >> command;

            Switch(ix, command, lines, name, street, phone);
            break;
        case 'R':
            std::cout << "Enter index for remove";
            std::cin >> ix;
            if(ix >= 0 && ix < lines.size())
                lines.erase(lines.begin() + ix);
            else
                std::cout << "Enter valid index: ";

            std::cout << "Enter Command: ";
            std::cin >> command;

            Switch(ix, command, lines, name, street, phone);
            break;
        case 'P':
            Print(lines);

            std::cout << "Enter Command: ";
            std::cin >> command;

            Switch(ix, command, lines, name, street, phone);
            break;
        case 'B':
            return;
        default:
            std::cout << ":::::Enter H for help, A for add, R for remove, P for print, B for END:::::";
            std::cout << std::endl;

            std::cout << "Enter Command: ";
            std::cin >> command;

            Switch(ix, command, lines, name, street, phone);
    }
}