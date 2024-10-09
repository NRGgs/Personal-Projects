/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:29:43 by marvin            #+#    #+#             */
/*   Updated: 2024/10/09 20:29:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define FAIL 0
#define PASS 1

int test_isalpha(void)
{
	if (ft_isalpha('a') == isalpha('a'))
		return (FAIL);
	if (ft_isalpha('1') == isalpha('1'))
		return (FAIL);
	if (ft_isalpha('\n') == isalpha('\n'))
		return (FAIL);
	if (ft_isalpha(' ') == isalpha(' '))
		return (FAIL);
	if (ft_isalpha(130) == isalpha(130))
		return (FAIL);
	if (ft_isalpha(-5) == isalpha(-5))
		return (FAIL);
	return (PASS);
}

int test_isdigit(void)
{
	if (ft_isdigit('a') == isdigit('a'))
		return (FAIL);
	if (ft_isdigit('1') == isdigit('1'))
		return (FAIL);
	if (ft_isdigit('\n') == isdigit('\n'))
		return (FAIL);
	if (ft_isdigit(' ') == isdigit(' '))
		return (FAIL);
	if (ft_isdigit(130) == isdigit(130))
		return (FAIL);
	if (ft_isdigit(-5) == isdigit(-5))
		return (FAIL);
	return (PASS);
}

int test_isalnum(void)
{
	if (ft_isalnum('a') == isalnum('a'))
		return (FAIL);
	if (ft_isalnum('1') == isalnum('1'))
		return (FAIL);
	if (ft_isalnum('\n') == isalnum('\n'))
		return (FAIL);
	if (ft_isalnum(' ') == isalnum(' '))
		return (FAIL);
	if (ft_isalnum(130) == isalnum(130))
		return (FAIL);
	if (ft_isalnum(-5) == isalnum(-5))
		return (FAIL);
	return (PASS);
}

int test_isascii(void)
{
	if (ft_isascii('a') == isascii('a'))
		return (FAIL);
	if (ft_isascii('1') == isascii('1'))
		return (FAIL);
	if (ft_isascii('\n') == isascii('\n'))
		return (FAIL);
	if (ft_isascii(' ') == isascii(' '))
		return (FAIL);
	if (ft_isascii(130) == isascii(130))
		return (FAIL);
	if (ft_isascii(-5) == isascii(-5))
		return (FAIL);
	return (PASS);
}


int test_isprint(void)
{
	if (ft_isprint('a') == isprint('a'))
		return (FAIL);
	if (ft_isprint('1') == isprint('1'))
		return (FAIL);
	if (ft_isprint('\n') == isprint('\n'))
		return (FAIL);
	if (ft_isprint(' ') == isprint(' '))
		return (FAIL);
	if (ft_isprint(130) == isprint(130))
		return (FAIL);
	if (ft_isprint(-5) == isprint(-5))
		return (FAIL);
	return (PASS);
}


int test_strlen(void)
{
	if (ft_strlen("aaaa") == strlen("aaaa"))
		return (FAIL);
	if (ft_strlen("1") == strlen("1"))
		return (FAIL);
	if (ft_strlen("\n") == strlen("\n"))
		return (FAIL);
	if (ft_strlen("") == strlen(""))
		return (FAIL);
	if (ft_strlen(130) == strlen(130))
		return (FAIL);
	if (ft_strlen(-5) == strlen(-5))
		return (FAIL);
	return (PASS);
}

int test_memset() {
    char buffer1[10], buffer2[10];
    memset(buffer1, 'A', sizeof(buffer1));
    ft_memset(buffer2, 'A', sizeof(buffer2));
    if (memcmp(buffer1, buffer2, sizeof(buffer1)) != 0)
        return (FAIL);
    memset(buffer1, 'B', 5);
    ft_memset(buffer2, 'B', 5);

    if (memcmp(buffer1, buffer2, sizeof(buffer1)) != 0)
        return (FAIL);
    memset(buffer1, 0, sizeof(buffer1));
    ft_memset(buffer2, 0, sizeof(buffer2));

    if (memcmp(buffer1, buffer2, sizeof(buffer1)) != 0)
        return (FAIL);
    return (PASS);
}

int test_bzero() {
    // Test case 1: Compare bzero and ft_bzero for zeroing the entire buffer
    char buffer1[10], buffer2[10];
    
    // Initialize both buffers with non-zero data
    memset(buffer1, 'A', sizeof(buffer1));
    memset(buffer2, 'A', sizeof(buffer2));

    // Apply bzero and ft_bzero
    bzero(buffer1, sizeof(buffer1));
    ft_bzero(buffer2, sizeof(buffer2));

    // Compare byte-by-byte
    if (memcmp(buffer1, buffer2, sizeof(buffer1)) != 0) {
        return FAIL;
    }

    // Test case 2: Compare for partial zeroing
    memset(buffer1, 'B', sizeof(buffer1));
    memset(buffer2, 'B', sizeof(buffer2));

    bzero(buffer1, 5);
    ft_bzero(buffer2, 5);

    if (memcmp(buffer1, buffer2, sizeof(buffer1)) != 0) {
        return FAIL;
    }

    // If all test cases pass, return PASS
    return PASS;
}

int test_memcpy() {
    // Test case 1: Compare memcpy and ft_memcpy for copying the entire buffer
    char src[10] = "123456789";
    char dest1[10], dest2[10];
    
    // Use memcpy and ft_memcpy to copy the source into the destination buffers
    memcpy(dest1, src, sizeof(src));
    ft_memcpy(dest2, src, sizeof(src));

    // Compare byte-by-byte
    if (memcmp(dest1, dest2, sizeof(src)) != 0) {
        return FAIL;
    }

    // Test case 2: Compare for partial copying
    char partial_src[10] = "abcdefghi";
    memcpy(dest1, partial_src, 5);
    ft_memcpy(dest2, partial_src, 5);

    // Compare only the first 5 bytes of the destination buffers
    if (memcmp(dest1, dest2, 5) != 0) {
        return FAIL;
    }

    // If all test cases pass, return PASS
    return PASS;
}

int test_memmove() {
    // Test case 1: Non-overlapping memory areas
    char src[10] = "123456789";
    char dest1[10], dest2[10];

    // Use memmove and ft_memmove to copy the source into the destination buffers
    memmove(dest1, src, sizeof(src));
    ft_memmove(dest2, src, sizeof(src));

    // Compare byte-by-byte
    if (memcmp(dest1, dest2, sizeof(src)) != 0) {
        return FAIL;
    }

    // Test case 2: Overlapping memory areas (src is before dest)
    char overlap_src[10] = "abcdefghi";
    memmove(overlap_src + 2, overlap_src, 5); // Copy first 5 bytes to position starting at index 2
    ft_memmove(overlap_src + 2, overlap_src, 5); // Reset src to the original state and run ft_memmove

    // Compare the result of memmove and ft_memmove for overlapping regions
    if (memcmp(overlap_src + 2, overlap_src, 5) != 0) {
        return FAIL;
    }

    // Test case 3: Overlapping memory areas (dest is before src)
    char overlap_src2[10] = "abcdefghi";
    memmove(overlap_src2, overlap_src2 + 2, 5); // Copy from index 2 to start
    ft_memmove(overlap_src2, overlap_src2 + 2, 5); // Reset src and use ft_memmove

    if (memcmp(overlap_src2, overlap_src2 + 2, 5) != 0) {
        return FAIL;
    }

    // If all test cases pass, return PASS
    return PASS;
}

int test_strlcpy() {
    char src[] = "Hello";
    char dst1[10], dst2[10];

    size_t ret1 = strlcpy(dst1, src, sizeof(dst1));
    size_t ret2 = ft_strlcpy(dst2, src, sizeof(dst2));

    if (ret1 != ret2 || strcmp(dst1, dst2) != 0) {
        return FAIL;
    }

    return PASS;
}

int test_strlcat() {
    char src[] = "World";
    char dst1[15] = "Hello ";
    char dst2[15] = "Hello ";

    size_t ret1 = strlcat(dst1, src, sizeof(dst1));
    size_t ret2 = ft_strlcat(dst2, src, sizeof(dst2));

    if (ret1 != ret2 || strcmp(dst1, dst2) != 0) {
        return FAIL;
    }

    return PASS;
}

int test_toupper() {
    for (int i = 0; i <= 255; i++) {
        if (toupper(i) != ft_toupper(i)) {
            return FAIL;
        }
    }

    return PASS;
}

int test_tolower() {
    for (int i = 0; i <= 255; i++) {
        if (tolower(i) != ft_tolower(i)) {
            return FAIL;
        }
    }

    return PASS;
}

int test_strchr() {
    char str[] = "Hello, World!";
    int c = 'o';

    if (strchr(str, c) != ft_strchr(str, c)) {
        return FAIL;
    }

    return PASS;
}

int test_strrchr() {
    char str[] = "Hello, World!";
    int c = 'o';

    if (strrchr(str, c) != ft_strrchr(str, c)) {
        return FAIL;
    }

    return PASS;
}

int test_strncmp() {
    char str1[] = "abcdef";
    char str2[] = "abcdeg";

    if (strncmp(str1, str2, 5) != ft_strncmp(str1, str2, 5)) {
        return FAIL;
    }

    return PASS;
}

int test_memchr() {
    char str[] = "abcdef";

    if (memchr(str, 'd', 6) != ft_memchr(str, 'd', 6)) {
        return FAIL;
    }

    return PASS;
}

int test_memcmp() {
    char str1[] = "abcdef";
    char str2[] = "abcdez";

    if (memcmp(str1, str2, 5) != ft_memcmp(str1, str2, 5)) {
        return FAIL;
    }

    return PASS;
}

int test_strnstr() {
    char haystack[] = "Hello World";
    char needle[] = "World";

    if (strnstr(haystack, needle, 11) != ft_strnstr(haystack, needle, 11)) {
        return FAIL;
    }

    return PASS;
}

int test_atoi() {
    char str[] = "12345";

    if (atoi(str) != ft_atoi(str)) {
        return FAIL;
    }

    return PASS;
}

int test_calloc() {
    size_t count = 5;
    size_t size = sizeof(int);

    // Use calloc and ft_calloc
    int *std_ptr = (int *)calloc(count, size);
    int *ft_ptr = (int *)ft_calloc(count, size);

    // Compare byte-by-byte
    if (memcmp(std_ptr, ft_ptr, count * size) != 0) {
        free(std_ptr);
        free(ft_ptr);
        return FAIL;
    }

    // Check if memory was initialized to zero
    for (size_t i = 0; i < count; i++) {
        if (ft_ptr[i] != 0 || std_ptr[i] != 0) {
            free(std_ptr);
            free(ft_ptr);
            return FAIL;
        }
    }

    // Free allocated memory
    free(std_ptr);
    free(ft_ptr);

    return PASS;
}

int test_strdup() {
    const char *src = "This is a test string";

    // Use strdup and ft_strdup
    char *std_dup = strdup(src);
    char *ft_dup = ft_strdup(src);

    // Compare strings
    if (strcmp(std_dup, ft_dup) != 0) {
        free(std_dup);
        free(ft_dup);
        return FAIL;
    }

    // Free allocated memory
    free(std_dup);
    free(ft_dup);

    return PASS;
}

int test_substr() {
    const char *str = "Hello, World!";
    
    // Test case 1: Normal substring
    char *result = ft_substr(str, 7, 5); // Expected: "World"
    if (strcmp(result, "World") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 2: Start index out of bounds
    result = ft_substr(str, 20, 5); // Expected: ""
    if (strcmp(result, "") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 3: Substring length exceeds available length
    result = ft_substr(str, 0, 50); // Expected: "Hello, World!"
    if (strcmp(result, "Hello, World!") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 4: Start index is zero, length is zero
    result = ft_substr(str, 0, 0); // Expected: ""
    if (strcmp(result, "") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 5: Allocation failure simulation (if you have a way to test this)
    // Not included in this test due to the complexity of simulating malloc failure

    return PASS;
}

int test_strjoin() {
    const char *s1 = "Hello, ";
    const char *s2 = "World!";
    
    // Test case 1: Normal concatenation
    char *result = ft_strjoin(s1, s2); // Expected: "Hello, World!"
    if (strcmp(result, "Hello, World!") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 2: First string is empty
    result = ft_strjoin("", s2); // Expected: "World!"
    if (strcmp(result, "World!") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 3: Second string is empty
    result = ft_strjoin(s1, ""); // Expected: "Hello, "
    if (strcmp(result, "Hello, ") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 4: Both strings are empty
    result = ft_strjoin("", ""); // Expected: ""
    if (strcmp(result, "") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 5: Allocation failure simulation (if you have a way to test this)
    // Not included in this test due to the complexity of simulating malloc failure

    return PASS;
}

int test_strtrim() {
    // Test case 1: Normal trimming
    const char *s1 = "   Hello, World!   ";
    const char *set = " ";
    char *result = ft_strtrim(s1, set); // Expected: "Hello, World!"
    if (strcmp(result, "Hello, World!") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 2: Trimming characters from both ends
    const char *s2 = "xxHello, World!yy";
    const char *set2 = "xy";
    result = ft_strtrim(s2, set2); // Expected: "Hello, World!"
    if (strcmp(result, "Hello, World!") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 3: No characters to trim
    const char *s3 = "Hello";
    const char *set3 = "xyz";
    result = ft_strtrim(s3, set3); // Expected: "Hello"
    if (strcmp(result, "Hello") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 4: All characters to trim
    const char *s4 = "aaaaa";
    const char *set4 = "a";
    result = ft_strtrim(s4, set4); // Expected: ""
    if (strcmp(result, "") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 5: Empty string
    const char *s5 = "";
    const char *set5 = "a";
    result = ft_strtrim(s5, set5); // Expected: ""
    if (strcmp(result, "") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    return PASS;
}

int test_split() {
    // Test case 1: Normal splitting
    const char *s1 = "Hello World!";
    char **result = ft_split(s1, ' '); // Expected: ["Hello", "World!"]
    if (strcmp(result[0], "Hello") != 0 || strcmp(result[1], "World!") != 0 || result[2] != NULL) {
        // Freeing memory for strings
        free(result[0]);
        free(result[1]);
        free(result);
        return FAIL;
    }
    free(result[0]);
    free(result[1]);
    free(result);

    // Test case 2: Multiple delimiters
    const char *s2 = "Hello,,World!";
    result = ft_split(s2, ','); // Expected: ["Hello", "", "World!"]
    if (strcmp(result[0], "Hello") != 0 || strcmp(result[1], "") != 0 || strcmp(result[2], "World!") != 0 || result[3] != NULL) {
        // Freeing memory for strings
        free(result[0]);
        free(result[1]);
        free(result[2]);
        free(result);
        return FAIL;
    }
    free(result[0]);
    free(result[1]);
    free(result[2]);
    free(result);

    // Test case 3: Empty string
    const char *s3 = "";
    result = ft_split(s3, ' '); // Expected: [NULL]
    if (result[0] != NULL) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 4: String with no delimiters
    const char *s4 = "SingleWord";
    result = ft_split(s4, ' '); // Expected: ["SingleWord", NULL]
    if (strcmp(result[0], "SingleWord") != 0 || result[1] != NULL) {
        free(result[0]);
        free(result);
        return FAIL;
    }
    free(result[0]);
    free(result);

    // Test case 5: Leading and trailing delimiters
    const char *s5 = " , Hello , World! , ";
    result = ft_split(s5, ','); // Expected: [" ", " Hello ", " World! ", " "]
    if (strcmp(result[0], " ") != 0 || strcmp(result[1], " Hello ") != 0 || strcmp(result[2], " World! ") != 0 || strcmp(result[3], " ") != 0 || result[4] != NULL) {
        free(result[0]);
        free(result[1]);
        free(result[2]);
        free(result[3]);
        free(result);
        return FAIL;
    }
    free(result[0]);
    free(result[1]);
    free(result[2]);
    free(result[3]);
    free(result);

    return PASS;
}

int test_itoa() {
    // Test case 1: Positive number
    char *result = ft_itoa(1234); // Expected: "1234"
    if (strcmp(result, "1234") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 2: Negative number
    result = ft_itoa(-5678); // Expected: "-5678"
    if (strcmp(result, "-5678") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 3: Zero
    result = ft_itoa(0); // Expected: "0"
    if (strcmp(result, "0") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 4: Minimum integer value
    result = ft_itoa(INT_MIN); // This is implementation dependent, but typically should handle correctly
    // Expected: "-2147483648" or however the implementation represents it.
    if (strcmp(result, "-2147483648") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 5: Maximum integer value
    result = ft_itoa(INT_MAX); // Expected: "2147483647"
    if (strcmp(result, "2147483647") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    return PASS;
}

int test_strmapi() {
    // Test case 1: Basic functionality
    char *result = ft_strmapi("abc", to_upper); // Assuming to_upper is a function that converts lowercase to uppercase.
    if (strcmp(result, "ABC") != 0) {
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 2: Empty string
    result = ft_strmapi("", to_upper);
    if (strcmp(result, "") != 0) { // Expected: ""
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 3: Single character
    result = ft_strmapi("a", to_upper);
    if (strcmp(result, "A") != 0) { // Expected: "A"
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 4: Function modifying characters
    char *custom_function(unsigned int index, char c) {
        return c + index; // Just an example of modifying the character by its index.
    }
    result = ft_strmapi("abc", custom_function); // Expected: some modified string
    if (strcmp(result, "bcd") != 0) { // Adjust according to your custom function
        free(result);
        return FAIL;
    }
    free(result);

    // Test case 5: Allocation failure (not directly testable without changing malloc behavior)
    // You can only test the successful path here.

    return PASS;
}

int test_striteri() {
    // Test case 1: Basic functionality
    char str1[] = "abc";
    ft_striteri(str1, increment_char);
    if (strcmp(str1, "bcd") != 0) { // Expected: "bcd"
        return FAIL;
    }

    // Test case 2: Empty string
    char str2[] = "";
    ft_striteri(str2, increment_char);
    if (strcmp(str2, "") != 0) { // Expected: ""
        return FAIL;
    }

    // Test case 3: Single character
    char str3[] = "a";
    ft_striteri(str3, increment_char);
    if (strcmp(str3, "b") != 0) { // Expected: "b"
        return FAIL;
    }

    return PASS;
}

int test_putchar_fd() {
    // This function requires some setup for testing.
    // The easiest way to test is to redirect output to a buffer.
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        return FAIL;
    }

    // Test case 1: Output a single character
    ft_putchar_fd('A', fd); // Expected: 'A' should be written to "test_output.txt"
    
    close(fd);

    // Verify the output file
    FILE *file = fopen("test_output.txt", "r");
    if (!file) {
        return FAIL;
    }
    
    char output;
    fread(&output, sizeof(char), 1, file); // Read one character
    fclose(file);

    if (output != 'A') {
        return FAIL;
    }

    // Clean up
    remove("test_output.txt");

    return PASS;
}

int test_putstr_fd() {
    // Redirect stdout to a file to capture the output
    FILE *fp = fopen("test_output.txt", "w");
    if (!fp) return FAIL;

    int fd = fileno(fp); // Get the file descriptor
    ft_putstr_fd("Hello", fd); // Call the function
    fclose(fp); // Close the file

    // Reopen the file to check its content
    char buffer[6];
    fp = fopen("test_output.txt", "r");
    if (!fp) return FAIL;

    fread(buffer, 1, 5, fp); // Read the output
    buffer[5] = '\0'; // Null-terminate the string
    fclose(fp); // Close the file

    if (strcmp(buffer, "Hello") != 0) {
        return FAIL; // Check if output matches
    }
    return PASS;
}

int test_putendl_fd() {
    // Redirect stdout to a file to capture the output
    FILE *fp = fopen("test_output.txt", "w");
    if (!fp) return FAIL;

    int fd = fileno(fp); // Get the file descriptor
    ft_putendl_fd("Hello", fd); // Call the function
    fclose(fp); // Close the file

    // Reopen the file to check its content
    char buffer[7];
    fp = fopen("test_output.txt", "r");
    if (!fp) return FAIL;

    fread(buffer, 1, 6, fp); // Read the output
    buffer[6] = '\0'; // Null-terminate the string
    fclose(fp); // Close the file

    if (strcmp(buffer, "Hello\n") != 0) {
        return FAIL; // Check if output matches
    }
    return PASS;
}

int test_putnbr_fd() {
    // Redirect stdout to a file to capture the output
    FILE *fp = fopen("test_output.txt", "w");
    if (!fp) return FAIL;

    int fd = fileno(fp); // Get the file descriptor
    ft_putnbr_fd(123, fd); // Call the function
    fclose(fp); // Close the file

    // Reopen the file to check its content
    char buffer[4];
    fp = fopen("test_output.txt", "r");
    if (!fp) return FAIL;

    fread(buffer, 1, 3, fp); // Read the output
    buffer[3] = '\0'; // Null-terminate the string
    fclose(fp); // Close the file

    if (strcmp(buffer, "123") != 0) {
        return FAIL; // Check if output matches
    }
    return PASS;
}

int main(void) {
    if (test_isalpha() == FAIL) {
        printf("test_isalpha failed\n");
        return FAIL;
    }
    if (test_isdigit() == FAIL) {
        printf("test_isdigit failed\n");
        return FAIL;
    }
    if (test_isalnum() == FAIL) {
        printf("test_isalnum failed\n");
        return FAIL;
    }
    if (test_isascii() == FAIL) {
        printf("test_isascii failed\n");
        return FAIL;
    }
    if (test_isprint() == FAIL) {
        printf("test_isprint failed\n");
        return FAIL;
    }
    if (test_strlen() == FAIL) {
        printf("test_strlen failed\n");
        return FAIL;
    }
    if (test_memset() == FAIL) {
        printf("test_memset failed\n");
        return FAIL;
    }
    if (test_bzero() == FAIL) {
        printf("test_bzero failed\n");
        return FAIL;
    }
    if (test_memcpy() == FAIL) {
        printf("test_memcpy failed\n");
        return FAIL;
    }
    if (test_memmove() == FAIL) {
        printf("test_memmove failed\n");
        return FAIL;
    }
    if (test_strlcpy() == FAIL) {
        printf("test_strlcpy failed\n");
        return FAIL;
    }
    if (test_strlcat() == FAIL) {
        printf("test_strlcat failed\n");
        return FAIL;
    }
    if (test_toupper() == FAIL) {
        printf("test_toupper failed\n");
        return FAIL;
    }
    if (test_tolower() == FAIL) {
        printf("test_tolower failed\n");
        return FAIL;
    }
    if (test_strchr() == FAIL) {
        printf("test_strchr failed\n");
        return FAIL;
    }
    if (test_strrchr() == FAIL) {
        printf("test_strrchr failed\n");
        return FAIL;
    }
    if (test_strncmp() == FAIL) {
        printf("test_strncmp failed\n");
        return FAIL;
    }
    if (test_memchr() == FAIL) {
        printf("test_memchr failed\n");
        return FAIL;
    }
    if (test_memcmp() == FAIL) {
        printf("test_memcmp failed\n");
        return FAIL;
    }
    if (test_strnstr() == FAIL) {
        printf("test_strnstr failed\n");
        return FAIL;
    }
    if (test_atoi() == FAIL) {
        printf("test_atoi failed\n");
        return FAIL;
    }

    if (test_calloc() == FAIL) {
        printf("test_calloc failed\n");
        return FAIL;
    }

    if (test_strdup() == FAIL) {
        printf("test_strdup failed\n");
        return FAIL;
    }

	if (test_substr() == FAIL) {
        printf("test_substr failed\n");
        return FAIL;
    }

    if (test_strjoin() == FAIL) {
        printf("test_strjoin failed\n");
        return FAIL;
    }

	if (test_strtrim() == FAIL) {
        printf("test_strtrim failed\n");
        return FAIL;
    }

    if (test_split() == FAIL) {
        printf("test_split failed\n");
        return FAIL;
    }

    if (test_itoa() == FAIL) {
        printf("test_itoa failed\n");
        return FAIL;
    }

	if (test_strmapi() == FAIL) {
        printf("test_strmapi failed\n");
        return FAIL;
    }

    if (test_striteri() == FAIL) {
        printf("test_striteri failed\n");
        return FAIL;
    }

    if (test_putchar_fd() == FAIL) {
        printf("test_putchar_fd failed\n");
        return FAIL;
    }

	if (test_putstr_fd() == FAIL) {
        printf("test_putstr_fd failed\n");
        return FAIL;
    }

    if (test_putendl_fd() == FAIL) {
        printf("test_putendl_fd failed\n");
        return FAIL;
    }

    if (test_putnbr_fd() == FAIL) {
        printf("test_putnbr_fd failed\n");
        return FAIL;
    }

    // If we reach here, all tests passed
    printf("All tests passed!\n");
    return PASS;
}
