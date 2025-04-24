/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:12:00 by jgueon            #+#    #+#             */
/*   Updated: 2025/04/24 19:39:53 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

/* Include the header file that contains ft_isalpha prototype soon*/

int	ft_isalpha(int c);
int	ft_isdigit(int c);


/**
 * This test file compares your replica "ft" function implementation with the standard
 * isalpha function from the C library to ensure it behaves correctly.
 *
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

	/* Test all ASCII characters */
	passed = 0;
	total = 0;
	printf("Testing ft_isalpha against standard isalpha:\n\n");

	/* Test ASCII values from 0 to 127 */
	printf("Testing ASCII characters (0-127):\n");
	i = 0;
	while (i <= 127)
	{
		int	std_result;
		int	ft_result;

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
		printf("\nCongratulations! Your ft_isalpha function works correctly!\n");
	else
		printf("\nYour ft_isalpha function needs some fixes.\n");

	// return (0);

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
        printf("All tests passed! ft_isdigit works correctly.\n");
    else
        printf("Some tests failed. Please check your implementation.\n");

    return (0);
}
