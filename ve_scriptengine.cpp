#include "ve_scriptengine.h"

#include <QEvent>

#include <QFile>

namespace VeinEvent
{
  AbstractScriptEngine::AbstractScriptEngine(QObject *t_parent) :
    EventSystem(t_parent)
  {
    qCDebug(VEIN_SCRIPTEVENT) << "Created script system";
  }

  AbstractScriptEngine::~AbstractScriptEngine()
  {
    qCDebug(VEIN_SCRIPTEVENT) << "Destroyed script system";

    /// @note Qt parent system deletes the m_engine automagical
  }


  QString AbstractScriptEngine::loadScript(QIODevice &t_device)
  {
    QString retVal;
    if(t_device.isOpen() == false)
    {
      t_device.open(QFile::ReadOnly);
    }

    if(t_device.isReadable())
    {
      retVal = QString::fromUtf8(t_device.readAll());
    }
    else
    {
      //warning
    }
    t_device.close();
    return retVal;
  }
}
