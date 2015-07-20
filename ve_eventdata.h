#ifndef VEINEVENT_VE_EVENTDATA_H
#define VEINEVENT_VE_EVENTDATA_H

#include "vein-event_global.h"

#include <QByteArray>

namespace VeinEvent
{
  /**
   * @brief The data of CommandEvent designed like the Command pattern from the GoF book
   */
  class VEINEVENTSHARED_EXPORT EventData
  {
  public:
    EventData();
    virtual ~EventData() {}

    enum class EventOrigin : qint8 {
      EO_LOCAL = 0,
      EO_FOREIGN = 1
    };

    EventOrigin eventOrigin() const;
    void setEventOrigin(EventOrigin t_eventOrigin);

    enum class EventTarget : qint8 {
      ET_IRRELEVANT = 0, /**< the target is irrelevant for incoming remote events */
      ET_LOCAL = 1, /**< flags that the event should not be transmitted over the network border */
      ET_ALL = 2 /**< the event can be transmitted freely */
    };

    EventTarget eventTarget() const;
    void setEventTarget(EventTarget t_eventTarget);

    virtual int type() =0;

    virtual bool isValid() const;

    /**
     * @brief Used to encode the class in binary information form
     * @note m_eventTarget and m_eventOrigin are not encoded as they are local only informations
     * @return
     */
    virtual QByteArray serialize() const = 0;

    /**
     * @brief Used to decode the class from binary information form
     * @note m_eventTarget and m_eventOrigin are not encoded as they are local only informations
     * @return
     */
    virtual void deserialize(const QByteArray &t_data) = 0;

    /**
     * @brief unique id of the entity concerning this event data
     */
    int entityId() const;
    void setEntityId(int t_entityId);

  private:
    /**
     * @note this member variable is not serialized, as it is only valid in a local context
     */
    EventOrigin m_eventOrigin;

    /**
     * @note this member variable is not serialized, as it is only valid in a local context
     */
    EventTarget m_eventTarget;

    int m_entityId = -1;
  };
} // namespace VeinEvent

#endif // VEINEVENT_VE_EVENTDATA_H
