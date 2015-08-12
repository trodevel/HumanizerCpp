#ifndef _DateHumanizeExtensions_h_
#define _DateHumanizeExtensions_h_

//using System.Globalization;
//using Humanizer.Configuration;

#include "CultureInfo.h"        // CultureInfo

namespace Humanizer
{
    using System::Globalization::CultureInfo;

    /// <summary>
    /// Humanizes DateTime into human readable sentence
    /// </summary>
    class DateHumanizeExtensions
    {
        public:
#ifdef XXX
        /// <summary>
        /// Turns the current or provided date into a human readable sentence
        /// </summary>
        /// <param name="input">The date to be humanized</param>
        /// <param name="utcDate">Boolean value indicating whether the date is in UTC or local</param>
        /// <param name="dateToCompareAgainst">Date to compare the input against. If null, current date is used as base</param>
        /// <param name="culture">Culture to use. If null, current thread's UI culture is used.</param>
        /// <returns>distance of time in words</returns>
        static std::string Humanize(this DateTime input, bool utcDate = true, DateTime? dateToCompareAgainst = null, CultureInfo culture = null)
        {
            var comparisonBase = dateToCompareAgainst ?? DateTime.UtcNow;

            if (!utcDate)
                comparisonBase = comparisonBase.ToLocalTime();

            return Configurator.DateTimeHumanizeStrategy.Humanize(input, comparisonBase, culture);
        }
#endif // XXX

#ifdef XXX
        /// <summary>
        /// Turns the current or provided date into a human readable sentence
        /// </summary>
        /// <param name="input">The date to be humanized</param>
        /// <param name="dateToCompareAgainst">Date to compare the input against. If null, current date is used as base</param>
        /// <param name="culture">Culture to use. If null, current thread's UI culture is used.</param>
        /// <returns>distance of time in words</returns>
        static std::string Humanize(DateTimeOffset input, DateTimeOffset? dateToCompareAgainst = null, CultureInfo culture = null)
        {
            var comparisonBase = dateToCompareAgainst ?? DateTimeOffset.UtcNow;

            return Configurator.DateTimeOffsetHumanizeStrategy.Humanize(input, comparisonBase, culture);
        }
#endif // XXX
    };
}
#endif // _DateHumanizeExtensions_h_
