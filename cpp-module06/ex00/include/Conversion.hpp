#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <string>

class Scalar 
{
	public:

		~Scalar();
		void setFloatDouble(const std::string &literal);
		void setPseudo(const std::string &literal);
		void convert(const std::string& literal);
		void setChar();
		void display();
		Scalar(const Scalar& other);
		Scalar();
		Scalar& operator=(const Scalar& other);
	
	private:
		std::string _toChar;
		int _toInt;
		float _toFloat;
		double _toDouble;
};

#endif