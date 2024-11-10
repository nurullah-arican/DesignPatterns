#include "FurnitureFactory.h"

void ClientCode(IFurnitureFactory& factory)
{
	auto chair = factory.CreateChair();
	auto sofa = factory.CreateSofa();
	chair->SitOn();
	sofa->LieOn();
}

int main()
{
	ModernFurniteFactory modernFurniture;
	ClientCode(modernFurniture);

	VictorianFurnitureFactory victorianFurniture;
	ClientCode(victorianFurniture);
}