#include "toy.h"

Toy::Toy(std::string name) : m_name(name)
{

}

//---------------------------------------------------

std::string Toy::getName() const noexcept
{
	return m_name;
}
