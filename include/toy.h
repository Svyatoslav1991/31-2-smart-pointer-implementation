#pragma once
#include <string>

class Toy {
public:
	Toy(std::string name = "ball");
	~Toy() = default;
	std::string getName() const noexcept;

private:
	std::string m_name;
};