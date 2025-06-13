/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:15:00 by pablo             #+#    #+#             */
/*   Updated: 2025/06/13 15:04:42 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/include_bonus/ft_printf_bonus.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

int	g_test_count = 0;
int	g_passed = 0;

void	test_char(const char *desc, const char *format, char c)
{
	int		ret1, ret2;

	g_test_count++;
	printf(CYAN "Test %d: %s" RESET "\n", g_test_count, desc);
	printf(YELLOW "Format: \"%s\"" RESET "\n", format);

	// Primera llamada a printf
	printf(BLUE "printf   : " RESET);
	fflush(stdout);
	ret1 = printf(format, c);
	printf("\n");
	fflush(stdout);

	// Segunda llamada a ft_printf
	printf(PURPLE "ft_printf: " RESET);
	fflush(stdout);
	ret2 = ft_printf(format, c);
	printf("\n");
	fflush(stdout);

	if (ret1 == ret2)
	{
		printf(GREEN "✓ PASS - Return values match (%d)" RESET "\n", ret1);
		g_passed++;
	}
	else
	{
		printf(RED "✗ FAIL - Return values differ: printf=%d, ft_printf=%d" RESET "\n", ret1, ret2);
	}
	printf("----------------------------------------\n\n");
}

void	test_string(const char *desc, const char *format, const char *str)
{
	int		ret1, ret2;

	g_test_count++;
	printf(CYAN "Test %d: %s" RESET "\n", g_test_count, desc);
	printf(YELLOW "Format: \"%s\"" RESET "\n", format);

	// Primera llamada a printf
	printf(BLUE "printf   : " RESET);
	fflush(stdout);
	ret1 = printf(format, str);
	printf("\n");
	fflush(stdout);

	// Segunda llamada a ft_printf
	printf(PURPLE "ft_printf: " RESET);
	fflush(stdout);
	ret2 = ft_printf(format, str);
	printf("\n");
	fflush(stdout);

	if (ret1 == ret2)
	{
		printf(GREEN "✓ PASS - Return values match (%d)" RESET "\n", ret1);
		g_passed++;
	}
	else
	{
		printf(RED "✗ FAIL - Return values differ: printf=%d, ft_printf=%d" RESET "\n", ret1, ret2);
	}
	printf("----------------------------------------\n\n");
}

void	test_int(const char *desc, const char *format, int num)
{
	int		ret1, ret2;

	g_test_count++;
	printf(CYAN "Test %d: %s" RESET "\n", g_test_count, desc);
	printf(YELLOW "Format: \"%s\"" RESET "\n", format);

	// Primera llamada a printf
	printf(BLUE "printf   : " RESET);
	fflush(stdout);
	ret1 = printf(format, num);
	printf("\n");
	fflush(stdout);

	// Segunda llamada a ft_printf
	printf(PURPLE "ft_printf: " RESET);
	fflush(stdout);
	ret2 = ft_printf(format, num);
	printf("\n");
	fflush(stdout);

	if (ret1 == ret2)
	{
		printf(GREEN "✓ PASS - Return values match (%d)" RESET "\n", ret1);
		g_passed++;
	}
	else
	{
		printf(RED "✗ FAIL - Return values differ: printf=%d, ft_printf=%d" RESET "\n", ret1, ret2);
	}
	printf("----------------------------------------\n\n");
}

void	test_ptr(const char *desc, const char *format, void *ptr)
{
	int		ret1, ret2;

	g_test_count++;
	printf(CYAN "Test %d: %s" RESET "\n", g_test_count, desc);
	printf(YELLOW "Format: \"%s\"" RESET "\n", format);

	// Primera llamada a printf
	printf(BLUE "printf   : " RESET);
	fflush(stdout);
	ret1 = printf(format, ptr);
	printf("\n");
	fflush(stdout);

	// Segunda llamada a ft_printf
	printf(PURPLE "ft_printf: " RESET);
	fflush(stdout);
	ret2 = ft_printf(format, ptr);
	printf("\n");
	fflush(stdout);

	if (ret1 == ret2)
	{
		printf(GREEN "✓ PASS - Return values match (%d)" RESET "\n", ret1);
		g_passed++;
	}
	else
	{
		printf(RED "✗ FAIL - Return values differ: printf=%d, ft_printf=%d" RESET "\n", ret1, ret2);
	}
	printf("----------------------------------------\n\n");
}

void	test_percent(const char *desc, const char *format)
{
	int		ret1, ret2;

	g_test_count++;
	printf(CYAN "Test %d: %s" RESET "\n", g_test_count, desc);
	printf(YELLOW "Format: \"%s\"" RESET "\n", format);

	// Primera llamada a printf
	printf(BLUE "printf   : " RESET);
	fflush(stdout);
	ret1 = printf("%s", format);
	printf("\n");
	fflush(stdout);

	// Segunda llamada a ft_printf
	printf(PURPLE "ft_printf: " RESET);
	fflush(stdout);
	ret2 = ft_printf("%s", format);
	printf("\n");
	fflush(stdout);

	if (ret1 == ret2)
	{
		printf(GREEN "✓ PASS - Return values match (%d)" RESET "\n", ret1);
		g_passed++;
	}
	else
	{
		printf(RED "✗ FAIL - Return values differ: printf=%d, ft_printf=%d" RESET "\n", ret1, ret2);
	}
	printf("----------------------------------------\n\n");
}

// Test function for multiple arguments - creates specific test functions for each case
#define test_multiple_2(desc, format, arg1, arg2) \
	do { \
		int ret1, ret2; \
		g_test_count++; \
		printf(CYAN "Test %d: %s" RESET "\n", g_test_count, desc); \
		printf(YELLOW "Format: \"%s\"" RESET "\n", format); \
		printf(BLUE "printf   : " RESET); \
		fflush(stdout); \
		ret1 = printf(format, arg1, arg2); \
		printf("\n"); \
		fflush(stdout); \
		printf(PURPLE "ft_printf: " RESET); \
		fflush(stdout); \
		ret2 = ft_printf(format, arg1, arg2); \
		printf("\n"); \
		fflush(stdout); \
		if (ret1 == ret2) { \
			printf(GREEN "✓ PASS - Return values match (%d)" RESET "\n", ret1); \
			g_passed++; \
		} else { \
			printf(RED "✗ FAIL - Return values differ: printf=%d, ft_printf=%d" RESET "\n", ret1, ret2); \
		} \
		printf("----------------------------------------\n\n"); \
	} while(0)

#define test_multiple_3(desc, format, arg1, arg2, arg3) \
	do { \
		int ret1, ret2; \
		g_test_count++; \
		printf(CYAN "Test %d: %s" RESET "\n", g_test_count, desc); \
		printf(YELLOW "Format: \"%s\"" RESET "\n", format); \
		printf(BLUE "printf   : " RESET); \
		fflush(stdout); \
		ret1 = printf(format, arg1, arg2, arg3); \
		printf("\n"); \
		fflush(stdout); \
		printf(PURPLE "ft_printf: " RESET); \
		fflush(stdout); \
		ret2 = ft_printf(format, arg1, arg2, arg3); \
		printf("\n"); \
		fflush(stdout); \
		if (ret1 == ret2) { \
			printf(GREEN "✓ PASS - Return values match (%d)" RESET "\n", ret1); \
			g_passed++; \
		} else { \
			printf(RED "✗ FAIL - Return values differ: printf=%d, ft_printf=%d" RESET "\n", ret1, ret2); \
		} \
		printf("----------------------------------------\n\n"); \
	} while(0)

#define test_multiple_4(desc, format, arg1, arg2, arg3, arg4) \
	do { \
		int ret1, ret2; \
		g_test_count++; \
		printf(CYAN "Test %d: %s" RESET "\n", g_test_count, desc); \
		printf(YELLOW "Format: \"%s\"" RESET "\n", format); \
		printf(BLUE "printf   : " RESET); \
		fflush(stdout); \
		ret1 = printf(format, arg1, arg2, arg3, arg4); \
		printf("\n"); \
		fflush(stdout); \
		printf(PURPLE "ft_printf: " RESET); \
		fflush(stdout); \
		ret2 = ft_printf(format, arg1, arg2, arg3, arg4); \
		printf("\n"); \
		fflush(stdout); \
		if (ret1 == ret2) { \
			printf(GREEN "✓ PASS - Return values match (%d)" RESET "\n", ret1); \
			g_passed++; \
		} else { \
			printf(RED "✗ FAIL - Return values differ: printf=%d, ft_printf=%d" RESET "\n", ret1, ret2); \
		} \
		printf("----------------------------------------\n\n"); \
	} while(0)

#define test_multiple_5(desc, format, arg1, arg2, arg3, arg4, arg5) \
	do { \
		int ret1, ret2; \
		g_test_count++; \
		printf(CYAN "Test %d: %s" RESET "\n", g_test_count, desc); \
		printf(YELLOW "Format: \"%s\"" RESET "\n", format); \
		printf(BLUE "printf   : " RESET); \
		fflush(stdout); \
		ret1 = printf(format, arg1, arg2, arg3, arg4, arg5); \
		printf("\n"); \
		fflush(stdout); \
		printf(PURPLE "ft_printf: " RESET); \
		fflush(stdout); \
		ret2 = ft_printf(format, arg1, arg2, arg3, arg4, arg5); \
		printf("\n"); \
		fflush(stdout); \
		if (ret1 == ret2) { \
			printf(GREEN "✓ PASS - Return values match (%d)" RESET "\n", ret1); \
			g_passed++; \
		} else { \
			printf(RED "✗ FAIL - Return values differ: printf=%d, ft_printf=%d" RESET "\n", ret1, ret2); \
		} \
		printf("----------------------------------------\n\n"); \
	} while(0)

#define test_multiple_8(desc, format, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
	do { \
		int ret1, ret2; \
		g_test_count++; \
		printf(CYAN "Test %d: %s" RESET "\n", g_test_count, desc); \
		printf(YELLOW "Format: \"%s\"" RESET "\n", format); \
		printf(BLUE "printf   : " RESET); \
		fflush(stdout); \
		ret1 = printf(format, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8); \
		printf("\n"); \
		fflush(stdout); \
		printf(PURPLE "ft_printf: " RESET); \
		fflush(stdout); \
		ret2 = ft_printf(format, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8); \
		printf("\n"); \
		fflush(stdout); \
		if (ret1 == ret2) { \
			printf(GREEN "✓ PASS - Return values match (%d)" RESET "\n", ret1); \
			g_passed++; \
		} else { \
			printf(RED "✗ FAIL - Return values differ: printf=%d, ft_printf=%d" RESET "\n", ret1, ret2); \
		} \
		printf("----------------------------------------\n\n"); \
	} while(0)

#define test_multiple_9(desc, format, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
	do { \
		int ret1, ret2; \
		g_test_count++; \
		printf(CYAN "Test %d: %s" RESET "\n", g_test_count, desc); \
		printf(YELLOW "Format: \"%s\"" RESET "\n", format); \
		printf(BLUE "printf   : " RESET); \
		fflush(stdout); \
		ret1 = printf(format, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9); \
		printf("\n"); \
		fflush(stdout); \
		printf(PURPLE "ft_printf: " RESET); \
		fflush(stdout); \
		ret2 = ft_printf(format, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9); \
		printf("\n"); \
		fflush(stdout); \
		if (ret1 == ret2) { \
			printf(GREEN "✓ PASS - Return values match (%d)" RESET "\n", ret1); \
			g_passed++; \
		} else { \
			printf(RED "✗ FAIL - Return values differ: printf=%d, ft_printf=%d" RESET "\n", ret1, ret2); \
		} \
		printf("----------------------------------------\n\n"); \
	} while(0)

int	main(void)
{
	printf(CYAN "========================================\n");
	printf("   FT_PRINTF BONUS COMPREHENSIVE TEST\n");
	printf("========================================\n\n" RESET);

	// Character tests
 	printf(GREEN "=== CHARACTER TESTS ===\n\n" RESET);
	test_char("Basic character", "%c", 'A');
	test_char("Character with width", "%5c", 'B');
	test_char("Character with left align", "%-5c", 'C');
	test_char("Character with zero padding", "%05c", 'D');
	test_char("Null character", "%c", '\0');
	test_char("Tab character", "%c", '\t');

	// String tests
 	printf(GREEN "=== STRING TESTS ===\n\n" RESET);
	test_string("Basic string", "%s", "Hello");
	test_string("NULL string", "%s", (char *)NULL);
	test_string("Empty string", "%s", "");
	test_string("String with width", "%10s", "World");
	test_string("String with left align", "%-10s", "Left");
	test_string("String with precision", "%.3s", "Precision");
	test_string("String with width and precision", "%10.3s", "Test");
	test_string("String with left align and precision", "%-10.3s", "Left");
	test_string("String with zero precision", "%.0s", "Hidden");
	test_string("Long string with small precision", "%.5s", "This is a very long string");

	// Pointer tests
	printf(GREEN "=== POINTER TESTS ===\n\n" RESET);
	char *ptr = "test";
	test_ptr("Basic pointer", "%p", ptr);
	test_ptr("NULL pointer", "%p", (void *)NULL);
	test_ptr("Pointer with width", "%20p", ptr);
	test_ptr("Pointer with left align", "%-20p", ptr);
	test_ptr("Pointer with zero padding", "%020p", ptr);

	// Integer tests (d and i)
	printf(GREEN "=== INTEGER TESTS ===\n\n" RESET);
	test_int("Basic positive integer", "%d", 42);
	test_int("Basic negative integer", "%d", -42);
	test_int("Zero", "%d", 0);
	test_int("Integer with width", "%10d", 123);
	test_int("Integer with left align", "%-10d", 123);
	test_int("Integer with zero padding", "%010d", 123);
	test_int("Negative with zero padding", "%010d", -123);
	test_int("Integer with precision", "%.5d", 123);
	test_int("Integer with width and precision", "%10.5d", 123);
	test_int("Negative with precision", "%.5d", -123);
	test_int("Zero with precision", "%.5d", 0);
	test_int("Precision zero with zero value", "%.0d", 0);
	test_int("Large number", "%d", 2147483647);
	test_int("Minimum int", "%d", -2147483648);

	// Same tests for %i
	test_int("Basic positive integer (i)", "%i", 42);
	test_int("Basic negative integer (i)", "%i", -42);
	test_int("Integer with zero padding (i)", "%010i", 123);

	// Unsigned integer tests
	printf(GREEN "=== UNSIGNED INTEGER TESTS ===\n\n" RESET);
	test_int("Basic unsigned", "%u", 42U);
	test_int("Zero unsigned", "%u", 0U);
	test_int("Large unsigned", "%u", 4294967295U);
	test_int("Unsigned with width", "%10u", 123U);
	test_int("Unsigned with left align", "%-10u", 123U);
	test_int("Unsigned with zero padding", "%010u", 123U);
	test_int("Unsigned with precision", "%.5u", 123U);
	test_int("Unsigned with width and precision", "%10.5u", 123U);

	// Hexadecimal lowercase tests
	printf(GREEN "=== HEXADECIMAL LOWERCASE TESTS ===\n\n" RESET);
	test_int("Basic hex lowercase", "%x", 42);
	test_int("Zero hex", "%x", 0);
	test_int("Large hex", "%x", 0xABCDEF);
	test_int("Hex with width", "%10x", 0x123);
	test_int("Hex with left align", "%-10x", 0x123);
	test_int("Hex with zero padding", "%010x", 0x123);
	test_int("Hex with precision", "%.5x", 0x123);
	test_int("Hex with width and precision", "%10.5x", 0x123);

	// Hexadecimal uppercase tests
	printf(GREEN "=== HEXADECIMAL UPPERCASE TESTS ===\n\n" RESET);
	test_int("Basic hex uppercase", "%X", 42);
	test_int("Zero hex uppercase", "%X", 0);
	test_int("Large hex uppercase", "%X", 0xABCDEF);
	test_int("Hex uppercase with width", "%10X", 0x123);
	test_int("Hex uppercase with left align", "%-10X", 0x123);
	test_int("Hex uppercase with zero padding", "%010X", 0x123);
	test_int("Hex uppercase with precision", "%.5X", 0x123);
	test_int("Hex uppercase with width and precision", "%10.5X", 0x123);


	// Alternate format (#) tests for hexadecimal
	printf(GREEN "=== ALTERNATE FORMAT (#) TESTS ===\n\n" RESET);
	test_int("Basic hex lowercase with #", "%#x", 42);
	test_int("Basic hex uppercase with #", "%#X", 42);
	test_int("Zero with # (x)", "%#x", 0);
	test_int("Zero with # (X)", "%#X", 0);
	test_int("Large hex with # (x)", "%#x", 0xABCDEF);
	test_int("Large hex with # (X)", "%#X", 0xABCDEF);
	test_int("Hex with # and width (x)", "%#10x", 0x123);
	test_int("Hex with # and width (X)", "%#10X", 0x123);
	test_int("Hex with # and left align (x)", "%#-10x", 0x123);
	test_int("Hex with # and left align (X)", "%#-10X", 0x123);
	test_int("Hex with # and zero padding (x)", "%#010x", 0x123);
	test_int("Hex with # and zero padding (X)", "%#010X", 0x123);
	test_int("Hex with # and precision (x)", "%#.5x", 0x123);
	test_int("Hex with # and precision (X)", "%#.5X", 0x123);
	test_int("Hex with # width and precision (x)", "%#10.5x", 0x123);
	test_int("Hex with # width and precision (X)", "%#10.5X", 0x123);
	test_int("# flag with precision zero and zero value (x)", "%#.0x", 0);
	test_int("# flag with precision zero and zero value (X)", "%#.0X", 0);
	test_int("# flag with different integers (x)", "%#x", 255);
	test_int("# flag with different integers (X)", "%#X", 255);
	test_int("# flag with negative conversion (x)", "%#x", -1);
	test_int("# flag with negative conversion (X)", "%#X", -1);

	// Test # flag with other specifiers (should have no effect)
	printf(GREEN "=== # FLAG WITH OTHER SPECIFIERS (NO EFFECT) ===\n\n" RESET);
	test_int("# flag with %d (no effect)", "%#d", 42);
	test_int("# flag with %i (no effect)", "%#i", 42);
	test_int("# flag with %u (no effect)", "%#u", 42U);
	test_char("# flag with %c (no effect)", "%#c", 'A');
	test_string("# flag with %s (no effect)", "%#s", "Hello");
	char *test_ptr2 = "test";
	test_ptr("# flag with %p (no effect)", "%#p", test_ptr2);
	test_percent("# flag with %% (no effect)", "%#%");

	// Space flag tests
	printf(GREEN "=== SPACE FLAG TESTS ===\n\n" RESET);
	test_int("Space flag with positive integer (d)", "% d", 42);
	test_int("Space flag with negative integer (d)", "% d", -42);
	test_int("Space flag with zero (d)", "% d", 0);
	test_int("Space flag with positive integer (i)", "% i", 42);
	test_int("Space flag with negative integer (i)", "% i", -42);
	test_int("Space flag with zero (i)", "% i", 0);
	test_int("Space flag with width (d)", "% 10d", 42);
	test_int("Space flag with width negative (d)", "% 10d", -42);
	test_int("Space flag with left align (d)", "% -10d", 42);
	test_int("Space flag with left align negative (d)", "% -10d", -42);
	test_int("Space flag with zero padding (d)", "% 010d", 42);
	test_int("Space flag with zero padding negative (d)", "% 010d", -42);
	test_int("Space flag with precision (d)", "% .5d", 42);
	test_int("Space flag with precision negative (d)", "% .5d", -42);
	test_int("Space flag with width and precision (d)", "% 10.5d", 42);
	test_int("Space flag with width and precision negative (d)", "% 10.5d", -42);
	test_int("Space flag with left align and precision (d)", "% -10.5d", 42);
	test_int("Space flag with left align and precision negative (d)", "% -10.5d", -42);
	test_int("Space flag with large number (d)", "% d", 2147483647);
	test_int("Space flag with minimum int (d)", "% d", -2147483648);

	// Space flag with other specifiers (should have no effect)
	printf(GREEN "=== SPACE FLAG WITH OTHER SPECIFIERS (NO EFFECT) ===\n\n" RESET);
	test_int("Space flag with %u (no effect)", "% u", 42U);
	test_int("Space flag with %x (no effect)", "% x", 42);
	test_int("Space flag with %X (no effect)", "% X", 42);
	test_char("Space flag with %c (no effect)", "% c", 'A');
	test_string("Space flag with %s (no effect)", "% s", "Hello");
	char *test_ptr3 = "test";
	test_ptr("Space flag with %p (no effect)", "% p", test_ptr3);
	test_percent("Space flag with %% (no effect)", "% %");

	// Percent tests
	printf(GREEN "=== PERCENT TESTS ===\n\n" RESET);
	test_percent("Basic percent", "%%");
	test_percent("Percent with width", "%5%");
	test_percent("Percent with left align", "%-5%");
	test_percent("Percent with zero padding", "%05%");

	// Plus flag tests
	printf(GREEN "=== PLUS FLAG TESTS ===\n\n" RESET);
	test_int("Plus flag with positive integer (d)", "%+d", 42);
	test_int("Plus flag with negative integer (d)", "%+d", -42);
	test_int("Plus flag with zero (d)", "%+d", 0);
	test_int("Plus flag with positive integer (i)", "%+i", 42);
	test_int("Plus flag with negative integer (i)", "%+i", -42);
	test_int("Plus flag with zero (i)", "%+i", 0);
	test_int("Plus flag with width (d)", "%+10d", 42);
	test_int("Plus flag with width negative (d)", "%+10d", -42);
	test_int("Plus flag with left align (d)", "%+-10d", 42);
	test_int("Plus flag with left align negative (d)", "%+-10d", -42);
	test_int("Plus flag with zero padding (d)", "%+010d", 42);
	test_int("Plus flag with zero padding negative (d)", "%+010d", -42);
	test_int("Plus flag with precision (d)", "%+.5d", 42);
	test_int("Plus flag with precision negative (d)", "%+.5d", -42);
	test_int("Plus flag with width and precision (d)", "%+10.5d", 42);
	test_int("Plus flag with width and precision negative (d)", "%+10.5d", -42);
	test_int("Plus flag with left align and precision (d)", "%+-10.5d", 42);
	test_int("Plus flag with left align and precision negative (d)", "%+-10.5d", -42);
	test_int("Plus flag with large number (d)", "%+d", 2147483647);
	test_int("Plus flag with minimum int (d)", "%+d", -2147483648);

	// Plus flag with other specifiers (should have no effect)
	printf(GREEN "=== PLUS FLAG WITH OTHER SPECIFIERS (NO EFFECT) ===\n\n" RESET);
	test_int("Plus flag with %u (no effect)", "%+u", 42U);
	test_int("Plus flag with %x (no effect)", "%+x", 42);
	test_int("Plus flag with %X (no effect)", "%+X", 42);
	test_char("Plus flag with %c (no effect)", "%+c", 'A');
	test_string("Plus flag with %s (no effect)", "%+s", "Hello");
	char *test_ptr4 = "test";
	test_ptr("Plus flag with %p (no effect)", "%+p", test_ptr4);
	test_percent("Plus flag with %% (no effect)", "%+%");

	// Combination of space and plus flags (plus takes precedence)
	printf(GREEN "=== SPACE AND PLUS FLAG COMBINATION ===\n\n" RESET);
	test_int("Space and plus flags positive (d)", "% +d", 42);
	test_int("Plus and space flags positive (d)", "%+ d", 42);
	test_int("Space and plus flags negative (d)", "% +d", -42);
	test_int("Plus and space flags negative (d)", "%+ d", -42);
	test_int("Space and plus flags zero (d)", "% +d", 0);
	test_int("Plus and space flags zero (d)", "%+ d", 0);
	test_int("Space and plus flags with width (d)", "% +10d", 42);
	test_int("Plus and space flags with width (d)", "%+ 10d", 42);

	// ADDITIONAL EDGE CASES
	printf(GREEN "=== ADDITIONAL EDGE CASES ===\n\n" RESET);

	// Maximum width tests
	test_int("Very large width", "%100d", 42);
	test_string("Very large width with string", "%100s", "test");
	test_char("Very large width with char", "%100c", 'A');

	// Zero precision with different values
	test_int("Zero precision with non-zero value", "%.0d", 42);
	test_int("Zero precision with negative value", "%.0d", -42);
	test_string("Zero precision with string", "%.0s", "Hello");

	// Precision larger than number
	test_int("Precision larger than number", "%.10d", 42);
	test_int("Precision larger than negative number", "%.10d", -42);

	// Width smaller than content
	test_int("Width smaller than content", "%2d", 12345);
	test_string("Width smaller than string", "%2s", "Hello");

	// Combination of precision and width
	test_int("Width and precision both large", "%20.15d", 42);
	test_string("Width and precision with string", "%20.3s", "Hello World");

	// Edge cases with zero
	test_int("Zero with various formats", "%+d", 0);
	test_int("Zero with space flag", "% d", 0);
	test_int("Zero with width and precision", "%10.5d", 0);
	test_int("Zero with # flag (should have no effect)", "%#d", 0);

	// Multiple format specifiers in one string
	printf(GREEN "=== MULTIPLE SPECIFIERS IN ONE STRING ===\n\n" RESET);
	test_multiple_2("Multiple integers", "%d %d", 42, 24);
	test_multiple_3("Mixed types", "%c %s %d", 'A', "Hello", 42);
	test_multiple_4("Complex mixed", "%+d %#x %s %c", -42, 255, "test", '!');
	test_multiple_3("Multiple with flags", "%+10d %-15s %#08x", 42, "Hello", 255);
	test_multiple_8("All specifiers", "%c %s %p %d %i %u %x %X %%", 'A', "test", ptr, 42, -42, 42U, 42, 42);

	// Invalid or edge format specifiers
	printf(GREEN "=== INVALID/EDGE FORMAT SPECIFIERS ===\n\n" RESET);
	test_percent("Just percent without flags", "%");
	// Note: This might cause undefined behavior, test carefully

	// Extreme values
	printf(GREEN "=== EXTREME VALUES ===\n\n" RESET);
	test_int("Maximum positive int", "%d", 2147483647);
	test_int("Minimum negative int", "%d", -2147483648);
	test_int("Maximum unsigned", "%u", 4294967295U);
	test_int("Zero unsigned", "%u", 0U);
	test_int("Large hex value", "%x", 0xFFFFFFFF);
	test_int("Large hex value uppercase", "%X", 0xFFFFFFFF);

	// Special characters in strings
	printf(GREEN "=== SPECIAL CHARACTERS ===\n\n" RESET);
	test_string("String with newlines", "%s", "Line1\nLine2\nLine3");
	test_string("String with tabs", "%s", "Col1\tCol2\tCol3");
	test_string("String with special chars", "%s", "Special: !@#$%^&*()");
	test_char("Newline character", "%c", '\n');
	test_char("Tab character", "%c", '\t');
	test_char("Carriage return", "%c", '\r');

	// Precision with hexadecimal
	printf(GREEN "=== PRECISION WITH HEXADECIMAL ===\n\n" RESET);
	test_int("Hex with precision", "%.5x", 42);
	test_int("Hex uppercase with precision", "%.5X", 42);
	test_int("Hex with zero precision", "%.0x", 42);
	test_int("Hex zero value with precision", "%.5x", 0);
	test_int("Hex # flag with precision", "%#.5x", 42);
	test_int("Hex # flag zero value with precision", "%#.0x", 0);

	// Complex flag combinations
	printf(GREEN "=== COMPLEX FLAG COMBINATIONS ===\n\n" RESET);
	test_int("All flags combined positive", "%+- #020.10d", 42);
	test_int("All flags combined negative", "%+- #020.10d", -42);
	test_int("Hex with all applicable flags", "%+- #020.10x", 42);
	test_string("String with all applicable flags", "%- 20.10s", "Hello");

	// Memory and performance tests
	printf(GREEN "=== MEMORY AND PERFORMANCE TESTS ===\n\n" RESET);
	test_string("Very long string", "%s", "This is a very long string that should test the memory allocation and performance of ft_printf when dealing with large amounts of text data that might stress the implementation");
	test_string("Long string with precision", "%.50s", "This is a very long string that should test the memory allocation and performance of ft_printf when dealing with large amounts of text data that might stress the implementation");
	test_multiple_5("Multiple large conversions", "%d %d %d %d %d", 2147483647, (int)-2147483648, 1234567890, -987654321, 555666777);

	// Edge cases that might cause undefined behavior (test carefully)
	printf(GREEN "=== POTENTIAL EDGE CASES (TEST CAREFULLY) ===\n\n" RESET);
	test_percent("Double percent", "%%%%");
	test_string("Percent in string", "%s", "This string contains %% characters");

	// Boundary tests for width and precision
	printf(GREEN "=== BOUNDARY TESTS ===\n\n" RESET);
	test_int("Width 1", "%1d", 42);
	test_int("Precision 1", "%.1d", 42);
	test_string("String precision 1", "%.1s", "Hello");
	test_int("Width equals content", "%2d", 42);
	test_string("Width equals string length", "%5s", "Hello");

	// Summary
	printf(CYAN "========================================\n");
	printf("              SUMMARY\n");
	printf("========================================\n" RESET);

	// ADDITIONAL COMPREHENSIVE TESTS SUGGESTED
	printf(GREEN "=== ADDITIONAL EDGE CASES TESTS ===\n\n" RESET);

	// Tests for numeric edge cases
	test_int("Binary boundary INT_MAX", "%d", 2147483647);
	test_int("Binary boundary INT_MIN", "%d", -2147483648);
	test_int("Power of 2 values", "%d", 1024);
	test_int("Power of 2 values negative", "%d", -1024);

	// Zero with different formatters
	test_int("Zero with # flag and hex", "%#x", 0);
	test_int("Zero with # flag and HEX", "%#X", 0);
	test_int("Zero with + flag", "%+d", 0);
	test_int("Zero with space flag", "% d", 0);
	test_int("Zero with width and +", "%+5d", 0);
	test_int("Zero with width and space", "% 5d", 0);

	// Tests for flag interaction edge cases
	test_int("Zero padding vs left align", "%-05d", 42);  // left align should override zero padding
	test_int("Zero padding vs left align negative", "%-05d", -42);
	test_int("Plus and space flags together", "%+ d", 42);  // plus should take precedence
	test_int("All flags with zero", "%#+-010.5d", 0);

	// String edge cases
	test_string("Very long string with small width", "%5s", "This is a very long string that exceeds the width");
	test_string("String with precision larger than length", "%.50s", "Short");
	test_string("Empty string with precision", "%.5s", "");
	test_string("Empty string with width", "%10s", "");

	// Character edge cases
	test_char("Space character", "%c", ' ');
	test_char("Character with very large width", "%50c", 'X');
	test_char("Character with flags (should ignore most)", "%+#- 05c", 'Y');

	// Pointer edge cases
	void *null_ptr = NULL;
	void *high_addr = (void *)0xFFFFFFFF;
	test_ptr("High address pointer", "%p", high_addr);
	test_ptr("Null pointer with width", "%20p", null_ptr);
/* 	test_ptr("Pointer with precision (undefined but test)", "%.10p", ptr); */

	// Hexadecimal edge cases
	test_int("Hex with all F's", "%x", 0xFFFF);
	test_int("Hex with mixed case input", "%x", 0xaBcD);
	test_int("Hex # flag with various numbers", "%#x", 0x1);
	test_int("Hex # flag with various numbers uppercase", "%#X", 0x1);
	test_int("Very large precision with hex", "%.20x", 42);
	test_int("Zero padding larger than content hex", "%020x", 42);

	// Unsigned edge cases
	test_int("Unsigned max value", "%u", 4294967295U);
	test_int("Unsigned with leading zeros via precision", "%.10u", 42U);
	test_int("Unsigned zero with precision", "%.5u", 0U);

	// Width and precision interaction
	test_int("Width < precision for integers", "%5.10d", 42);
	test_int("Width = precision for integers", "%10.10d", 42);
	test_int("Width > precision for integers", "%15.10d", 42);
	test_string("Width < precision for strings", "%5.10s", "Hello World");

	// Multiple specifiers stress test
	test_multiple_8("Stress test all types", "%c|%s|%p|%d|%i|%u|%x|%X", 'Z', "test", ptr, -42, 42, 42U, 255, 255);

	// Flag precedence tests
	test_int("Multiple contradictory flags 1", "%0-10d", 42);  // left align wins over zero pad
	test_int("Multiple contradictory flags 2", "%+-10d", 42);  // plus wins over space
	test_int("Multiple contradictory flags 3", "% +010d", 42); // plus wins, left align wins

	// Format string edge cases
	test_percent("Multiple percent signs", "%%%%%%");
	test_percent("Percent at end", "Text ends with %");

	// Precision zero with various types
	test_int("Precision zero with positive", "%.0d", 123);
	test_int("Precision zero with negative", "%.0d", -123);
	test_int("Precision zero with hex", "%.0x", 123);
	test_int("Precision zero with HEX", "%.0X", 123);
	test_int("Precision zero with unsigned", "%.0u", 123U);

	// Tests with very specific values that might cause issues
	test_int("Value 1", "%d", 1);
	test_int("Value -1", "%d", -1);
	test_int("Value 10", "%d", 10);
	test_int("Value -10", "%d", -10);
	test_int("Hex value 16", "%x", 16);  // 0x10
	test_int("Hex value 255", "%x", 255); // 0xff

	// String with only special characters
	test_string("Only special chars", "%s", "\n\t\r\v\f");
	test_string("Only spaces", "%s", "     ");

	// Tests for consistency between %d and %i
	test_multiple_2("d vs i comparison", "%d equals %i", 42, 42);
	test_multiple_2("d vs i negative", "%d equals %i", -42, -42);

	// Tests específicos para el comportamiento del signo %
	printf(GREEN "=== PERCENT SIGN EDGE CASES ===\n\n" RESET);
	test_percent("Isolated percent", "%");
	test_percent("Text with percent", "Progress: 50%% complete");
	test_multiple_2("Mixed percent and format", "Value: %d (that's %d%%)", 50, 100);

	// Tests para valores límite con diferentes bases
	printf(GREEN "=== BASE CONVERSION LIMITS ===\n\n" RESET);
	test_int("Binary boundary in hex", "%x", 0x7FFFFFFF);
	test_int("Binary boundary in HEX", "%X", 0x7FFFFFFF);
	test_int("All bits set in hex", "%x", 0xFFFFFFFF);
	test_int("All bits set in HEX", "%X", 0xFFFFFFFF);

	// Tests para interacción compleja de flags
	printf(GREEN "=== COMPLEX FLAG INTERACTIONS ===\n\n" RESET);
	test_int("Zero pad vs left align precedence", "%-010d", 42);
	test_int("Plus vs space precedence", "%+ d", 42);
	test_int("All flags with negative", "%#+-010.5d", -42);
	test_int("All flags with zero", "%#+-010.5d", 0);

	// Tests para casos que podrían causar overflow en buffers
	printf(GREEN "=== BUFFER STRESS TESTS ===\n\n" RESET);
	test_int("Maximum width test", "%200d", 42);
	test_int("Maximum precision test", "%.200d", 42);
	test_string("Maximum width string", "%200s", "short");

	/* printf("Total tests: %d\n", g_test_count);
	printf("Passed: " GREEN "%d\n" RESET, g_passed);
	printf("Failed: " RED "%d\n" RESET, g_test_count - g_passed); */

	// ADDITIONAL TESTS FOR COMPREHENSIVE COVERAGE
	printf(CYAN "\n========================================\n");
	printf("   ADDITIONAL EDGE CASE TESTS\n");
	printf("========================================\n\n" RESET);

	// Tests para caracteres ASCII extremos
	printf(GREEN "=== EXTREME ASCII CHARACTER TESTS ===\n\n" RESET);
	test_char("ASCII 0 (null)", "%c", 0);
	test_char("ASCII 1", "%c", 1);
	test_char("ASCII 127 (DEL)", "%c", 127);
	test_char("Character 255", "%c", 255);

	// Tests para combinaciones de flags complejas
	printf(GREEN "=== COMPLEX FLAG COMBINATIONS ===\n\n" RESET);
	test_int("Triple flag combination", "%+-#10d", 42);
	test_int("Quad flag combination", "%+-# 10d", 42);
	test_int("Five flag combination", "%+-#0 10d", 42);
	test_int("Hex with complex flags", "%+-#020.8x", 42);
	test_int("Uppercase hex complex", "%+-#020.8X", 42);

	// Tests para valores específicos que pueden causar problemas
	printf(GREEN "=== PROBLEMATIC VALUES ===\n\n" RESET);
	test_int("Power of 2 - 1", "%d", 1023);
	test_int("Power of 2", "%d", 1024);
	test_int("Power of 2 + 1", "%d", 1025);
	test_int("Hex powers of 16", "%x", 256);
	test_int("Hex powers of 16", "%x", 4096);
	test_int("Binary significant values", "%d", 32767);
	test_int("Binary significant values", "%d", 65535);

	// Tests para strings con caracteres de control
	printf(GREEN "=== CONTROL CHARACTER STRINGS ===\n\n" RESET);
	test_string("String with bell", "%s", "Alert\a");
	test_string("String with backspace", "%s", "Back\bspace");
	test_string("String with form feed", "%s", "Form\ffeed");
	test_string("String with vertical tab", "%s", "Vert\vtab");

	// Tests para casos donde precision > width significativamente
	printf(GREEN "=== PRECISION VS WIDTH EXTREMES ===\n\n" RESET);
	test_int("Precision much larger than width", "%5.20d", 42);
	test_int("Width much larger than precision", "%20.5d", 42);
	test_string("String precision vs width", "%5.20s", "Hello");
	test_string("String width vs precision", "%20.5s", "Hello World Extended");

	// Tests para números con patrones específicos
	printf(GREEN "=== SPECIFIC NUMBER PATTERNS ===\n\n" RESET);
	test_int("All ones in binary", "%d", 1111);
	test_int("Alternating pattern", "%d", 1010);
	test_int("Hex nice patterns", "%x", 0x1234);
	test_int("Hex nice patterns upper", "%X", 0xABCD);
	test_int("Palindromic number", "%d", 12321);

	// Tests para múltiples argumentos con tipos mezclados
	printf(GREEN "=== COMPLEX MULTI-ARGUMENT TESTS ===\n\n" RESET);
	test_multiple_8("All types mixed max args", "%c%s%p%d%i%u%x%X", 'M', "str", ptr, -1, 2, 3U, 4, 5);
	test_multiple_4("Flags mixed types", "%+d%#x%-10s%5c", -42, 255, "test", 'A');
	test_multiple_3("Precision mixed", "%.3d%.5s%.2x", 123, "hello", 255);

	// Tests para casos donde los flags no deberían tener efecto
	printf(GREEN "=== FLAGS WITH NO EFFECT VALIDATION ===\n\n" RESET);
	test_char("All flags with char", "%+-#0 5c", 'X');
	test_string("Numeric flags with string", "%+#010.5s", "test");
	test_ptr("Numeric flags with pointer", "%+#010p", ptr);

	// Tests para manejo de memoria extremo
	printf(GREEN "=== MEMORY STRESS TESTS ===\n\n" RESET);
	test_string("Very wide format", "%500s", "short");
	test_int("Very wide number", "%500d", 42);
	test_int("Very high precision", "%.500d", 42);

	// Tests específicos para el símbolo %
	printf(GREEN "=== PERCENT SYMBOL EDGE CASES ===\n\n" RESET);
	test_percent("Percent with width and left align", "%-10%");
	test_percent("Percent with zero padding", "%010%");
	test_percent("Multiple percents in sequence", "%%%%%%%%");

	// Tests para verificar la robustez del parser
	printf(GREEN "=== PARSER ROBUSTNESS TESTS ===\n\n" RESET);
	test_int("Format with many digits", "%00000000000010d", 42);
	test_int("Format with leading zeros", "%010.05d", 42);
	test_string("Complex string format", "%030.15s", "test string");

	// Tests para casos límite de hex con # flag
	printf(GREEN "=== HEX # FLAG EDGE CASES ===\n\n" RESET);
	test_int("# flag with hex 1", "%#x", 1);
	test_int("# flag with hex small", "%#x", 0xf);
	test_int("# flag with hex medium", "%#x", 0xff);
	test_int("# flag with hex large", "%#x", 0xfff);

	// Tests para verificar comportamiento con valores negativos en unsigned
	printf(GREEN "=== UNSIGNED WITH NEGATIVE INPUTS ===\n\n" RESET);
	test_int("Negative as unsigned", "%u", -1);
	test_int("Negative as hex", "%x", -1);
	test_int("Negative as HEX", "%X", -1);
	test_int("Negative with # flag hex", "%#x", -1);

	// Tests finales para consistencia
	printf(GREEN "=== CONSISTENCY VERIFICATION ===\n\n" RESET);
	test_multiple_2("Same value different formats", "%d vs %i", 42, 42);
	test_multiple_2("Same value hex formats", "%x vs %X", 255, 255);
	test_multiple_3("Flags consistency", "%+d % d %d", 42, 42, 42);

	printf(CYAN "\n========================================\n");
	printf("       FINAL COMPREHENSIVE SUMMARY\n");
	printf("========================================\n" RESET);
	printf("Total tests executed: %d\n", g_test_count);
	printf("Tests passed: " GREEN "%d" RESET "\n", g_passed);
	printf("Tests failed: " RED "%d" RESET "\n", g_test_count - g_passed);
	printf("Success rate: %.2f%%\n", (float)g_passed / g_test_count * 100);

	if (g_passed == g_test_count)
		printf(GREEN "\n🎉 PERFECT SCORE! ALL TESTS PASSED! 🎉\n" RESET);
	else
		printf(RED "\n❌ Some tests need attention. Review failed cases above.\n" RESET);

	return (0);
}
