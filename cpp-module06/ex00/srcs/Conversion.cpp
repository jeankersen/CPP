
#include "Conversion.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>

Scalar::Scalar()
{
    _toChar = "";
	_toInt = 0;
	_toFloat = 0;
	_toDouble = 0;
}
Scalar::~Scalar() {}

Scalar::Scalar(const Scalar &other) { *this = other; }

Scalar &Scalar::operator=(const Scalar &other)
{
    (void)other;
    return *this;
}

void Scalar::convert(const std::string &literal)
{
    if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
    {
        _toChar = literal[0];
        std::cout << "char: " << _toChar << std::endl;
        std::cout << "int: " << static_cast<int>(_toChar[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(_toChar[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(_toChar[0]) << ".0" << std::endl;
    }
    else
    {
	    this->_toInt  = std::atoi(literal.c_str());
        setPseudo(literal);
        setFloatDouble(literal);
        setChar();
        display();
    }
}

void Scalar::setFloatDouble(const std::string &literal)
{
	if (literal[literal.length() - 1] == 'f') 
	{
		_toFloat = std::atof(literal.c_str());
		_toDouble = static_cast<double>(_toFloat);
	} else 
	{
		_toDouble = std::atof(literal.c_str());
		_toFloat = static_cast<float>(_toDouble);
	}
}

void Scalar::setPseudo(const std::string &literal)
{
	std::string specialTypes[6] = 
	{
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};
	for (int i = 0; i < 6; ++i) 
	{
		if (literal == specialTypes[i]) 
		{
			_toChar = "imposible"; break;
		}
	}
}

void Scalar::setChar()
{
	if (_toChar == "" && std::isprint(_toInt)) 
	{
		_toChar = "'";
		_toChar += static_cast<char>(_toInt);
		_toChar += "'";
	} 
	else if (_toChar == "") 
	{
		_toChar = "Non displayable";
	}
	std::cout << "char: " << _toChar << std::endl;

	if (_toChar == "imposible") 
	{
		std::cout << "int: imposible" << std::endl;
	} 
	else 
	{
		std::cout << "int: " << _toInt << std::endl;
	}
}


void Scalar::display()
{
	if (_toChar == "imposible" && _toFloat == 0) 
	{
		std::cout << "float: imposible" << std::endl;
		std::cout << "double: imposible" << std::endl;
	} 
	else 
	{
		if (_toChar != "imposible" && _toFloat - static_cast<int>(_toFloat) == 0) 
		{
			std::cout << "float: " << _toFloat << ".0f" << std::endl;
			std::cout << "double: " << _toDouble << ".0" << std::endl;
		} 
		else 
		{
			std::cout << "float: " << _toFloat << "f" << std::endl;
			std::cout << "double: " << _toDouble << std::endl;
		}
	}
}