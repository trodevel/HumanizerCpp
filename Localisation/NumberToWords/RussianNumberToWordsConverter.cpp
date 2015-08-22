// automatically converted from C# to C++ by convert_cs_to_cpp.sh ver. 1.1

#include <stdexcept>    // std::out_of_range

#include "RussianNumberToWordsConverter.h"                          // self
#include "../GrammaticalNumber/RussianGrammaticalNumberDetector.h"  // RussianGrammaticalNumberDetector
#include "../../String.h"       // System::Join

using namespace System;
using namespace Humanizer::Localisation::NumberToWords;

typedef Humanizer::Localisation::GrammaticalNumber::RussianGrammaticalNumberDetector RussianGrammaticalNumberDetector;

const std::string RussianNumberToWordsConverter::HundredsMap[] = { "ноль", "сто", "двести", "триста", "четыреста", "пятьсот", "шестьсот", "семьсот", "восемьсот", "девятьсот" };
const std::string RussianNumberToWordsConverter::TensMap[] = { "ноль", "десять", "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто" };
const std::string RussianNumberToWordsConverter::UnitsMap[] = { "ноль", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять", "десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать" };
const std::string RussianNumberToWordsConverter::UnitsOrdinalPrefixes[] = { "", "", "двух", "трёх", "четырёх", "пяти", "шести", "семи", "восьми", "девяти", "десяти", "одиннадцати", "двенадцати", "тринадцати", "четырнадцати", "пятнадцати", "шестнадцати", "семнадцати", "восемнадцати", "девятнадцати" };
const std::string RussianNumberToWordsConverter::TensOrdinalPrefixes[] = { "", "десяти", "двадцати", "тридцати", "сорока", "пятидесяти", "шестидесяти", "семидесяти", "восьмидесяти", "девяносто" };
const std::string RussianNumberToWordsConverter::TensOrdinal[] = { "", "десят", "двадцат", "тридцат", "сороков", "пятидесят", "шестидесят", "семидесят", "восьмидесят", "девяност" };
const std::string RussianNumberToWordsConverter::UnitsOrdinal[] = { "", "перв", "втор", "трет", "четверт", "пят", "шест", "седьм", "восьм", "девят", "десят", "одиннадцат", "двенадцат", "тринадцат", "четырнадцат", "пятнадцат", "шестнадцат", "семнадцат", "восемнадцат", "девятнадцат" };

std::string RussianNumberToWordsConverter::Convert( int number, GrammaticalGender gender ) const
{
    if( number == 0 )
        return "ноль";

    std::vector<std::string> parts;

    if( number < 0 )
    {
        parts.push_back( "минус" );
        number = -number;
    }

    CollectParts( parts, number, 1000000000, GrammaticalGender::Masculine, { "миллиард", "миллиарда", "миллиардов" } );
    CollectParts( parts, number, 1000000, GrammaticalGender::Masculine, { "миллион", "миллиона", "миллионов" } );
    CollectParts( parts, number, 1000, GrammaticalGender::Feminine, { "тысяча", "тысячи", "тысяч" } );

    if( number > 0 )
        CollectPartsUnderOneThousand( parts, number, gender );

    return Join( " ", parts );
}

std::string RussianNumberToWordsConverter::ConvertToOrdinal( int number, GrammaticalGender gender ) const
{
    if( number == 0 )
        return "нулев" + GetEndingForGender( gender, number );

    std::vector<std::string> parts;

    if( number < 0 )
    {
        parts.push_back( "минус" );
        number = -number;
    }

    CollectOrdinalParts( parts, number, 1000000000, GrammaticalGender::Masculine, "миллиардн" + GetEndingForGender( gender, number ),
            { "миллиард", "миллиарда", "миллиардов" } );
    CollectOrdinalParts( parts, number, 1000000, GrammaticalGender::Masculine, "миллионн" + GetEndingForGender( gender, number ),
            { "миллион", "миллиона", "миллионов" } );
    CollectOrdinalParts( parts, number, 1000, GrammaticalGender::Feminine, "тысячн" + GetEndingForGender( gender, number ),
            { "тысяча", "тысячи", "тысяч" } );

    if( number >= 100 )
    {
        auto ending = GetEndingForGender( gender, number );
        auto hundreds = number / 100;
        number %= 100;
        if( number == 0 )
            parts.push_back( UnitsOrdinalPrefixes[hundreds] + "сот" + ending );
        else
            parts.push_back( HundredsMap[hundreds] );
    }

    if( number >= 20 )
    {
        auto ending = GetEndingForGender( gender, number );
        auto tens = number / 10;
        number %= 10;
        if( number == 0 )
            parts.push_back( TensOrdinal[tens] + ending );
        else
            parts.push_back( TensMap[tens] );
    }

    if( number > 0 )
        parts.push_back( UnitsOrdinal[number] + GetEndingForGender( gender, number ) );

    return Join( " ", parts );
}

void RussianNumberToWordsConverter::CollectPartsUnderOneThousand( std::vector<std::string> & parts, int number,
        GrammaticalGender gender )
{
    if( number >= 100 )
    {
        auto hundreds = number / 100;
        number %= 100;
        parts.push_back( HundredsMap[hundreds] );
    }

    if( number >= 20 )
    {
        auto tens = number / 10;
        parts.push_back( TensMap[tens] );
        number %= 10;
    }

    if( number > 0 )
    {
        if( number == 1 && gender == GrammaticalGender::Feminine )
            parts.push_back( "одна" );
        else if( number == 1 && gender == GrammaticalGender::Neuter )
            parts.push_back( "одно" );
        else if( number == 2 && gender == GrammaticalGender::Feminine )
            parts.push_back( "две" );
        else if( number < 20 )
            parts.push_back( UnitsMap[number] );
    }
}

std::string RussianNumberToWordsConverter::GetPrefix( int number )
{
    std::vector<std::string> parts;

    if( number >= 100 )
    {
        auto hundreds = number / 100;
        number %= 100;
        if( hundreds != 1 )
            parts.push_back( UnitsOrdinalPrefixes[hundreds] + "сот" );
        else
            parts.push_back( "сто" );
    }

    if( number >= 20 )
    {
        auto tens = number / 10;
        number %= 10;
        parts.push_back( TensOrdinalPrefixes[tens] );
    }

    if( number > 0 )
    {
        parts.push_back( number == 1 ? "одно" : UnitsOrdinalPrefixes[number] );
    }

    return Join( "", parts );
}

void RussianNumberToWordsConverter::CollectParts( std::vector<std::string> & parts, int & number, int divisor,
        GrammaticalGender gender, const std::vector<std::string>& forms )
{
    if( number < divisor )
        return;
    auto result = number / divisor;
    number %= divisor;

    CollectPartsUnderOneThousand( parts, result, gender );
    parts.push_back( ChooseOneForGrammaticalNumber( result, forms ) );
}

void RussianNumberToWordsConverter::CollectOrdinalParts( std::vector<std::string> & parts, int & number, int divisor,
        GrammaticalGender gender, std::string prefixedForm, const std::vector<std::string>& forms )
{
    if( number < divisor )
        return;
    auto result = number / divisor;
    number %= divisor;
    if( number == 0 )
    {
        if( result == 1 )
            parts.push_back( prefixedForm );
        else
            parts.push_back( GetPrefix( result ) + prefixedForm );
    }
    else
    {
        CollectPartsUnderOneThousand( parts, result, gender );
        parts.push_back( ChooseOneForGrammaticalNumber( result, forms ) );
    }
}

int RussianNumberToWordsConverter::GetIndex( RussianGrammaticalNumber number )
{
    if( number == RussianGrammaticalNumber::Singular )
        return 0;

    if( number == RussianGrammaticalNumber::Paucal )
        return 1;

    return 2;
}

std::string RussianNumberToWordsConverter::ChooseOneForGrammaticalNumber( int number, const std::vector<std::string>& forms )
{
    return forms[GetIndex( RussianGrammaticalNumberDetector::Detect( number ) )];
}

std::string RussianNumberToWordsConverter::GetEndingForGender( GrammaticalGender gender, int number )
{
    switch( gender )
    {
    case GrammaticalGender::Masculine:
        if( number == 0 || number == 2 || number == 6 || number == 7 || number == 8 || number == 40 )
            return "ой";
        if( number == 3 )
            return "ий";
        return "ый";
    case GrammaticalGender::Feminine:
        if( number == 3 )
            return "ья";
        return "ая";
    case GrammaticalGender::Neuter:
        if( number == 3 )
            return "ье";
        return "ое";
    default:
        throw new std::out_of_range( "gender" );
    }
}

