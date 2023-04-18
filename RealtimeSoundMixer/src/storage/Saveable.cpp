#include "Saveable.h"
void WriteString(const std::string& str, std::ofstream& file) {
	size_t str_size = str.size();
	WRITE(str_size, file);
	file.write(&str[0], str_size);
}

void ReadString(std::string& str, std::ifstream& file) {
	size_t str_size = 0;
	READ(str_size, file);
	file.read(&str[0], str_size);
}


#include <iostream>
void WriteSaveable(const Saveable& oj, std::ofstream& file) {
	size_t id = oj.GetId();//retrieve correct id from oj
	std::cout << "saved type id: " << id << std::endl;
	WRITE(id, file);
	oj.Save(file);
}

Saveable* ReadSaveable(std::ifstream& file)
{
	size_t id = 0;
	READ(id, file);
	Saveable* ojPtr = static_cast<Saveable*>(CreateOjFromId(id));//create an object of the correct type
	if(ojPtr) ojPtr->Load(file);//load the data into the object (if the object was created successfully)
	return ojPtr;
}
