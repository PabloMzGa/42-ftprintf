/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:15:00 by pablo             #+#    #+#             */
/*   Updated: 2025/06/09 09:51:32 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/include_bonus/ft_printf_bonus.h"
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
	ret1 = printf(format);
	printf("\n");
	fflush(stdout);

	// Segunda llamada a ft_printf
	printf(PURPLE "ft_printf: " RESET);
	fflush(stdout);
	ret2 = ft_printf(format);
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

void	test_multiple(const char *desc, const char *format, ...)
{
	int		ret1, ret2;
	va_list	args1, args2;

	g_test_count++;
	printf(CYAN "Test %d: %s" RESET "\n", g_test_count, desc);
	printf(YELLOW "Format: \"%s\"" RESET "\n", format);

	// Primera llamada a printf
	printf(BLUE "printf   : " RESET);
	fflush(stdout);
	va_start(args1, format);
	ret1 = vprintf(format, args1);
	va_end(args1);
	printf("\n");
	fflush(stdout);

	// Segunda llamada a ft_printf
	printf(PURPLE "ft_printf: " RESET);
	fflush(stdout);
	va_start(args2, format);
	ret2 = ft_printf(format, args2);
	va_end(args2);
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
	test_multiple("Multiple integers", "%d %d", 42, 24);
	test_multiple("Mixed types", "%c %s %d", 'A', "Hello", 42);
	test_multiple("Complex mixed", "%+d %#x %s %c", -42, 255, "test", '!');
	test_multiple("Multiple with flags", "%+10d %-15s %#08x", 42, "Hello", 255);
	test_multiple("All specifiers", "%c %s %p %d %i %u %x %X %%", 'A', "test", ptr, 42, -42, 42U, 42, 42);

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
	test_multiple("Multiple large conversions", "%d %d %d %d %d", 2147483647, -2147483648, 1234567890, -987654321, 555666777);

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
	printf("Total tests: %d\n", g_test_count);
	printf("Passed: " GREEN "%d\n" RESET, g_passed);
	printf("Failed: " RED "%d\n" RESET, g_test_count - g_passed);

	if (g_passed == g_test_count)
		printf(GREEN "🎉 ALL TESTS PASSED! 🎉\n" RESET);
	else
		printf(RED "❌ Some tests failed. Check the output above.\n" RESET);

	return (0);
}
