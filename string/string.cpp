#include "string.h"
#include <iostream>

string::string()
{
	data = nullptr;
	length = 0;
	allocatedMemory = 0;
}

string::string(const char * a_data)
{
	// SET length to be that of a_data
	length = Length(a_data);
	// + 1 for null terminator
	allocatedMemory = length + 1;
	// ASSIGN memory
	data = new char[allocatedMemory];
	// copy over the data from the passed in argument to this
	Copy(data, a_data);
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
	// temp char[] for the current string
	char * temp = new char[allocatedMemory];
	// copy it over
	Copy(temp, data);
	// delete old memory
	delete[] data;
	// increase length based on the other length
	length += a_other.length;
	// set allocated memory to length + 1 (null-terminator)
	allocatedMemory = length + 1;
	// remake the memory with enough length
	data = new char[allocatedMemory];
	// copy over the old data
	Copy(data, temp);
	// delete the old temp memory
	delete[] temp;
	// append the other data
	ConCat(data, a_other.data);
}

void string::Prepend(string & a_other)
{
	// temp char[] for the current string
	char * temp = new char[allocatedMemory];
	// copy it over
	Copy(temp, data);
	// delete old memory
	delete[] data;
	// increase length based on the other length
	length += a_other.length;
	// set allocated memory to length + 1 (null-terminator)
	allocatedMemory = length + 1;
	// remake the memory with enough length
	data = new char[allocatedMemory];
	// copy over the other data
	Copy(data, a_other.data);
	// concatenate the original data
	ConCat(data, temp);
	// delete the old temp memory
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
	return 0;
}

int string::Find(int a_startIndex, string & a_other)
{
	return 0;
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
	if (data == nullptr)
		return;
	std::cout << data;
}

bool string::operator==(const char & a_other)
{
	int result = Compare(data, &a_other);
	if (result == 0)
		return true;
	return false;
}

bool string::operator==(string & a_other)
{
	return *this == *a_other.data;
}

void string::operator=(const char & a_other)
{
	// delete old data if it's there
	if (data != nullptr)
	{
		delete[] data;
	}

	// set the length and allocated memory
	length = Length(&a_other);
	allocatedMemory = length + 1;
	
	// create the memory for the new data
	data = new char[allocatedMemory];
	
	Copy(data, &a_other);
}

void string::operator=(string & a_other)
{
	*this = *a_other.data;
}

string & string::operator+(const char & a_other)
{
	string result(&a_other);
	result.Prepend(*this);
	return result;
}

string & string::operator+(string & a_other)
{
	string result = *this;
	result.Append(a_other);
	return result;
}

void string::operator+=(const char & a_other)
{
	*this = *this + a_other;
}
void string::operator+=(string & a_other)
{
	*this = *this + a_other;
}

char * string::operator[](unsigned int a_index)
{
	if (a_index < 0 || a_index >= length)
		return nullptr;
	return &data[a_index];
}

int string::Length(const char * a_str)
{
	int index = 0;
	while (a_str[index] != 0)
	{
		index++;
	}
	return index;
}

void string::Copy(char *& a_dest, const char * a_src)
{
	int destL = Length(a_dest);
	int srcL  = Length(a_src);

	if (destL == srcL)
	{
		for (int i = 0; i <= destL; i++)
		{
			a_dest[i] = a_src[i];
		}
	}
	else
	{
		delete[] a_dest;
		a_dest = new char[srcL + 1];
		for (int i = 0; i <= srcL; i++)
		{
			a_dest[i] = a_src[i];
		}
	}
}

void string::ConCat(char * a_dest, const char * a_src)
{
	char * temp = new char[Length(a_dest) + 1];
	for (int i = 0; i <= Length(a_dest); i++)
	{
		temp[i] = a_dest[i];
	}
	delete a_dest;
	a_dest = new char[Length(temp) + Length(a_src) + 1];
	for (int i = 0; i <= Length(temp) + Length(a_src); i++)
	{
		if (i < Length(temp))
		{
			a_dest[i] = temp[i];
		}
		else
		{
			a_dest[i] = a_src[i];
		}
	}
}

bool string::Compare(const char * a_str1, const char * a_str2)
{
	return false;
}

void string::Resize(char * a_str, int a_size)
{

}

void string::WriteToConsole(char * a_str)
{
	std::cout << a_str;
}