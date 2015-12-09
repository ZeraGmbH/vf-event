#ifndef VEINEVENT_GLOBAL_H
#define VEINEVENT_GLOBAL_H

#include <QtCore/qglobal.h>
#include "vh_logging.h"

/*! \mainpage Vein Framework
 *
 * \section Introduction
 *
 * Event based Entity Component System implementation (ECS)
 *
 *
 * \section Download
 *
 * git clone ssh://git@s-zera-source01/~/soc/libs/vein-framework/vein-framework.git
 *
 * \section Initialization
 *
 * cd vein-framework && ./scripts/setup-git-zera.sh
 *
 */

Q_DECLARE_LOGGING_CATEGORY(VEIN_EVENT)
Q_DECLARE_LOGGING_CATEGORY(VEIN_SCRIPTEVENT)

#if defined(VEINEVENT_LIBRARY)
#  define VEINEVENTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define VEINEVENTSHARED_EXPORT Q_DECL_IMPORT
#endif


#if defined(VEIN_COLORS_SUPPORT)
# define VEIN_DEBUGNAME_EVENT "\e[1;34m<Vein.Event>\033[0m"
# define VEIN_DEBUGNAME_SCRIPT "\e[1;37m<Vein.Script>\033[0m"
#else
# define VEIN_DEBUGNAME_EVENT "<Vein.Event>"
# define VEIN_DEBUGNAME_SCRIPT "<Vein.Script>"
#endif //defined(VEIN_DEBUG_COLOR_SUPPORT)


#endif // VEINEVENT_GLOBAL_H
