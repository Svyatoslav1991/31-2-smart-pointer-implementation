#pragma once

#include <string>

class shared_ptr_toy
{
public:
    shared_ptr_toy(const std::string& name = "ball");
    shared_ptr_toy(const shared_ptr_toy& other);
    shared_ptr_toy(shared_ptr_toy&& other) noexcept;
    ~shared_ptr_toy();
    shared_ptr_toy& operator=(const shared_ptr_toy& other);
    shared_ptr_toy& operator=(shared_ptr_toy&& other) noexcept;
    void reset();
    std::string getName() const noexcept;
private:
    std::string m_name; 
    int* m_refCount;    
};
