#ifndef _GrammaticalGender_h_
#define _GrammaticalGender_h_

namespace Humanizer
{
    /// <summary>
    /// Options for specifying the desired grammatical gender for the output words
    /// </summary>
    enum class GrammaticalGender
    {
        /// <summary>
        /// Indicates masculine grammatical gender
        /// </summary>
        Masculine,
        /// <summary>
        /// Indicates feminine grammatical gender
        /// </summary>
        Feminine,
        /// <summary>
        /// Indicates neuter grammatical gender
        /// </summary>
        Neuter
    };
}

#endif // _GrammaticalGender_h_
