// automatically converted from C# to C++ by convert_cs_to_cpp.sh ver. 1.1

#ifndef _LocaliserRegistry_h_
#define _LocaliserRegistry_h_


using System;
using System::Collections::Generic;
using System::Globalization;

namespace Humanizer
{
namespace Configuration
{
    /// <summary>
    /// A registry of localised system components with their associated locales
    /// </summary>
    /// <typeparam name="TLocaliser"></typeparam>
    public:
 class LocaliserRegistry<TLocaliser>
        where TLocaliser : class
    {
        private:
 const IDictionary<std::string, std::function<CultureInfo, TLocaliser>> _localisers = new std::map<std::string, std::function<CultureInfo, TLocaliser>>();
        private:
 const std::function<CultureInfo, TLocaliser> _defaultLocaliser;

        /// <summary>
        /// Creates a localiser registry with the default localiser set to the provided value
        /// </summary>
        /// <param name="defaultLocaliser"></param>
        public:
 LocaliserRegistry(TLocaliser defaultLocaliser)
        {
            _defaultLocaliser = (culture) => defaultLocaliser;
        }

        /// <summary>
        /// Creates a localiser registry with the default localiser factory set to the provided value
        /// </summary>
        /// <param name="defaultLocaliser"></param>
        public:
 LocaliserRegistry(std::function<CultureInfo, TLocaliser> defaultLocaliser)
        {
            _defaultLocaliser = defaultLocaliser;
        }

        /// <summary>
        /// Gets the localiser for the current thread's UI culture 
        /// </summary>
        public:
 TLocaliser ResolveForUiCulture()
        {
            return ResolveForCulture(null);
        }

        /// <summary>
        /// Gets the localiser for the specified culture 
        /// </summary>
        /// <param name="culture">The culture to retrieve localiser for. If not specified, current thread's UI culture is used.</param>
        public:
 TLocaliser ResolveForCulture(CultureInfo culture)
        {
            return FindLocaliser(culture ?? CultureInfo.CurrentUICulture)(culture);
        }

        /// <summary>
        /// Registers the localiser for the culture provided 
        /// </summary>
        public:
 void Register(std::string localeCode, TLocaliser localiser)
        {
            _localisers[localeCode] = (culture) => localiser;
        }

        /// <summary>
        /// Registers the localiser factory for the culture provided
        /// </summary>
        public:
 void Register(std::string localeCode, std::function<CultureInfo, TLocaliser> localiser)
        {
            _localisers[localeCode] = localiser;
        }

        private:
 std::function<CultureInfo, TLocaliser> FindLocaliser(CultureInfo culture)
        {
            std::function<CultureInfo, TLocaliser> localiser;

            if (_localisers.TryGetValue(culture.Name, out localiser))
                return localiser;

            if (_localisers.TryGetValue(culture.TwoLetterISOLanguageName, out localiser))
                return localiser;

            return _defaultLocaliser;
        }
    }
}


#endif // _LocaliserRegistry_h_
