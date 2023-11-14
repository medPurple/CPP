#include "Serialization.hpp"


/*----------------- Coplien ------------- */

Serialization::Serialization(){}

Serialization::Serialization(const Serialization& rhs){*this = rhs;}

Serialization &Serialization::operator=(const Serialization& rhs){

	if (this != &rhs)
		*this = rhs;
	return *this;
}

Serialization::~Serialization(){}


/*---------------- Operator ------------- */

/*---------- Getter / Setter ------------ */

/*--------------- Function -------------- */

uintptr_t Serialization::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serialization::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}

/*--------------- Exception ------------- */
