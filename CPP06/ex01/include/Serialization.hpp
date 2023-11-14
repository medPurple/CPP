#pragma once

#include <iostream>
#include <string>
#include <stdint.h>


struct Data{
				int age;
				int size;
				bool unknow; 
				std::string name;
};

class Serialization{
	public		:
					static uintptr_t serialize(Data* ptr);
					static Data* deserialize(uintptr_t raw);
	protected	:

	private		:
					Serialization();
					Serialization(const Serialization& rhs);
					Serialization &operator=(const Serialization& rhs);
					~Serialization();

};

