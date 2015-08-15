// automatically converted from C# to C++ by convert_cs_to_cpp.sh ver. 1.0

#ifndef _GermanNumberToWordsConverter_h_
#define _GermanNumberToWordsConverter_h_


using System;
using System::Collections::Generic;

namespace Humanizer
{
namespace Localisation
{
namespace NumberToWords
{
    class GermanNumberToWordsConverter : GenderedNumberToWordsConverter
    {
        private:
 static const std::string[] UnitsMap = { "null", "ein", "zwei", "drei", "vier", "fünf", "sechs", "sieben", "acht", "neun", "zehn", "elf", "zwölf", "dreizehn", "vierzehn", "fünfzehn", "sechzehn", "siebzehn", "achtzehn", "neunzehn" };
        private:
 static const std::string[] TensMap = { "null", "zehn", "zwanzig", "dreißig", "vierzig", "fünfzig", "sechzig", "siebzig", "achtzig", "neunzig" };
        private:
 static const string[] UnitsOrdinal = { std::string.Empty, "ers", "zwei", "drit", "vier", "fünf", "sechs", "sieb", "ach", "neun", "zehn", "elf", "zwölf", "dreizehn", "vierzehn", "fünfzehn", "sechzehn", "siebzehn", "achtzehn", "neunzehn" };
        private:
 static const std::string[] MillionOrdinalSingular = {"einmillion", "einemillion"};
        private:
 static const std::string[] MillionOrdinalPlural = {"{0}million", "{0}millionen"};
        private:
 static const std::string[] BillionOrdinalSingular = {"einmilliard", "einemilliarde"};
        private:
 static const std::string[] BillionOrdinalPlural = {"{0}milliard", "{0}milliarden"};

        public:
 virtual std::string Convert(int number, GrammaticalGender gender)
        {
            if (number == 0)
                return "null";

            if (number < 0)
                return std::string.Format("minus {0}", Convert(-number));

            auto parts = new std::list<std::string>();

            auto billions = number/1000000000;
            if (billions > 0)
            {
                parts.Add(Part("{0} Milliarden", "eine Milliarde", billions));
                number %= 1000000000;
                if (number > 0)
                    parts.Add(" ");
            }

            auto millions = number/1000000;
            if (millions > 0)
            {
                parts.Add(Part("{0} Millionen", "eine Million", millions));
                number %= 1000000;
                if (number > 0)
                    parts.Add(" ");
            }

            auto thousands = number/1000;
            if (thousands > 0)
            {
                parts.Add(Part("{0}tausend", "eintausend", thousands));
                number %= 1000;
            }

            auto hundreds = number/100;
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
                    auto units = number%10;
                    if (units > 0)
                        parts.Add(std::string.Format("{0}und", UnitsMap[units]));

                    parts.Add(TensMap[number/10]);
                }
            }

            return std::string.Join("", parts);
        }

        public:
 virtual std::string ConvertToOrdinal(int number, GrammaticalGender gender)
        {
            if (number == 0)
                return "null" + GetEndingForGender(gender);

            auto parts = new std::list<std::string>();
            if (number < 0)
            {
                parts.Add("minus ");
                number = -number;
            }

            auto billions = number/1000000000;
            if (billions > 0)
            {
                number %= 1000000000;
                auto noRest = NoRestIndex(number);
                parts.Add(Part(BillionOrdinalPlural[noRest], BillionOrdinalSingular[noRest], billions));
            }

            auto millions = number/1000000;
            if (millions > 0)
            {
                number %= 1000000;
                auto noRest = NoRestIndex(number);
                parts.Add(Part(MillionOrdinalPlural[noRest], MillionOrdinalSingular[noRest], millions));
            }

            auto thousands = number/1000;
            if (thousands > 0)
            {
                parts.Add(Part("{0}tausend", "eintausend", thousands));
                number %= 1000;
            }

            auto hundreds = number/100;
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

        private:
 string Part(string pluralFormat, std::string singular, int number)
        {
            if (number == 1)
                return singular;
            return std::string.Format(pluralFormat, Convert(number));
        }

        private:
 static int NoRestIndex(int number)
        {
            return number == 0 ? 0 : 1;
        }

        private:
 static std::string GetEndingForGender(GrammaticalGender gender)
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
                    throw new std::out_of_range("gender");
            }
        }
    }
}

#endif // _GermanNumberToWordsConverter_h_
