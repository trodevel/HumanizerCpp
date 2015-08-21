// automatically converted from C# to C++ by convert_cs_to_cpp.sh ver. 1.1

#ifndef _LocaliserRegistry_h_
#define _LocaliserRegistry_h_

#include <map>                      // std::map
#include <functional>               // std::function

#include "../CultureInfo.h"         // CultureInfo

namespace Humanizer
{
namespace Configuration
{
/// <summary>
/// A registry of localised system components with their associated locales
/// </summary>
/// <typeparam name="TLocaliser"></typeparam>
template< class TLocaliser >
class LocaliserRegistry
{
    typedef System::Globalization::CultureInfo CultureInfo;

private:
    std::map<std::string, TLocaliser*> _localisers;
    TLocaliser* _defaultLocaliser;

public:
    /// <summary>
    /// Creates a localiser registry with the default localiser set to the provided value
    /// </summary>
    /// <param name="defaultLocaliser"></param>
    LocaliserRegistry( TLocaliser *defaultLocaliser )
    {
        _defaultLocaliser = defaultLocaliser;
    }

#ifdef XXX
    /// <summary>
    /// Creates a localiser registry with the default localiser factory set to the provided value
    /// </summary>
    /// <param name="defaultLocaliser"></param>
    LocaliserRegistry(std::function<CultureInfo, TLocaliser> defaultLocaliser)
    {
        _defaultLocaliser = defaultLocaliser;
    }
#endif

    /// <summary>
    /// Gets the localiser for the current thread's UI culture
    /// </summary>
    TLocaliser* ResolveForUiCulture()
    {
        return ResolveForCulture( nullptr );
    }

    /// <summary>
    /// Gets the localiser for the specified culture
    /// </summary>
    /// <param name="culture">The culture to retrieve localiser for. If not specified, current thread's UI culture is used.</param>
    const TLocaliser* ResolveForCulture( const CultureInfo *culture ) const
    {
        return FindLocaliser( culture );
    }

/// <summary>
/// Registers the localiser for the culture provided
/// </summary>
    void Register( const std::string & localeCode, TLocaliser * localiser )
    {
        _localisers[localeCode] = localiser;
    }

#ifdef XXX
/// <summary>
/// Registers the localiser factory for the culture provided
/// </summary>
    void Register(std::string localeCode, std::function<CultureInfo, TLocaliser> localiser)
    {
        _localisers[localeCode] = localiser;
    }
#endif

    const TLocaliser* FindLocaliser( const CultureInfo *culture ) const
    {
        if( culture == nullptr )
            return _defaultLocaliser;

        auto it = _localisers.find( culture->TwoLetterISOLanguageName );
        if( it != _localisers.end() )
            return it->second;

        return _defaultLocaliser;
    }
};
}
}

#endif // _LocaliserRegistry_h_
