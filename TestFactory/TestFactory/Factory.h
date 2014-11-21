//Factory.h
#pragma once

class Product;

class Factory
{
public:
	
	virtual Product* CreateProduct() = 0;

	virtual ~Factory() = 0;

protected:

	Factory();
};

class ConcreteFactory :public Factory
{
public:
	~ConcreteFactory();

	ConcreteFactory();

	Product* CreateProduct();
};