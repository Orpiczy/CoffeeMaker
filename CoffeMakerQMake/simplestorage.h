#ifndef SIMPLESTORAGE_H
#define SIMPLESTORAGE_H

#include <map>



template<typename unit,typename storedObj> class SimpleStorage{
    SimpleStorage();
    const std::optional<int> get(const storedObj storedObjSubType) const;
    void set(const storedObj storedObjSubType, const int amount);
private:
    std::map<storedObj,unit> storage;
}

#endif // SIMPLESTORAGE_H
