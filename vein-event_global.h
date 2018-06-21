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

#endif // VEINEVENT_GLOBAL_H
