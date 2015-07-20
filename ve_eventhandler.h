#ifndef VEINEVENTHANDLER_H
#define VEINEVENTHANDLER_H

#include "vein-event_global.h"

#include <QObject>
#include <QList>

namespace VeinEvent
{
  class EventSystem;

  /**
   * @brief A simple event handler
   * @note if you want to capture events, eg. for replay, please note that the QEvent::type (see http://doc.qt.io/qt-5/qevent.html#type) of most events is not initialized in a deterministic manner
   * @todo multithreading support
   * @todo maybe implement specialized groups of systems with the strategy pattern
   */
  class VEINEVENTSHARED_EXPORT EventHandler : public QObject
  {
    Q_OBJECT

    Q_PROPERTY(bool eventTerminationEnabled READ eventTerminationEnabled WRITE setEventTerminationEnabled)
    Q_PROPERTY(QList<EventSystem*> subsystems READ subsystems WRITE setSubsystems NOTIFY subsystemsChanged)

  public:
    explicit EventHandler(QObject *t_parent=0);

    bool eventTerminationEnabled() const;

    QList<EventSystem*> subsystems() const;

  public slots:
    void setEventTerminationEnabled(bool t_terminationEnabled);

    /**
     * @brief Sets up the list of EventSystem
     *
     * @warning the EventHandler is not responsible for deleting subsystems
     */
    void setSubsystems(QList<EventSystem*> t_subsystems);

  signals:
    void subsystemsChanged(QList<EventSystem*> t_subsystems);

  protected:
    void customEvent(QEvent *t_event) override;

  private:
    /**
     * @brief If set events will be set as accepted after processing to not pollute other event handlers
     */
    bool m_eventTerminationEnabled = true;

    /**
     * @brief Ordered list of event system that is reprenstable for the event processing order
     * @todo add partitioning of event systems by event type to reduce overhead in event processing
     */
    QList<EventSystem*> m_subsystems;
  };
}
#endif // VEINEVENTHANDLER_H
