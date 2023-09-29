#include "../include/sed.h"


int main(int ac, char **av)
{
	if (ac != 4)
		return (error("You need 1 file and 2 arguments to use sed"),error("use ./sed [file] [search] [replace]"), 1);
	const std::string		file 	= av[1];
	const std::string		search	= av[2];
	const std::string		replace	= av[3];
	std::string				str;
	std::ifstream			infile;
	std::ofstream			outfile;

	if (file.length() < 1 || search.length() < 1 || replace.length() < 1)
		return (error("Empty arguments. Try again"), EXIT_FAILURE);
	infile.open(file.c_str());
	str.append(file);
	str.append(".replace");
	if (infile.is_open() == false)
		return (error("[Error] open infile"), EXIT_FAILURE);
	outfile.open(str.c_str(), std::fstream::out | std::fstream::trunc);
	str.clear();
	if (outfile.is_open() == false)
		return (infile.close(), error("[Error] open outfile"), EXIT_FAILURE);
	while (std::getline(infile, str))
	{
		outfile << search_and_replace(str, search, replace);
		if (infile.peek() != EOF)
			outfile << std::endl;
	}
	return (infile.close(), outfile.close(), EXIT_SUCCESS);
	
}

std::string search_and_replace(std::string str, std::string search,std::string replace)
{
	unsigned long s_len = search.length();
	unsigned long position = str.find(search, s_len);
	while (position != std::string::npos)
	{
		str.erase(position, s_len);
		str.insert(position,replace);
		position = str.find(search, s_len);
	}
	return (str);
}

void error(std::string str)
{
	std::cout << str << std::endl;
}