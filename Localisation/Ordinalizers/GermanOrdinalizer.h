#ifndef _GermanOrdinalizer_h_
#define _GermanOrdinalizer_h_

﻿namespace Humanizer.Localisation.Ordinalizers
{
    internal class GermanOrdinalizer : DefaultOrdinalizer
    {
        public override string Convert(int number, string numberString)
        {
            return numberString + ".";
        }
    }
}
#endif // _GermanOrdinalizer_h_
