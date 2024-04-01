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
