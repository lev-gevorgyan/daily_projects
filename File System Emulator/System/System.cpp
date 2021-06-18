#include <iostream>

#include "System.h"

void System::ls() {
    for (size_t ix{}; ix < _cur->_dirs.size(); ++ix)
        std::cout << _cur->_dirs[ix]->getName() << '\n';
    for (size_t ix{}; ix < _cur->_files.size(); ++ix)
        std::cout << _cur->_files[ix]->getName() << '\n';
}

void System::mkdir(const std::string &fld) {
    _cur->_dirs.push_back(std::make_shared<Dir>(fld, &_cur));
}

void System::cd(const std::string &name) {
    const size_t dirs_size = _cur->_dirs.size();
    if(".." == name) {
        if(_cur->_parent) {
            _cur = _prev;
            _prev = *(_cur->_parent);
        } else std::cout << "You are in ROOT";
        return;
    }
    for(size_t ix{}; ix < dirs_size; ++ix) {
        if(_cur->_dirs[ix]->getName() == name) {
            _cur = _prev;
            _prev = _cur->_dirs[ix];
            return;
        }
        if(dirs_size - 1 == ix) {
            std::cout << "There is no directory named " << name << std::endl;
            return;
        }
    }
}

void System::touch(const std::string &name, const std::string &content) {
    _cur->_files.push_back(std::make_shared<File>(name, content));
}

void System::rm(const std::string &file_name) {
    const size_t files_size = _cur->_files.size();
    for(size_t ix{}; ix < files_size; ++ix) {
        if(_cur->_files[ix]->getName() == file_name) {
            _cur->_files.erase(_cur->_files.begin() + ix);
            return;
        }
        if(files_size - 1 == ix) std::cout << "There is no file named " << file_name << std::endl;
    }
}

void System::rmdir(const std::string &dir_name) {
    const size_t dirs_size = _cur->_dirs.size();
    for(size_t ix{}; ix < dirs_size; ++ix) {
        if(_cur->_dirs[ix]->getName() == dir_name) {
            _cur->_dirs.erase(_cur->_dirs.begin() + ix);
            return;
        }
        if(dirs_size - 1 == ix) std::cout << "There is no directory named " << dir_name << std::endl;
    }
}

std::pair<std::string, std::string> System::parser(const std::string &txt) {
    std::string first;
    std::string second;

    size_t ix{};
    while(ix < txt.size() && ' ' != txt[ix]) {
        first += txt[ix++];
    }
    ++ix;
    while(ix < txt.size()) {
        second += txt[ix++];
    }

    return std::make_pair(first, second);
}

void System::command(const std::pair<std::string, std::string> &command) {
    const std::string COMMAND{command.first};
    const std::string ARGUMENT{command.second};

    if("ls" == COMMAND) {
        ls();
        return;
    }
    if("mkdir" == COMMAND) {
        mkdir(ARGUMENT);
        return;
    }
    if("cd" == COMMAND) {
        cd(ARGUMENT);
        return;
    }
    if("touch" == COMMAND) {
        touch(ARGUMENT);
        return;
    }
    if("rm" == COMMAND) {
        rm(ARGUMENT);
        return;
    }
    if("rmdir" == COMMAND) {
        rmdir(ARGUMENT);
        return;
    }
    std::cout << "Invalid Command" << std::endl;
}