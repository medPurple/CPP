#include "../include/sed.h"

void   replaceStr(const std::string& s1, const std::string& s2, std::ifstream& ifs, std::ofstream& ofs) {
    
    std::string line;
    int pos;
    while (std::getline(ifs, line)) {
        pos = 0;
        while (pos != -1){
            pos = line.find(s1, pos);
            if (pos != -1){
                line.erase(pos, s1.length());
                line.insert(pos, s2);
                pos += s2.length();
            }
        }
        ofs << line << std::endl;
    }
    ifs.close();
    ofs.close();
}


int main (int ac, char **av) {

    if (ac != 4)
        return std::cout << "usage: ./replace <filename> <s1> <s2>" << std::endl, -1;

    std::string s1(av[2]);
    std::string s2(av[3]);
    if (s1.empty() || s2.empty())
        return std::cout << "s1 and s2 must not be empty" << std::endl, -1;
    
    std::ifstream ifs(av[1]);
    if (!ifs.is_open())
        return std::cout << "could not open file" << std::endl, -1;

    std::string replace_file_name((std::string)av[1] + ".replace");
    std::ofstream ofs(replace_file_name.c_str(), std::ios::trunc); 
    if (!ofs.is_open())
        return std::cout << "could not create replace file" << std::endl, ifs.close(), -1;

    replaceStr(s1, s2, ifs, ofs);
    return 0;
}