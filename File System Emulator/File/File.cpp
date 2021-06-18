#include "File.h"

std::string File::getContent() const {return _content;}
void File::setContent(std::string content) {_content = std::move(content);}

std::string File::getName() const {return _name;}
void File::setName(std::string name) {_name = std::move(name);}