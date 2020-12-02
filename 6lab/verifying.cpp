#include "verifying.h"

bool isReal(char** line)
{
	if (isSign(line))
	{
		if (isMantissa(line))
		{
			if (isExponent(line))
			{
				*line += 1;
				return (**line == '\0');
			}
		}
	}
	return false;
}

bool isMantissa(char** line)
{
	if (isInteger(line))
	{
		while (isInteger(line));
		if (isDot(line))
		{
			if (isInteger(line))
			{
				while (isInteger(line));
			}
		}
		return true;
	}
	return false;
}

bool isExponent(char** line)
{
	if (isE(line))
	{
		if (isSign(line))
		{
			if (isInteger(line))
			{
				return true;
			}
		}
	}
	return false;
}

bool isInteger(char** line)
{
	if (isCifer(line))
	{
		return true;
	}
	return false;
}

bool isDot(char** line)
{
	if (**line == '.')
	{
		*line += 1;
		return true;
	}
	return false;
}

bool isE(char** E)
{
	if (**E == 'E')
	{
		*E += 1;
		return true;
	}
	return false;
}

bool isCifer(char** line)
{
	if (**line == '0' || **line == '1' || **line == '2' || **line == '3' || **line == '4' or
		**line == '5' || **line == '6' || **line == '7' || **line == '8' || **line == '9')
	{
		*line += 1;
		return true;
	}
	return false;
}

bool isSign(char** sign)
{
	if ((**sign == '+') || (**sign == '-'))
	{
		*sign += 1;
		return true;
	}
	return false;
}