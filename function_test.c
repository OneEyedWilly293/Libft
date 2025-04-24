/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:12:00 by jgueon            #+#    #+#             */
/*   Updated: 2025/04/24 20:51:43 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
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
	int	i;
	int	passed;
	int	total;
    int std_result;
    int ft_result;

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

		printf(" | Standard: %d | Yours: %d", std_result, ft_result);

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



    return (0);
}
