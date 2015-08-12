#ifndef _GenderedNumberToWordsConverter_h_
#define _GenderedNumberToWordsConverter_h_

#include "INumberToWordsConverter.h"        // INumberToWordsConverter

namespace Humanizer
{
namespace Localisation
{
namespace NumberToWords
{
    class GenderedNumberToWordsConverter : INumberToWordsConverter
    {
        private:

        GrammaticalGender _defaultGender;

        protected:

        GenderedNumberToWordsConverter(GrammaticalGender defaultGender = GrammaticalGender::Masculine)
        {
            _defaultGender = defaultGender;
        }

        public:
        /// <summary>
        /// Converts the number to std::string using the locale's default grammatical gender
        /// </summary>
        /// <param name="number"></param>
        /// <returns></returns>
        std::string Convert(int number)
        {
            return Convert(number, _defaultGender);
        }

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
        std::string ConvertToOrdinal(int number)
        {
            return ConvertToOrdinal(number, _defaultGender);
        }

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

#endif // _GenderedNumberToWordsConverter_h_
