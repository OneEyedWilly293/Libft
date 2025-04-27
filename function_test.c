/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:12:00 by jgueon            #+#    #+#             */
/*   Updated: 2025/04/27 23:57:18 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <bsd/string.h>     // for strlcpy function[COMPILE with -lbsd]
#include "libft.h"


/* *****************************************************************************************************
 * This test file compares your replica "ft" function implementation with the standard                 *
 * isalpha function from the C library to ensure it behaves correctly.                                 *
 *                                                                                                     *
 * *****************************************************************************************************
 *                                     TEST FOR FT_ISALPHA FUNCTION                                    *
 * It tests:                                                                                           *
 * 1. All uppercase letters (A-Z)                                                                      *
 * 2. All lowercase letters (a-z)                                                                      *
 * 3. Digits (0-9)                                                                                     *
 * 4. Special characters and control characters                                                        *
 * ****************************************************************************************************/
int	main(void)
{
	int i;
	size_t	j;
	int	passed;
	int	total;
	size_t std_result;
	size_t ft_result;

	/* Test all ASCII characters */
	passed = 0;
	total = 0;
	printf("Testing ft_isalpha against standard isalpha:\n\n");

	/* Test ASCII values from 0 to 127 */
	printf("Testing ASCII characters (0-127):\n");
	i = 0;
	while (i <= 127)
	{
		//int	std_result;
		//int	ft_result;

		std_result = isalpha(i);
		ft_result = ft_isalpha(i);

		/* Convert to 1/0 for easier comparison */
		std_result = std_result != 0 ? 1 : 0;
		ft_result = ft_result != 0 ? 1 : 0;

		if (std_result == ft_result)
		{
			passed++;
			printf("✓ "); // \u2713
		}
		else
		{
			printf("✗ "); // \u2717
		}

		printf("Char: ");
		if (i >= 32 && i <= 126)
			printf("'%c'", i);
		else
			printf("(ASCII %d)", i);

		printf(" | Standard: %zu | Yours: %zu", std_result, ft_result);

		if (std_result != ft_result)
			printf(" <- MISMATCH!");

		printf("\n");
		total++;
		i++;
	}

	/* Print summary */
	printf("\nSummary: %d/%d tests passed (%d%%)\n",
		passed, total, (passed * 100) / total);

	if (passed == total)
		printf("\nCongratulations! Your ft_isalpha function works correctly!\n\n\n");
	else
		printf("\nYour ft_isalpha function needs some fixes.\n\n\n");



	/* ******************************************************************************** */
	/*																				    */
	/*							TEST FOR FT_ISDIGIT FUNCTION                            */
	/*                                                                                  */
	/*	* Test program for ft_isdigit function                                          */
	/*                                                                                  */
	/* This program tests the ft_isdigit function by comparing its results              */
	/* with the standard isdigit function from the C library.                           */
	/* It normalizes the return values to 1 (true) or 0 (false) for clearer comparison.	*/
	/* ******************************************************************************** */

	/* Initialize counters */
	passed = 0;
	total = 0;

	/* Print header for the test */
	printf("\n===== TESTING FT_ISDIGIT =====\n\n");
	printf("Testing all ASCII characters (0-127):\n");

	/* Test all standard ASCII characters */
	for (i = 0; i <= 127; i++)
	{
		/* Normalize the return values to 0 or 1 */
		int expected = isdigit(i) ? 1 : 0;
		int result = ft_isdigit(i) ? 1 : 0;

		total++;

		/* Check if our function matches the standard library function */
		if (expected == result)
		{
			passed++;
			printf("✓ ");
		}
		else
		{
			printf("✗ ");
		}

		/* Print the character and test results */
		if (i >= 32 && i <= 126) /* Printable characters */
			printf("Char: '%c' (ASCII: %3d) | Expected: %d | Result: %d\n",
				i, i, expected, result);
		else /* Non-printable characters */
			printf("Char: '\\%3d' (ASCII: %3d) | Expected: %d | Result: %d\n",
				i, i, expected, result);
	}

	/* Print specific test cases for clarity */
	printf("\n===== SPECIFIC TEST CASES =====\n\n");

	/* Test digits */
	printf("Testing digits (0-9):\n");
	for (i = '0'; i <= '9'; i++)
	{
		printf("ft_isdigit('%c'): %d (Expected: %d)\n",
			i, ft_isdigit(i) ? 1 : 0, isdigit(i) ? 1 : 0);
	}

	/* Test some non-digits */
	printf("\nTesting some non-digits:\n");
	printf("ft_isdigit('a'): %d (Expected: %d)\n", ft_isdigit('a') ? 1 : 0, isdigit('a') ? 1 : 0);
	printf("ft_isdigit('Z'): %d (Expected: %d)\n", ft_isdigit('Z') ? 1 : 0, isdigit('Z') ? 1 : 0);
	printf("ft_isdigit('*'): %d (Expected: %d)\n", ft_isdigit('*') ? 1 : 0, isdigit('*') ? 1 : 0);
	printf("ft_isdigit(' '): %d (Expected: %d)\n", ft_isdigit(' ') ? 1 : 0, isdigit(' ') ? 1 : 0);

	/* Test edge cases */
	printf("\nTesting edge cases:\n");
	printf("ft_isdigit(-1): %d (Expected: %d)\n", ft_isdigit(-1) ? 1 : 0, isdigit(-1) ? 1 : 0);
	printf("ft_isdigit(128): %d (Expected: %d)\n", ft_isdigit(128) ? 1 : 0, isdigit(128) ? 1 : 0);

	/* Print test summary */
	printf("\n===== TEST SUMMARY =====\n");
	printf("Tests passed: %d/%d (%.2f%%)\n",
		passed, total, (float)passed / total * 100);

	if (passed == total)
		printf("All tests passed! ft_isdigit works correctly.\n\n\n");
	else
		printf("Some tests failed. Please check your implementation.\n\n\n");


	/* ************************************************************************************
	 *                          TEST FOR FT_ISALNUM FUNCTION                              *
	 *                                                                                    *
	 * This test file checks the ft_isalnum function by:                                  *
	 * 1. Testing all ASCII characters (0-127)                                            *
	 * 2. Comparing results with the standard isalnum function                            *
	 * 3. Testing specific categories: digits, uppercase letters, lowercase letters       *
	 * 4. Testing non-alphanumeric characters                                             *
	 * ***********************************************************************************/
	  /* Initialize counters */
	  passed = 0;
	  total = 0;

	  /* Print header for the test */
	  printf("\n===== TESTING FT_ISALNUM =====\n\n");
	  printf("Testing all ASCII characters (0-127):\n");

	  /* Test all standard ASCII characters */
	  for (i = 0; i <= 127; i++)
	  {
		  /* Normalize the return values to 0 or 1 */
		  int expected = isalnum(i) ? 1 : 0;
		  int result = ft_isalnum(i) ? 1 : 0;

		  total++;

		  /* Check if our function matches the standard library function */
		  if (expected == result)
		  {
			  passed++;
			  printf("✓ ");
		  }
		  else
		  {
			  printf("✗ ");
		  }

		  /* Print the character and test results */
		  if (i >= 32 && i <= 126) /* Printable characters */
			  printf("Char: '%c' (ASCII: %3d) | Expected: %d | Result: %d\n",
				  i, i, expected, result);
		  else /* Non-printable characters */
			  printf("Char: '\\%3d' (ASCII: %3d) | Expected: %d | Result: %d\n",
				  i, i, expected, result);
	  }

	  /* Print specific test cases for clarity */
	  printf("\n===== SPECIFIC TEST CASES FOR FT_ISALNUM =====\n\n");

	  /* Test digits */
	  printf("Testing digits (0-9):\n");
	  for (i = '0'; i <= '9'; i++)
	  {
		  printf("ft_isalnum('%c'): %d (Expected: %d)\n",
			  i, ft_isalnum(i) ? 1 : 0, isalnum(i) ? 1 : 0);
	  }

	  /* Test uppercase letters */
	  printf("\nTesting uppercase letters (A-Z):\n");
	  for (i = 'A'; i <= 'Z'; i++)
	  {
		  printf("ft_isalnum('%c'): %d (Expected: %d)\n",
			  i, ft_isalnum(i) ? 1 : 0, isalnum(i) ? 1 : 0);
	  }

	  /* Test lowercase letters */
	  printf("\nTesting lowercase letters (a-z):\n");
	  for (i = 'a'; i <= 'z'; i++)
	  {
		  printf("ft_isalnum('%c'): %d (Expected: %d)\n",
			  i, ft_isalnum(i) ? 1 : 0, isalnum(i) ? 1 : 0);
	  }

	  /* Test some non-alphanumeric characters */
	  printf("\nTesting some non-alphanumeric characters:\n");
	  char non_alnum[] = " \t\n!@#$%^&*()-_=+[]{}|;:'\",.<>/?\\";
	  for (i = 0; non_alnum[i] != '\0'; i++)
	  {
		  printf("ft_isalnum('%c'): %d (Expected: %d)\n",
			  non_alnum[i], ft_isalnum(non_alnum[i]) ? 1 : 0,
			  isalnum(non_alnum[i]) ? 1 : 0);
	  }

	  /* Test edge cases */
	  printf("\nTesting edge cases:\n");
	  printf("ft_isalnum(-1): %d (Expected: %d)\n",
		  ft_isalnum(-1) ? 1 : 0, isalnum(-1) ? 1 : 0);
	  printf("ft_isalnum(128): %d (Expected: %d)\n",
		  ft_isalnum(128) ? 1 : 0, isalnum(128) ? 1 : 0);

	  /* Print test summary */
	  printf("\n===== FT_ISALNUM TEST SUMMARY =====\n");
	  printf("Tests passed: %d/%d (%.2f%%)\n",
		  passed, total, (float)passed / total * 100);

	  if (passed == total)
		  printf("All tests passed! ft_isalnum works correctly.\n\n\n");
	  else
		  printf("Some tests failed. Please check your implementation.\n\n\n");



	/* ******************************************************************************** */
	/*                                                                                  */
	/*                        TEST FOR FT_ISASCII FUNCTION                              */
	/*                                                                                  */
	/* This program tests the ft_isascii function by comparing its results              */
	/* with the standard isascii function from the C library.                           */
	/* It tests all character values from -10 to 150 to verify correct behavior         */
	/* for both valid ASCII (0-127) and invalid values outside this range.              */
	/* ******************************************************************************** */

	/* Initialize counters */
	passed = 0;
	total = 0;

	/* Print header for the test */
	printf("\n===== TESTING FT_ISASCII =====\n\n");
	printf("Testing characters from -10 to 150:\n");

	/* Test a range of values including outside ASCII range */
	for (i = -10; i <= 150; i++)
	{
		/* Normalize the return values to 0 or 1 */
		int expected = isascii(i) ? 1 : 0;
		int result = ft_isascii(i) ? 1 : 0;

		total++;

		/* Check if our function matches the standard library function */
		if (expected == result)
		{
			passed++;
			printf("✓ ");
		}
		else
		{
			printf("✗ ");
		}

		/* Print the character and test results */
		if (i >= 32 && i <= 126) /* Printable characters */
			printf("Char: '%c' (ASCII: %3d) | Expected: %d | Result: %d\n",
				i, i, expected, result);
		else /* Non-printable or non-ASCII characters */
			printf("Char: (ASCII: %3d) | Expected: %d | Result: %d\n",
				i, expected, result);
	}

	/* Print specific test cases for clarity */
	printf("\n===== SPECIFIC TEST CASES FOR FT_ISASCII =====\n\n");

	/* Test boundary values */
	printf("Testing boundary values:\n");
	printf("ft_isascii(-1): %d (Expected: %d)\n",
		ft_isascii(-1) ? 1 : 0, isascii(-1) ? 1 : 0);
	printf("ft_isascii(0): %d (Expected: %d)\n",
		ft_isascii(0) ? 1 : 0, isascii(0) ? 1 : 0);
	printf("ft_isascii(127): %d (Expected: %d)\n",
		ft_isascii(127) ? 1 : 0, isascii(127) ? 1 : 0);
	printf("ft_isascii(128): %d (Expected: %d)\n",
		ft_isascii(128) ? 1 : 0, isascii(128) ? 1 : 0);

	/* Test some ASCII categories */
	printf("\nTesting some ASCII categories:\n");
	printf("Control characters (0-31):\n");
	printf("ft_isascii(0): %d (Expected: %d)\n",
		ft_isascii(0) ? 1 : 0, isascii(0) ? 1 : 0);
	printf("ft_isascii(31): %d (Expected: %d)\n",
		ft_isascii(31) ? 1 : 0, isascii(31) ? 1 : 0);

	printf("\nPrintable characters (32-126):\n");
	printf("ft_isascii(' '): %d (Expected: %d)\n",
		ft_isascii(' ') ? 1 : 0, isascii(' ') ? 1 : 0);
	printf("ft_isascii('A'): %d (Expected: %d)\n",
		ft_isascii('A') ? 1 : 0, isascii('A') ? 1 : 0);
	printf("ft_isascii('z'): %d (Expected: %d)\n",
		ft_isascii('z') ? 1 : 0, isascii('z') ? 1 : 0);
	printf("ft_isascii('~'): %d (Expected: %d)\n",
		ft_isascii('~') ? 1 : 0, isascii('~') ? 1 : 0);

	printf("\nDEL character (127):\n");
	printf("ft_isascii(127): %d (Expected: %d)\n",
		ft_isascii(127) ? 1 : 0, isascii(127) ? 1 : 0);

	/* Print test summary */
	printf("\n===== FT_ISASCII TEST SUMMARY =====\n");
	printf("Tests passed: %d/%d (%.2f%%)\n",
		passed, total, (float)passed / total * 100);

	if (passed == total)
		printf("All tests passed! ft_isascii works correctly.\n\n\n");
	else
		printf("Some tests failed. Please check your implementation.\n\n\n");



	/* ******************************************************************************** */
	/*                                                                                  */
	/*                        TEST FOR FT_ISPRINT FUNCTION                              */
	/*                                                                                  */
	/* This program tests the ft_isprint function by comparing its results              */
	/* with the standard isprint function from the C library.                           */
	/* It tests all character values from -10 to 150 to verify correct behavior         */
	/* for both printable (32-126) and non-printable characters.                        */
	/* ******************************************************************************** */

	/* Initialize counters */
	passed = 0;
	total = 0;

	/* Print header for the test */
	printf("\n===== TESTING FT_ISPRINT =====\n\n");
	printf("Testing characters from -10 to 150:\n");

	/* Test a range of values including outside printable range */
	for (i = -10; i <= 150; i++)
	{
		/* Normalize the return values to 0 or 1 */
		int expected = isprint(i) ? 1 : 0;
		int result = ft_isprint(i) ? 1 : 0;

		total++;

		/* Check if our function matches the standard library function */
		if (expected == result)
		{
			passed++;
			printf("✓ ");
		}
		else
		{
			printf("✗ ");
		}

		/* Print the character and test results */
		if (i >= 32 && i <= 127) /* Printable characters */
			printf("Char: '%c' (ASCII: %3d) | Expected: %d | Result: %d\n",
				i, i, expected, result);
		else /* Non-printable or non-ASCII characters */
			printf("Char: (ASCII: %3d) | Expected: %d | Result: %d\n",
				i, expected, result);
	}

	/* Print specific test cases for clarity */
	printf("\n===== SPECIFIC TEST CASES FOR FT_ISPRINT =====\n\n");

	/* Test boundary values */
	printf("Testing boundary values:\n");
	printf("ft_isprint(31): %d (Expected: %d)\n",
		ft_isprint(31) ? 1 : 0, isprint(31) ? 1 : 0);
	printf("ft_isprint(32): %d (Expected: %d)\n",
		ft_isprint(32) ? 1 : 0, isprint(32) ? 1 : 0);
	printf("ft_isprint(126): %d (Expected: %d)\n",
		ft_isprint(126) ? 1 : 0, isprint(126) ? 1 : 0);
	printf("ft_isprint(127): %d (Expected: %d)\n",
		ft_isprint(127) ? 1 : 0, isprint(127) ? 1 : 0);

	/* Test character categories */
	printf("\nTesting character categories:\n");
	printf("Control characters (0-31):\n");
	printf("ft_isprint(0): %d (Expected: %d)\n",
		ft_isprint(0) ? 1 : 0, isprint(0) ? 1 : 0);
	printf("ft_isprint('\\n'): %d (Expected: %d)\n",
		ft_isprint('\n') ? 1 : 0, isprint('\n') ? 1 : 0);
	printf("ft_isprint('\\t'): %d (Expected: %d)\n",
		ft_isprint('\t') ? 1 : 0, isprint('\t') ? 1 : 0);

	printf("\nPrintable characters (samples):\n");
	printf("ft_isprint(' '): %d (Expected: %d)\n",
		ft_isprint(' ') ? 1 : 0, isprint(' ') ? 1 : 0);
	printf("ft_isprint('A'): %d (Expected: %d)\n",
		ft_isprint('A') ? 1 : 0, isprint('A') ? 1 : 0);
	printf("ft_isprint('z'): %d (Expected: %d)\n",
		ft_isprint('z') ? 1 : 0, isprint('z') ? 1 : 0);
	printf("ft_isprint('0'): %d (Expected: %d)\n",
		ft_isprint('0') ? 1 : 0, isprint('0') ? 1 : 0);
	printf("ft_isprint('~'): %d (Expected: %d)\n",
		ft_isprint('~') ? 1 : 0, isprint('~') ? 1 : 0);

	printf("\nDEL and extended ASCII:\n");
	printf("ft_isprint(127): %d (Expected: %d)\n",
		ft_isprint(127) ? 1 : 0, isprint(127) ? 1 : 0);
	printf("ft_isprint(128): %d (Expected: %d)\n",
		ft_isprint(128) ? 1 : 0, isprint(128) ? 1 : 0);

	/* Test edge cases */
	printf("\nTesting edge cases:\n");
	printf("ft_isprint(-1): %d (Expected: %d)\n",
		ft_isprint(-1) ? 1 : 0, isprint(-1) ? 1 : 0);

	/* Print test summary */
	printf("\n===== FT_ISPRINT TEST SUMMARY =====\n");
	printf("Tests passed: %d/%d (%.2f%%)\n",
		passed, total, (float)passed / total * 100);

	if (passed == total)
		printf("All tests passed! ft_isprint works correctly.\n\n\n");
	else
		printf("Some tests failed. Please check your implementation.\n\n\n");




	/* *************************************************************************************
	*                            TEST FOR FT_STRLEN FUNCTION                               *
	*                                                                                      *
	* This test file compares your ft_strlen function with the standard strlen function    *
	* from the C library to ensure it behaves correctly.                                   *
	*                                                                                      *
	* It tests:                                                                            *
	* 1. Empty strings                                                                     *
	* 2. Short strings                                                                     *
	* 3. Long strings                                                                      *
	* 4. Strings with special characters                                                   *
	* 5. Strings with null characters in the middle (which should be handled correctly)    *
	* *************************************************************************************/

	/* Initialize counters */
	passed = 0;
	total = 0;

	/* Print header for the test */
	printf("\n===== TESTING FT_STRLEN =====\n\n");

	/* Test case 1: Empty string */
	const char *test1 = "";
	std_result = strlen(test1);
	ft_result = ft_strlen(test1);
	total++;

	printf("Test 1: Empty string\n");
	printf("String: \"\"\n");
	printf("Standard strlen: %zu | Your ft_strlen: %zu\n", std_result, ft_result);

	if (std_result == ft_result)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed! Expected: %zu, Got: %zu\n\n", std_result, ft_result);

	/* Test case 2: Short string */
	const char *test2 = "Hello";
	std_result = strlen(test2);
	ft_result = ft_strlen(test2);
	total++;

	printf("Test 2: Short string\n");
	printf("String: \"%s\"\n", test2);
	printf("Standard strlen: %zu | Your ft_strlen: %zu\n", std_result, ft_result);

	if (std_result == ft_result)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed! Expected: %zu, Got: %zu\n\n", std_result, ft_result);

	/* Test case 3: String with spaces */
	const char *test3 = "Hello, world! How are you?";
	std_result = strlen(test3);
	ft_result = ft_strlen(test3);
	total++;

	printf("Test 3: String with spaces\n");
	printf("String: \"%s\"\n", test3);
	printf("Standard strlen: %zu | Your ft_strlen: %zu\n", std_result, ft_result);

	if (std_result == ft_result)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed! Expected: %zu, Got: %zu\n\n", std_result, ft_result);

	/* Test case 4: String with special characters */
	const char *test4 = "!@#$%^&*()_+{}[]|\\:;\"'<>,.?/~`";
	std_result = strlen(test4);
	ft_result = ft_strlen(test4);
	total++;

	printf("Test 4: String with special characters\n");
	printf("String: \"%s\"\n", test4);
	printf("Standard strlen: %zu | Your ft_strlen: %zu\n", std_result, ft_result);

	if (std_result == ft_result)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed! Expected: %zu, Got: %zu\n\n", std_result, ft_result);

	/* Test case 5: Long string */
	const char *test5 = "This is a much longer string that we're using to test the ft_strlen function. "
						"It contains multiple sentences and should be long enough to test the function's "
						"ability to handle longer strings correctly. The function should count all characters "
						"until it reaches the null terminator at the end of this string.";
	std_result = strlen(test5);
	ft_result = ft_strlen(test5);
	total++;

	printf("Test 5: Long string\n");
	printf("String length: %zu characters\n", std_result);
	printf("Standard strlen: %zu | Your ft_strlen: %zu\n", std_result, ft_result);

	if (std_result == ft_result)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed! Expected: %zu, Got: %zu\n\n", std_result, ft_result);

	/* Test case 6: String with non-ASCII characters */
	const char *test6 = "Hello, 你好, 안녕하세요, こんにちは";
	std_result = strlen(test6);
	ft_result = ft_strlen(test6);
	total++;

	printf("Test 6: String with non-ASCII characters\n");
	printf("String: \"%s\"\n", test6);
	printf("Standard strlen: %zu | Your ft_strlen: %zu\n", std_result, ft_result);
	printf("Note: Non-ASCII characters are multi-byte in UTF-8 encoding\n");

	if (std_result == ft_result)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed! Expected: %zu, Got: %zu\n\n", std_result, ft_result);

	/* Test case 7: String with escaped characters */
	const char *test7 = "Line1\nLine2\tTabbed\rReturn";
	std_result = strlen(test7);
	ft_result = ft_strlen(test7);
	total++;

	printf("Test 7: String with escaped characters\n");
	printf("String contains newlines, tabs, and carriage returns\n");
	printf("Standard strlen: %zu | Your ft_strlen: %zu\n", std_result, ft_result);

	if (std_result == ft_result)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed! Expected: %zu, Got: %zu\n\n", std_result, ft_result);

	/* Print test summary */
	printf("\n===== FT_STRLEN TEST SUMMARY =====\n");
	printf("Tests passed: %d/%d (%.2f%%)\n",
		passed, total, (float)passed / total * 100);

	if (passed == total)
		printf("All tests passed! Your ft_strlen function works correctly.\n\n\n");
	else
		printf("Some tests failed. Please check your implementation.\n\n\n");


	/* ******************************************************************************** */
	/*                                                                                  */
	/*                        TEST FOR FT_TOUPPER FUNCTION                              */
	/*                                                                                  */
	/* This program tests the ft_toupper function by comparing its results              */
	/* with the standard toupper function from the C library.                           */
	/* It tests all ASCII characters (0-127) and some extended values to ensure         */
	/* proper handling of lowercase-to-uppercase conversion.                            */
	/* ******************************************************************************** */

	/* Initialize counters */
	passed = 0;
	total = 0;

	/* Print header for the test */
	printf("\n===== TESTING FT_TOUPPER =====\n\n");
	printf("Testing all ASCII characters (0-127):\n");

	/* Test all standard ASCII characters */
	for (i = 0; i <= 127; i++)
	{
		/* Get results from both functions */
		int expected = toupper(i);
		int result = ft_toupper(i);

		total++;

		/* Check if our function matches the standard library function */
		if (expected == result)
		{
			passed++;
			printf("✓ ");
		}
		else
		{
			printf("✗ ");
		}

		/* Print the character and test results */
		if (i >= 32 && i <= 126) /* Printable characters */
			printf("Char: '%c' (ASCII: %3d) | Expected: '%c' | Result: '%c'\n",
				i, i, expected, result);
		else /* Non-printable characters */
			printf("Char: (ASCII: %3d) | Expected: %3d | Result: %3d\n",
				i, expected, result);
	}

	/* Print specific test cases for clarity */
	printf("\n===== SPECIFIC TEST CASES FOR FT_TOUPPER =====\n\n");

	/* Test lowercase letters */
	printf("Testing lowercase letters (a-z):\n");
	for (i = 'a'; i <= 'z'; i++)
	{
		printf("ft_toupper('%c'): '%c' (Expected: '%c')\n",
			i, ft_toupper(i), toupper(i));
	}

	/* Test uppercase letters (should remain unchanged) */
	printf("\nTesting uppercase letters (A-Z):\n");
	for (i = 'A'; i <= 'Z'; i++)
	{
		printf("ft_toupper('%c'): '%c' (Expected: '%c')\n",
			i, ft_toupper(i), toupper(i));
	}

	/* Test digits (should remain unchanged) */
	printf("\nTesting digits (0-9):\n");
	for (i = '0'; i <= '9'; i++)
	{
		printf("ft_toupper('%c'): '%c' (Expected: '%c')\n",
			i, ft_toupper(i), toupper(i));
	}

	/* Test some special characters (should remain unchanged) */
	printf("\nTesting some special characters:\n");
	char special_chars[] = " !@#$%^&*()-_=+[]{}|;:'\",.<>/?\\";
	for (i = 0; special_chars[i] != '\0'; i++)
	{
		printf("ft_toupper('%c'): '%c' (Expected: '%c')\n",
			special_chars[i], ft_toupper(special_chars[i]), toupper(special_chars[i]));
	}

	/* Test edge cases */
	printf("\nTesting edge cases:\n");
	printf("ft_toupper(-1): %d (Expected: %d)\n",
		ft_toupper(-1), toupper(-1));
	printf("ft_toupper(128): %d (Expected: %d)\n",
		ft_toupper(128), toupper(128));

	/* Print test summary */
	printf("\n===== FT_TOUPPER TEST SUMMARY =====\n");
	printf("Tests passed: %d/%d (%.2f%%)\n",
		passed, total, (float)passed / total * 100);

	if (passed == total)
		printf("All tests passed! ft_toupper works correctly.\n\n\n");
	else
		printf("Some tests failed. Please check your implementation.\n\n\n");


	/* ******************************************************************************** */
	/*                                                                                  */
	/*                        TEST FOR FT_TOLOWER FUNCTION                              */
	/*                                                                                  */
	/* This program tests the ft_tolower function by comparing its results              */
	/* with the standard tolower function from the C library.                           */
	/* It tests all ASCII characters (0-127) and some extended values to ensure         */
	/* proper handling of uppercase-to-lowercase conversion.                            */
	/* ******************************************************************************** */

	/* Initialize counters */
	passed = 0;
	total = 0;

	/* Print header for the test */
	printf("\n===== TESTING FT_TOLOWER =====\n\n");
	printf("Testing all ASCII characters (0-127):\n");

	/* Test all standard ASCII characters */
	for (i = 0; i <= 127; i++)
	{
		/* Get results from both functions */
		int expected = tolower(i);
		int result = ft_tolower(i);

		total++;

		/* Check if our function matches the standard library function */
		if (expected == result)
		{
			passed++;
			printf("✓ ");
		}
		else
		{
			printf("✗ ");
		}

		/* Print the character and test results */
		if (i >= 32 && i <= 126) /* Printable characters */
			printf("Char: '%c' (ASCII: %3d) | Expected: '%c' | Result: '%c'\n",
				i, i, expected, result);
		else /* Non-printable characters */
			printf("Char: (ASCII: %3d) | Expected: %3d | Result: %3d\n",
				i, expected, result);
	}

	/* Print specific test cases for clarity */
	printf("\n===== SPECIFIC TEST CASES FOR FT_TOLOWER =====\n\n");

	/* Test uppercase letters */
	printf("Testing uppercase letters (A-Z):\n");
	for (i = 'A'; i <= 'Z'; i++)
	{
		printf("ft_tolower('%c'): '%c' (Expected: '%c')\n",
			i, ft_tolower(i), tolower(i));
	}

	/* Test lowercase letters (should remain unchanged) */
	printf("\nTesting lowercase letters (a-z):\n");
	for (i = 'a'; i <= 'z'; i++)
	{
		printf("ft_tolower('%c'): '%c' (Expected: '%c')\n",
			i, ft_tolower(i), tolower(i));
	}

	/* Test digits (should remain unchanged) */
	printf("\nTesting digits (0-9):\n");
	for (i = '0'; i <= '9'; i++)
	{
		printf("ft_tolower('%c'): '%c' (Expected: '%c')\n",
			i, ft_tolower(i), tolower(i));
	}

	/* Test some special characters (should remain unchanged) */
	printf("\nTesting some special characters:\n");
	//char special_chars[] = " !@#$%^&*()-_=+[]{}|;:'\",.<>/?\\"; [Already specified in LINE 727]
	for (i = 0; special_chars[i] != '\0'; i++)
	{
		printf("ft_tolower('%c'): '%c' (Expected: '%c')\n",
			special_chars[i], ft_tolower(special_chars[i]), tolower(special_chars[i]));
	}

	/* Test edge cases */
	printf("\nTesting edge cases:\n");
	printf("ft_tolower(-1): %d (Expected: %d)\n",
		ft_tolower(-1), tolower(-1));
	printf("ft_tolower(128): %d (Expected: %d)\n",
		ft_tolower(128), tolower(128));

	/* Print test summary */
	printf("\n===== FT_TOLOWER TEST SUMMARY =====\n");
	printf("Tests passed: %d/%d (%.2f%%)\n",
		passed, total, (float)passed / total * 100);

	if (passed == total)
		printf("All tests passed! ft_tolower works correctly.\n\n\n");
	else
		printf("Some tests failed. Please check your implementation.\n\n\n");



	   /* ******************************************************************************** */
	   /*                                                                                  */
	   /*                        TEST FOR FT_MEMSET FUNCTION                               */
	   /*                                                                                  */
	   /* This program tests the ft_memset function by comparing its results               */
	   /* with the standard memset function from the C library.                            */
	   /* It tests various buffer sizes, different fill values, and edge cases to ensure   */
	   /* proper memory filling behavior.                                                  */
	   /* ******************************************************************************** */

	   /* Initialize counters */
	   passed = 0;
	   total = 0;

	   /* Print header for the test */
	   printf("\n===== TESTING FT_MEMSET =====\n\n");

	   /* Test case 1: Basic functionality with a char array */
	   char str1[] = "Hello, world!";
	   char str2[] = "Hello, world!";
	   size_t len1 = 5;
	   int c1 = 'A';

	   memset(str1, c1, len1);
	   ft_memset(str2, c1, len1);
	   total++;

	   printf("Test 1: Basic functionality (fill first 5 bytes with 'A')\n");
	   printf("Original: \"Hello, world!\"\n");
	   printf("Standard memset: \"%s\"\n", str1);
	   printf("Your ft_memset: \"%s\"\n", str2);

	   if (memcmp(str1, str2, strlen(str1) + 1) == 0)
	   {
		   passed++;
		   printf("✓ Test passed!\n\n");
	   }
	   else
		   printf("✗ Test failed!\n\n");

	   /* Test case 2: Fill with zero */
	   char str3[] = "Hello, world!";
	   char str4[] = "Hello, world!";
	   size_t len2 = 5;
	   int c2 = 0;

	   memset(str3, c2, len2);
	   ft_memset(str4, c2, len2);
	   total++;

	   printf("Test 2: Fill with zero (fill first 5 bytes with '\\0')\n");
	   printf("Original: \"Hello, world!\"\n");
	   printf("Standard memset: \"");
	   for (j = 0; j < strlen(str3) + 5; j++)
		   printf(str3[j] ? "%c" : "\\0", str3[j]);
	   printf("\"\n");

	   printf("Your ft_memset: \"");
	   for (j = 0; j < strlen(str4) + 5; j++)
		   printf(str4[j] ? "%c" : "\\0", str4[j]);
	   printf("\"\n");

	   if (memcmp(str3, str4, strlen(str3) + 1) == 0)
	   {
		   passed++;
		   printf("✓ Test passed!\n\n");
	   }
	   else
		   printf("✗ Test failed!\n\n");

	   /* Test case 3: Fill entire buffer */
	   char str5[] = "Hello, world!";
	   char str6[] = "Hello, world!";
	   size_t len3 = strlen(str5);
	   int c3 = 'X';

	   memset(str5, c3, len3);
	   ft_memset(str6, c3, len3);
	   total++;

	   printf("Test 3: Fill entire buffer with 'X'\n");
	   printf("Original: \"Hello, world!\"\n");
	   printf("Standard memset: \"%s\"\n", str5);
	   printf("Your ft_memset: \"%s\"\n", str6);

	   if (memcmp(str5, str6, strlen(str5) + 1) == 0)
	   {
		   passed++;
		   printf("✓ Test passed!\n\n");
	   }
	   else
		   printf("✗ Test failed!\n\n");

	   /* Test case 4: Fill with non-character value */
	   unsigned char buffer1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	   unsigned char buffer2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	   size_t len4 = 10;
	   int c4 = 0xFF; /* 255 or hexadecimal(base 16) 11111111*/

	   memset(buffer1, c4, len4);
	   ft_memset(buffer2, c4, len4);
	   total++;

	   printf("Test 4: Fill with non-character value (0xFF)\n");
	   printf("Original: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]\n");

	   printf("Standard memset: [");
	   for (j = 0; j < len4; j++)
	   {
		   printf("%d", buffer1[j]);
		   if (j < len4 - 1)
			   printf(", ");
	   }
	   printf("]\n");

	   printf("Your ft_memset: [");
	   for (j = 0; j < len4; j++)
	   {
		   printf("%d", buffer2[j]);
		   if (j < len4 - 1)
			   printf(", ");
	   }
	   printf("]\n");

	   if (memcmp(buffer1, buffer2, len4) == 0)
	   {
		   passed++;
		   printf("✓ Test passed!\n\n");
	   }
	   else
		   printf("✗ Test failed!\n\n");

	   /* Test case 5: Zero-length operation */
	   char str7[] = "Hello, world!";
	   char str8[] = "Hello, world!";
	   size_t len5 = 0;
	   int c5 = 'Z';

	   memset(str7, c5, len5);
	   ft_memset(str8, c5, len5);
	   total++;

	   printf("Test 5: Zero-length operation\n");
	   printf("Original: \"Hello, world!\"\n");
	   printf("Standard memset: \"%s\"\n", str7);
	   printf("Your ft_memset: \"%s\"\n", str8);

	   if (memcmp(str7, str8, strlen(str7) + 1) == 0)
	   {
		   passed++;
		   printf("✓ Test passed!\n\n");
	   }
	   else
		   printf("✗ Test failed!\n\n");

	   /* Test case 6: Large buffer */
	   #define LARGE_SIZE 1000
	   unsigned char large_buffer1[LARGE_SIZE];
	   unsigned char large_buffer2[LARGE_SIZE];
	   int c6 = 42;

	   /* Initialize buffers with different values */
	   for (j = 0; j < LARGE_SIZE; j++)
	   {
		   large_buffer1[j] = j % 256;
		   large_buffer2[j] = j % 256;
	   }

	   memset(large_buffer1, c6, LARGE_SIZE);
	   ft_memset(large_buffer2, c6, LARGE_SIZE);
	   total++;

	   printf("Test 6: Large buffer (1000 bytes)\n");
	   printf("Filling 1000 bytes with value 42\n");

	   /* Check if all bytes are set correctly */
	   int large_buffer_match = 1;
	   for (j = 0; j < LARGE_SIZE; j++)
	   {
		   if (large_buffer1[j] != large_buffer2[j])
		   {
			   large_buffer_match = 0;
			   printf("Mismatch at index %d: Expected %d, Got %d\n", 
					  i, large_buffer1[j], large_buffer2[j]);
			   break;
		   }
	   }

	   if (large_buffer_match)
	   {
		   passed++;
		   printf("✓ Test passed!\n\n");
	   }
	   else
		   printf("✗ Test failed!\n\n");

	   /* Print test summary */
	   printf("\n===== FT_MEMSET TEST SUMMARY =====\n");
	   printf("Tests passed: %d/%d (%.2f%%)\n",
		   passed, total, (float)passed / total * 100);

	   if (passed == total)
		   printf("All tests passed! Your ft_memset function works correctly.\n\n\n");
	   else
		   printf("Some tests failed. Please check your implementation.\n\n\n");




	/* ******************************************************************************** */
	/*                                                                                  */
	/*                        TEST FOR FT_BZERO FUNCTION                                */
	/*                                                                                  */
	/* This program tests the ft_bzero function by comparing its results                */
	/* with the standard bzero function from the C library.                             */
	/* It tests various buffer sizes and edge cases to ensure proper memory zeroing.    */
	/* ******************************************************************************** */
	{
	/* Initialize counters */
	passed = 0;
	total = 0;

	/* Print header for the test */
	printf("\n===== TESTING FT_BZERO =====\n\n");

	/* Test case 1: Basic functionality with a char array */
	char str1[] = "Hello, world!";
	char str2[] = "Hello, world!";
	size_t len1 = 5;

	bzero(str1, len1);
	ft_bzero(str2, len1);
	total++;

	printf("Test 1: Basic functionality (zero first 5 bytes)\n");
	printf("Original: \"Hello, world!\"\n");
	printf("Standard bzero: \"");
	for (j = 0; j < strlen("Hello, world!"); j++)
		printf(str1[j] ? "%c" : "\\0", str1[j]);
	printf("\"\n");

	printf("Your ft_bzero: \"");
	for (j = 0; j < strlen("Hello, world!"); j++)
		printf(str2[j] ? "%c" : "\\0", str2[j]);
	printf("\"\n");

	if (memcmp(str1, str2, strlen("Hello, world!") + 1) == 0)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 2: Zero entire buffer */
	char str3[] = "Hello, world!";
	char str4[] = "Hello, world!";
	size_t len2 = strlen(str3);

	bzero(str3, len2);
	ft_bzero(str4, len2);
	total++;

	printf("Test 2: Zero entire buffer\n");
	printf("Original: \"Hello, world!\"\n");
	printf("Standard bzero: \"");
	for (j = 0; j < len2; j++)
		printf(str3[j] ? "%c" : "\\0", str3[j]);
	printf("\"\n");

	printf("Your ft_bzero: \"");
	for (j = 0; j < len2; j++)
		printf(str4[j] ? "%c" : "\\0", str4[j]);
	printf("\"\n");

	if (memcmp(str3, str4, len2) == 0)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 3: Zero-length operation */
	char str5[] = "Hello, world!";
	char str6[] = "Hello, world!";
	size_t len3 = 0;

	bzero(str5, len3);
	ft_bzero(str6, len3);
	total++;

	printf("Test 3: Zero-length operation\n");
	printf("Original: \"Hello, world!\"\n");
	printf("Standard bzero: \"%s\"\n", str5);
	printf("Your ft_bzero: \"%s\"\n", str6);

	if (memcmp(str5, str6, strlen(str5) + 1) == 0)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 4: Numeric array */
	int nums1[5] = {1, 2, 3, 4, 5};
	int nums2[5] = {1, 2, 3, 4, 5};
	size_t len4 = 3 * sizeof(int); /* Zero first 3 integers */

	bzero(nums1, len4);
	ft_bzero(nums2, len4);
	total++;

	printf("Test 4: Numeric array (zero first 3 integers)\n");
	printf("Original: [1, 2, 3, 4, 5]\n");

	printf("Standard bzero: [");
	for (j = 0; j < 5; j++)
	{
		printf("%d", nums1[j]);
		if (j < 4)
			printf(", ");
	}
	printf("]\n");

	printf("Your ft_bzero: [");
	for (j = 0; j < 5; j++)
	{
		printf("%d", nums2[j]);
		if (j < 4)
			printf(", ");
	}
	printf("]\n");

	if (memcmp(nums1, nums2, 5 * sizeof(int)) == 0)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 5: Large buffer */
	#define BZERO_LARGE_SIZE 1000
	unsigned char large_buffer1[BZERO_LARGE_SIZE];
	unsigned char large_buffer2[BZERO_LARGE_SIZE];

	/* Initialize buffers with non-zero values */
	for (j = 0; j < BZERO_LARGE_SIZE; j++)
	{
		large_buffer1[j] = j % 256;
		large_buffer2[j] = j % 256;
	}

	bzero(large_buffer1, BZERO_LARGE_SIZE);
	ft_bzero(large_buffer2, BZERO_LARGE_SIZE);
	total++;

	printf("Test 5: Large buffer (1000 bytes)\n");
	printf("Zeroing 1000 bytes\n");

	/* Check if all bytes are zeroed correctly */
	int bzero_large_buffer_match = 1;
	for (j = 0; j < BZERO_LARGE_SIZE; j++)
	{
		if (large_buffer1[j] != large_buffer2[j])
		{
			bzero_large_buffer_match = 0;
			printf("Mismatch at index %zu: Expected %d, Got %d\n", 
					j, large_buffer1[j], large_buffer2[j]);
			break;
		}
	}

	if (bzero_large_buffer_match)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 6: Struct zeroing */
	struct test_struct {
		int a;
		char b;
		double c;
		char str[10];
	} test1, test2;

	/* Initialize structs with values */
	test1.a = 42;
	test1.b = 'X';
	test1.c = 3.14159;
	strcpy(test1.str, "Hello");

	test2.a = 42;
	test2.b = 'X';
	test2.c = 3.14159;
	strcpy(test2.str, "Hello");

	bzero(&test1, sizeof(struct test_struct));
	ft_bzero(&test2, sizeof(struct test_struct));
	total++;

	printf("Test 6: Struct zeroing\n");
	printf("Zeroing a struct with mixed data types\n");

	if (memcmp(&test1, &test2, sizeof(struct test_struct)) == 0)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Print test summary */
	printf("\n===== FT_BZERO TEST SUMMARY =====\n");
	printf("Tests passed: %d/%d (%.2f%%)\n",
		passed, total, (float)passed / total * 100);

	if (passed == total)
		printf("All tests passed! Your ft_bzero function works correctly.\n\n\n");
	else
		printf("Some tests failed. Please check your implementation.\n\n\n");

	}




	/* ******************************************************************************** */
	/*                                                                                  */
	/*                        TEST FOR FT_MEMCPY FUNCTION                               */
	/*                                                                                  */
	/* This program tests the ft_memcpy function by comparing its results               */
	/* with the standard memcpy function from the C library.                            */
	/* It tests various buffer sizes, different data types, and edge cases to ensure    */
	/* proper memory copying behavior.                                                  */
	/* ******************************************************************************** */

	{
	/* Initialize counters */
	passed = 0;
	total = 0;

	/* Print header for the test */
	printf("\n===== TESTING FT_MEMCPY =====\n\n");

	/* Test case 1: Basic functionality with a char array */
	char src1[] = "Hello, world!";
	char dest1[20] = {0};
	char dest2[20] = {0};
	size_t len1 = strlen(src1) + 1; /* Include null terminator */

	memcpy(dest1, src1, len1);
	ft_memcpy(dest2, src1, len1);
	total++;

	printf("Test 1: Basic string copy\n");
	printf("Source: \"%s\"\n", src1);
	printf("Standard memcpy: \"%s\"\n", dest1);
	printf("Your ft_memcpy: \"%s\"\n", dest2);

	if (memcmp(dest1, dest2, len1) == 0)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 2: Partial copy */
	char src2[] = "Hello, world!";
	char dest3[20] = "XXXXXXXXXXXXXXX";
	char dest4[20] = "XXXXXXXXXXXXXXX";
	size_t len2 = 5; /* Copy only "Hello" */

	memcpy(dest3, src2, len2);
	ft_memcpy(dest4, src2, len2);
	total++;

	printf("Test 2: Partial copy (first 5 bytes)\n");
	printf("Source: \"%s\"\n", src2);
	printf("Destination before: \"XXXXXXXXXXXXXXX\"\n");
	printf("Standard memcpy: \"%s\"\n", dest3);
	printf("Your ft_memcpy: \"%s\"\n", dest4);

	if (memcmp(dest3, dest4, 20) == 0)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 3: Copy integers */
	int src_int1[] = {1, 2, 3, 4, 5};
	int dest_int1[5] = {0};
	int dest_int2[5] = {0};
	size_t len3 = sizeof(src_int1);

	memcpy(dest_int1, src_int1, len3);
	ft_memcpy(dest_int2, src_int1, len3);
	total++;

	printf("Test 3: Copy integers\n");
	printf("Source: [1, 2, 3, 4, 5]\n");

	printf("Standard memcpy: [");
	for (j = 0; j < 5; j++)
	{
		printf("%d", dest_int1[j]);
		if (j < 4)
			printf(", ");
	}
	printf("]\n");

	printf("Your ft_memcpy: [");
	for (j = 0; j < 5; j++)
	{
		printf("%d", dest_int2[j]);
		if (j < 4)
			printf(", ");
	}
	printf("]\n");

	if (memcmp(dest_int1, dest_int2, len3) == 0)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 4: Zero-length operation */
	char src3[] = "Hello, world!";
	char dest5[20] = "XXXXXXXXXXXXXXX";
	char dest6[20] = "XXXXXXXXXXXXXXX";
	size_t len4 = 0;

	memcpy(dest5, src3, len4);
	ft_memcpy(dest6, src3, len4);
	total++;

	printf("Test 4: Zero-length operation\n");
	printf("Source: \"%s\"\n", src3);
	printf("Destination before: \"XXXXXXXXXXXXXXX\"\n");
	printf("Standard memcpy: \"%s\"\n", dest5);
	printf("Your ft_memcpy: \"%s\"\n", dest6);

	if (memcmp(dest5, dest6, 20) == 0)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 5: Copy with non-aligned addresses */
	char src4[] = "Hello, world!";
	char dest7[20] = "XXXXXXXXXXXXXXX";
	char dest8[20] = "XXXXXXXXXXXXXXX";
	size_t len5 = 10;

	memcpy(dest7 + 3, src4 + 2, len5);
	ft_memcpy(dest8 + 3, src4 + 2, len5);
	total++;

	printf("Test 5: Copy with non-aligned addresses\n");
	printf("Source: \"%s\" (starting from index 2)\n", src4);
	printf("Destination before: \"XXXXXXXXXXXXXXX\" (starting at index 3)\n");
	printf("Standard memcpy: \"%s\"\n", dest7);
	printf("Your ft_memcpy: \"%s\"\n", dest8);

	if (memcmp(dest7, dest8, 20) == 0)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 6: Large buffer */
	#define MEMCPY_LARGE_SIZE 1000
	unsigned char large_src[MEMCPY_LARGE_SIZE];
	unsigned char large_dest1[MEMCPY_LARGE_SIZE];
	unsigned char large_dest2[MEMCPY_LARGE_SIZE];

	/* Initialize buffers with values */
	for (j = 0; j < MEMCPY_LARGE_SIZE; j++)
	{
		large_src[j] = j % 256;
		large_dest1[j] = 0;
		large_dest2[j] = 0;
	}

	memcpy(large_dest1, large_src, MEMCPY_LARGE_SIZE);
	ft_memcpy(large_dest2, large_src, MEMCPY_LARGE_SIZE);
	total++;

	printf("Test 6: Large buffer (1000 bytes)\n");
	printf("Copying 1000 bytes from source to destination\n");

	/* Check if all bytes are copied correctly */
	int memcpy_large_buffer_match = 1;
	for (j = 0; j < MEMCPY_LARGE_SIZE; j++)
	{
		if (large_dest1[j] != large_dest2[j])
		{
			memcpy_large_buffer_match = 0;
			printf("Mismatch at index %zu: Expected %d, Got %d\n",
					j, large_dest1[j], large_dest2[j]);
			break;
		}
	}

	if (memcpy_large_buffer_match)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 7: Struct copying */
	struct test_struct_memcpy {
		int a;
		char b;
		double c;
		char str[10];
	} src_struct, dest_struct1, dest_struct2;

	/* Initialize source struct with values */
	src_struct.a = 42;
	src_struct.b = 'X';
	src_struct.c = 3.14159;
	strcpy(src_struct.str, "Hello");

	/* Clear destination structs */
	memset(&dest_struct1, 0, sizeof(struct test_struct_memcpy));
	memset(&dest_struct2, 0, sizeof(struct test_struct_memcpy));

	memcpy(&dest_struct1, &src_struct, sizeof(struct test_struct_memcpy));
	ft_memcpy(&dest_struct2, &src_struct, sizeof(struct test_struct_memcpy));
	total++;

	printf("Test 7: Struct copying\n");
	printf("Copying a struct with mixed data types\n");
	printf("Source struct: {a: %d, b: '%c', c: %f, str: \"%s\"}\n",
		src_struct.a, src_struct.b, src_struct.c, src_struct.str);
	printf("Standard memcpy: {a: %d, b: '%c', c: %f, str: \"%s\"}\n",
		dest_struct1.a, dest_struct1.b, dest_struct1.c, dest_struct1.str);
	printf("Your ft_memcpy: {a: %d, b: '%c', c: %f, str: \"%s\"}\n",
		dest_struct2.a, dest_struct2.b, dest_struct2.c, dest_struct2.str);

	if (memcmp(&dest_struct1, &dest_struct2, sizeof(struct test_struct_memcpy)) == 0)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 8: NULL pointers with zero length */
	char dummy_src[1] = {0};
	char dummy_dest[1] = {0};
	void *result1 = memcpy(dummy_dest, dummy_src, 0);
	void *result2 = ft_memcpy(dummy_dest, dummy_src, 0);
	total++;

	printf("Test 8: NULL pointers with zero length\n");
	printf("Testing behavior with NULL source and destination but zero length\n");

	/* This test is a bit tricky since the standard says this is undefined behavior,
	but many implementations handle it by just returning the destination pointer.
	We'll check if your implementation behaves the same as the system's memcpy. */

	if ((result1 == NULL && result2 == NULL) || (result1 != NULL && result2 != NULL))
	{
		passed++;
		printf("✓ Test passed! Both functions returned %s\n\n",
			result1 == NULL ? "NULL" : "non-NULL");
	}
	else
		printf("✗ Test failed! Standard memcpy returned %s but your ft_memcpy returned %s\n\n",
			result1 == NULL ? "NULL" : "non-NULL",
			result2 == NULL ? "NULL" : "non-NULL");

	/* Print test summary */
	printf("\n===== FT_MEMCPY TEST SUMMARY =====\n");
	printf("Tests passed: %d/%d (%.2f%%)\n",
		passed, total, (float)passed / total * 100);

	if (passed == total)
		printf("All tests passed! Your ft_memcpy function works correctly.\n\n\n");
	else
		printf("Some tests failed. Please check your implementation.\n\n\n");

	}




	/* ******************************************************************************** */
	/*                                                                                  */
	/*                        TEST FOR FT_STRLCPY FUNCTION                              */
	/*                                                                                  */
	/* This program tests the ft_strlcpy function by comparing its results              */
	/* with the standard strlcpy function from the C library.                           */
	/* It tests various buffer sizes, edge cases, and different string types to ensure  */
	/* proper string copying behavior with size limitations.                            */
	/* ******************************************************************************** */
	{
	/* Initialize counters */
	passed = 0;
	total = 0;

	/* Print header for the test */
	printf("\n===== TESTING FT_STRLCPY =====\n\n");

	/* Test case 1: Basic functionality with sufficient buffer */
	char src1[] = "Hello, world!";
	char dest1[20] = {0};
	char dest2[20] = {0};
	size_t len1 = sizeof(dest1);
	size_t ret1, ret2;

	ret1 = strlcpy(dest1, src1, len1);
	ret2 = ft_strlcpy(dest2, src1, len1);
	total++;

	printf("Test 1: Basic string copy (sufficient buffer)\n");
	printf("Source: \"%s\" (length: %zu)\n", src1, strlen(src1));
	printf("Buffer size: %zu\n", len1);
	printf("Standard strlcpy: \"%s\" (return: %zu)\n", dest1, ret1);
	printf("Your ft_strlcpy: \"%s\" (return: %zu)\n", dest2, ret2);

	if (strcmp(dest1, dest2) == 0 && ret1 == ret2)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 2: Truncation (buffer smaller than source) */
	char src2[] = "Hello, world!";
	char dest3[7] = {0};  /* Only enough for "Hello," + null */
	char dest4[7] = {0};
	size_t len2 = sizeof(dest3);
	size_t ret3, ret4;

	ret3 = strlcpy(dest3, src2, len2);
	ret4 = ft_strlcpy(dest4, src2, len2);
	total++;

	printf("Test 2: Truncation (buffer smaller than source)\n");
	printf("Source: \"%s\" (length: %zu)\n", src2, strlen(src2));
	printf("Buffer size: %zu\n", len2);
	printf("Standard strlcpy: \"%s\" (return: %zu)\n", dest3, ret3);
	printf("Your ft_strlcpy: \"%s\" (return: %zu)\n", dest4, ret4);

	if (strcmp(dest3, dest4) == 0 && ret3 == ret4)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 3: Exact buffer size (buffer size = source length + 1) */
	char src3[] = "Hello";
	char dest5[6] = {0};  /* Exactly enough for "Hello" + null */
	char dest6[6] = {0};
	size_t len3 = sizeof(dest5);
	size_t ret5, ret6;

	ret5 = strlcpy(dest5, src3, len3);
	ret6 = ft_strlcpy(dest6, src3, len3);
	total++;

	printf("Test 3: Exact buffer size (buffer = source length + 1)\n");
	printf("Source: \"%s\" (length: %zu)\n", src3, strlen(src3));
	printf("Buffer size: %zu\n", len3);
	printf("Standard strlcpy: \"%s\" (return: %zu)\n", dest5, ret5);
	printf("Your ft_strlcpy: \"%s\" (return: %zu)\n", dest6, ret6);

	if (strcmp(dest5, dest6) == 0 && ret5 == ret6)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 4: Zero-size buffer */
	char src4[] = "Hello, world!";
	char dest7[10] = "XXXXXXXXX";
	char dest8[10] = "XXXXXXXXX";
	size_t len4 = 0;
	size_t ret7, ret8;

	ret7 = strlcpy(dest7, src4, len4);
	ret8 = ft_strlcpy(dest8, src4, len4);
	total++;

	printf("Test 4: Zero-size buffer\n");
	printf("Source: \"%s\" (length: %zu)\n", src4, strlen(src4));
	printf("Buffer size: %zu\n", len4);
	printf("Destination before: \"XXXXXXXXX\"\n");
	printf("Standard strlcpy return: %zu\n", ret7);
	printf("Your ft_strlcpy return: %zu\n", ret8);
	printf("Standard strlcpy result: \"%s\"\n", dest7);
	printf("Your ft_strlcpy result: \"%s\"\n", dest8);

	if (strcmp(dest7, dest8) == 0 && ret7 == ret8)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 5: Empty source string */
	char src5[] = "";
	char dest9[10] = "XXXXXXXXX";
	char dest10[10] = "XXXXXXXXX";
	size_t len5 = sizeof(dest9);
	size_t ret9, ret10;

	ret9 = strlcpy(dest9, src5, len5);
	ret10 = ft_strlcpy(dest10, src5, len5);
	total++;

	printf("Test 5: Empty source string\n");
	printf("Source: \"\" (empty string)\n");
	printf("Buffer size: %zu\n", len5);
	printf("Destination before: \"XXXXXXXXX\"\n");
	printf("Standard strlcpy: \"%s\" (return: %zu)\n", dest9, ret9);
	printf("Your ft_strlcpy: \"%s\" (return: %zu)\n", dest10, ret10);

	if (strcmp(dest9, dest10) == 0 && ret9 == ret10)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 6: Size exactly 1 (only null terminator) */
	char src6[] = "Hello, world!";
	char dest11[10] = "XXXXXXXXX";
	char dest12[10] = "XXXXXXXXX";
	size_t len6 = 1;
	size_t ret11, ret12;

	ret11 = strlcpy(dest11, src6, len6);
	ret12 = ft_strlcpy(dest12, src6, len6);
	total++;

	printf("Test 6: Size exactly 1 (only null terminator)\n");
	printf("Source: \"%s\" (length: %zu)\n", src6, strlen(src6));
	printf("Buffer size: %zu\n", len6);
	printf("Destination before: \"XXXXXXXXX\"\n");
	printf("Standard strlcpy: \"");
	for (j = 0; j < 9; j++)
		printf(dest11[j] ? "%c" : "\\0", dest11[j]);
	printf("\" (return: %zu)\n", ret11);

	printf("Your ft_strlcpy: \"");
	for (j = 0; j < 9; j++)
		printf(dest12[j] ? "%c" : "\\0", dest12[j]);
	printf("\" (return: %zu)\n", ret12);

	if (memcmp(dest11, dest12, 10) == 0 && ret11 == ret12)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 7: String with special characters */
	char src7[] = "Hello\t\n\r\0World";  /* Note: strlen will stop at \0 */
	char dest13[20] = {0};
	char dest14[20] = {0};
	size_t len7 = sizeof(dest13);
	size_t src7_len = 7;  /* Length up to the \0 */
	size_t ret13, ret14;

	ret13 = strlcpy(dest13, src7, len7);
	ret14 = ft_strlcpy(dest14, src7, len7);
	total++;

	printf("Test 7: String with special characters\n");
	printf("Source contains: \"Hello\" followed by tab, newline, carriage return, and null\n");
	printf("Buffer size: %zu\n", len7);
	printf("Standard strlcpy return: %zu\n", ret13);
	printf("Your ft_strlcpy return: %zu\n", ret14);

	/* Display the content character by character */
	printf("Standard strlcpy result: \"");
	for (j = 0; j < src7_len; j++)
	{
		if (dest13[j] == '\t') printf("\\t");
		else if (dest13[j] == '\n') printf("\\n");
		else if (dest13[j] == '\r') printf("\\r");
		else if (dest13[j] == '\0') printf("\\0");
		else printf("%c", dest13[j]);
	}
	printf("\"\n");

	printf("Your ft_strlcpy result: \"");
	for (j = 0; j < src7_len; j++)
	{
		if (dest14[j] == '\t') printf("\\t");
		else if (dest14[j] == '\n') printf("\\n");
		else if (dest14[j] == '\r') printf("\\r");
		else if (dest14[j] == '\0') printf("\\0");
		else printf("%c", dest14[j]);
	}
	printf("\"\n");

	if (memcmp(dest13, dest14, len7) == 0 && ret13 == ret14)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 8: Large string */
	#define LARGE_STR_SIZE 1000
	char large_src[LARGE_STR_SIZE + 1];
	char large_dest1[LARGE_STR_SIZE + 100] = {0};
	char large_dest2[LARGE_STR_SIZE + 100] = {0};
	size_t large_len = sizeof(large_dest1);
	size_t ret_large1, ret_large2;

	/* Fill the large source string with repeating pattern */
	for (j = 0; j < LARGE_STR_SIZE; j++)
	{
		large_src[j] = 'A' + (j % 26);
	}
	large_src[LARGE_STR_SIZE] = '\0';

	ret_large1 = strlcpy(large_dest1, large_src, large_len);
	ret_large2 = ft_strlcpy(large_dest2, large_src, large_len);
	total++;

	printf("Test 8: Large string (1000 characters)\n");
	printf("Source: [1000-character string with pattern A-Z]\n");
	printf("Buffer size: %zu\n", large_len);
	printf("Standard strlcpy return: %zu\n", ret_large1);
	printf("Your ft_strlcpy return: %zu\n", ret_large2);
	printf("First 20 chars - Standard: %.20s\n", large_dest1);
	printf("First 20 chars - Yours: %.20s\n", large_dest2);

	/* Check if strings match */
	int large_match = (strcmp(large_dest1, large_dest2) == 0);
	/* Check if return values match */
	int return_match = (ret_large1 == ret_large2);

	if (large_match && return_match)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
	{
		printf("✗ Test failed!\n");
		if (!large_match)
			printf("  - Strings don't match\n");
		if (!return_match)
			printf("  - Return values don't match (expected %zu, got %zu)\n", 
				ret_large1, ret_large2);
		printf("\n");
	}

	/* Print test summary */
	printf("\n===== FT_STRLCPY TEST SUMMARY =====\n");
	printf("Tests passed: %d/%d (%.2f%%)\n",
		passed, total, (float)passed / total * 100);

	if (passed == total)
		printf("All tests passed! Your ft_strlcpy function works correctly.\n\n\n");
	else
		printf("Some tests failed. Please check your implementation.\n\n\n");

	}



	/* **************************************************************************************
	*                            TEST FOR FT_STRLCAT FUNCTION                              *
	*                                                                                      *
	* This test compares your ft_strlcat function with the standard strlcat function        *
	* from the BSD library to ensure it behaves correctly.                                 *
	*                                                                                      *
	* It tests:                                                                            *
	* 1. Basic concatenation                                                               *
	* 2. Truncation when buffer is too small                                               *
	* 3. Zero-size buffer                                                                 *
	* 4. Empty source and/or destination                                                   *
	* 5. Buffer size exactly equal to destination length                                   *
	* 6. Large string concatenation                                                        *
	* *************************************************************************************/

	/* Initialize counters */
	passed = 0;
	total = 0;

	/* Print header for the test */
	printf("\n===== TESTING FT_STRLCAT =====\n\n");

	/* Test case 1: Basic concatenation with enough space */
	char buf1[30] = "Hello, ";
	char buf2[30] = "Hello, ";
	const char *src1 = "world!";
	size_t size1 = sizeof(buf1);
	size_t ret1, ret2;

	ret1 = strlcat(buf1, src1, size1);
	ret2 = ft_strlcat(buf2, src1, size1);

	total++;

	printf("Test 1: Basic concatenation with enough space\n");
	printf("Destination before: \"Hello, \"\n");
	printf("Source: \"%s\"\n", src1);
	printf("Buffer size: %zu\n", size1);
	printf("Standard strlcat: \"%s\" (return: %zu)\n", buf1, ret1);
	printf("Your ft_strlcat: \"%s\" (return: %zu)\n", buf2, ret2);

	if (strcmp(buf1, buf2) == 0 && ret1 == ret2)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
	printf("✗ Test failed!\n\n");

	/* Test case 2: Truncation (buffer too small) */
	char buf3[10] = "Hello, ";
	char buf4[10] = "Hello, ";
	const char *src2 = "world!";
	size_t size2 = sizeof(buf3);
	size_t ret3, ret4;

	ret3 = strlcat(buf3, src2, size2);
	ret4 = ft_strlcat(buf4, src2, size2);
	total++;

	printf("Test 2: Truncation (buffer too small)\n");
	printf("Destination before: \"Hello, \"\n");
	printf("Source: \"%s\"\n", src2);
	printf("Buffer size: %zu\n", size2);
	printf("Standard strlcat: \"%s\" (return: %zu)\n", buf3, ret3);
	printf("Your ft_strlcat: \"%s\" (return: %zu)\n", buf4, ret4);

	if (strcmp(buf3, buf4) == 0 && ret3 == ret4)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
	printf("✗ Test failed!\n\n");

	/* Test case 3: Zero-size buffer */
	char buf5[10] = "Hello";
	char buf6[10] = "Hello";
	const char *src3 = "world";
	size_t size3 = 0;
	size_t ret5, ret6;

	ret5 = strlcat(buf5, src3, size3);
	ret6 = ft_strlcat(buf6, src3, size3);
	total++;

	printf("Test 3: Zero-size buffer\n");
	printf("Destination before: \"Hello\"\n");
	printf("Source: \"%s\"\n", src3);
	printf("Buffer size: %zu\n", size3);
	printf("Standard strlcat: \"%s\" (return: %zu)\n", buf5, ret5);
	printf("Your ft_strlcat: \"%s\" (return: %zu)\n", buf6, ret6);

	if (strcmp(buf5, buf6) == 0 && ret5 == ret6)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 4: Empty source string */
	char buf7[15] = "Hello";
	char buf8[15] = "Hello";
	const char *src4 = "";
	size_t size4 = sizeof(buf7);
	size_t ret7, ret8;

	ret7 = strlcat(buf7, src4, size4);
	ret8 = ft_strlcat(buf8, src4, size4);
	total++;

	printf("Test 4: Empty source string\n");
	printf("Destination before: \"Hello\"\n");
	printf("Source: \"\" (empty string)\n");
	printf("Buffer size: %zu\n", size4);
	printf("Standard strlcat: \"%s\" (return: %zu)\n", buf7, ret7);
	printf("Your ft_strlcat: \"%s\" (return: %zu)\n", buf8, ret8);

	if (strcmp(buf7, buf8) == 0 && ret7 == ret8)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 5: Empty destination string */
	char buf9[15] = "";
	char buf10[15] = "";
	const char *src5 = "world!";
	size_t size5 = sizeof(buf9);
	size_t ret9, ret10;

	ret9 = strlcat(buf9, src5, size5);
	ret10 = ft_strlcat(buf10, src5, size5);
	total++;

	printf("Test 5: Empty destination string\n");
	printf("Destination before: \"\" (empty string)\n");
	printf("Source: \"%s\"\n", src5);
	printf("Buffer size: %zu\n", size5);
	printf("Standard strlcat: \"%s\" (return: %zu)\n", buf9, ret9);
	printf("Your ft_strlcat: \"%s\" (return: %zu)\n", buf10, ret10);

	if (strcmp(buf9, buf10) == 0 && ret9 == ret10)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 6: Buffer size equals destination length */
	char buf11[7] = "Hello";
	char buf12[7] = "Hello";
	const char *src6 = "world";
	size_t size6 = strlen(buf11); // buffer size = destination length (no room to append)
	size_t ret11, ret12;

	ret11 = strlcat(buf11, src6, size6);
	ret12 = ft_strlcat(buf12, src6, size6);
	total++;

	printf("Test 6: Buffer size equals destination length\n");
	printf("Destination before: \"Hello\"\n");
	printf("Source: \"%s\"\n", src6);
	printf("Buffer size: %zu\n", size6);
	printf("Standard strlcat: \"%s\" (return: %zu)\n", buf11, ret11);
	printf("Your ft_strlcat: \"%s\" (return: %zu)\n", buf12, ret12);

	if (strcmp(buf11, buf12) == 0 && ret11 == ret12)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 7: Large string concatenation */
	#define STRLCAT_LARGE_SIZE 1000
	char large_dst1[STRLCAT_LARGE_SIZE + 100] = {0};
	char large_dst2[STRLCAT_LARGE_SIZE + 100] = {0};
	char large_src[STRLCAT_LARGE_SIZE + 1];
	for (j = 0; j < STRLCAT_LARGE_SIZE; j++)
		large_src[j] = 'A' + (j % 26);
	large_src[STRLCAT_LARGE_SIZE] = '\0';
	strcpy(large_dst1, "Begin-");
	strcpy(large_dst2, "Begin-");
	size_t large_buf_size = sizeof(large_dst1);
	size_t ret_large1, ret_large2;

	ret_large1 = strlcat(large_dst1, large_src, large_buf_size);
	ret_large2 = ft_strlcat(large_dst2, large_src, large_buf_size);
	total++;

	printf("Test 7: Large string concatenation\n");
	printf("Destination before: \"Begin-\"\n");
	printf("Source: [1000-character string]\n");
	printf("Buffer size: %zu\n", large_buf_size);
	printf("First 20 chars - Standard: %.20s\n", large_dst1);
	printf("First 20 chars - Yours: %.20s\n", large_dst2);
	printf("Standard strlcat return: %zu\n", ret_large1);
	printf("Your ft_strlcat return: %zu\n", ret_large2);

	int large_match = (strcmp(large_dst1, large_dst2) == 0);
	int return_match = (ret_large1 == ret_large2);

	if (large_match && return_match)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
	{
		printf("✗ Test failed!\n");
		if (!large_match)
			printf("  - Strings don't match\n");
		if (!return_match)
			printf("  - Return values don't match (expected %zu, got %zu)\n",
				ret_large1, ret_large2);
		printf("\n");
	}

	/* Print test summary */
	printf("\n===== FT_STRLCAT TEST SUMMARY =====\n");
	printf("Tests passed: %d/%d (%.2f%%)\n",
		passed, total, (float)passed / total * 100);

	if (passed == total)
		printf("All tests passed! Your ft_strlcat function works correctly.\n\n\n");
	else
		printf("Some tests failed. Please check your implementation.\n\n\n");



	/* **************************************************************************************
	*                               TEST FOR FT_STRCHR FUNCTION                            *
	*                                                                                      *
	* This test compares your ft_strchr function with the standard strchr function         *
	* from the C library to ensure it behaves correctly.                                   *
	*                                                                                      *
	* It tests:                                                                            *
	* 1. Regular characters in various positions                                           *
	* 2. Character not present in the string                                               *
	* 3. Searching for the null terminator ('\0')                                          *
	* 4. Empty string                                                                      *
	* 5. Non-ASCII and edge values                                                         *
	* *************************************************************************************/

	/* Initialize counters */
	passed = 0;
	total = 0;

	/* Print header for the test */
	printf("\n===== TESTING FT_STRCHR =====\n\n");

	/* Test case 1: Character present in the middle */
	const char *str1 = "Hello, world!";
	int ch1 = 'o';
	const char *std_ptr1 = strchr(str1, ch1);
	const char *ft_ptr1 = ft_strchr(str1, ch1);
	total++;
	printf("Test 1: Character present in the middle\n");
	printf("String: \"%s\", Char: '%c'\n", str1, ch1);
	printf("Standard strchr: %s\n", std_ptr1 ? std_ptr1 : "NULL");
	printf("Your ft_strchr: %s\n", ft_ptr1 ? ft_ptr1 : "NULL");
	if (std_ptr1 == ft_ptr1)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 2: Character at the beginning */
	const char *str2 = "Test";
	int ch2 = 'T';
	const char *std_ptr2 = strchr(str2, ch2);
	const char *ft_ptr2 = ft_strchr(str2, ch2);
	total++;
	printf("Test 2: Character at the beginning\n");
	printf("String: \"%s\", Char: '%c'\n", str2, ch2);
	printf("Standard strchr: %s\n", std_ptr2 ? std_ptr2 : "NULL");
	printf("Your ft_strchr: %s\n", ft_ptr2 ? ft_ptr2 : "NULL");
	if (std_ptr2 == ft_ptr2)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 3: Character at the end */
	const char *str3 = "End.";
	int ch3 = '.';
	const char *std_ptr3 = strchr(str3, ch3);
	const char *ft_ptr3 = ft_strchr(str3, ch3);
	total++;
	printf("Test 3: Character at the end\n");
	printf("String: \"%s\", Char: '%c'\n", str3, ch3);
	printf("Standard strchr: %s\n", std_ptr3 ? std_ptr3 : "NULL");
	printf("Your ft_strchr: %s\n", ft_ptr3 ? ft_ptr3 : "NULL");
	if (std_ptr3 == ft_ptr3)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 4: Character not present */
	const char *str4 = "abcdef";
	int ch4 = 'X';
	const char *std_ptr4 = strchr(str4, ch4);
	const char *ft_ptr4 = ft_strchr(str4, ch4);
	total++;
	printf("Test 4: Character not present\n");
	printf("String: \"%s\", Char: '%c'\n", str4, ch4);
	printf("Standard strchr: %s\n", std_ptr4 ? std_ptr4 : "NULL");
	printf("Your ft_strchr: %s\n", ft_ptr4 ? ft_ptr4 : "NULL");
	if (std_ptr4 == ft_ptr4)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 5: Search for null terminator */
	const char *str5 = "abc";
	int ch5 = '\0';
	const char *std_ptr5 = strchr(str5, ch5);
	const char *ft_ptr5 = ft_strchr(str5, ch5);
	total++;
	printf("Test 5: Search for null terminator\n");
	printf("String: \"%s\", Char: '\\0'\n", str5);
	printf("Standard strchr: %p\n", (void*)std_ptr5);
	printf("Your ft_strchr: %p\n", (void*)ft_ptr5);
	if (std_ptr5 == ft_ptr5)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 6: Empty string, search for '\0' */
	const char *str6 = "";
	int ch6 = '\0';
	const char *std_ptr6 = strchr(str6, ch6);
	const char *ft_ptr6 = ft_strchr(str6, ch6);
	total++;
	printf("Test 6: Empty string, search for '\\0'\n");
	printf("String: \"\", Char: '\\0'\n");
	printf("Standard strchr: %p\n", (void*)std_ptr6);
	printf("Your ft_strchr: %p\n", (void*)ft_ptr6);
	if (std_ptr6 == ft_ptr6)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 7: Empty string, search for non-null */
	const char *str7 = "";
	int ch7 = 'A';
	const char *std_ptr7 = strchr(str7, ch7);
	const char *ft_ptr7 = ft_strchr(str7, ch7);
	total++;
	printf("Test 7: Empty string, search for 'A'\n");
	printf("String: \"\", Char: 'A'\n");
	printf("Standard strchr: %s\n", std_ptr7 ? std_ptr7 : "NULL");
	printf("Your ft_strchr: %s\n", ft_ptr7 ? ft_ptr7 : "NULL");
	if (std_ptr7 == ft_ptr7)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 8: Multiple occurrences */
	const char *str8 = "banana";
	int ch8 = 'a';
	const char *std_ptr8 = strchr(str8, ch8);
	const char *ft_ptr8 = ft_strchr(str8, ch8);
	total++;
	printf("Test 8: Multiple occurrences\n");
	printf("String: \"%s\", Char: '%c'\n", str8, ch8);
	printf("Standard strchr: %s\n", std_ptr8 ? std_ptr8 : "NULL");
	printf("Your ft_strchr: %s\n", ft_ptr8 ? ft_ptr8 : "NULL");
	if (std_ptr8 == ft_ptr8)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 9: Non-ASCII character */
	const char *str9 = "héllo";
	int ch9 = (unsigned char)'é';
	const char *std_ptr9 = strchr(str9, ch9);
	const char *ft_ptr9 = ft_strchr(str9, ch9);
	total++;
	printf("Test 9: Non-ASCII character\n");
	printf("String: \"%s\", Char: '%c' (ASCII %d)\n", str9, ch9, ch9);
	printf("Standard strchr: %s\n", std_ptr9 ? std_ptr9 : "NULL");
	printf("Your ft_strchr: %s\n", ft_ptr9 ? ft_ptr9 : "NULL");
	if (std_ptr9 == ft_ptr9)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 10: Search for int value > 127 */
	const char *str10 = "abc";
	int ch10 = 200;
	const char *std_ptr10 = strchr(str10, ch10);
	const char *ft_ptr10 = ft_strchr(str10, ch10);
	total++;
	printf("Test 10: Search for int value > 127\n");
	printf("String: \"%s\", Char: %d\n", str10, ch10);
	printf("Standard strchr: %s\n", std_ptr10 ? std_ptr10 : "NULL");
	printf("Your ft_strchr: %s\n", ft_ptr10 ? ft_ptr10 : "NULL");
	if (std_ptr10 == ft_ptr10)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Print test summary */
	printf("\n===== FT_STRCHR TEST SUMMARY =====\n");
	printf("Tests passed: %d/%d (%.2f%%)\n",
		passed, total, (float)passed / total * 100);

	if (passed == total)
		printf("All tests passed! Your ft_strchr function works correctly.\n\n\n");
	else
		printf("Some tests failed. Please check your implementation.\n\n\n");



	/* **************************************************************************************
	*                               TEST FOR FT_STRRCHR FUNCTION                            *
	*                                                                                      *
	* This test compares your ft_strrchr function with the standard strrchr function       *
	* from the C library to ensure it behaves correctly.                                   *
	*                                                                                      *
	* It tests:                                                                            *
	* 1. Character present once in the string                                              *
	* 2. Character present multiple times                                                  *
	* 3. Character not present                                                             *
	* 4. Searching for null terminator                                                     *
	* 5. Empty string cases                                                                *
	* 6. Non-ASCII characters                                                              *
	* 7. Edge cases (first/last character)                                                 *
	* *************************************************************************************/

	/* Initialize counters */
	passed = 0;
	total = 0;

	/* Print header for the test */
	printf("\n===== TESTING FT_STRRCHR =====\n\n");

	/* Test case 1: Character present once */
	const char *str1 = "Hello, world!";
	int ch1 = 'o';
	const char *std_ptr1 = strrchr(str1, ch1);
	const char *ft_ptr1 = ft_strrchr(str1, ch1);
	total++;
	printf("Test 1: Single occurrence\n");
	printf("String: \"%s\", Char: '%c'\n", str1, ch1);
	printf("Standard strrchr: %s\n", std_ptr1 ? std_ptr1 : "NULL");
	printf("Your ft_strrchr: %s\n", ft_ptr1 ? ft_ptr1 : "NULL");
	if (std_ptr1 == ft_ptr1 || (std_ptr1 && ft_ptr1 && *std_ptr1 == *ft_ptr1))
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 2: Multiple occurrences */
	const char *str2 = "banana";
	int ch2 = 'a';
	const char *std_ptr2 = strrchr(str2, ch2);
	const char *ft_ptr2 = ft_strrchr(str2, ch2);
	total++;
	printf("Test 2: Multiple occurrences\n");
	printf("String: \"%s\", Char: '%c'\n", str2, ch2);
	printf("Standard strrchr: %s\n", std_ptr2 ? std_ptr2 : "NULL");
	printf("Your ft_strrchr: %s\n", ft_ptr2 ? ft_ptr2 : "NULL");
	if (std_ptr2 == ft_ptr2 || (std_ptr2 && ft_ptr2 && *std_ptr2 == *ft_ptr2))
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 3: Character not present */
	const char *str3 = "abcdef";
	int ch3 = 'z';
	const char *std_ptr3 = strrchr(str3, ch3);
	const char *ft_ptr3 = ft_strrchr(str3, ch3);
	total++;
	printf("Test 3: Character not found\n");
	printf("String: \"%s\", Char: '%c'\n", str3, ch3);
	printf("Standard strrchr: %s\n", std_ptr3 ? std_ptr3 : "NULL");
	printf("Your ft_strrchr: %s\n", ft_ptr3 ? ft_ptr3 : "NULL");
	if (std_ptr3 == ft_ptr3)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 4: Search for null terminator */
	const char *str4 = "test";
	int ch4 = '\0';
	const char *std_ptr4 = strrchr(str4, ch4);
	const char *ft_ptr4 = ft_strrchr(str4, ch4);
	total++;
	printf("Test 4: Search for null terminator\n");
	printf("String: \"%s\", Char: '\\0'\n", str4);
	printf("Standard strrchr: %p\n", (void*)std_ptr4);
	printf("Your ft_strrchr: %p\n", (void*)ft_ptr4);
	if (std_ptr4 == ft_ptr4)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 5: Empty string */
	const char *str5 = "";
	int ch5 = 'a';
	const char *std_ptr5 = strrchr(str5, ch5);
	const char *ft_ptr5 = ft_strrchr(str5, ch5);
	total++;
	printf("Test 5: Empty string\n");
	printf("String: \"\", Char: '%c'\n", ch5);
	printf("Standard strrchr: %s\n", std_ptr5 ? std_ptr5 : "NULL");
	printf("Your ft_strrchr: %s\n", ft_ptr5 ? ft_ptr5 : "NULL");
	if (std_ptr5 == ft_ptr5)
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 6: First character match */
	const char *str6 = "first";
	int ch6 = 'f';
	const char *std_ptr6 = strrchr(str6, ch6);
	const char *ft_ptr6 = ft_strrchr(str6, ch6);
	total++;
	printf("Test 6: First character match\n");
	printf("String: \"%s\", Char: '%c'\n", str6, ch6);
	printf("Standard strrchr: %s\n", std_ptr6 ? std_ptr6 : "NULL");
	printf("Your ft_strrchr: %s\n", ft_ptr6 ? ft_ptr6 : "NULL");
	if (std_ptr6 == ft_ptr6 || (std_ptr6 && ft_ptr6 && *std_ptr6 == *ft_ptr6))
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Test case 7: Non-ASCII character */
	const char *str7 = "café";
	int ch7 = 0xE9; /* é in Latin-1 */
	const char *std_ptr7 = strrchr(str7, ch7);
	const char *ft_ptr7 = ft_strrchr(str7, ch7);
	total++;
	printf("Test 7: Non-ASCII character\n");
	printf("String: \"%s\", Char: 0x%x\n", str7, ch7);
	printf("Standard strrchr: %s\n", std_ptr7 ? std_ptr7 : "NULL");
	printf("Your ft_strrchr: %s\n", ft_ptr7 ? ft_ptr7 : "NULL");
	if (std_ptr7 == ft_ptr7 || (std_ptr7 && ft_ptr7 && *std_ptr7 == *ft_ptr7))
	{
		passed++;
		printf("✓ Test passed!\n\n");
	}
	else
		printf("✗ Test failed!\n\n");

	/* Print test summary */
	printf("\n===== FT_STRRCHR TEST SUMMARY =====\n");
	printf("Tests passed: %d/%d (%.2f%%)\n",
		passed, total, (float)passed / total * 100);

	if (passed == total)
		printf("All tests passed! Your ft_strrchr function works correctly.\n\n\n");
	else
		printf("Some tests failed. Please check your implementation.\n\n\n");



	/* ******************************************************************************** */
	/*                                                                                  */
	/*                        TEST FOR FT_STRNCMP FUNCTION                              */
	/*                                                                                  */
	/* This program tests the ft_strncmp function by comparing its results              */
	/* with the standard strncmp function from the C library.                           */
	/* It tests various string combinations and edge cases to ensure proper comparison  */
	/* behavior up to n characters.                                                     */
	/* ******************************************************************************** */

	/* Initialize counters */
	passed = 0;
	total = 0;

	/* Print header for the test */
	printf("\n===== TESTING FT_STRNCMP =====\n\n");

	/* Test case array */
	struct test_case {
		const char *s1;
		const char *s2;
		size_t n;
		int expected;
	} tests[] = {
		/* Basic comparisons */
		{"apple", "apple", 5, 0},
		{"apple", "apples", 5, 0},
		{"apple", "apples", 6, -'s'},
		{"apple", "banana", 5, 'a' - 'b'},
		{"banana", "apple", 5, 'b' - 'a'},
		{"", "", 0, 0},

		/* Case sensitivity */
		{"HELLO", "hello", 5, 'H' - 'h'},
		{"hello", "HELLO", 5, 'h' - 'H'},

		/* Different lengths */
		{"short", "shorter", 5, 0},
		{"shorter", "short", 5, 0},
		{"shorter", "short", 6, 'e' - '\0'},

		/* Special characters */
		{"test\200", "test\0", 5, 128},
		{"\255", "\255", 1, 0},
		{"\0abc", "\0xyz", 4, 0},

		/* Edge cases */
		{"", "non-empty", 0, 0},
		{"abc", "abc", 0, 0},
		{"abc", "abd", 2, 0},
		{"abc", "abd", 3, 'c' - 'd'}
	};

	size_t num_tests = sizeof(tests) / sizeof(tests[0]);

	for (size_t t = 0; t < num_tests; t++) {
		int result = ft_strncmp(tests[t].s1, tests[t].s2, tests[t].n);
		int actual = result < 0 ? -1 : result > 0 ? 1 : 0;
		int expected = tests[t].expected < 0 ? -1 : tests[t].expected > 0 ? 1 : 0;

		total++;

		if (actual == expected) {
			passed++;
			printf("✓ ");
		} else {
			printf("✗ ");
		}

		printf("Test %zu: s1=\"%s\", s2=\"%s\", n=%zu\n", t+1,
			tests[t].s1, tests[t].s2, tests[t].n);
		printf("Expected: %d | Actual: %d\n", expected, actual);

		if (actual != expected) {
			printf("MISMATCH! (Standard: %d, Yours: %d)\n",
				strncmp(tests[t].s1, tests[t].s2, tests[t].n), result);
		}
	}

	/* Additional comprehensive test */
	printf("\n===== COMPREHENSIVE ASCII TEST =====\n\n");
	for (int i = 0; i <= 127; i++) {
		for (int j = 0; j <= 127; j++) {
			char s1[2] = {i, '\0'};
			char s2[2] = {j, '\0'};
			int expected = strncmp(s1, s2, 1);
			int result = ft_strncmp(s1, s2, 1);
			int norm_expected = expected < 0 ? -1 : expected > 0 ? 1 : 0;
			int norm_result = result < 0 ? -1 : result > 0 ? 1 : 0;

			total++;
			if (norm_expected == norm_result) {
				passed++;
			} else {
				printf("✗ Char %d vs %d: Expected %d, Got %d\n",
					i, j, norm_expected, norm_result);
			}
		}
	}

	/* Print test summary */
	printf("\n===== FT_STRNCMP TEST SUMMARY =====\n");
	printf("Tests passed: %d/%d (%.2f%%)\n",
		passed, total, (float)passed / total * 100);

	if (passed == total)
		printf("All tests passed! Your ft_strncmp works correctly.\n\n\n");
	else
		printf("Some tests failed. Please check your implementation.\n\n\n");


	return (0);
}
