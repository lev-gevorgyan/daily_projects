#ifndef DAILY_PROJECTS_DIR_H
#define DAILY_PROJECTS_DIR_H

#include <vector>
#include <string>
#include <memory>

#include "../File/File.h"

class Dir {
public:
    explicit Dir(std::string name, std::shared_ptr<Dir>* parent = nullptr) : _name{std::move(name)}
                                                          , _parent{parent}
    {};
    Dir(const Dir& rhs) = default;
    Dir(Dir&& rhs) = default;
    Dir& operator= (const Dir& rhs) = default;
    Dir& operator= (Dir&& rhs) = default;

    [[nodiscard]] std::string getName() const;
    void setName(std::string content);

    std::vector<std::shared_ptr<File>> _files{};
    std::vector<std::shared_ptr<Dir>> _dirs{};
    std::shared_ptr<Dir>* _parent{nullptr};
private:
    std::string _name{};
};

#endif //DAILY_PROJECTS_DIR_H