#ifndef _EnglishNumberToWordsConverter_h_
#define _EnglishNumberToWordsConverter_h_

#include <map>                                  // std::map

#include "GenderlessNumberToWordsConverter.h"   // GenderlessNumberToWordsConverter

namespace Humanizer
{
namespace Localisation
{
namespace NumberToWords
{
    class EnglishNumberToWordsConverter : public GenderlessNumberToWordsConverter
    {
    private:
        static const std::string UnitsMap[];
        static const std::string TensMap[];

        static const std::map<int, std::string> OrdinalExceptions;

    public:

        std::string Convert(int number);

        std::string ConvertToOrdinal(int number);

    private:

        std::string Convert(int number, bool isOrdinal);

        static std::string GetUnitValue(int number, bool isOrdinal);

        static std::string RemoveOnePrefix(const std::string & toWords);

        static bool ExceptionNumbersToWords(int number, std::string & words );
    };
}
}
}

#endif // _EnglishNumberToWordsConverter_h_
