#ifndef _DefaultOrdinalizer_h_
#define _DefaultOrdinalizer_h_

﻿namespace Humanizer.Localisation.Ordinalizers
{
    internal class DefaultOrdinalizer : IOrdinalizer
    {
        public virtual string Convert(int number, string numberString, GrammaticalGender gender)
        {
            return Convert(number, numberString);
        }

        public virtual string Convert(int number, string numberString)
        {
            return numberString;
        }
    }
}
#endif // _DefaultOrdinalizer_h_
