#include "ve_eventhandler.h"

#include "ve_eventsystem.h"
#include <QEvent>
#include "vh_logging.h"

namespace VeinEvent
{
  EventHandler::EventHandler(QObject *t_parent) :
    QObject(t_parent)
  {
    vCDebug(VEIN_EVENT) << "Created event handler";
  }

  bool EventHandler::eventTerminationEnabled() const
  {
    return m_eventTerminationEnabled;
  }

  QList<EventSystem *> EventHandler::subsystems() const
  {
    return m_subsystems;
  }

  void EventHandler::setEventTerminationEnabled(bool t_terminationEnabled)
  {
    m_eventTerminationEnabled = t_terminationEnabled;
  }

  void EventHandler::setSubsystems(QList<EventSystem *> t_subsystems)
  {
    if(m_subsystems!=t_subsystems)
    {
      m_subsystems = t_subsystems;
      foreach (EventSystem *tmpSystem, m_subsystems) {
        tmpSystem->attach(this);
      }
      emit subsystemsChanged(t_subsystems);
    }
  }


  void EventHandler::customEvent(QEvent *t_event)
  {
    /** @todo maybe event processing can be accelerated with QtConcurrent? */

    for(int i=0; i < m_subsystems.count() && t_event->isAccepted()==false; ++i)
    {
      m_subsystems.at(i)->processEvent(t_event);
    }

    if(m_eventTerminationEnabled)
    {
      t_event->accept();
    }
  }
}
