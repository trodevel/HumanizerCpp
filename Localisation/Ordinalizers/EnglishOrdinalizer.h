#ifndef _EnglishOrdinalizer_h_
#define _EnglishOrdinalizer_h_

﻿namespace Humanizer.Localisation.Ordinalizers
{
    internal class EnglishOrdinalizer : DefaultOrdinalizer
    {
        public override string Convert(int number, string numberString)
        {
            int nMod100 = number % 100;

            if (nMod100 >= 11 && nMod100 <= 13)
                return numberString + "th";

            switch (number % 10)
            {
                case 1:
                    return numberString + "st";

                case 2:
                    return numberString + "nd";

                case 3:
                    return numberString + "rd";

                default:
                    return numberString + "th";
            }
        }
    }
}
#endif // _EnglishOrdinalizer_h_
