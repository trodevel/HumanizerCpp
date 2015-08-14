#include <iostream>     // std::cout

#include "EnglishNumberToWordsConverter.h"  // EnglishNumberToWordsConverter

using namespace Humanizer::Localisation::NumberToWords;


void test_kern( int number, const std::string & loc, const std::string & expected, bool is_ordinary )
{
    EnglishNumberToWordsConverter e;

    std::string res = e.Convert( number );

    if( res == expected )
        std::cout << "number " << number << " - PASSED" << std::endl;
    else
        std::cout << "number " << number << " got " << res << ", expected " << expected << " - FAILED" << std::endl;
}

void test( int number, const std::string & expected )
{
    test_kern( number, "en-US", expected, false );
}

void test( int number, const std::string & loc, const std::string & expected )
{
    test_kern( number, loc, expected, false );
}

void test_ord( int number, const std::string & expected )
{
    test_kern( number, "en-US", expected, true );
}

void test_ord( int number, const std::string & loc, const std::string & expected )
{
    test_kern( number, loc, expected, true );
}

int main()
{
    test( 1, "one" );
    test( 10, "ten" );
    test( 11, "eleven" );
    test( 20, "twenty" );
    test( 122, "one hundred and twenty-two" );
    test( 3501, "three thousand five hundred and one" );
    test( 100, "one hundred" );
    test( 1000, "one thousand" );
    test( 100000, "one hundred thousand" );
    test( 1000000, "one million" );
    test( 10000000, "ten million" );
    test( 100000000, "one hundred million" );
    test( 1000000000, "one billion" );
    test( 111, "one hundred and eleven" );
    test( 1111, "one thousand one hundred and eleven" );
    test( 111111, "one hundred and eleven thousand one hundred and eleven" );
    test( 1111111, "one million one hundred and eleven thousand one hundred and eleven" );
    test( 11111111, "eleven million one hundred and eleven thousand one hundred and eleven" );
    test( 111111111, "one hundred and eleven million one hundred and eleven thousand one hundred and eleven" );
    test( 1111111111, "one billion one hundred and eleven million one hundred and eleven thousand one hundred and eleven" );
    test( 123, "one hundred and twenty-three" );
    test( 1234, "one thousand two hundred and thirty-four" );
    test( 12345, "twelve thousand three hundred and forty-five" );
    test( 123456, "one hundred and twenty-three thousand four hundred and fifty-six" );
    test( 1234567, "one million two hundred and thirty-four thousand five hundred and sixty-seven" );
    test( 12345678, "twelve million three hundred and forty-five thousand six hundred and seventy-eight" );
    test( 123456789, "one hundred and twenty-three million four hundred and fifty-six thousand seven hundred and eighty-nine" );
    test( 1234567890, "one billion two hundred and thirty-four million five hundred and sixty-seven thousand eight hundred and ninety" );

    test_ord( 0, "zeroth" );
    test_ord( 1, "first" );
    test_ord( 2, "second" );
    test_ord( 3, "third" );
    test_ord( 4, "fourth" );
    test_ord( 5, "fifth" );
    test_ord( 6, "sixth" );
    test_ord( 7, "seventh" );
    test_ord( 8, "eighth" );
    test_ord( 9, "ninth" );
    test_ord( 10, "tenth" );
    test_ord( 11, "eleventh" );
    test_ord( 12, "twelfth" );
    test_ord( 13, "thirteenth" );
    test_ord( 14, "fourteenth" );
    test_ord( 15, "fifteenth" );
    test_ord( 16, "sixteenth" );
    test_ord( 17, "seventeenth" );
    test_ord( 18, "eighteenth" );
    test_ord( 19, "nineteenth" );
    test_ord( 20, "twentieth" );
    test_ord( 21, "twenty-first" );
    test_ord( 22, "twenty-second" );
    test_ord( 30, "thirtieth" );
    test_ord( 40, "fortieth" );
    test_ord( 50, "fiftieth" );
    test_ord( 60, "sixtieth" );
    test_ord( 70, "seventieth" );
    test_ord( 80, "eightieth" );
    test_ord( 90, "ninetieth" );
    test_ord( 95, "ninety-fifth" );
    test_ord( 96, "ninety-sixth" );
    test_ord( 100, "hundredth" );
    test_ord( 112, "hundred and twelfth" );
    test_ord( 120, "hundred and twentieth" );
    test_ord( 121, "hundred and twenty-first" );
    test_ord( 1000, "thousandth" );
    test_ord( 1001, "thousand and first" );
    test_ord( 1021, "thousand and twenty-first" );
    test_ord( 10000, "ten thousandth" );
    test_ord( 10121, "ten thousand one hundred and twenty-first" );
    test_ord( 100000, "hundred thousandth" );
    test_ord( 1000000, "millionth" );


    test( 11, "en-US", "eleven" );
    test( 22, "ar", "اثنان و عشرون" );
    test( 40, "ru", "сорок" );

    test_ord( 1021, "en-US", "thousand and twenty-first" );
    test_ord( 21, "ar", "الحادي و العشرون" );
    test_ord( 1112, "ru", "одна тысяча сто двенадцатый" );

    return 0;
}
