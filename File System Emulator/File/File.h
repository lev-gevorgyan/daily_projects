#ifndef DAILY_PROJECTS_FILE_H
#define DAILY_PROJECTS_FILE_H

#include <string>
#include <utility>

class File {
public:
    explicit File(std::string name, std::string content = "") : _content{std::move(content)}
                                                              , _name{std::move(name)}
                                                              {};
    File(const File& rhs) = default;
    File(File&& rhs) = default;
    File& operator= (const File& rhs) = default;
    File& operator= (File&& rhs) = default;

    [[nodiscard]] std::string getContent() const;
    void setContent(std::string content);
    [[nodiscard]] std::string getName() const;
    void setName(std::string content);
private:
    std::string _name{};
    std::string _content{};
};

#endif //DAILY_PROJECTS_FILE_H