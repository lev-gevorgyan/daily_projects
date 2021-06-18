#include <iostream>

#include "EncrypterDecrypter/Encrypter/Msg/Msg.h"
#include "EncrypterDecrypter/Decrypter/Decrypter.h"
#include "PasswordGenerator/PasswordGenerator.h"
#include "PersonList/PersonList.h"
#include "RLE/RLE.h"
#include "File System Emulator/System/System.h"

int main() {
    //EncrypterDecrypter test
    /*Msg m("Code Republic FOREVER");
    std::cout << decrypter(m.m_list);*/

    //PasswordGeneratorTest
    //std::cout << std::boolalpha << test(password());

    //PersonListTest
    /*char command{'H'};
    size_t ix{};
    std::string name;
    std::string street;
    std::string phone;
    std::vector<std::tuple<std::string, std::string, std::string> > lines;

    Switch(ix, command, lines, name, street, phone);*/

    //RLEtest
    /*const std::string txt{"AAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBC"};
    RLE compress;
    std::cout << compress.encode(txt);
    std::cout << std::endl;
    std::cout << compress.decode(compress.encode(txt));*/

    //File System Emulator test
    /*std::string command;
    System s;
    do {
        getline (std::cin, command);
        s.command(s.parser(command));
    }
    while(command != "break");*/

    return 0;
}