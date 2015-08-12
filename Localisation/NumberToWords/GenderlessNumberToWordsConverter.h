#ifndef _GenderlessNumberToWordsConverter_h_
#define _GenderlessNumberToWordsConverter_h_

#include "INumberToWordsConverter.h"        // INumberToWordsConverter

namespace Humanizer
{
namespace Localisation
{
namespace NumberToWords
{
    class GenderlessNumberToWordsConverter : public INumberToWordsConverter
    {
    public:
        /// <summary>
        /// Converts the number to std::string
        /// </summary>
        /// <param name="number"></param>
        /// <returns></returns>
        virtual std::string Convert(int number) = 0;

        /// <summary>
        /// Converts the number to std::string ignoring the provided grammatical gender
        /// </summary>
        /// <param name="number"></param>
        /// <param name="gender"></param>
        /// <returns></returns>
        std::string Convert(int number, GrammaticalGender gender)
        {
            return Convert(number);
        }

        /// <summary>
        /// Converts the number to ordinal std::string
        /// </summary>
        /// <param name="number"></param>
        /// <returns></returns>
        virtual std::string ConvertToOrdinal(int number)    = 0;

        /// <summary>
        /// Converts the number to ordinal std::string ignoring  the provided grammatical gender
        /// </summary>
        /// <param name="number"></param>
        /// <param name="gender"></param>
        /// <returns></returns>
        std::string ConvertToOrdinal(int number, GrammaticalGender gender)
        {
            return ConvertToOrdinal(number);
        }
    };
}
}
}
#endif // _GenderlessNumberToWordsConverter_h_
