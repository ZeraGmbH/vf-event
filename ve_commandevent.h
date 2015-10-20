#ifndef VE_TRANSACTIONEVENT_H
#define VE_TRANSACTIONEVENT_H

#include "vein-event_global.h"

#include <QEvent>
#include <QVariant>

namespace VeinEvent
{
  class EventData;

  class VEINEVENTSHARED_EXPORT CommandEvent : public QEvent
  {
  public:
    /**
     * @brief The EventSubtype enum provides information about the authoritative status of the event
     */
    enum class EventSubtype : qint8 {
      NOTIFICATION = 0, /**< The event meets the authoritative requirements (if any) */
      TRANSACTION = 1 /**< The event requires to be inspected about its authoritative status */
    };

    explicit CommandEvent(EventSubtype subtype, EventData *data);
    ~CommandEvent();

    static int eventType();

    int peerId() const;
    void setPeerId(int pPeerId);

    EventSubtype eventSubtype() const;
    void setEventSubtype(EventSubtype newType);

    /**
     * @brief eventData
     * @return do not use the pointer in a contex where it could be deleted, failing to do so will result in a double delete segfault
     */
    EventData *eventData();

  private:
    /**
     * @brief 'Randomly' assigned static event type (QEvent::Type)
     */
    static int m_eventType;

    /**
     * @brief Depending on the context of the event this may be the sender or receiver of the event, defaults to -1
     * @note Validator may use this data to check for permissions, an introspection system may use this data for sender/receiver addressing
     */
    int m_peerId = -1;

    /**
     * @brief The authoritative status of the event
     */
    EventSubtype m_subtype;

    /**
     * @brief Payload of the event
     */
    EventData *m_eventData;
  };
}
#endif // VE_TRANSACTIONEVENT_H
