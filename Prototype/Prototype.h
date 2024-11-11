#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <memory>
#include <string>
#include <iostream>

class IShape
{
public:
	virtual ~IShape() = default;
	virtual std::unique_ptr<IShape> Clone() const = 0;
	virtual void Draw() const = 0;

protected:
	std::string color_;
};

class Circle : public IShape
{
public:
	Circle(double radius, std::string color) : radius_(radius) {
		this->color_ = color;
	}

	std::unique_ptr<IShape> Clone() const override {
		return std::make_unique<Circle>(*this);
	}

	void Draw() const override {
		std::cout << "Circle with radius: " << radius_ << " color is: " << this->color_ << std::endl;
	}

private:
	double radius_;

};

class Rectangle : public IShape
{
public:
	Rectangle(double width, double height, std::string color) : width_(width), height_(height) {
		this->color_ = color;
	}

	std::unique_ptr<IShape> Clone() const override {
		return std::make_unique<Rectangle>(*this);
	}

	void Draw() const override {
		std::cout << "Rectangle with width: " << width_ << " height is: " << height_ << "color is: " << this->color_ << std::endl;
	}

private:
	double width_;
	double height_;
};


#endif // PROTOTYPE_H
