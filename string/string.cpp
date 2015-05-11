#include "string.h"
#include <iostream>

string::string()
{
	data = nullptr;
	length = 0;
	allocatedMemory = 0;
}

string::string(char * a_data)
{
	// SET length to be that of a_data
	length = strlen(a_data);
	// + 1 for null terminator
	allocatedMemory = length + 1;
	// ASSIGN memory
	data = new char[allocatedMemory]; 
	// copy over the data from the passed in arguement to this
	for (unsigned int i = 0; i < length; i++)
	{
		data[i] = a_data[i];
	}	
	// add null terminator
	data[length] = 0;
}

string::~string()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
}

unsigned int string::Length()
{
	return length;
}

char * string::CharacterAt(unsigned int a_index)
{
	// Check that the index is with the length of the string
	if (a_index >= length)
		return nullptr;

	return &data[a_index];
}

bool string::EqualTo(string & a_other)
{
	// They're not equal if they're not the same length
	if (length != a_other.length)
		return false;

	// Check every char against the one at the same position in other
	for (unsigned int i = 0; i < length; i++)
	{
		// if they're different then the strings differ
		if (data[i] != a_other.data[i])
			return false;
	}

	// if we got to here then they are the same
	return true;
}

void string::Append(string & a_other)
{
	// Resize
	char * temp = new char[length];
	strcpy(temp, data);
	delete[] data;
	length += a_other.length;
	allocatedMemory += a_other.length;
	data = new char[allocatedMemory];
	strcpy(data, temp);
	delete[] temp;
	// end resize
	strcat(data, a_other.data);
}

void string::Prepend(string & a_other)
{
	// Resize
	char * temp = new char[length];
	strcpy(temp, data);
	delete[] data;
	length += a_other.length;
	allocatedMemory += a_other.length;
	data = new char[allocatedMemory];
	// end resize
	strcpy(data, a_other.data);
	strcat(data, temp);
	delete[] temp;
}

const char * string::CStr()
{
	return data;
}

void string::ToLower()
{
	for (unsigned int i = 0; i < length; i++)
	{
		if (data[i] >= 65 && data[i] <= 90)
			data[i] += 32;
	}
}

void string::ToUpper()
{
	for (unsigned int i = 0; i < length; i++)
	{
		if (data[i] >= 95 && data[i] <= 122)
			data[i] -= 32;
	}
}

int string::Find(string & a_other)
{

}

int string::Find(int a_startIndex, string & a_other)
{

}

void string::Replace(string & a_findString, string & a_replaceString)
{

}

void string::ReadFromConsole()
{
	std::cin >> data;
}

void string::WriteToConsole()
{
	std::cout << data;
}

void string::operator=(char * a_other)
{
	if (data != nullptr)
	{
		delete[] data;
	}
	data = new char[strlen(a_other)];
	for (int i = 0; i < strlen(a_other); i++)
	{
		data[i] = a_other[i];
	}
	data[strlen(a_other)] = 0;
	length = strlen(a_other);
	allocatedMemory = length + 1;
}