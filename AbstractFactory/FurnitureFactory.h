#ifndef FURNITUREFACTORY_H
#define FURNITUREFACTORY_H

#include <memory>
#include <iostream>
#include <string>

class IChair
{
public:
	virtual ~IChair() = default;
	virtual void SitOn() const = 0;
};

class ModernChair : public IChair
{
public:
	void SitOn() const override {
		std::cout << "You are sitting on a modern chair !" << std::endl;
	}
};

class VictorianChair : public IChair
{
public:
	void SitOn() const override {
		std::cout << "You are sitting on a victorian chair !" << std::endl;
	}
};


class ISofa
{
public:
	virtual ~ISofa() = default;
	virtual void LieOn() const = 0;
};

class ModernSofa : public ISofa
{
public:
	void LieOn() const override {
		std::cout << "You are lying on a modern sofa !" << std::endl;
	}
};

class VictorianSofa : public ISofa
{
public:
	void LieOn() const override {
		std::cout << "You are lying on a victorian sofa !" << std::endl;
	}
};

class IFurnitureFactory
{
public:
	virtual ~IFurnitureFactory() = default;
	virtual std::unique_ptr<IChair> CreateChair() = 0;
	virtual std::unique_ptr<ISofa> CreateSofa() = 0;
};

class ModernFurniteFactory : public IFurnitureFactory
{
public:
	std::unique_ptr<IChair> CreateChair() override {
		return std::make_unique<ModernChair>();
	}

	std::unique_ptr<ISofa> CreateSofa() override {
		return std::make_unique<ModernSofa>();
	}
};


class VictorianFurnitureFactory : public IFurnitureFactory
{
public:
	std::unique_ptr<IChair> CreateChair() override {
		return std::make_unique<VictorianChair>();
	}

	std::unique_ptr<ISofa> CreateSofa() override {
		return std::make_unique<VictorianSofa>();
	}
};

#endif // FURNITUREFACTORY_H
