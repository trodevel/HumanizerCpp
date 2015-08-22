// automatically converted from C# to C++ by convert_cs_to_cpp.sh ver. 1.1

#ifndef _DefaultNumberToWordsConverter_h_
#define _DefaultNumberToWordsConverter_h_

#include "GenderlessNumberToWordsConverter.h"   // GenderlessNumberToWordsConverter

namespace Humanizer
{
namespace Localisation
{
namespace NumberToWords
{
class DefaultNumberToWordsConverter: public GenderlessNumberToWordsConverter
{
private:
//    const std::string _culture;

    /// <summary>
    /// Constructor.
    /// </summary>
    /// <param name="culture">Culture to use.</param>
public:
    DefaultNumberToWordsConverter()
    {
    }

    DefaultNumberToWordsConverter( const std::string & culture )
    {
//        _culture = culture;
    }

    /// <summary>
    /// 3501.ToWords() -> "three thousand five hundred and one"
    /// </summary>
    /// <param name="number">Number to be turned to words</param>
    /// <returns></returns>
public:
    virtual std::string Convert( int number ) const
    {
        return std::to_string( number );
    }

    /// <summary>
    /// 1.ToOrdinalWords() -> "first"
    /// </summary>
    /// <param name="number">Number to be turned to ordinal words</param>
    /// <returns></returns>
public:
    virtual std::string ConvertToOrdinal( int number ) const
    {
        return std::to_string( number );
    }
};
}
}
}

#endif // _DefaultNumberToWordsConverter_h_
