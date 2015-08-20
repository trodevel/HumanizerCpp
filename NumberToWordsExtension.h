#ifndef _NumberToWordsExtension_h_
#define _NumberToWordsExtension_h_

#include "GrammaticalGender.h"          // GrammaticalGender
#include "CultureInfo.h"                // CultureInfo
#include "Configuration/Configurator.h" // Configurator

namespace Humanizer
{

/// <summary>
/// Transform a number into words; e.g. 1 => one
/// </summary>
class NumberToWordsExtension
{
    typedef System::Globalization::CultureInfo CultureInfo;
    typedef Humanizer::Configuration::Configurator Configurator;

public:
    /// <summary>
    /// 3501.ToWords() -> "three thousand five hundred and one"
    /// </summary>
    /// <param name="number">Number to be turned to words</param>
    /// <param name="culture">Culture to use. If nullptr, current thread's UI culture is used.</param>
    /// <returns></returns>
    static std::string ToWords( int number, const CultureInfo * culture = nullptr )
    {
        return Configurator::GetNumberToWordsConverter( culture ).Convert( number );
    }

    /// <summary>
    /// For locales that support gender-specific forms
    /// </summary>
    /// <example>
    /// Russian:
    /// <code>
    ///   1.ToWords(GrammaticalGender.Masculine) -> "один"
    ///   1.ToWords(GrammaticalGender.Feminine) -> "одна"
    /// </code>
    /// Hebrew:
    /// <code>
    ///   1.ToWords(GrammaticalGender.Masculine) -> "אחד"
    ///   1.ToWords(GrammaticalGender.Feminine) -> "אחת"
    /// </code>
    /// </example>
    ///
    /// <param name="number">Number to be turned to words</param>
    /// <param name="gender">The grammatical gender to use for output words</param>
    /// <param name="culture">Culture to use. If nullptr, current thread's UI culture is used.</param>
    /// <returns></returns>
    static std::string ToWords( int number, GrammaticalGender gender, const CultureInfo * culture = nullptr )
    {
        return Configurator::GetNumberToWordsConverter( culture ).Convert( number, gender );
    }

    /// <summary>
    /// 1.ToOrdinalWords() -> "first"
    /// </summary>
    /// <param name="number">Number to be turned to ordinal words</param>
    /// <param name="culture">Culture to use. If nullptr, current thread's UI culture is used.</param>
    /// <returns></returns>
    static std::string ToOrdinalWords( int number, const CultureInfo * culture = nullptr )
    {
        return Configurator::GetNumberToWordsConverter( culture ).ConvertToOrdinal( number );
    }

    /// <summary>
    /// for Brazilian Portuguese locale
    /// 1.ToOrdinalWords(GrammaticalGender.Masculine) -> "primeiro"
    /// 1.ToOrdinalWords(GrammaticalGender.Feminine) -> "primeira"
    /// </summary>
    /// <param name="number">Number to be turned to words</param>
    /// <param name="gender">The grammatical gender to use for output words</param>
    /// <param name="culture">Culture to use. If nullptr, current thread's UI culture is used.</param>
    /// <returns></returns>
    static std::string ToOrdinalWords( int number, GrammaticalGender gender, const CultureInfo * culture = nullptr )
    {
        return Configurator::GetNumberToWordsConverter( culture ).ConvertToOrdinal( number, gender );
    }
};
}

#endif // _NumberToWordsExtension_h_
