#include "NumberToWordsConverterRegistry.h"      // self

#include "../Localisation/NumberToWords/DefaultNumberToWordsConverter.h"    // DefaultNumberToWordsConverter
#include "../Localisation/NumberToWords/EnglishNumberToWordsConverter.h"    // EnglishNumberToWordsConverter
#include "../Localisation/NumberToWords/GermanNumberToWordsConverter.h"     // GermanNumberToWordsConverter

using namespace Humanizer::Configuration;
using namespace Humanizer::Localisation::NumberToWords;

NumberToWordsConverterRegistry::NumberToWordsConverterRegistry() :
        base( new DefaultNumberToWordsConverter() )
{
//    Register( "af", new AfrikaansNumberToWordsConverter() );
    Register( "en", new EnglishNumberToWordsConverter() );
//    Register( "ar", new ArabicNumberToWordsConverter() );
//    Register( "fa", new FarsiNumberToWordsConverter() );
//    Register( "es", new SpanishNumberToWordsConverter() );
//    Register("pl", (culture) => new PolishNumberToWordsConverter(culture));
//    Register( "pt-BR", new BrazilianPortugueseNumberToWordsConverter() );
//    Register( "ru", new RussianNumberToWordsConverter() );
//    Register( "fr", new FrenchNumberToWordsConverter() );
//    Register( "nl", new DutchNumberToWordsConverter() );
//    Register("he", (culture) => new HebrewNumberToWordsConverter(culture));
//    Register("sl", (culture) => new SlovenianNumberToWordsConverter(culture));
    Register( "de", new GermanNumberToWordsConverter() );
//    Register( "bn-BD", new BanglaNumberToWordsConverter() );
//    Register( "tr", new TurkishNumberToWordConverter() );
//    Register( "it", new ItalianNumberToWordsConverter() );
//    Register( "uk", new UkrainianNumberToWordsConverter() );
//    Register( "uz-Latn-UZ", new UzbekLatnNumberToWordConverter() );
//    Register( "uz-Cyrl-UZ", new UzbekCyrlNumberToWordConverter() );
//    Register( "sr", new SerbianCyrlNumberToWordsConverter( culture ) );
//    Register( "sr-Latn", new SerbianNumberToWordsConverter( culture ) );
}
