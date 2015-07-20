#include "ve_eventsystem.h"
#include "ve_eventhandler.h"
#include <QLoggingCategory>
#include <QCoreApplication>

Q_LOGGING_CATEGORY(VEIN_EVENT, VEIN_DEBUGNAME_EVENT)
Q_LOGGING_CATEGORY(VEIN_SCRIPTEVENT, VEIN_DEBUGNAME_SCRIPT)

namespace VeinEvent
{
  EventSystem::EventSystem(QObject *t_parent) :
    QObject(t_parent)
  {
  }

  void EventSystem::attach(EventHandler *t_eventHandler)
  {
    if(m_attached == false)
    {
      QObject::connect(this,&VeinEvent::EventSystem::sigSendEvent,[=](QEvent *ev)
      {
        /// @todo add multithreaded event sending support
        QCoreApplication::instance()->postEvent(t_eventHandler, ev);
      });
      m_attached = true;
    }
  }
}
