#include "ChainOfResponsibility.h"

using namespace std;

int main()
{
	Manager* manager = new Manager();
	Director* director = new Director();
	GeneralManager* generalManager = new GeneralManager();

	manager->setNextHandler(director);
	director->setNextHandler(generalManager);

	cout << "Complaint: Small issue" << endl;
	manager->handleComplaint(Small);

	cout << "\nComplaint: Medium issue" << endl;
	manager->handleComplaint(Medium);
	
	cout << "\nComplaint: Large issue" << endl;
	manager->handleComplaint(Large);

	delete manager;
	delete director;
	delete generalManager;
}