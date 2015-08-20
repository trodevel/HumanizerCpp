#ifndef _CultureInfo_h_
#define _CultureInfo_h_

#include <stdint.h>     // uint32_t

namespace System
{
namespace Globalization
{
    class CultureInfo
    {
    public:
        CultureInfo(uint32_t);
        CultureInfo(std::string);
        CultureInfo(uint32_t, bool);
        CultureInfo(std::string, bool);

    public:
        std::string Name;
        std::string TwoLetterISOLanguageName;
    };
}
}

#endif // _CultureInfo_h_
