#include "../include/ClapTrap.h"


ClapTrap::ClapTrap(): name("default"), hitPoints(10), energyPoints(10), attackDamage(0) {

}

ClapTrap::ClapTrap(const std::string &name): name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{

}

ClapTrap::~ClapTrap()
{

}

void ClapTrap::attack(const std::string &target)
{
}

void ClapTrap::takeDamage(unsigned int amount)
{
}

void ClapTrap::beRepaired(unsigned int amount)
{
}
