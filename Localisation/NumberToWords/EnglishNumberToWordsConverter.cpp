#include "EnglishNumberToWordsConverter.h"      // self

#include "../../String.h"       // System::TrimEnd

#include <vector>               // std::vector

using namespace Humanizer::Localisation::NumberToWords;
using namespace System;

const std::string EnglishNumberToWordsConverter::UnitsMap[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
const std::string EnglishNumberToWordsConverter::TensMap[] = { "zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

const std::map<int, std::string> EnglishNumberToWordsConverter::OrdinalExceptions =
{
    {1, "first"},
    {2, "second"},
    {3, "third"},
    {4, "fourth"},
    {5, "fifth"},
    {8, "eighth"},
    {9, "ninth"},
    {12, "twelfth"},
};

std::string EnglishNumberToWordsConverter::Convert(int number)
{
    return Convert(number, false);
}

std::string EnglishNumberToWordsConverter::ConvertToOrdinal(int number)
{
    return Convert(number, true);
}

std::string EnglishNumberToWordsConverter::Convert(int number, bool isOrdinal)
{
    if (number == 0)
        return GetUnitValue(0, isOrdinal);

    if (number < 0)
        return "minus " + Convert(-number);

    std::vector<std::string> parts;

    if ((number / 1000000000) > 0)
    {
        parts.push_back( Convert(number / 1000000000) + " billion" );
        number %= 1000000000;
    }

    if ((number / 1000000) > 0)
    {
        parts.push_back( Convert(number / 1000000) + " million" );
        number %= 1000000;
    }

    if ((number / 1000) > 0)
    {
        parts.push_back( Convert(number / 1000) + " thousand" );
        number %= 1000;
    }

    if ((number / 100) > 0)
    {
        parts.push_back( Convert(number / 100) + " hundred" );
        number %= 100;
    }

    if (number > 0)
    {
        if (parts.size() != 0)
            parts.push_back("and");

        if (number < 20)
            parts.push_back(GetUnitValue(number, isOrdinal));
        else
        {
            auto lastPart = TensMap[number / 10];
            if ((number % 10) > 0)
                lastPart += "-" + GetUnitValue(number % 10, isOrdinal);
            else if (isOrdinal)
                lastPart = TrimEnd( lastPart, 'y' ) + "ieth";

            parts.push_back(lastPart);
        }
    }
    else if (isOrdinal)
        parts[parts.size() - 1] += "th";

    std::string toWords = Join(" ", parts);

    if (isOrdinal)
        toWords = RemoveOnePrefix(toWords);

    return toWords;
}

std::string EnglishNumberToWordsConverter::GetUnitValue(int number, bool isOrdinal)
{
    if (isOrdinal)
    {
        std::string exceptionString;
        if (ExceptionNumbersToWords(number, exceptionString))
            return exceptionString;
        else
            return UnitsMap[number] + "th";
    }
    else
        return UnitsMap[number];
}

std::string EnglishNumberToWordsConverter::RemoveOnePrefix(const std::string & toWords)
{
    // one hundred => hundredth
    if (toWords.find("one") == 0)
        return toWords.substr(4);

    return toWords;
}

bool EnglishNumberToWordsConverter::ExceptionNumbersToWords(int number, std::string & words)
{
    auto it = OrdinalExceptions.find( number );

    if( it == OrdinalExceptions.end() )
        return false;

    words = it->second;

    return true;
}
