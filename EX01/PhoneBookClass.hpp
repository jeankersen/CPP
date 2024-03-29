#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP



class Contact
{
	private:
	std::string		_fname;
    std::string		_lname;
    std::string		_nname;
    std::string		_nbr;
    std::string		_secret;


    public:
    void set_fname(std::string str);
    void set_lname(std::string str);
    void set_nname(std::string str);
    void set_nbr(std::string str);
    void set_secret(std::string str);

    std::string get_fname(void);
    std::string get_lname(void);
    std::string get_nname(void);
    std::string get_nbr(void);
    std::string get_secret(void);
    
    std::string get_fname_short(void);
    std::string get_lname_short(void);
    std::string get_nname_short(void);
    std::string get_nbr_short(void);
    std::string get_secret_short(void);
};

class PhoneBook
{
    public:
    Contact Cons[8];
    int         index;

    PhoneBook(void);
    ~PhoneBook(void); 
    void set_index(int i);
    int get_index(void);
};

#endif

/* 


void	Phonebook::search(void)
{
	std::string	str;

	if (!search_ui(this->_contacts))
	{
		std::cout << std::endl << "Phonebook is empty!" << std::endl;
		return ;
	}
	while (!std::cin.eof())
	{
		std::cout << "Select an index: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
					this->_contacts[str[0] - 1 - '0'].get_fname().size())
				break ;
		}
		if (str != "")
			std::cout << "Invalid index!" << std::endl;
	}
	if (!std::cin.eof())
		this->print(this->_contacts[str[0] - 1 - '0']);
}






void MenuSearch(PhoneBook &phone)
{
    std::string index;
    //std::cout << "Enter index: " << std::endl;
    //std::cin.ignore();
    //std::getline(std::cin, index);
    while(!std::cin.eof())
    {
        std::cout << "Select an index: ";
        if(std::getline(std::cin, index) && index != "")
        {
            if(index.size() == 1 && index[0] >= '1' && index[0] <= phone.index)
            {
                std::cout << index  << "_" << std::right<< phone.Cons[index[0] - 1].get_name_tronk() << std::endl;
                break;

            }
            if(index != "")
                std::cout << "Invalid index!" << std::endl;

        }
    }
    FirstMenu();
}




    afficherAligneADroite(col1_ligne1); std::cout << " "; afficherAligneADroite(col2_ligne1); std::cout << std::endl;
    afficherAligneADroite(col1_ligne2); std::cout << " "; afficherAligneADroite(col2_ligne2); std::cout << std::endl;


void OptionSearch(PhoneBook &phone)
{
    ClearConsole();
    if(phone.index <= 0)
    {
        std::cout << "No contacts found !" << std::endl;
        FirstMenu();
    }
    else
    {
        	std::cout << " ___________________________________________ " << std::endl;
	        std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	        std::cout << "|----------|----------|----------|----------|" << std::endl;
            //std::cout << std::setw(10) << i + 1 << "_" << std::right << phone.Cons[i].get_name_tronk() << std::endl;
        for(int i = 0; i < phone.index; i++)
        {
            std::string name;
            name = phone.Cons[i].get_name_tronk();
            ToRightN(i + 1);
            ToRight(name);
            std::cout << phone.Cons[i].get_name_tronk();
            std::cout << std::endl;

        }
        MenuSearch(phone);
    }
}

        	std::cout << " ___________________________________________ " << std::endl;
	        std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	        std::cout << "|----------|----------|----------|----------|" << std::endl;
            std::cout << "        "<< i + 1 << "_" << phone.Cons[i].get_name_tronk() << std::endl;
*/