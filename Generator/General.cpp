#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <fcntl.h>
#include <io.h>
#include <fstream>
#include "variables.h"
#include "choice.h"
#include "stringLength.h"
#include "General.h"

std::wstring hns::loadFileString(std::string name)
{
	std::string filename(name + ".txt");
	std::vector<char> bytes;
	char byte = 0;

	std::ifstream input_file(filename);
	if (!input_file.is_open())
	{
		std::cerr << "Could not open the file '"
			<< filename << "'" << std::endl;
		exit(1);
	}

	while (input_file.get(byte))
	{
		bytes.push_back(byte);
	}

	std::wstring load = L"";

	for (const wchar_t& i : bytes)
	{
		load = load + i;
	}

	input_file.close();
	return load;
}