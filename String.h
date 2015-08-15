// $Revision: 2316 $ $Date:: 2015-08-14 #$ $Author: serge $

#ifndef _System_String_h_
#define _System_String_h_

#include <string>     // std::string
#include <vector>     // std::vector

namespace System
{

inline std::string TrimEnd(const std::string & s, std::string::value_type c)
{
    if( s.empty() )
        return s;

    std::string::size_type sz = s.size();

    if( s[sz-1] == c )
    {
        return s.substr( 0, sz - 1 );
    }

    return s;
}

inline std::string Join( const std::string & delim, const std::vector<std::string> & parts )
{
    std::string res;

    bool is_first = true;

    for( auto & e : parts )
    {
        if( is_first )
        {
            is_first = false;
        }
        else
        {
            res += delim;
        }

        res += e;
    }

    return res;
}

}

#endif // _System_String_h_
