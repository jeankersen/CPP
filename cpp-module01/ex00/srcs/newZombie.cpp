#include "Zombie.hpp"
#include "Function.hpp"

Zombie* newZombie(std::string name)
{
    Zombie* zombie = new Zombie();

    zombie->set_name(name);
    
    return(zombie);
}