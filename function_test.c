/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:12:00 by jgueon            #+#    #+#             */
/*   Updated: 2025/04/25 14:56:32 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include "libft.h"


/* Include the header file that contains ft_isalpha prototype soon*/

//int	ft_isalpha(int c);
//int	ft_isdigit(int c);
//int ft_isalnum(int c);


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
           printf("%d", buffer1[i]);
           if (j < len4 - 1)
               printf(", ");
       }
       printf("]\n");

       printf("Your ft_memset: [");
       for (j = 0; j < len4; j++)
       {
           printf("%d", buffer2[i]);
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



    return (0);
}
