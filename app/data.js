 const filesToCheck = [
    "ft_isalpha.c",
    "ft_isdigit.c",
    "ft_isalnum.c",
    "ft_isascii.c",
    "ft_isprint.c",
    "ft_strlen.c",
    "ft_memset.c",
    "ft_bzero.c",
    "ft_memcpy.c",
    "ft_memmove.c",
    "ft_strlcpy.c",
    "ft_strlcat.c",
    "ft_toupper.c",
    "ft_tolower.c",
    "ft_strchr.c",
    "ft_strrchr.c",
    "ft_strncmp.c",
    "ft_memchr.c",
    "ft_memcmp.c",
    "ft_strnstr.c",
    "ft_atoi.c",
    "ft_calloc.c",
    "ft_strdup.c",
    "ft_substr.c",
    "ft_itoa.c",
    "ft_split.c",
    "ft_striteri.c",
    "ft_strmapi.c",
    "ft_strtrim.c",
    "Makefile",
    "ft_putchar_fd.c",
    "ft_putstr_fd.c",
    "ft_putendl_fd.c",
    "ft_putnbr_fd.c",
    "libft.h",
];

 const functionNames = [
    "ft_isalpha",
    "ft_isdigit",
    "ft_isalnum",
    "ft_isascii",
    "ft_isprint",
    "ft_strlen",
    "ft_memset",
    "ft_bzero",
    "ft_memcpy",
    "ft_memmove",
    "ft_strlcpy",
    "ft_strlcat",
    "ft_toupper",
    "ft_tolower",
    "ft_strchr",
    "ft_strrchr",
    "ft_strncmp",
    "ft_memchr",
    "ft_memcmp",
    "ft_strnstr",
    "ft_atoi",
    "ft_calloc",
    "ft_strdup",
    'ft_substr',
    'ft_itoa',
    'ft_split',
    'ft_striteri',
    'ft_strmapi',
    'ft_strtrim'
];

const tests_cases = [
    '"Character: %c, String: %s##end", \'A\', "Hello"',
    '"Decimal: %d, Character: %c##end", 42, \'B\'',
    '"String: %s, Integer: %i, Percent sign: %%##end", "World", 100',
    '"Hex lowercase: %x, Hex uppercase: %X, Decimal: %d##end", 255, 255, 123',
    '"Unsigned: %u, Char: %c, String: %s##end", 500, \'C\', "Text"',
    '"Decimal: %d, Integer: %i, String: %s##end", 150, -150, "Example"',
    '"Char: %c, Decimal: %d, String: %s, Hex: %x##end", \'D\', 250, "Complex", 240',
    '"Unsigned: %u, Hex Upper: %X, String: %s##end", 1000, 512, "Data"',
    '"Dec: %d, String: %s, Unsigned: %u, Hex: %x, Percent: %%##end", 42, "Mix", 300, 255',
    '"Ints: %d, %i, %u, String: %s##end", 12, -45, 300, "Testing"',
    '"Decimal: %d, String: %s, Hex Lowercase: %x##end", 1234, "MoreTest", 4321',
    '"Integer: %i, Unsigned: %u, Hex Upper: %X##end", -1234, 1234, 255',
    '"Char: %c, String: %s, Hex: %x, Extra: ---##end", \'E\', "Formatted", 1024',
    '"Unsigned: %u, Integer: %d, Char: %c##end", 999, 555, \'F\'',
    '"String: %s, Decimal: %d, Hex Upper: %X, Percent: %%##end", "Check", 256, 512',
    '"Decimal: %d, Integer: %i, Hex: %x##end", 1024, -512, 255',
    '"String: %s, Unsigned: %u, Hex Upper: %X##end", "Hello", 200, 1023',
    '"String: %s, Dec: %d, Int: %i, Hex: %x##end", "World", 999, -999, 666',
    '"Char: %c, Dec: %d, Hex Upper: %X##end", \'G\', 256, 1023',
    '"String: %s, Unsigned: %u, Hex Upper: %X, Percent: %%##end", "Complex", 500, 255',
    '"String: %s, Char: %c, Int: %i, Percent: %%##end", "Combo", \'H\', 321',
    '"Decimal: %d, Int: %i, Hex Upper: %X, String: %s##end", 2048, -2048, 512, "Values"',
    '"Char: %c, String: %s, Dec: %d, %% %% %%##end", \'I\', "Multiple", 123',
    '"Unsigned: %u, Hex Lower: %x, Hex Upper: %X##end", 12345, 678, 1024',
    '"String: %s, Dec: %d, Char: %c, Hex: %x##end", "Mix", 500, \'J\', 2048',
    '"Unsigned: %u, Hex Upper: %X, Integer: %i##end", 9999, 2048, -555',
    '"Dec: %d, Hex Upper: %X, String: %s, Char: %c##end", 1234, 5678, "Combined", \'K\'',
    '"Unsigned: %u, Hex Lower: %x, Hex Upper: %X##end", 1500, 750, 375',
    '"Char: %c, String: %s, Decimal: %d##end", \'L\', "Final", 555',
    '"Int: %i, String: %s, Hex Upper: %X, Chars: %c %c %c##end", -100, "Test", 512, \'M\', \'N\', \'O\''
];

module.exports = {functionNames , filesToCheck , tests_cases}