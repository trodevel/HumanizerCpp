// automatically converted from C# to C++ by convert_cs_to_cpp.sh ver. 1.1

#ifndef _RussianNumberToWordsConverter_h_
#define _RussianNumberToWordsConverter_h_

#include <vector>                                           // std::vector
#include "GenderedNumberToWordsConverter.h"                 // GenderedNumberToWordsConverter
#include "../GrammaticalNumber/RussianGrammaticalNumber.h"  // RussianGrammaticalNumber

namespace Humanizer
{
namespace Localisation
{
namespace NumberToWords
{
class RussianNumberToWordsConverter: public GenderedNumberToWordsConverter
{
    typedef Humanizer::Localisation::GrammaticalNumber::RussianGrammaticalNumber RussianGrammaticalNumber;
private:
    static const std::string HundredsMap[];
    static const std::string TensMap[];
    static const std::string UnitsMap[];
    static const std::string UnitsOrdinalPrefixes[];
    static const std::string TensOrdinalPrefixes[];
    static const std::string TensOrdinal[];
    static const std::string UnitsOrdinal[];

public:
    virtual std::string Convert( int number, GrammaticalGender gender ) const;
    virtual std::string ConvertToOrdinal( int number, GrammaticalGender gender ) const;

private:
    static void CollectPartsUnderOneThousand( std::vector<std::string> & parts, int number, GrammaticalGender gender );
    static std::string GetPrefix( int number );
    static void CollectParts( std::vector<std::string> & parts, int & number, int divisor, GrammaticalGender gender, const std::vector<std::string>& forms );
    static void CollectOrdinalParts( std::vector<std::string> & parts, int & number, int divisor, GrammaticalGender gender, std::string prefixedForm, const std::vector<std::string>& forms );
    static int GetIndex( RussianGrammaticalNumber number );
    static std::string ChooseOneForGrammaticalNumber( int number, const std::vector<std::string>& forms );
    static std::string GetEndingForGender( GrammaticalGender gender, int number );
};
}
}
}

#endif // _RussianNumberToWordsConverter_h_
