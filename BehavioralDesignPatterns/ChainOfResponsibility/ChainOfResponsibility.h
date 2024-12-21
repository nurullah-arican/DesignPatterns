#ifndef CHAINOFRESPONSIBILITY_H
#define CHAINOFRESPONSIBILITY_H

#include <iostream>
#include <string>

enum ComplaintType {
	Small,
	Medium,
	Large
};

// Base Handler
class ComplaintHandler {
protected:
	ComplaintHandler* nextHandler;

public:
	virtual ~ComplaintHandler() = default;

	void setNextHandler(ComplaintHandler* handler) {
		nextHandler = handler;
	}

	virtual void handleComplaint(ComplaintType complaint) = 0;
};

// Concrete Handler I
class Manager : public ComplaintHandler {
public:
	void handleComplaint(ComplaintType complaint) override {
		if (complaint == ComplaintType::Small) {
			std::cout << "I am a Manager, i can handle small complaints." << std::endl;
		}
		else if (nextHandler) {
			std::cout << "Manager: Passing the complaint to the next handler..." << std::endl;
			nextHandler->handleComplaint(complaint);
		}
		else {
			std::cout << "No one can handle this complaint." << std::endl;
		}
	}
};

// Concrete Handler II
class Director : public ComplaintHandler {
public:
	void handleComplaint(ComplaintType complaint) override {
		if (complaint == ComplaintType::Medium) {
			std::cout << "I am a Director, I can handle medium complaints." << std::endl;
		}
		else if (nextHandler) {
			std::cout << "Director: Passing the complaint to the next handler..." << std::endl;
			nextHandler->handleComplaint(complaint);
		}
		else {
			std::cout << "No one can handle this complaint." << std::endl;
		}
	}
};

// Concrete Handler III
class GeneralManager : public ComplaintHandler {
public:
	void handleComplaint(ComplaintType complaint) override {
		if (complaint == ComplaintType::Large) {
			std::cout << "I am a GeneralManager, i can handle large complaints." << std::endl;
		}
		else if (nextHandler) {
			std::cout << "GeneralManager: Passing the complaint to the next handler..." << std::endl;
			nextHandler->handleComplaint(complaint);
		}
		else {
			std::cout << "No one can handle this complaint." << std::endl;
		}
	}
};


#endif // CHAINOFRESPONSIBILITY_H