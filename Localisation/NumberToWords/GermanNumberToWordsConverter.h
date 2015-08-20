// automatically converted from C# to C++ by convert_cs_to_cpp.sh ver. 1.0

#ifndef _GermanNumberToWordsConverter_h_
#define _GermanNumberToWordsConverter_h_

#include "GenderedNumberToWordsConverter.h"     // GenderedNumberToWordsConverter

namespace Humanizer
{
namespace Localisation
{
namespace NumberToWords
{
    class GermanNumberToWordsConverter : public GenderedNumberToWordsConverter
    {
        typedef GenderedNumberToWordsConverter Base;
private:
    static const std::string UnitsMap[];
    static const std::string TensMap[];
    static const std::string UnitsOrdinal[];
    static const std::string MillionOrdinalSingular[];
    static const std::string MillionOrdinalPlural[];
    static const std::string BillionOrdinalSingular[];
    static const std::string BillionOrdinalPlural[];

public:
    virtual std::string Convert( int number, GrammaticalGender gender );
    virtual std::string ConvertToOrdinal( int number, GrammaticalGender gender );

private:
    std::string Part( const std::string & pluralFormat, const std::string & singular, int number );
    static int NoRestIndex( int number );
    static std::string GetEndingForGender( GrammaticalGender gender );

    };
}
}
}

#endif // _GermanNumberToWordsConverter_h_
