// automatically converted from C# to C++ by convert_cs_to_cpp.sh ver. 1.2

#ifndef _RussianGrammaticalNumberDetector_h_
#define _RussianGrammaticalNumberDetector_h_

#include "RussianGrammaticalNumber.h"   // RussianGrammaticalNumber

namespace Humanizer
{
namespace Localisation
{
namespace GrammaticalNumber
{
class RussianGrammaticalNumberDetector
{
public:
    static RussianGrammaticalNumber Detect( int number )
    {
        auto tens = number % 100 / 10;
        if( tens != 1 )
        {
            auto unity = number % 10;

            if( unity == 1 ) // 1, 21, 31, 41 ... 91, 101, 121 ...
                return RussianGrammaticalNumber::Singular;

            if( unity > 1 && unity < 5 ) // 2, 3, 4, 22, 23, 24 ...
                return RussianGrammaticalNumber::Paucal;
        }

        return RussianGrammaticalNumber::Plural;
    }
};
}
}
}

#endif // _RussianGrammaticalNumberDetector_h_
