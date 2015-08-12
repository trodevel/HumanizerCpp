#ifndef _ItalianOrdinalizer_h_
#define _ItalianOrdinalizer_h_

﻿namespace Humanizer.Localisation.Ordinalizers
{
    internal class ItalianOrdinalizer : DefaultOrdinalizer
    {
        public override string Convert(int number, string numberString)
        {
            return Convert(number, numberString, GrammaticalGender.Masculine);
        }

        public override string Convert(int number, string numberString, GrammaticalGender gender)
        {
            // No ordinal for 0 in italian (neologism apart)
            if (number == 0)
                return "0";

            if (gender == GrammaticalGender.Feminine)
                return numberString + "ª";

            return numberString + "°";
        }
    }
}
#endif // _ItalianOrdinalizer_h_
