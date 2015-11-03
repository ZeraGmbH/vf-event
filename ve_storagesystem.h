#ifndef STORAGESYSTEM_H
#define STORAGESYSTEM_H

#include "vein-event_global.h"

#include "ve_eventsystem.h"

Q_DECLARE_LOGGING_CATEGORY(VEIN_STORAGE)

namespace VeinEvent
{
  /**
   * @brief Interface to stores entity/component data, abstracts away implementation details of the underlying storage
   */
  class VEINEVENTSHARED_EXPORT StorageSystem : public EventSystem
  {
    Q_OBJECT
  public:
    explicit StorageSystem(QObject *t_parent=0);

    /**
     * @brief getNextEntityId
     * @return
     * @todo change the implementation, suggested is something like: https://github.com/SuperV1234/SSVUtils/blob/master/include/SSVUtils/HandleVector/HandleVector.hpp
     * @warning not thread safe
     */
    static int getNextEntityId();

    enum StorageType {
      MEMORY_STORAGE = 0, /**< like a QHash or an in memory SQLITE DB */
      FILE_STORAGE = 1, /**< like a JSON file or a SQLITE file DB */
      NETWORK_STORAGE = 2 /**< like a DHT or a MySQL database */
    };

    /**
     * @brief Depending on the StorageType the storage system is useful for different purposes
     * @return Returns the StorageType of this implementation
     */
    virtual StorageType getStorageType() const=0;


    /**
     * @brief Execution speed depends on the implementation
     * @param t_entityId
     * @param t_componentName
     * @return May be invalid if no data is found / or the storage is not accessible
     */
    virtual QVariant getStoredValue(int t_entityId, const QString &t_componentName) const =0;
    virtual bool hasStoredValue(int t_entityId, const QString &t_componentName) const =0;

    /**
     * @brief Retrieves a list of the components from entity t_entityId
     * @return
     */
    virtual QList<QString> getEntityComponents(int t_entityId) const =0;
    virtual bool hasEntity(int t_entityId) const =0;

    virtual QList<int> getEntityList() const =0;

    /**
     * @brief Causes a StorageType specific dump of the storage contents to a file
     * Useful for debugging purposes.
     *
     * @param t_fileDevice file path for the dump
     * @param t_overwrite overwrites existing files if set to true
     */
    virtual void dumpToFile(QIODevice *t_fileDevice, bool t_overwrite=false) const=0;

    /**
     * @brief Optional function that sets up the storage
     * @param t_sourceUrl
     * @return success indicator
     */
    virtual bool initializeData(const QUrl &t_sourceUrl)=0;

  private:
    /**
     * @todo add a consecutive tracking variable that cannot overflow and recycles unused numbers
     */
    static int m_entityIdNext;
  };
}

#endif // STORAGESYSTEM_H

