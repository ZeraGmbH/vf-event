#ifndef SCRIPTSYSTEM_H
#define SCRIPTSYSTEM_H

#include "vein-event_global.h"

#include "ve_eventsystem.h"

class QFile;

namespace VeinEvent
{
  class StorageSystem;
  //class ComponentEvent;
  class NetworkEvent;

  /**
   * @brief A simple event based script engine
   * @todo Redesign script functionality entirely
   */
  class VEINEVENTSHARED_EXPORT AbstractScriptEngine : public EventSystem
  {
    Q_OBJECT
  public:
    explicit AbstractScriptEngine(QObject *t_parent=0);
    ~AbstractScriptEngine();

  public:
    virtual void addScript(int t_orderId, QIODevice &t_newScript, QString t_fileName=QString())=0;
    virtual void replaceScript(int t_orderId, QIODevice &t_newScript, QString t_fileName=QString())=0;
    virtual void removeScript(int t_orderId)=0;
    virtual void clearScripts()=0;

    /**
     * @brief Loads the script from the QIODevice if it is readable
     * @param t_url url pointing to the script file
     */
    virtual void loadScript(QUrl &t_url) =0;

  };
}

#endif // SCRIPTSYSTEM_H
