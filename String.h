// $Revision: 2332 $ $Date:: 2015-08-18 #$ $Author: serge $

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

// http://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string
inline void replaceAll( std::string& str, const std::string& from, const std::string& to )
{
    if( from.empty() )
        return;
    size_t start_pos = 0;
    while( ( start_pos = str.find( from, start_pos ) ) != std::string::npos )
    {
        str.replace( start_pos, from.length(), to );
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

inline std::string Format( const std::string & format, const std::string & arg0 )
{
    std::string res = format;

    replaceAll( res, "{0}", arg0 );

    return res;
}

inline std::string Format( const std::string & format, const std::string & arg0, const std::string & arg1 )
{
    std::string res = format;

    replaceAll( res, "{0}", arg0 );
    replaceAll( res, "{1}", arg1 );

    return res;
}

}

#endif // _System_String_h_
