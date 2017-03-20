#ifndef VE_COMMANDEVENT_H
#define VE_COMMANDEVENT_H

#include "vein-event_global.h"

#include <QEvent>
#include <QVariant>

namespace VeinEvent
{
  class EventData;

  /**
   * @brief The CommandEvent class is a container for component and entity changes
   */
  class VEINEVENTSHARED_EXPORT CommandEvent : public QEvent
  {
  public:
    /**
     * @brief The EventSubtype enum provides information about the authoritative status of the event
     */
    enum class EventSubtype : int {
      NOTIFICATION = 0, /**< The event meets the authoritative requirements (if any) */
      TRANSACTION = 1 /**< The event requires to be inspected about its authoritative status */
    };

    explicit CommandEvent(EventSubtype t_subtype, EventData *t_data);
    ~CommandEvent();

    static int eventType();

    int peerId() const;
    void setPeerId(int t_pPeerId);

    EventSubtype eventSubtype() const;
    void setEventSubtype(EventSubtype t_newType);

    /**
     * @brief eventData
     * @return do not use the pointer in a context where it could be deleted, failing to do so will result in a double delete segfault
     */
    EventData *eventData() const;

  private:
    /**
     * @brief 'Randomly' assigned static event type (QEvent::Type)
     */
    static const int s_eventType;

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
#endif // VE_COMMANDEVENT_H
