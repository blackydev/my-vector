#ifndef JIPP_PROJECT_FIND_ONE_H
#define JIPP_PROJECT_FIND_ONE_H

template <typename T, typename Key>
T* findOne(T* beginPtr, const T* endPtr, const Key& key) {
    if (beginPtr >= endPtr)
        return nullptr;

    T* ptrTmp = const_cast<T*>(beginPtr);

    for (; ptrTmp != endPtr; ptrTmp++)
        if (*ptrTmp == key)
            return ptrTmp;

    return nullptr;
}

#endif //JIPP_PROJECT_FIND_ONE_H
