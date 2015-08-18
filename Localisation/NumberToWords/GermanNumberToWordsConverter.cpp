#include "GermanNumberToWordsConverter.h"       // self

#include <vector>       // std::vector
#include <stdexcept>    // std::out_of_range

#include "../../String.h"       // System::Format

using namespace Humanizer::Localisation::NumberToWords;
using namespace System;

const std::string GermanNumberToWordsConverter::UnitsMap[] = { "null", "ein", "zwei", "drei", "vier", "fünf", "sechs", "sieben", "acht", "neun", "zehn", "elf", "zwölf", "dreizehn", "vierzehn", "fünfzehn", "sechzehn", "siebzehn", "achtzehn", "neunzehn" };
const std::string GermanNumberToWordsConverter::TensMap[] = { "null", "zehn", "zwanzig", "dreißig", "vierzig", "fünfzig", "sechzig", "siebzig", "achtzig", "neunzig" };
const std::string GermanNumberToWordsConverter::UnitsOrdinal[] = { "", "ers", "zwei", "drit", "vier", "fünf", "sechs", "sieb", "ach", "neun", "zehn", "elf", "zwölf", "dreizehn", "vierzehn", "fünfzehn", "sechzehn", "siebzehn", "achtzehn", "neunzehn" };
const std::string GermanNumberToWordsConverter::MillionOrdinalSingular[] = {"einmillion", "einemillion"};
const std::string GermanNumberToWordsConverter::MillionOrdinalPlural[] = {"{0}million", "{0}millionen"};
const std::string GermanNumberToWordsConverter::BillionOrdinalSingular[] = {"einmilliard", "einemilliarde"};
const std::string GermanNumberToWordsConverter::BillionOrdinalPlural[] = {"{0}milliard", "{0}milliarden"};

std::string GermanNumberToWordsConverter::Convert( int number, GrammaticalGender gender )
{
    if( number == 0 )
        return "null";

    if( number < 0 )
        return Format( "minus {0}", Base::Convert( -number ) );

    std::vector<std::string> parts;

    auto billions = number / 1000000000;
    if( billions > 0 )
    {
        parts.push_back( Part( "{0} Milliarden", "eine Milliarde", billions ) );
        number %= 1000000000;
        if( number > 0 )
            parts.push_back( " " );
    }

    auto millions = number / 1000000;
    if( millions > 0 )
    {
        parts.push_back( Part( "{0} Millionen", "eine Million", millions ) );
        number %= 1000000;
        if( number > 0 )
            parts.push_back( " " );
    }

    auto thousands = number / 1000;
    if( thousands > 0 )
    {
        parts.push_back( Part( "{0}tausend", "eintausend", thousands ) );
        number %= 1000;
    }

    auto hundreds = number / 100;
    if( hundreds > 0 )
    {
        parts.push_back( Part( "{0}hundert", "einhundert", hundreds ) );
        number %= 100;
    }

    if( number > 0 )
    {
        if( number < 20 )
        {
            if( number > 1 )
                parts.push_back( UnitsMap[number] );
            else
                parts.push_back( "eins" );
        }
        else
        {
            auto units = number % 10;
            if( units > 0 )
                parts.push_back( Format( "{0}und", UnitsMap[units] ) );

            parts.push_back( TensMap[number / 10] );
        }
    }

    return Join( "", parts );
}

std::string GermanNumberToWordsConverter::ConvertToOrdinal( int number, GrammaticalGender gender )
{
    if( number == 0 )
        return "null" + GetEndingForGender( gender );

    std::vector<std::string> parts;

    if( number < 0 )
    {
        parts.push_back( "minus " );
        number = -number;
    }

    auto billions = number / 1000000000;
    if( billions > 0 )
    {
        number %= 1000000000;
        auto noRest = NoRestIndex( number );
        parts.push_back( Part( BillionOrdinalPlural[noRest], BillionOrdinalSingular[noRest], billions ) );
    }

    auto millions = number / 1000000;
    if( millions > 0 )
    {
        number %= 1000000;
        auto noRest = NoRestIndex( number );
        parts.push_back( Part( MillionOrdinalPlural[noRest], MillionOrdinalSingular[noRest], millions ) );
    }

    auto thousands = number / 1000;
    if( thousands > 0 )
    {
        parts.push_back( Part( "{0}tausend", "eintausend", thousands ) );
        number %= 1000;
    }

    auto hundreds = number / 100;
    if( hundreds > 0 )
    {
        parts.push_back( Part( "{0}hundert", "einhundert", hundreds ) );
        number %= 100;
    }

    if( number > 0 )
        parts.push_back( number < 20 ? UnitsOrdinal[number] : Base::Convert( number ) );

    if( number == 0 || number >= 20 )
        parts.push_back( "s" );

    parts.push_back( GetEndingForGender( gender ) );

    return Join( "", parts );
}

std::string GermanNumberToWordsConverter::Part( const std::string & pluralFormat, const std::string & singular, int number )
{
    if( number == 1 )
        return singular;
    return Format( pluralFormat, Base::Convert( number ) );
}

int GermanNumberToWordsConverter::NoRestIndex( int number )
{
    return number == 0 ? 0 : 1;
}

std::string GermanNumberToWordsConverter::GetEndingForGender( GrammaticalGender gender )
{
    switch( gender )
    {
    case GrammaticalGender::Masculine:
        return "ter";
    case GrammaticalGender::Feminine:
        return "te";
    case GrammaticalGender::Neuter:
        return "tes";
    default:
        throw std::out_of_range( "gender" );
    }
}
