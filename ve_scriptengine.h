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

  class VEINEVENTSHARED_EXPORT AbstractScriptEngine : public EventSystem
  {
    Q_OBJECT
  public:
    explicit AbstractScriptEngine(QObject *t_parent=0);
    ~AbstractScriptEngine();

  public:
    /**
     * @brief addScript
     * @param orderId The execution order depends on this id, every id should be unique
     * @param newScript
     * @param fileName Used for script debugging (e.g. error messages from the scriptengine)
     */
    virtual void addScript(int t_orderId, QIODevice &t_newScript, QString t_fileName=QString())=0;
    virtual void replaceScript(int t_orderId, QIODevice &t_newScript, QString t_fileName=QString())=0;
    virtual void removeScript(int t_orderId)=0;
    virtual void clearScripts()=0;

  protected:
    /**
     * @brief Loads the script from the QIODevice if it is readable
     * @param f As QIODevice anything could be inserted here (QFile, QByteArray via QBuffer...)
     * @return script in String form
     */
    virtual QString loadScript(QIODevice &t_device) final;

  };
}

#endif // SCRIPTSYSTEM_H
