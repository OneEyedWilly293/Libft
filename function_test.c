/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:12:00 by jgueon            #+#    #+#             */
/*   Updated: 2025/04/23 20:17:08 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

/* Include the header file that contains ft_isalpha prototype soon*/

int	ft_isalpha(int c);

/**
 * This test file compares your ft_isalpha implementation with the standard
 * isalpha function from the C library to ensure it behaves correctly.
 *
 * It tests:
 * 1. All uppercase letters (A-Z)
 * 2. All lowercase letters (a-z)
 * 3. Digits (0-9)
 * 4. Special characters and control characters
 * 5. Extended ASCII values
 */
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

	return (0);
}
