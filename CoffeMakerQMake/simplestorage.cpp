#include "simplestorage.h"



template<typename unit, typename storedObj>
const std::optional<int> SimpleStorage<unit, storedObj>::get(const storedObj subType) const
{
    auto subTypeInf = storage.find(subType);
    if(subTypeInf != storage.end()){
        return subTypeInf->second;
    }else{
       return std::nullopt;
    }
}

template<typename unit, typename storedObj>
void SimpleStorage<unit, storedObj>::set(const storedObj subType, const int amount)
{
    auto subTypeInf = storage.find(subType);
    if(subTypeInf != storage.end()){
        subTypeInf->second = amount;
    }
}
