#include "Prototype.h"

int main()
{
	std::unique_ptr<IShape> circle = std::make_unique<Circle>(5.0, "red");
	std::unique_ptr<IShape> rectangle = std::make_unique<Rectangle>(10.0, 5.0, "blue");

	circle->Draw();
	rectangle->Draw();

	std::unique_ptr<IShape> cloneCircle = circle->Clone();
	std::unique_ptr<IShape> cloneRectangle = rectangle->Clone();

	cloneCircle->Draw();
	cloneRectangle->Draw();
}
