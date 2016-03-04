#include "ve_validator.h"

#include "ve_commandevent.h"
#include "ve_eventdata.h"

namespace VeinEvent
{

  Validator::Validator(QObject *t_parent) :
    EventSystem(t_parent)
  {
  }

  bool Validator::processEvent(QEvent *t_event)
  {
    bool retVal = false;


    if(t_event->type() == CommandEvent::eventType())
    {
      CommandEvent *cEvent = 0;
      EventData *evData = 0;
      cEvent = static_cast<VeinEvent::CommandEvent *>(t_event);
      Q_ASSERT(cEvent != 0);

      evData = cEvent->eventData();
      Q_ASSERT(evData != 0);

      switch(cEvent->eventSubtype())
      {
        case CommandEvent::EventSubtype::TRANSACTION:
        {
          retVal = true;
          cEvent->setEventSubtype(CommandEvent::EventSubtype::NOTIFICATION);
          evData->setEventOrigin(EventData::EventOrigin::EO_LOCAL); //the validated answer is authored from the system that runs the validator (aka. this system)
          evData->setEventTarget(EventData::EventTarget::ET_ALL); //inform all users (may or may not result in network messages)

          vCDebug(VEIN_EVENT) << "Translated transaction event:" << cEvent << "into a notification event";
          break;
        }
        default:
          break;
      }
    }
    return retVal;
  }
} // namespace VeinEvent
