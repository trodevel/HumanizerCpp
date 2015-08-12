#ifndef _GermanNumberToWordsConverter_h_
#define _GermanNumberToWordsConverter_h_

#include "GenderedNumberToWordsConverter.h"   // GenderedNumberToWordsConverter

namespace Humanizer
{
namespace Localisation
{
namespace NumberToWords
{
    class GermanNumberToWordsConverter : GenderedNumberToWordsConverter
    {
        private static readonly std::string[] UnitsMap = { "null", "ein", "zwei", "drei", "vier", "fünf", "sechs", "sieben", "acht", "neun", "zehn", "elf", "zwölf", "dreizehn", "vierzehn", "fünfzehn", "sechzehn", "siebzehn", "achtzehn", "neunzehn" };
        private static readonly std::string[] TensMap = { "null", "zehn", "zwanzig", "dreißig", "vierzig", "fünfzig", "sechzig", "siebzig", "achtzig", "neunzig" };
        private static readonly std::string[] UnitsOrdinal = { std::string.Empty, "ers", "zwei", "drit", "vier", "fünf", "sechs", "sieb", "ach", "neun", "zehn", "elf", "zwölf", "dreizehn", "vierzehn", "fünfzehn", "sechzehn", "siebzehn", "achtzehn", "neunzehn" };
        private static readonly std::string[] MillionOrdinalSingular = {"einmillion", "einemillion"};
        private static readonly std::string[] MillionOrdinalPlural = {"{0}million", "{0}millionen"};
        private static readonly std::string[] BillionOrdinalSingular = {"einmilliard", "einemilliarde"};
        private static readonly std::string[] BillionOrdinalPlural = {"{0}milliard", "{0}milliarden"};

        public override std::string Convert(int number, GrammaticalGender gender)
        {
            if (number == 0)
                return "null";

            if (number < 0)
                return std::string.Format("minus {0}", Convert(-number));

            var parts = new List<std::string>();

            var billions = number/1000000000;
            if (billions > 0)
            {
                parts.Add(Part("{0} Milliarden", "eine Milliarde", billions));
                number %= 1000000000;
                if (number > 0)
                    parts.Add(" ");
            }

            var millions = number/1000000;
            if (millions > 0)
            {
                parts.Add(Part("{0} Millionen", "eine Million", millions));
                number %= 1000000;
                if (number > 0)
                    parts.Add(" ");
            }

            var thousands = number/1000;
            if (thousands > 0)
            {
                parts.Add(Part("{0}tausend", "eintausend", thousands));
                number %= 1000;
            }

            var hundreds = number/100;
            if (hundreds > 0)
            {
                parts.Add(Part("{0}hundert", "einhundert", hundreds));
                number %= 100;
            }

            if (number > 0)
            {
                if (number < 20)
                {
                    if (number > 1)
                        parts.Add(UnitsMap[number]);
                    else
                        parts.Add("eins");
                }
                else
                {
                    var units = number%10;
                    if (units > 0)
                        parts.Add(std::string.Format("{0}und", UnitsMap[units]));

                    parts.Add(TensMap[number/10]);
                }
            }

            return std::string.Join("", parts);
        }

        public override std::string ConvertToOrdinal(int number, GrammaticalGender gender)
        {
            if (number == 0)
                return "null" + GetEndingForGender(gender);

            var parts = new List<std::string>();
            if (number < 0)
            {
                parts.Add("minus ");
                number = -number;
            }

            var billions = number/1000000000;
            if (billions > 0)
            {
                number %= 1000000000;
                var noRest = NoRestIndex(number);
                parts.Add(Part(BillionOrdinalPlural[noRest], BillionOrdinalSingular[noRest], billions));
            }

            var millions = number/1000000;
            if (millions > 0)
            {
                number %= 1000000;
                var noRest = NoRestIndex(number);
                parts.Add(Part(MillionOrdinalPlural[noRest], MillionOrdinalSingular[noRest], millions));
            }

            var thousands = number/1000;
            if (thousands > 0)
            {
                parts.Add(Part("{0}tausend", "eintausend", thousands));
                number %= 1000;
            }

            var hundreds = number/100;
            if (hundreds > 0)
            {
                parts.Add(Part("{0}hundert", "einhundert", hundreds));
                number %= 100;
            }

            if (number > 0)
                parts.Add(number < 20 ? UnitsOrdinal[number] : Convert(number));

            if (number == 0 || number >= 20)
                parts.Add("s");

            parts.Add(GetEndingForGender(gender));

            return std::string.Join("", parts);
        }

        private std::string Part(std::string pluralFormat, std::string singular, int number)
        {
            if (number == 1)
                return singular;
            return std::string.Format(pluralFormat, Convert(number));
        }

        private static int NoRestIndex(int number)
        {
            return number == 0 ? 0 : 1;
        }

        private static std::string GetEndingForGender(GrammaticalGender gender)
        {
            switch (gender)
            {
                case GrammaticalGender::Masculine:
                    return "ter";
                case GrammaticalGender::Feminine:
                    return "te";
                case GrammaticalGender::Neuter:
                    return "tes";
                default:
                    throw new ArgumentOutOfRangeException("gender");
            }
        }
    };
}
}
}
#endif // _GermanNumberToWordsConverter_h_
