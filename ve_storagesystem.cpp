#include "ve_storagesystem.h"
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(VEIN_STORAGE, "\033[1;36m<Vein.Storage>\033[0m")

namespace VeinEvent
{
  StorageSystem::StorageSystem(QObject *t_parent) :
    EventSystem(t_parent)
  {
  }

  int StorageSystem::getNextEntityId()
  {
    return ++m_entityIdNext;
  }

  int StorageSystem::m_entityIdNext=0;
}
