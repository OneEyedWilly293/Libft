# Libft
### <ins>17.04.2025</ins>
- Created ft_split function
	> *Allocates memory (using malloc(3)) and returns a
copy of ’s1’ with characters from ’set’ removed
from the beginning and the end.* 

- Created ft_memchr function
	> *The memchr() function scans the initial n bytes of the memory area pointed to by s for the first instance of c. Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char.*

- Created ft_strncmp function
	> *The strncmp() function is similar, except it only compares the first (at most) n bytes of s1 and s2.*

- Created ft_strrchr function
	> *The strrchr() function returns a pointer to the last occurrence of the character c in the string s. *

### <ins>16.04.2025</ins>
- Created ft_strchr function
	> *The strchr() function returns a pointer to the first occurrence of the character c in the string s.*

- Created ft_tolower function
	> *tolower() converts the letter c to lower case, if possible.*
	
- Created ft_toupper function
	> *toupper() converts the letter c to upper case, if possible.*

- Created ft_strlcat function
	> * The strlcat() function appends the NUL-terminated string src to the end of dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.
- Created ft_strlcpy function
	<!--
	The strlcpy() function copies up to size - 1 characters from the NUL-terminated string src to dst, NUL-terminating the result.
	-->
- Created ft_memmove function
	<!--
	The memmove() function copies n bytes from memory area src to memory area dest. The memory areas may overlap: copying takes place as though the bytes in src are first copied into a temporary array that does not overlap src or dest, and the bytes are then copied from the temporary array to dest.
	-->


# 15.04.2025
- Created ft_memcpy function
	<!---
	The memcpy() function copies n bytes from memory area src to memory area dest. The memory areas must not overlap. Use memmove(3) if the memory areas do overlap.
	--->
- Created ft_bzero function
	<!--- The bzero() function sets the first n bytes of the area starting at s to zero (bytes containing aq\0aq). --->
- Created ft_memset function
	<!--- The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c. --->
- Created ft_isprint function
	<!--- checks for any printable character including space. --->
- Created ft_isalpha function
	<!--- checks for an alphabetic character; in the standard "C" locale, it is equivalent to (isupper(c) || islower(c)). In some locales, there may be additional characters for which isalpha() is true-letters which are neither upper case nor lower case. --->
- Created ft_isalnum function
	<!--- checks for an alphanumeric character; it is equivalent to (isalpha(c) || isdigit(c)). --->
- Created ft_isascii function
	<!--- checks whether c is a 7-bit unsigned char value that fits into the ASCII character set. --->
- Added comments of descriptions of each individual functions(visible in file)
- Updated minor error in the 42 header of ft_atoi and ft_strlen
- Updated ft_strlen function name(from strlen)

- Quality of life configuration done in VScode(github, terminal change[bash->zsh], added additional extensions)
- Created README.md
- Created git repo(personal)


# 14.04.2025
- Created strlen
- Created ft_atoi