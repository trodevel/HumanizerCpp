#ifndef _INumberToWordsConverter_h_
#define _INumberToWordsConverter_h_

#include <string>                       // std::string
#include "../../GrammaticalGender.h"    // GrammaticalGender

namespace Humanizer
{
namespace Localisation
{
namespace NumberToWords
{
    /// <summary>
    /// An interface you should implement to localise ToWords and ToOrdinalWords methods
    /// </summary>
    struct INumberToWordsConverter
    {
        virtual ~INumberToWordsConverter() {}
        /// <summary>
        /// Converts the number to std::string using the locale's default grammatical gender
        /// </summary>
        /// <param name="number"></param>
        /// <returns></returns>
        virtual std::string Convert(int number)  = 0;

        /// <summary>
        /// Converts the number to std::string using the provided grammatical gender
        /// </summary>
        /// <param name="number"></param>
        /// <param name="gender"></param>
        /// <returns></returns>
        virtual std::string Convert(int number, GrammaticalGender gender) = 0;

        /// <summary>
        /// Converts the number to ordinal std::string using the locale's default grammatical gender
        /// </summary>
        /// <param name="number"></param>
        /// <returns></returns>
        virtual std::string ConvertToOrdinal(int number) = 0;

        /// <summary>
        /// Converts the number to ordinal std::string using the provided grammatical gender
        /// </summary>
        /// <param name="number"></param>
        /// <param name="gender"></param>
        /// <returns></returns>
        virtual std::string ConvertToOrdinal(int number, GrammaticalGender gender) = 0;
    };
}
}
}
#endif // _INumberToWordsConverter_h_
