#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Component
class FileEntity {
public:
	virtual ~FileEntity() = default;
	virtual void display(const int indent = 0) = 0;
	virtual int getSize() = 0;
};

// Leaf
class File : public FileEntity {
private:
	int m_size;
	std::string m_name;
public:
	File(int size, std::string name) : m_size(size), m_name(name) {}
	
	void display(const int indent = 0) override {
		std::cout << std::string(indent, ' ') << "Name of the file: " << m_name << " Size of the file: " << m_size << std::endl;
	}
	
	int getSize() override {
		return m_size;
	}
};

// Composite
class Folder : public FileEntity {
private:
	std::string m_name;
	std::vector<FileEntity*> m_children;
public:
	Folder(std::string name) : m_name(name) {}

	void add(FileEntity* entity) {
		m_children.push_back(entity);
	}

	void display(const int indent = 0) override {
		std::cout << std::string(indent, ' ') << "+ Folder: " << m_name << std::endl;
		for (const auto& entity : m_children) {
			entity->display(indent + 2);
		}
	}

	int getSize() override {
		int totalSize = 0;
		for (const auto& entity : m_children) {
			totalSize += entity->getSize();
		}
		return totalSize;
	}
};


#endif // COMPOSITE_H