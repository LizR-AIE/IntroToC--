#pragma once

class string
{
public:

	//--------------------------------
	// Constructors, Destructor, move & copy
	//--------------------------------
	string();
	string(char * a_data);
	~string();

	//--------------------------------
	// Public functions
	//--------------------------------
	// Returns an integer representing the count of characters up to the null termination character
	unsigned int Length();
	// Returns a char representing the character at the location. 
	char * CharacterAt(unsigned int index);
	// Returns true if str contains the same characters.
	bool EqualTo(string & other);
	// Adds str to the end of the string
	void Append(string & other);
	// Adds str to the front of the string
	void Prepend(string & other);
	// Return the const char * that is useable with std::cout	const char * CStr();	// Convert all characters to lowercase	void ToLower();	// Convert all characters to uppercase	void ToUpper();	// Returns the location of the findString. If not found, return -1	int Find(string & findString);	// Returns the location of the strToFind. Beginning the	search from startIndex.If not found, return -1	int Find(int startIndex, string & findString);	// Replaces all occurrences of findString with replaceString	void Replace(string & findString, string & replaceString);	// Wait for input in the console window and store the result	void ReadFromConsole();	// Write the string to the console window	void WriteToConsole();	//--------------------------------
	// operator overloads : ==, =, +, +=, []
	//--------------------------------
	// Comparison
	bool		operator==(string & other);
	// Set
	void		operator= (string & other);
	void		operator= (char * other);
	// returns Concatinate
	string &	operator+ (string & other);
	// set concatinate
	void		operator+=(string & other);
	// get at index
	char *		operator[](unsigned int index);

private:
	unsigned int length;
	unsigned int allocatedMemory;
	char * data;
};