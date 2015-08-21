// automatically converted from C# to C++ by convert_cs_to_cpp.sh ver. 1.1

#include "../Configuration/Configurator.h"     // self

using namespace Humanizer::Configuration;

const LocaliserRegistry<INumberToWordsConverter> *Configurator::NumberToWordsConverters::_numberToWordsConverters = new NumberToWordsConverterRegistry();
