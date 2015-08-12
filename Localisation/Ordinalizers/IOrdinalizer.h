#ifndef _IOrdinalizer_h_
#define _IOrdinalizer_h_

﻿namespace Humanizer.Localisation.Ordinalizers
{
    /// <summary>
    /// The interface used to localise the Ordinalize method
    /// </summary>
    public interface IOrdinalizer
    {
        /// <summary>
        /// Ordinalizes the number 
        /// </summary>
        /// <param name="number"></param>
        /// <param name="numberString"></param>
        /// <returns></returns>
        string Convert(int number, string numberString);

        /// <summary>
        /// Ordinalizes the number using the provided grammatical gender
        /// </summary>
        /// <param name="number"></param>
        /// <param name="numberString"></param>
        /// <param name="gender"></param>
        /// <returns></returns>
        string Convert(int number, string numberString, GrammaticalGender gender);
    }
}

#endif // _IOrdinalizer_h_
