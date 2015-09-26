#include "archivotype.h"

ArchivoType::~ArchivoType()
{
}

string ArchivoType::GetName()
{
	return Name;
}


ArchivoType::ArchivoType(Type *t)
{
    this->OfType=t;
    this->Name="Archivo";
}

