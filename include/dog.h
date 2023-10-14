#pragma once
#include <string>
#include <memory>
#include "shared_ptr_toy.h"
#include "functions.h"

class Dog
{
public:
	Dog(std::string name = "Unnamed", shared_ptr_toy toy = make_shared_toy("ball"), int64_t age = 0);
	Dog(int64_t age);
	void copyLovelyToy(const Dog& other) noexcept;
	void setBestie(std::shared_ptr<Dog> bestie) noexcept;
	void getToy(shared_ptr_toy& toy) noexcept;
	void dropToy() noexcept;
	std::string getName() const noexcept;

private:
	std::string m_name;
	int64_t m_age;
	shared_ptr_toy m_lovelyToy;
	std::weak_ptr<Dog> m_bestie;
};
