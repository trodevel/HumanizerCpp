// automatically converted from C# to C++ by convert_cs_to_cpp.sh ver. 1.0

#ifndef _NumberToWordsConverterRegistry_h_
#define _NumberToWordsConverterRegistry_h_

#include "LocaliserRegistry.h"      // LocaliserRegistry
#include "../Localisation/NumberToWords/INumberToWordsConverter.h"    // INumberToWordsConverter

namespace Humanizer
{
namespace Configuration
{
typedef Humanizer::Localisation::NumberToWords::INumberToWordsConverter INumberToWordsConverter;

class NumberToWordsConverterRegistry: public LocaliserRegistry<INumberToWordsConverter>
{
    typedef LocaliserRegistry<INumberToWordsConverter> base;

public:
    NumberToWordsConverterRegistry();
};
}
}

#endif // _NumberToWordsConverterRegistry_h_
