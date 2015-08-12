#ifndef _RussianOrdinalizer_h_
#define _RussianOrdinalizer_h_

﻿namespace Humanizer.Localisation.Ordinalizers
{
    internal class RussianOrdinalizer : DefaultOrdinalizer
    {
        public override string Convert(int number, string numberString)
        {
            return Convert(number, numberString, GrammaticalGender.Masculine);
        }

        public override string Convert(int number, string numberString, GrammaticalGender gender)
        {
            if (gender == GrammaticalGender.Masculine)
                return numberString + "-й";
            
            if (gender == GrammaticalGender.Feminine)
                return numberString + "-я";

            return numberString + "-е";
        }
    }
}

#endif // _RussianOrdinalizer_h_
