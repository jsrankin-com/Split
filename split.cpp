
// ************************EIGHTY CHARACTER CODING AREA*************************// LANDSCAPE COMMENT SECTION LENGTH
/*
   _________________________________________________________________________
 / \                                                                        \
|   |Split.cpp                                                              |
 \_ | Accepts input as first param and splits the content based on the      |
    |the second param. If no second param is supplied then it will split on |
    |any whitespace character.                                              |
    |              This function is overloaded to be more functional, which |
    |means there is quite a bit of code duplication.			    |
    |									    |
    |@params:                                                               |
    | (std::string)							    |
    | (std::istringstream&)						    |
    | (std::string, char)                                                   |
    | (std::istringstream&, char)                                           |
    | (std::string, char[])                                                 |
    | (std::istringstream&, char[])                                         |
    | (std::string, std::vector<char>)                                      |
    | (std::istringstream&, std::vector<char>)                              |
    | (std::string, std::string)                                            |
    | (std::istringstream&, std::string)                                    |
    | (std::string, std::string[])					    |
    | (std::istringstream&, std::string[				    |
    | (std::string, std::vector<std::string>)				    |
    | (std::istringstream&, std::vector<std::string>)			    |
    | (std::string, std::function<bool(char)>)                              |
    | (std::istringstream&, std::function<bool(char)>)                      |
    | (std::string, std::regex)						    |
    | (std::istringstream&, std::regex)                                     |
    |                                                                       |
    |@returns:                                                              |
    | std::vector<std::string>                                              |
    |http://websites.umich.edu/~eecs381/handouts/filestreams.pdf            |
    |    ___________________________________________________________________|___
    |   /                                                                      /
     \_/______________________________________________________________________/

//Interesting article about having to convert std::istringstream& to std::string
//http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0757r0.html

*/
/*
.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.
 \_//-\\_//-\\_//-\\_//-\\_//-\\_// \\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\

 Split()
 @params: std::string str
 @returns: std::vector<std::string>

 Split()
 @params: std::istringstream& str
 @returns: std::vector<std::string>

 Description:
  Split on whitespace character using std::isspace

 .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .
//-\\_//-\\_//-\\_//-\\_//-\\_// \\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//
*/

#pragma once
#include "Split.h"

std::vector<std::string> Split(std::string str)
{
	//Split on whitespace character
	return Split(str, isspace);
}


std::vector<std::string> Split(std::istringstream& iss)
{
	std::string str = iss.str();

	//Split on whitespace character
	return Split(str, isspace);
}

/*
.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.
 \_//-\\_//-\\_//-\\_//-\\_//-\\_// \\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\

 Split()
 @params: std::string, char
 @returns: std::vector<std::string>

 Split()
 @params: std::istringstream&, char
 @returns: std::vector<std::string>

 Description:
  Split on second param. Strings are proccesed using find and istringstreams are
  processed using getline.

 .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .
//-\\_//-\\_//-\\_//-\\_//-\\_// \\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//
*/

//Processed using std::find
std::vector<std::string> Split(std::string str, char del)
{
	std::vector<std::string> vec;

	if (str.empty())
	{
		return vec;
	}

	if (del == 0)
	{
		//Split on whitespace character
		return Split(str, isspace);
	}

	const std::size_t str_length = str.length();
	std::size_t current_pos = 0;

	std::size_t pos = str.find(del);

	while (pos != std::string::npos)
	{
		//Catch multiple deliminators in a row
		if (pos != current_pos)
			vec.emplace_back(str.substr(current_pos, pos - current_pos));

		//Update current position
		current_pos = pos + 1;

		//Find delimiter from current position
		pos = str.find(del, current_pos);
	}
	//Append remaining string
	if (current_pos != str_length)
		vec.emplace_back(str.substr(current_pos, str_length - current_pos));

	return vec;
}

//Processed using std::getline
std::vector<std::string> Split(std::istringstream& iss, char del)
{
	std::vector<std::string> vec;
	if (!iss.good())
	{
		return vec;
	}

	if (del == 0)
	{
		//Split on whitespace character
		return Split(iss, isspace);
	}

	std::string str_cache;
	while (getline(iss, str_cache, del))
	{
		if (!str_cache.empty())
			vec.emplace_back(str_cache);
	}


	return vec;
}

/*
.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.
 \_//-\\_//-\\_//-\\_//-\\_//-\\_// \\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\

 Split()
 @params: std::string, std::vector<char>
 @returns: std::vector<std::string>

 Split()
 @params: std::istringstream&, char[]
 @returns: std::vector<std::string>

 Description:
  Split on second params.

 .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .
//-\\_//-\\_//-\\_//-\\_//-\\_// \\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//
*/

std::vector<std::string> Split(std::string str, std::vector<char> del)
{
	std::vector<std::string> vec;

	if (str.empty())
	{
		return vec;
	}

	if (del.empty())
	{
		//Split on whitespace character
		return Split(str, isspace);
	}

	const std::size_t str_length = str.length();
	std::size_t current_pos = 0;
	std::size_t pos = 0;

	std::size_t found_first = std::string::npos;
	const std::size_t del_length = 1;

	for (char s : del)
	{
		pos = str.find(s);
		if (pos < found_first)
		{
			found_first = pos;
		}
	}

	while (found_first != std::string::npos)
	{
		//Catch multiple deliminators in a row
		if (found_first != current_pos)
			vec.emplace_back(str.substr(current_pos, found_first - current_pos));

		//Update current position
		current_pos = found_first + del_length;

		//Find delimiter from current position
		found_first = std::string::npos;
		for (char s : del)
		{
			pos = str.find(s, current_pos);
			if (pos < found_first)
			{
				found_first = pos;
			}
		}
	}
	//Append remaining string
	if (current_pos != str_length)
		vec.emplace_back(str.substr(current_pos, str_length - current_pos));

	return vec;
}

std::vector<std::string> Split(std::string str, char del[])
{
	std::vector<std::string> vec;

	if (str.empty())
	{
		return vec;
	}

	if (del == 0)
	{
		//Split on whitespace character
		return Split(str, isspace);
	}

	const std::size_t str_length = str.length();
	const std::size_t del_length = strlen(del);

	std::size_t current_pos = 0;
	std::size_t pos = str.find(del);

	while (pos != std::string::npos)
	{
		//Catch multiple deliminators in a row
		if (pos != current_pos)
			vec.emplace_back(str.substr(current_pos, pos - current_pos));

		//Update current position
		current_pos = pos + del_length;

		//Find delimiter from current position
		pos = str.find(del, current_pos);
	}
	//Append remaining string
	if (current_pos != str_length)
		vec.emplace_back(str.substr(current_pos, str_length - current_pos));

	return vec;
}

std::vector<std::string> Split(std::istringstream& iss, char del[])
{
	std::string str = iss.str();
	return Split(str, del);
}



/*
.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.
 \_//-\\_//-\\_//-\\_//-\\_//-\\_// \\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\

 Split()
 @params: std::string, std::string
 @returns: std::vector<std::string>

 Split()
 @params: std::istringstream&, std::string
 @returns: std::vector<std::string>

 Description:
  Split on second param.

 .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .
//-\\_//-\\_//-\\_//-\\_//-\\_// \\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//
*/

std::vector<std::string> Split(std::string str, std::string del)
{
	std::vector<std::string> vec;

	if (str.empty())
	{
		return vec;
	}

	if (del.empty())
	{
		//Split on whitespace character
		return Split(str, isspace);
	}

	const std::size_t str_length = str.length();
	const std::size_t del_length = del.length();

	std::size_t current_pos = 0;
	std::size_t pos = str.find(del);

	while (pos != std::string::npos)
	{
		//Catch multiple deliminators in a row
		if (pos != current_pos)
			vec.emplace_back(str.substr(current_pos, pos - current_pos));

		//Update current position
		current_pos = pos + del_length;

		//Find delimiter from current position
		pos = str.find(del, current_pos);
	}
	//Append remaining string
	if (current_pos != str_length)
		vec.emplace_back(str.substr(current_pos, str_length - current_pos));

	return vec;
}

std::vector<std::string> Split(std::istringstream& iss, std::string del)
{
	std::vector<std::string> vec;
	std::string str = iss.str();

	if (str.empty())
	{
		return vec;
	}

	if (del.empty())
	{
		//Split on whitespace character
		return Split(str, isspace);
	}

	const std::size_t del_length = del.length();

	if (del_length == 1)
	{
		return Split(iss, del[0]);
	}

	const std::size_t str_length = str.length();

	std::size_t current_pos = 0;
	std::size_t pos = str.find(del);

	while (pos != std::string::npos)
	{
		//Catch multiple deliminators in a row
		if (pos != current_pos)
			vec.emplace_back(str.substr(current_pos, pos - current_pos));

		//Update current position
		current_pos = pos + del_length;

		//Find delimiter from current position
		pos = str.find(del, current_pos);
	}
	//Append remaining string
	if (current_pos != str_length)
		vec.emplace_back(str.substr(current_pos, str_length - current_pos));

	return vec;
}


/*
.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.
 \_//-\\_//-\\_//-\\_//-\\_//-\\_// \\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\

 Split()
 @params: std::string, std::string[]
 @returns: std::vector<std::string>

 Split()
 @params: std::istringstream&, std::string[]
 @returns: std::vector<std::string>

 Description:
  Split on second params.

 .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .
//-\\_//-\\_//-\\_//-\\_//-\\_// \\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//
*/

std::vector<std::string> Split(std::string str, std::string del[])
{
	std::vector<std::string> vec;

	if (str.empty())
	{
		return vec;
	}

	if (del == 0)
	{
		//Split on whitespace character
		return Split(str, isspace);
	}

	const std::size_t str_length = str.length();
	std::size_t current_pos = 0;
	std::size_t pos = 0;

	std::size_t found_first = std::string::npos;
	std::size_t del_length = 0;

	for (std::size_t i = 0; i < sizeof(del); ++i)
	{
		if (!del[i].empty())
		{
			pos = str.find(del[i]);
			if (pos < found_first)
			{
				found_first = pos;
				del_length = del[i].length();
			}
		}
	}

	while (found_first != std::string::npos)
	{
		//Catch multiple deliminators in a row
		if (found_first != current_pos)
			vec.emplace_back(str.substr(current_pos, found_first - current_pos));

		//Update current position
		current_pos = found_first + del_length;

		//Find delimiter from current position
		found_first = std::string::npos;
		for (std::size_t i = 0; i < sizeof(del); ++i)
		{
			if (!del[i].empty())
			{
				pos = str.find(del[i], current_pos);
				if (pos < found_first)
				{
					found_first = pos;
					del_length = del[i].length();
				}
			}
		}
	}
	//Append remaining string
	if (current_pos != str_length)
		vec.emplace_back(str.substr(current_pos, str_length - current_pos));

	return vec;
}


/*
.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.
 \_//-\\_//-\\_//-\\_//-\\_//-\\_// \\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\

 Split()
 @params: std::string, std::vector<std::string>
 @returns: std::vector<std::string>

 Split()
 @params: std::istringstream&, std::vector<std::string>
 @returns: std::vector<std::string>

 Description:
  Split on second params.

 .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .
//-\\_//-\\_//-\\_//-\\_//-\\_// \\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//
*/

std::vector<std::string> Split(std::string str, std::vector<std::string> del)
{
	std::vector<std::string> vec;

	if (str.empty())
	{
		return vec;
	}

	if (del.empty())
	{
		//Split on whitespace character
		return Split(str, isspace);
	}

	const std::size_t str_length = str.length();
	std::size_t current_pos = 0;
	std::size_t pos = 0;

	std::size_t found_first = std::string::npos;
	std::size_t del_length = 0;

	for (std::string s : del)
	{
		if (!s.empty())
		{
			pos = str.find(s);
			if (pos < found_first)
			{
				found_first = pos;
				del_length = s.length();
			}
		}
	}

	while (found_first != std::string::npos)
	{
		//Catch multiple deliminators in a row
		if (found_first != current_pos)
			vec.emplace_back(str.substr(current_pos, found_first - current_pos));

		//Update current position
		current_pos = found_first + del_length;

		//Find delimiter from current position
		found_first = std::string::npos;
		for (std::string s : del)
		{
			if (!s.empty())
			{
				pos = str.find(s, current_pos);
				if (pos < found_first)
				{
					found_first = pos;
					del_length = s.length();
				}
			}
		}
	}
	//Append remaining string
	if (current_pos != str_length)
		vec.emplace_back(str.substr(current_pos, str_length - current_pos));

	return vec;
}

/*
.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.
 \_//-\\_//-\\_//-\\_//-\\_//-\\_// \\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\
 Split()
 @params: std::string, std::function<bool(char)>
 @returns: std::vector<std::string>

 Split()
 @params: std::istringstream&, std::function<bool(char)>
 @returns: std::vector<std::string>

 Description:
  Split with a supplied std::function. Parses string char by char using the
  second param as a comparator function. If std::istringstream& is supplied it
  is converted to an std::string.
 .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .
//-\\_//-\\_//-\\_//-\\_//-\\_// \\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//
*/

std::vector<std::string> Split(std::string str, CharacterComparator fn)
{
	std::vector<std::string> vec;

	if (str.empty())
	{
		return vec;
	}

	const std::size_t str_length = str.length();
	const std::size_t del_length = 1;

	if (str_length == del_length)
	{
		if (!fn(str[0]))
			vec.emplace_back(str);
	}
	else
	{
		const std::size_t difference_str_del = str_length - del_length;
		std::size_t current_pos = 0;
		//Iterate std::string character by character
		//Use difference to ensure we never read past the end of the string
		for (std::size_t i = 0; i <= difference_str_del; ++i)
		{
			if (fn(str[i]))
			{
				//Catch multiple deliminators in a row
				if (i != current_pos)
					vec.emplace_back(str.substr(current_pos, i - current_pos));

				//Advance past the delimiter
				current_pos = i + del_length;
			}
		}
		//Append remaining string
		if (current_pos != str_length)
			vec.emplace_back(str.substr(current_pos, str_length - current_pos));
	}

	return vec;
}

std::vector<std::string> Split(std::istringstream& iss, CharacterComparator fn)
{
	std::string str = iss.str();

	return Split(str, fn);
}

/*
.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.
 \_//-\\_//-\\_//-\\_//-\\_//-\\_// \\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\
 Split()
 @params: std::string, std::regex
 @returns: std::vector<std::string>

 Split()
 @params: std::istringstream&, std::regex
 @returns: std::vector<std::string>

 Description:
  Split with a supplied std::regex. If std::istringstream& is supplied it is
  converted to an std::string. Implemented with std::sregex_token_iterator.
 .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .-.   .
//-\\_//-\\_//-\\_//-\\_//-\\_// \\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//-\\_//
*/
std::vector<std::string> Split(std::string str, std::regex e)
{
	std::vector<std::string> vec;
	if (!str.empty())
	{
		//Null set
		std::sregex_token_iterator rend;
		//-1 indicates match as Splitters
		std::sregex_token_iterator d(str.begin(), str.end(), e, -1);
		while (d != rend) vec.emplace_back(*d++);
	}
	return vec;
}

std::vector<std::string> Split(std::istringstream& iss, std::regex e)
{
	std::string str = iss.str();

	return Split(str, e);
}
