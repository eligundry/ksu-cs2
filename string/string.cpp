/*
 * Author      : Eli Gundry
 * Date        : 02/15/2012
 * Name        : string
 * Description : My own implementation of the string datatype
 *
 */

#include "string.h"

/*
 * Initalizes string to '\0'
 * Ex: string str(); 
 */
string::string()
{
	s[0] = '\0';
}

bool string::operator==(const string& rhs) 
{
	int i = 0;

	do {
		if (rhs.s[i] != s[i]) {
			return false;
		}
		++i;
	} while (s[i] != '\0' && rhs.s[i] != '\0' && i < MAX_SIZE);

	return true;
}

char string::operator[](const int spot)
{
	return s[spot];
}
