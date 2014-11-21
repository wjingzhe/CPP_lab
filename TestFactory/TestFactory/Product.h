//Product.h
#pragma once


class Product
{
public:
	virtual ~Product() = 0;

protected:
	Product();

private:
};


class ConcreteProduct :public Product
{
public:
	ConcreteProduct();
	~ConcreteProduct();

private:

};