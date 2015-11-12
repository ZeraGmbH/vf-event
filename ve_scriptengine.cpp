#include "ve_scriptengine.h"

#include <QEvent>

#include <QFile>

namespace VeinEvent
{
  AbstractScriptEngine::AbstractScriptEngine(QObject *t_parent) :
    EventSystem(t_parent)
  {
    vCDebug(VEIN_SCRIPTEVENT) << "Created script system";
  }

  AbstractScriptEngine::~AbstractScriptEngine()
  {
    vCDebug(VEIN_SCRIPTEVENT) << "Destroyed script system";

    /// @note Qt parent system deletes the m_engine automagical
  }
}
