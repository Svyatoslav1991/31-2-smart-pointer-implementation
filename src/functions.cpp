#include "functions.h"

shared_ptr_toy make_shared_toy(std::string name)
{
	return shared_ptr_toy(name);
}

//-------------------------------------------------------------------------------

shared_ptr_toy make_shared_toy(const shared_ptr_toy& other)
{
	return shared_ptr_toy(other);
}
