// automatically converted from C# to C++ by convert_cs_to_cpp.sh ver. 1.1

#ifndef _Configurator_h_
#define _Configurator_h_


#include "../Localisation/NumberToWords/INumberToWordsConverter.h"  // INumberToWordsConverter

//using System;
//using System::Collections::Generic;
//using System::Globalization;
//using System::Reflection;
//using Humanizer::DateTimeHumanizeStrategy;
//using Humanizer::Localisation::Formatters;
using Humanizer::Localisation::NumberToWords;
//using Humanizer::Localisation::Ordinalizers;
//using Humanizer::Localisation::CollectionFormatters;

namespace Humanizer
{
namespace Configuration
{
    /// <summary>
    /// Provides a configuration point for Humanizer
    /// </summary>
 class Configurator
    {
     typedef System::Globalization::CultureInfo CultureInfo;
     typedef Humanizer::Localisation::NumberToWords::INumberToWordsConverter INumberToWordsConverter;

#ifdef XXX
        private:
 static const LocaliserRegistry<ICollectionFormatter> _collectionFormatters = new CollectionFormatterRegistry();

        /// <summary>
        /// A registry of formatters used to format collections based on the current locale
        /// </summary>
        public:
 static LocaliserRegistry<ICollectionFormatter> CollectionFormatters
        {
            get { return _collectionFormatters; }
        }

        private:
 static const LocaliserRegistry<IFormatter> _formatters = new FormatterRegistry();
        /// <summary>
        /// A registry of formatters used to format strings based on the current locale
        /// </summary>
        public:
 static LocaliserRegistry<IFormatter> Formatters
        {
            get { return _formatters; }
        }
#endif

        private:
    class NumberToWordsConverters
    {
        static const LocaliserRegistry<INumberToWordsConverter> *_numberToWordsConverters = new NumberToWordsConverterRegistry();
        /// <summary>
        /// A registry of number to words converters used to localise ToWords and ToOrdinalWords methods
        /// </summary>
    public:
        static LocaliserRegistry<INumberToWordsConverter> get()
        {
            return _numberToWordsConverters;
        }
    };

#ifdef XXX
        private:
 static const LocaliserRegistry<IOrdinalizer> _ordinalizers = new OrdinalizerRegistry();
        /// <summary>
        /// A registry of ordinalizers used to localise Ordinalize method
        /// </summary>
        public:
 static LocaliserRegistry<IOrdinalizer> Ordinalizers
        {
            get { return _ordinalizers; }
        }
        static ICollectionFormatter CollectionFormatter
        {
            get
            {
                return CollectionFormatters.ResolveForUiCulture();
            }
        }

        /// <summary>
        /// The formatter to be used
        /// </summary>
        /// <param name="culture">The culture to retrieve formatter for. Null means that current thread's UI culture should be used.</param>
        static IFormatter GetFormatter(CultureInfo culture)
        {
            return Formatters.ResolveForCulture(culture);
        }
#endif

    /// <summary>
    /// The converter to be used
    /// </summary>
    /// <param name="culture">The culture to retrieve number to words converter for. Null means that current thread's UI culture should be used.</param>
    static INumberToWordsConverter GetNumberToWordsConverter( const CultureInfo *culture )
    {
        return NumberToWordsConverters::get().ResolveForCulture( culture );
    }
#ifdef XXX
        /// <summary>
        /// The ordinalizer to be used
        /// </summary>
        static IOrdinalizer Ordinalizer
        {
            get
            {
                return Ordinalizers.ResolveForUiCulture();
            }
        }

        private:
 static IDateTimeHumanizeStrategy _dateTimeHumanizeStrategy = new DefaultDateTimeHumanizeStrategy();
        /// <summary>
        /// The strategy to be used for DateTime.Humanize
        /// </summary>
        public:
 static IDateTimeHumanizeStrategy DateTimeHumanizeStrategy
        {
            get { return _dateTimeHumanizeStrategy; }
            set { _dateTimeHumanizeStrategy = value; }
        }

        private:
 static IDateTimeOffsetHumanizeStrategy _dateTimeOffsetHumanizeStrategy = new DefaultDateTimeOffsetHumanizeStrategy();
        /// <summary>
        /// The strategy to be used for DateTimeOffset.Humanize
        /// </summary>
        public:
 static IDateTimeOffsetHumanizeStrategy DateTimeOffsetHumanizeStrategy
        {
            get { return _dateTimeOffsetHumanizeStrategy; }
            set { _dateTimeOffsetHumanizeStrategy = value; }
        }

        private:
 static const std::function<PropertyInfo, bool> DefaultEnumDescriptionPropertyLocator = p => p.Name == "Description";
        private:
 static std::function<PropertyInfo, bool> _enumDescriptionPropertyLocator = DefaultEnumDescriptionPropertyLocator;
        /// <summary>
        /// A predicate function for description property of attribute to use for Enum.Humanize
        /// </summary>
        public:
 static std::function<PropertyInfo, bool> EnumDescriptionPropertyLocator
        {
            get { return _enumDescriptionPropertyLocator; }
            set { _enumDescriptionPropertyLocator = value ?? DefaultEnumDescriptionPropertyLocator; }
        }
    }
#endif
};
}
}

#endif // _Configurator_h_
