#include "Std_types.h"
#include "String.h"

u8 String_u8GetStrLen (u8 * string)
{
	u8 charachter = 0;
	
	while (string[charachter] != '\0')
	{
		charachter ++;
	}
	return charachter;
}
