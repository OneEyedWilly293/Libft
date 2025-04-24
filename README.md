# Libft

## <ins>Logs</ins>

### <ins>24.04.2025</ins>
- Quick fixes on ft_atoi & ft_itoa detected via Norm check
	> *Need to revisit ft_itoa in the future(over 25 line limit). *
- Minor fix in ft_isprint function located via test.
- Added test file for ft_isprint function.
- Added test file for ft_isascii function.
- Updated ft_isascii.c function in file(from "isascii).
- Added test file for ft_isalnum function.
- Modified ft_isalnum function to check smaller alphabets as well.
- Created test file for ft_isdigit function.
- Minor fix on syntax error in libft.h
- Created ft_isdigit function.
- Renamed ft_isalnum functioned file accordingly(from ft_isdigit).


### <ins>23.04.2025</ins>
- Created test file for ft_isalpha function.
- Modified ft_isalpha.
- Created libft header file.
- Constructed a plan to implement tests for all functions created into one file.
	> *Thank you Boris!*

### <ins>22.04.2025</ins>
- Created ft_putnbr_fd
	> *Outputs the integer ’n’ to the specified file
descriptor.*

- Created ft_putendl_fd
	> *Outputs the string ’s’ to the specified file
descriptor followed by a newline.*

- Created ft_putstr_fd function
	> *Outputs the string ’s’ to the specified file
descriptor.*

- Created ft_putchar_fd function
	> *Outputs the character ’c’ to the specified file
descriptor.*

- Created ft_striteri function
	> *Applies the function ’f’ to each character of the
string passed as argument, passing its index as
the first argument. Each character is passed by
address to ’f’ so it can be modified if necessary.*

- Created ft_strmapi function
	> *Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to store the
results from the successive applications of f.*

- Created ft_itoa function
	> *Allocates memory (using malloc(3)) and returns
a string representing the integer received as an
argument. Negative numbers must be handled.*

- Changed ft_split function according to prototype in exercise
	> *Allocates memory (using malloc(3)) and returns an
array of strings obtained by splitting ’s’ using
the character ’c’ as a delimiter. The array must
end with a NULL pointer.*

- Created ft_strtrim function
	> *Allocates memory (using malloc(3)) and returns a
copy of ’s1’ with characters from ’set’ removed
from the beginning and the end.*

### <ins>20.04.2025</ins>
- Created ft_strjoin function
	> *Allocates memory (using malloc(3)) and returns a
	new string, which is the result of concatenating
	’s1’ and ’s2’.*

- Created ft_substr function
	> *Allocates memory (using malloc(3)) and returns a
	substring from the string ’s’.
	The substring starts at index ’start’ and has a
	maximum length of ’len’.*

- Created ft_strdup function
	> *The strdup() function returns a pointer to a new string which is a duplicate of the string s. Memory for the new string is obtained with malloc(3), and can be freed with free(3).*


### <ins>18.04.2025</ins>
- Created ft_calloc function
	> *The calloc() function allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory. The memory is set to zero. If nmemb or size is 0, then calloc() returns either NULL, or a unique pointer value that can later be successfully passed to free().*

- Added Description for the <sub>atoi</sub> function

- Created ft_strnstr function
	> *The strnstr() function locates the first occurrence of the null-termi-
     nated string s2 in the string s1, where not more than n characters are
     searched.  Characters that appear after a `\0' character are not
     searched.  Since the strnstr() function is a FreeBSD specific API, it
     should only be used when portability is not a concern.*

- Created ft_memcmp function
	> *The memcmp() function compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.*


### <ins>17.04.2025</ins>
- Created ft_split function
	> *Allocates memory (using malloc(3)) and returns a copy of ’s1’ with characters from ’set’ removed from the beginning and the end.* 

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
	> *The strlcat() function appends the NUL-terminated string src to the end of dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.*

- Created ft_strlcpy function
	> *The strlcpy() function copies up to size - 1 characters from the NUL-terminated string src to dst, NUL-terminating the result.*

- Created ft_memmove function
	> *The memmove() function copies n bytes from memory area src to memory area dest. The memory areas may overlap: copying takes place as though the bytes in src are first copied into a temporary array that does not overlap src or dest, and the bytes are then copied from the temporary array to dest.*


### <ins>15.04.2025</ins>
- Created ft_memcpy function
	> *The memcpy() function copies n bytes from memory area src to memory area dest. The memory areas must not overlap. Use memmove(3) if the memory areas do overlap.*

- Created ft_bzero function
	> *The bzero() function sets the first n bytes of the area starting at s to zero (bytes containing aq\0aq).*
- Created ft_memset function
	> *The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.*
- Created ft_isprint function
	> *checks for any printable character including space.*
- Created ft_isalpha function
	> *checks for an alphabetic character; in the standard "C" locale, it is equivalent to (isupper(c) || islower(c)). In some locales, there may be additional characters for which isalpha() is true-letters which are neither upper case nor lower case.*
- Created ft_isalnum function
	> *checks for an alphanumeric character; it is equivalent to (isalpha(c) || isdigit(c)).*
- Created ft_isascii function
	> *checks whether c is a 7-bit unsigned char value that fits into the ASCII character set.*
- ~Added comments of descriptions of each individual functions(visible in file)~
- Updated minor error in the 42 header of ft_atoi and ft_strlen
- Updated ft_strlen function name(from strlen)

- Quality of life configuration done in VScode(github, terminal change[bash->zsh], added additional extensions)
- Created README.md
- Created git repo(personal)


### <ins>14.04.2025</ins>
- Created strlen
- Created ft_atoi
	> * The atoi() function converts the initial portion of the string pointed to by nptr to int. The behavior is the same as
			strtol(nptr, NULL, 10);
		except that atoi() does not detect errors.*
