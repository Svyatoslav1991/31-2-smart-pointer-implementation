#pragma once

#include "toy.h"


class shared_ptr_toy
{
public:
    shared_ptr_toy(const std::string& name = "ball");
    shared_ptr_toy(const shared_ptr_toy& other);
    shared_ptr_toy(shared_ptr_toy&& other) noexcept;
    ~shared_ptr_toy();
    shared_ptr_toy& operator=(const shared_ptr_toy& other);
    shared_ptr_toy& operator=(shared_ptr_toy&& other) noexcept;
    void reset() noexcept;
    std::string getName() const noexcept;
    Toy* get() const noexcept;
    int use_count() const noexcept;
private:
    Toy* m_toy;
    int* m_refCount;    
};
