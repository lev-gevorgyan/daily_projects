#ifndef DAILY_PROJECTS_SYSTEM_H
#define DAILY_PROJECTS_SYSTEM_H

#include <utility>
#include <vector>
#include <memory>

#include "../Directory/Dir.h"
#include "../File/File.h"

class System {
public:
    void ls();
    void mkdir(const std::string& fld);
    void cd(const std::string& name);
    void touch(const std::string& name ,const std::string& content = "");
    void rm(const std::string& file_name);
    void rmdir(const std::string& dir_name);

    void command(const std::pair<std::string, std::string>& command);
    std::pair<std::string, std::string> parser(const std::string& txt);

private:
    std::shared_ptr<Dir> _prev{nullptr};
    std::shared_ptr<Dir> _cur{std::make_shared<Dir>("root")};
};

#endif //DAILY_PROJECTS_SYSTEM_H