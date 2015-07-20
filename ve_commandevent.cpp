#include "ve_commandevent.h"
#include "ve_eventdata.h"

namespace VeinEvent
{

  CommandEvent::CommandEvent(EventSubtype subtype, EventData *data) :
    QEvent(static_cast<QEvent::Type>(eventType())),
    m_subtype(subtype),
    m_eventData(data)
  {
    if(data->isValid() == false)
    {
      qCWarning(VEIN_EVENT) << "Invalid event data" << data;
    }
    this->setAccepted(false);
  }

  CommandEvent::~CommandEvent()
  {
    delete m_eventData;
  }


  int CommandEvent::eventType()
  {
    if(m_eventType==0)
    {
      m_eventType = QEvent::registerEventType();
    }
    return m_eventType;
  }

  int CommandEvent::peerId() const
  {
    return m_peerId;
  }

  void CommandEvent::setPeerId(int pPeerId)
  {
    if(pPeerId >= 0)
    {
      m_peerId = pPeerId;
    }
  }

  CommandEvent::EventSubtype CommandEvent::eventSubtype() const
  {
    return m_subtype;
  }

  void CommandEvent::setEventSubtype(CommandEvent::EventSubtype newType)
  {
    m_subtype = newType;
  }

  EventData *CommandEvent::eventData()
  {
    return m_eventData;
  }

  int CommandEvent::m_eventType =0;
}
