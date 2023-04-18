#pragma once

#include <fstream>
#include "storage/TypeIdSystem.h"

//source:https://stackoverflow.com/questions/67035898/saving-class-object-to-binary-file
//e.g. create save file: std::ofstream fout("name.extension", std::ofstream::binary);		NOTE: don't forget fout.close() when you're done
//e.g. create load file: std::ifstream fin("name.extension", std::ofstream::binary);		NOTE: don't forget fin.close() when you're done

#define WRITE(var, file) file.write((const char*)&var, sizeof(var))
void WriteString(const std::string& str, std::ofstream& file);

#define READ(var, file) file.read((char*)&var, sizeof(var))
void ReadString(std::string& str, std::ifstream& file);



class Saveable
{
public:
	virtual void Save(std::ofstream &file) const = 0;//save the current object into the file
	virtual void Load(std::ifstream &file) = 0;//loads the data into the current object

	virtual size_t GetId() const = 0;
};


/*
template<typename T>
void WriteSaveable(const T& oj, std::ofstream& file) {
	std::cout << "saved type id: " << GET_ID(T) << std::endl;
	WRITE(GET_ID(T), file);
	oj.Save(file);
}*/
void WriteSaveable(const Saveable& oj, std::ofstream& file);
Saveable* ReadSaveable(std::ifstream& file);