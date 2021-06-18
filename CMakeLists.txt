cmake_minimum_required(VERSION 3.19)
project(daily_projects)

set(CMAKE_CXX_STANDARD 20)

add_executable(daily_projects main.cpp EncrypterDecrypter/Encrypter/Cube/Cube.cpp EncrypterDecrypter/Encrypter/Cube/Cube.h EncrypterDecrypter/Encrypter/Msg/Msg.cpp EncrypterDecrypter/Encrypter/Msg/Msg.h EncrypterDecrypter/Decrypter/Decrypter.h EncrypterDecrypter/Decrypter/Decrypter.cpp PasswordGenerator/PasswordGenerator.h PasswordGenerator/PasswordGenerator.cpp PersonList/PersonList.h PersonList/PersonList.cpp RLE/RLE.cpp RLE/RLE.h "File System Emulator/File/File.cpp" "File System Emulator/File/File.h" "File System Emulator/Directory/Dir.cpp" "File System Emulator/Directory/Dir.h" "File System Emulator/System/System.cpp" "File System Emulator/System/System.h")