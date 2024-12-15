#include "Composite.h"

int main()
{
	Folder* rootFolder = new Folder("root");
	Folder* subFolder1 = new Folder("subFolder1");
	Folder* subFolder2 = new Folder("subFolder2");
	
	File* file1 = new File(11, "file1");
	File* file2 = new File(12, "file2");
	File* file3 = new File(20, "file3");
	File* file4 = new File(15, "file4");

	rootFolder->add(subFolder1);
	rootFolder->add(subFolder2);

	subFolder1->add(file1);
	subFolder2->add(file2);
	subFolder2->add(file3);
	subFolder2->add(file4);

	rootFolder->display();
}