#include <iostream>
#include <string>
#include <fstream>

std::string replace_str(std::string str, const std::string &search, const std::string &replace) {

	size_t position = str.find(search);

	while (position != std::string::npos) {
		str.erase(position, search.length());
		str.insert(position, replace);
		position = str.find(search, position + replace.length());
	}

	return str;

}

int main(const int argc, char **argv) {

	if (argc != 4) {
		std::cout << "Syntax error: ./replace <file> <search> <replace>" << std::endl;
		return 1;
	}

	const std::string file = argv[1];
	const std::string search = argv[2];
	const std::string replace = argv[3];

	std::ifstream in;
	std::ofstream out;

	in.open(file);

	if (!in.is_open()) {
		std::perror("Input file error.");
		std::cout << "Output file not created." << std::endl;
		return 1;
	}

	out.open(file + ".replace", std::ios::out | std::ios::trunc);

	if (!out.is_open()) {
		std::perror("Outfile Error");
		in.close();
		return 1;
	}

	std::string buffer;

	while (std::getline(in, buffer)) {
		buffer = replace_str(buffer, search, replace);
		out << buffer;
		if (in.peek() != EOF)
			out << std::endl;
	}

	in.close();
	out.close();
	return 0;

}