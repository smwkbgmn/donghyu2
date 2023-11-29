#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
: ClapTrap(100, 100, 30)
{
	std::cout << "[CON-DEF] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

FragTrap::FragTrap( const str_t &name )
: ClapTrap(name, 100, 100, 30)
{
	std::cout << "[CON-NME] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

FragTrap::FragTrap( const FragTrap &target )
{
	*this = target;

	std::cout << "[CON-CPY] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "[DES] ";	
	printName();
	std::cout << "has destroyed ";
	printAttr();
	std::cout << std::endl;
}

FragTrap &FragTrap::operator=( const FragTrap &target )
{
	std::cout << "[Copy assignment called]" << std::endl;

	if (this != &target)
	{
		_name = target.getName();
		_hit = target.getHit();
		_energy = target.getEnergy();
		_damage = target.getDamage();
	}

	return *this;
}

void FragTrap::attack( const str_t &name )
{
	if (available())
	{
		_energy--;

		printName();
		std::cout << "attacks " << name << ", ";
		std::cout << "causing " << _damage << " points of damage!";
		std::cout << std::endl;
	}
}

void FragTrap::highFivesGuys( void )
{
	if (available())
	{
		printName();
		std::cout << "raised hands up for HighFives!!";
		std::cout << std::endl; 
	}
}

void FragTrap::printName( void )
{
	std::cout << "FragTrap " << _name << ' ';
}