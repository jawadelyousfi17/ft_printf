#include <printf.h>
#include <assert.h>
#include <stdio.h>

int get_n_args(const char *s);

int main()
{
    assert(get_n_args("%c%s%p%d%i%u%x%X") == 8);
    assert(get_n_args("%c %s %p %d %i %u %x %X ") == 8);
    assert(get_n_args("%c %s %p %d %i %u ") == 6);
    assert(get_n_args("%c%s%d") == 3);
    assert(get_n_args("%c%s%d%u%p%x") == 6);
    assert(get_n_args("%s%d%i%X") == 4);
    assert(get_n_args("%c %d %s %p") == 4);
    assert(get_n_args("%% %c %s %i %u %d") == 5);
    assert(get_n_args("%%%d%%%c%%%s") == 3);
    assert(get_n_args("%p %i %x %X %u") == 5);
    assert(get_n_args("%c%c%c%c%c") == 5);
    assert(get_n_args("%d %i %u %X %x") == 5);
    assert(get_n_args("%p%s%u%d%i%c") == 6);
    assert(get_n_args("%d %d %d %d") == 4);
    assert(get_n_args("%X %x %p %i %d") == 5);
    assert(get_n_args("%s%s%s%s%s") == 5);
    assert(get_n_args("%u %d %c %i %s %p %x") == 7);
    assert(get_n_args("%c%s %i %u %d") == 5);
    assert(get_n_args("%d %d %d") == 3);
    assert(get_n_args("%s %s %p %x %X %u") == 6);
    assert(get_n_args("%c%s%p1333%d%iHowareyou world%u%x Hello %X") == 8);
    assert(get_n_args("%c %s %p Hello%dYou%i %u world%x%X!") == 8);
    assert(get_n_args("%c%sHi%d%i%u I%x%X!") == 7);
    assert(get_n_args("Char: %cStr: %sPtr: %pNum: %dIndex: %iUnsigned: %u%x%X End") == 8);
    assert(get_n_args("%c Hello%s World%p!%d Nice to meet%i you%u%x%X") == 8);
    assert(get_n_args("Let's test %c%s%p with some%d%i and%u%x%X variables") == 8);
    assert(get_n_args("%c%s%p1333%d%iHow%u%xAre%X you") == 8);
    assert(get_n_args("%c%s%d%iHey%u%x%X Let's go!") == 7);
    assert(get_n_args("Special Test %c%s%pGood%d%i%u%x%X%!!!") == 8);
    assert(get_n_args("%p%s%dHere's an example: %c%i%u%x %X!") == 8);
    assert(get_n_args("%cWelcome %sHere%p is%d the%i Test%u for%x you%X") == 8);
    assert(get_n_args("First %c%s%p Next %d%i %u Let's test%x it%X!") == 8);
    assert(get_n_args("This is a test%c%s%p%d%i%u%x%X of% parsing") == 8);
    assert(get_n_args("%c%sA tricky test%p%d%i Now%u%xTo the end%X") == 8);
    assert(get_n_args("Just testing%c some%s parameters %p%d%i%u%x With%X") == 8);
    assert(get_n_args("%c%s%pExtra 1337%d values are%i here%u%x and%X there") == 8);
    assert(get_n_args("Case with no spaces%c%s %p %d %i%u%x and%X") == 8);
    assert(get_n_args("Mixed%cString%sTesting%pNumbers%dMixed%i%u%x%XParsing") == 8);
    assert(get_n_args("A%c string%s and%p some%d%i numbers%u plus%x characters%X!") == 8);
    assert(get_n_args("%c%s%pTesting%dNo%iSpaces%u%xOn%X Purpose") == 8);
    assert(get_n_args("First %c%s%p %d%p%s%cHello%c%d Next %d%i %u%d%u Let's test%x it%X!") == 16);
    assert(get_n_args("Example%c String%sTest%pWith%dMany%p%sMore%cSymbols%cInside%dPlus%dOthers%iIncluding%uSome%d%xAnd%X!") == 15);
    assert(get_n_args("Mix%cAll%sSorts%pTogether%dAnd%p%sUse%cMore%cRandom%dCharacters%dIn%iBetween%u%d%xSymbols%X") == 15);
    assert(get_n_args("A%c%sTest%pWith%dMultiple%p%sFormats%cIncluded%cNext%dLine%d%iSeveral%u%d%xAnd%XCharacters!") == 15);
    assert(get_n_args("Complex%c Example%s With%p Multiple%d Sets%p Of%s Different%c Format%c Specifiers%dAnd%dMixing%iIt%uAll%dTogether%xFor%XComplexity!") == 15);
    assert(get_n_args("%c%s%pComplex%d Example%p With%sMultiple%c Format%c Specifiers%d On%d One%mp Line% With% More% Variables%!") == 10);
    assert(get_n_args("Testing%c%sMultiple%p Scenarios%dIn%p Different%s Ways%c Random%c Mix%d Of%dSymbols%iLike%uThis%dOne%x And%XAnother!") == 15);
    assert(get_n_args(NULL) == 0);
    assert(get_n_args("Hellod%g%e%r%t%y%%o%k%v%b%n%ù%%axxb") == 0);
    assert(get_n_args("% d % c % u % x") == 0);
    assert(get_n_args("% cd % cd % xu % ux") == 0);
    assert(get_n_args("%c") == 1);
    assert(get_n_args("%d") == 1);
    assert(get_n_args("%s") == 1);
    assert(get_n_args("%p") == 1);
    assert(get_n_args("%u") == 1);
    assert(get_n_args("%x") == 1);
    assert(get_n_args("%X") == 1);
    assert(get_n_args("%%") == 0);
    assert(get_n_args("") == 0);
    printf("☑️  OK!\n");
    return 0;
}