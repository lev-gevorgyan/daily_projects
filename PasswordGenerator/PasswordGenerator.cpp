#include <iostream>
#include <ctime>
#include <algorithm>

#include "PasswordGenerator.h"

int random(int min, int max)
{
    static bool first = true;
    if (first)
    {
        srand( std::time(nullptr) );
        first = false;
    }
    int res{min + rand() % (( max + 1 ) - min)};
    if(42 == res || 40 == res)
    {
        return res + 1;
    }
    return res;
}

std::string password()
{
    int change{random(1,3)};
    int size = random(8, 24) - 6;

    std::string res;
    if(1 == change) {
        res += random(97, 122);
        res += random(65, 90);
        res += random(123, 126);
        res += random(65, 90);
        res += random(58, 64);
        res += random(97, 122);
    }
    if(2 == change) {
        res += random(97, 122);
        res += random(65, 90);
        res += random(97, 122);
        res += random(91, 96);
        res += random(123, 126);
        res += random(65, 90);
    }
    if(3 == change) {
        res += random(32, 47);
        res += random(97, 122);
        res += random(65, 90);
        res += random(97, 122);
        res += random(65, 90);
        res += random(58, 64);
    }
    for(size_t ix{}; ix < size; ++ix)
    {
        size_t tmp = random(1,3);
        if(1 == tmp)
            res += random(97, 122);
        if(2 == tmp)
            res += random(65, 90);
        if(3 == tmp)
            res += random(48, 57);
    }

    std::random_shuffle(res.begin(), res.end());
    std::cout << "Size is " << res.size() << std::endl;
    std::cout << res << std::endl;
    return res;
}

bool test(const std::string& str)
{
    size_t upperCount{};
    size_t lowerCount{};
    size_t symbolCount{};

    if(str.size() < 8 || str.size() > 24) return false;

    for(size_t ix{}; ix < str.size(); ++ix)
    {
        if(str[ix] >= 97 && str[ix] <= 122) ++lowerCount;
        if(str[ix] >= 65 && str[ix] <= 90) ++upperCount;
        if(str[ix] >= 32 && str[ix] <= 47
           || str[ix] >= 123 && str[ix] <= 126
           || str[ix] >= 91 && str[ix] <= 96
           || str[ix] >= 58 && str[ix] <= 64) ++symbolCount;
        if(40 == str[ix] || 42 == str[ix]) return false;
    }
    return (lowerCount >= 2 && upperCount >= 2 && symbolCount == 2);
}