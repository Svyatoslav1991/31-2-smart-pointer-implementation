#include "shared_ptr_toy.h"

shared_ptr_toy::shared_ptr_toy(const std::string& name) : m_name(name), m_refCount(new int(1))
{

}

//--------------------------------------------------------------------------------------------------

shared_ptr_toy::shared_ptr_toy(const shared_ptr_toy& other) : m_name(other.m_name), m_refCount(other.m_refCount)
{
	if (m_refCount)
	{
		(*m_refCount) += 1;
	}
}

//--------------------------------------------------------------------------------------------------

shared_ptr_toy::shared_ptr_toy(shared_ptr_toy&& other) noexcept : m_name(std::move(other.m_name)), m_refCount(other.m_refCount)
{
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
				delete m_refCount;
			}
		}

		m_name = other.m_name;
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
			}
		}

		m_name = std::move(other.m_name);
		m_refCount = other.m_refCount;

		other.m_refCount = nullptr;
	}

	return *this;
}

//--------------------------------------------------------------------------------------------------

void shared_ptr_toy::reset()
{
	if (m_refCount)
	{
		(*m_refCount)--;
		if (*m_refCount == 0)
		{
			delete m_refCount;
		}
	}

	m_name = "empty";
	m_refCount = new int(0);
}

//--------------------------------------------------------------------------------------------------

std::string shared_ptr_toy::getName() const noexcept
{
	return m_name;
}
