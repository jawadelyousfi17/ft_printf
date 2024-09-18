#include <stdio.h>

int main()
{
    printf("Character: %c, String: %s##end", 'A', "Hello");
    // Test 2: Mixing %d and %c
    printf("Decimal: %d, Character: %c##end", 42, 'B');
    // Test 3: Mixing %s, %i, and %%
    printf("String: %s, Integer: %i, Percent sign: %%##end", "World", 1000);
    // Test 4: Mixing %x, %X, and %d
    printf("Hex lowercase: %x, Hex uppercase: %X, Decimal: %d##end", 255, 255, 123);
    // Test 5: Mixing %u, %c, and %s
    printf("Unsigned: %u, Char: %c, String: %s##end", 500, 'C', "Text");
    // Test 6: Mixing %d, %i, and %s
    printf("Decimal: %d, Integer: %i, String: %s##end", 150, -150, "Example");
    // Test 7: Complex combination of %c, %d, %s, %x
    printf("Char: %c, Decimal: %d, String: %s, Hex: %x##end", 'D', 250, "Complex", 2400);
    // Test 8: Combination of %u, %X, %s
    printf("Unsigned: %u, Hex Upper: %X, String: %s##end", 1000, 512, "Data");
    // Test 9: Combining %d, %s, %u, %x, %%
    printf("Dec: %d, String: %s, Unsigned: %u, Hex: %x, Percent: %%##end", 42, "Mix", 300, 255);
    // Test 10: Multiple integers and string formatting
    printf("Ints: %d, %i, %u, String: %s##end", 12, -45, 300, "Testing");
    // Test 11: More complex %d, %s, %x
    printf("Decimal: %d, String: %s, Hex Lowercase: %x##end", 1234, "MoreTest", 4321);
    // Test 12: %i, %u, %X mixed
    printf("Integer: %i, Unsigned: %u, Hex Upper: %X##end", -1234, 1234, 255);
    // Test 13: %c, %s, %x with extra characters
    printf("Char: %c, String: %s, Hex: %x, Extra: ---##end", 'E', "Formatted", 1024);
    // Test 14: Multiple unsigned, integer, and char tests
    printf("Unsigned: %u, Integer: %d, Char: %c##end", 999, 555, 'F');
    // Test 15: Complex %s, %d, %X, %% formatting
    printf("String: %s, Decimal: %d, Hex Upper: %X, Percent: %%##end", "Check", 256, 512);
    // Test 16: Multiple %d, %i, %x in one line
    printf("Decimal: %d, Integer: %i, Hex: %x##end", 1024, -512, 255);
    // Test 17: Combining %s, %u, %X, and more
    printf("String: %s, Unsigned: %u, Hex Upper: %X##end", "Hello", 200, 1023);
    // Test 18: Mixing %s, %d, %i, %x in complex formatting
    printf("String: %s, Dec: %d, Int: %i, Hex: %x##end", "World", 999, -999, 666);
    // Test 19: Mixing %c, %d, and %X
    printf("Char: %c, Dec: %d, Hex Upper: %X##end", 'G', 256, 1023);
    // Test 20: Mixing %s, %u, %X, %%
    printf("String: %s, Unsigned: %u, Hex Upper: %X, Percent: %%##end", "Complex", 500, 255);
    // Test 21: Complex %s, %c, %i, and %
    printf("String: %s, Char: %c, Int: %i, Percent: %%##end", "Combo", 'H', 321);
    // Test 22: Multiple %d, %i, %X, and %s
    printf("Decimal: %d, Int: %i, Hex Upper: %X, String: %s##end", 2048, -2048, 512, "Values");
    // Test 23: %c, %s, %d, and multiple %% signs
    printf("Char: %c, String: %s, Dec: %d, %% %% %%##end", 'I', "Multiple", 123);
    // Test 24: %u, %x, %X, and text
    printf("Unsigned: %u, Hex Lower: %x, Hex Upper: %X##end", 12345, 678, 1024);
    // Test 25: Combining %s, %d, %c, and hex
    printf("String: %s, Dec: %d, Char: %c, Hex: %x##end", "Mix", 500, 'J', 2048);
    // Test 26: %u, %X, %i, and more mixed
    printf("Unsigned: %u, Hex Upper: %X, Integer: %i##end", 9999, 2048, -555);
    // Test 27: Mixing %d, %X, %s, and char
    printf("Dec: %d, Hex Upper: %X, String: %s, Char: %c##end", 1234, 5678, "Combined", 'K');
    // Test 28: Complex %u, %x, %X, and text
    printf("Unsigned: %u, Hex Lower: %x, Hex Upper: %X##end", 1500, 750, 375);
    // Test 29: Mixing %c, %s, and %d
    printf("Char: %c, String: %s, Decimal: %d##end", 'L', "Final", 555);
    // Test 30: Complex %i, %s, %X, and multiple chars
    printf("Int: %i, String: %s, Hex Upper: %X, Chars: %c %c %c##end", -100, "Test", 512, 'M', 'N', 'O');
}