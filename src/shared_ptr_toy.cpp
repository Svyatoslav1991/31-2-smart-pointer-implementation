#include "shared_ptr_toy.h"

shared_ptr_toy::shared_ptr_toy(const std::string& name) : m_toy(new Toy(name)), m_refCount(new int(1))
{

}

//--------------------------------------------------------------------------------------------------

shared_ptr_toy::shared_ptr_toy(const shared_ptr_toy& other) : m_toy(other.m_toy), m_refCount(other.m_refCount)
{
	if (m_refCount)
	{
		(*m_refCount) += 1;
	}
}

//--------------------------------------------------------------------------------------------------

shared_ptr_toy::shared_ptr_toy(shared_ptr_toy&& other) noexcept : m_toy(std::move(other.m_toy)), m_refCount(other.m_refCount)
{
	other.m_toy = nullptr;
	other.m_refCount = nullptr;
}

//--------------------------------------------------------------------------------------------------

shared_ptr_toy::~shared_ptr_toy()
{
	if (m_refCount)
	{
		(*m_refCount)--;
		if (m_refCount == 0)
		{
			delete m_refCount;
			delete m_toy;
		}
	}
}

//--------------------------------------------------------------------------------------------------

shared_ptr_toy& shared_ptr_toy::operator=(const shared_ptr_toy& other)
{
	if (this != &other)
	{
		if (m_refCount)
		{
			(*m_refCount)--;
			if (m_refCount == 0)
			{
				delete m_toy;
				delete m_refCount;
			}
		}

		m_toy = other.m_toy;
		m_refCount = other.m_refCount;

		if (m_refCount)
		{
			(*m_refCount) += 1;
		}
	}

	return *this;
}

//--------------------------------------------------------------------------------------------------

shared_ptr_toy& shared_ptr_toy::operator=(shared_ptr_toy&& other) noexcept
{
	if (this != &other)
	{
		if (m_refCount)
		{
			(*m_refCount)--;
			if (m_refCount == 0)
			{
				delete m_refCount;
				delete m_toy;
			}
		}

		m_toy = std::move(other.m_toy);
		m_refCount = other.m_refCount;

		other.m_refCount = nullptr;
	}

	return *this;
}

//--------------------------------------------------------------------------------------------------

void shared_ptr_toy::reset() noexcept
{
	if (m_refCount)
	{
		(*m_refCount)--;
		if (*m_refCount == 0)
		{
			delete m_refCount;
			delete m_toy;
		}

		m_toy = nullptr;
		m_refCount = nullptr;
	}
}

//--------------------------------------------------------------------------------------------------

std::string shared_ptr_toy::getName() const noexcept
{
	if (m_toy)
	{
		return m_toy->getName();
	}
	
	return "empty";
}

//--------------------------------------------------------------------------------------------------

Toy* shared_ptr_toy::get() const noexcept
{
	return m_toy;
}

//--------------------------------------------------------------------------------------------------

int shared_ptr_toy::use_count() const noexcept
{
	if (m_refCount)
	{
		return *m_refCount;
	}

	return 0;
}
