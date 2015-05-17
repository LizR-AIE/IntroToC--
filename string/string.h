#pragma once

class string
{
public:
	//----------------------------------------------------------------
	// Constructors, Destructor, move & copy
	//----------------------------------------------------------------
#pragma region constructors
	string ();
	string (const char * a_data);
	~string();
#pragma endregion

	//----------------------------------------------------------------
	// Public functions
	//----------------------------------------------------------------
#pragma region PublicFunctions
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
	// Return the const char * that is useable with std::cout
	const char * CStr();
	// Convert all characters to lowercase
	void ToLower();
	// Convert all characters to uppercase
	void ToUpper();
	// Returns the location of the findString. If not found, return -1
	int Find(string & findString);
	// Returns the location of the strToFind. Beginning the	search from startIndex.If not found, return -1
	int Find(int startIndex, string & findString);
	// Replaces all occurrences of findString with replaceString
	void Replace(string & findString, string & replaceString);
	// Wait for input in the console window and store the result
	void ReadFromConsole();
	// Write the string to the console window
	void WriteToConsole();
#pragma endregion

	//----------------------------------------------------------------
	// operator overloads : ==, =, +, +=, []
	//----------------------------------------------------------------
#pragma region operatorOverloads
	// Comparison
	bool		operator==(const char	& other);
	bool		operator==(string		& other);
	// Set
	void		operator= (const char	& other);
	void		operator= (string		& other);
	// returns Concatenate
	string &	operator+ (const char	& other);
	string &	operator+ (string		& other);
	// set concatenate
	void		operator+=(const char	& other);
	void		operator+=(string		& other);
	// get at index
	char *		operator[](unsigned int index);
#pragma endregion

private:
#pragma region variables
	unsigned int	length;
	unsigned int	allocatedMemory;
	char *			data;
#pragma endregion

public:
	//----------------------------------------------------------------
	//						Static functions
	//----------------------------------------------------------------
#pragma region staticFunctions
	// Returns the length of the char array
	static int	Length			(const char * str);
	// Copies src into dest, resizing dest if need be
	static void Copy			(char *& dest, const char * src);
	// Adds str to the end of dest
	static void ConCat			(char * dest, const char * src);
	// Returns true if the two str are the same
	static bool Compare			(const char * str1, const char * str2);
	// Resizes the char array to the specified size
	static void Resize			(char * str, int size);
	// Writes the str to console : a wrapper for std::cout <<
	static void WriteToConsole	(char * str);
#pragma endregion
};