#include "dog.h"
#include <stdexcept>
#include <iostream>

Dog::Dog(std::string name, shared_ptr_toy toy, int64_t age) : m_name(name), m_lovelyToy(toy)
{
	if (age < 0 || age > 30)
	{
		throw std::out_of_range("Invalid dog age. Age must be between 0 and 30");
	}
	
	m_age = age;
}

//----------------------------------------------------------------------------------------------------------------------

Dog::Dog(int64_t age) : m_name("Unnamed"), m_lovelyToy(make_shared_toy("ball"))
{
	if (age < 0 || age > 30)
	{
		throw std::out_of_range("Invalid dog age. Age must be between 0 and 30");
	}

	m_age = age;
}

//----------------------------------------------------------------------------------------------------------------------

void Dog::copyLovelyToy(const Dog& other) noexcept
{
	if (other.m_name != "empty")
	{
		m_lovelyToy = other.m_lovelyToy;
	}
	else
	{
		m_lovelyToy.reset();
	}
}

//----------------------------------------------------------------------------------------------------------------------

void Dog::setBestie(std::shared_ptr<Dog> bestie) noexcept
{
	m_bestie = bestie;
}

//----------------------------------------------------------------------------------------------------------------------

void Dog::getToy(shared_ptr_toy& toy) noexcept
{
	toy = m_lovelyToy;
}

//----------------------------------------------------------------------------------------------------------------------

void Dog::dropToy() noexcept
{
	m_lovelyToy.reset();
}

//----------------------------------------------------------------------------------------------------------------------

std::string Dog::getName() const noexcept
{
	return m_name;
}
