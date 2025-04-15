# Libft

_______________________________________________________________________________________
15.04.2025
- Created ft_memcpy
	(::comment)
	The memcpy() function copies n bytes from memory area src to memory area dest. The memory areas must not overlap. Use memmove(3) if the memory areas do overlap.
	(:/comment)
- Created ft_bzero function
	# The bzero() function sets the first n bytes of the area starting at s to zero (bytes containing aq\0aq).
- Created ft_memset function
	# The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.
- Created ft_isprint function
	# checks for any printable character including space.
- Created ft_isalpha function
	# checks for an alphabetic character; in the standard "C" locale, it is equivalent to (isupper(c) || islower(c)). In some locales, there may be additional characters for which isalpha() is true-letters which are neither upper case nor lower case.
- Created ft_isalnum function
	# checks for an alphanumeric character; it is equivalent to (isalpha(c) || isdigit(c)).
- Created ft_isascii function
	# checks whether c is a 7-bit unsigned char value that fits into the ASCII character set.
- Added comments of descriptions of each individual functions(visible in file)
- Updated minor error in the 42 header of ft_atoi and ft_strlen
- Updated ft_strlen function name(from strlen)
- Created git repo(personal)
- Quality of life configuration done in VScode(github, terminal change[bash->zsh], added additional extensions)
- Created README.md
_____________________________________________________________________________________
14.04.2025
- Created strlen
- Created ft_atoi