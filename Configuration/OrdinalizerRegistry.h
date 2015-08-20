// automatically converted from C# to C++ by convert_cs_to_cpp.sh ver. 1.0

#ifndef _OrdinalizerRegistry_h_
#define _OrdinalizerRegistry_h_


using Humanizer::Localisation::Ordinalizers;

namespace Humanizer
{
namespace Configuration
{
    class OrdinalizerRegistry : LocaliserRegistry<IOrdinalizer>
    {
        public:
 OrdinalizerRegistry() : base(new DefaultOrdinalizer())
        {
            Register("de", new GermanOrdinalizer());
            Register("en", new EnglishOrdinalizer());
            Register("es", new SpanishOrdinalizer());
            Register("it", new ItalianOrdinalizer());
            Register("nl", new DutchOrdinalizer());
            Register("pt", new PortugueseOrdinalizer());
            Register("ru", new RussianOrdinalizer());
            Register("tr", new TurkishOrdinalizer());
            Register("uk", new UkrainianOrdinalizer());
        }
    };
}
}
}


#endif // _OrdinalizerRegistry_h_
