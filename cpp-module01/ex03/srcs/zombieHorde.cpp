#include "Zombie.hpp"
#include "ZombieHorde.hpp"

Zombie* newZombie(std::string name)
{
    Zombie* zombie = new Zombie();

    zombie->set_name(name);

    return(zombie);
}

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* horde = new Zombie[N];
    
    for(int i = 0; i < N; i++)
    {
        horde[i] = *newZombie(name);
    }
    
    return horde;
}

