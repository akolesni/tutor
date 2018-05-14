#include "TestSharedPtr.h"
#include "SharedPtr.h"
#include "Base.h"

void TestSharedPtr::Do()
{
//    testCreateSharePtrCtor();
//    testCreateMakeShared();
//    testCopySharePtr();
    testCopySharePtrReturn();
}

void copySharePtr2(SharedPtr<Base> sharedPtr)
{
    std::cout << "\n" << __PRETTY_FUNCTION__ << "---" << std::endl;
    sharedPtr->operation();
}

void copySharePtr1(SharedPtr<Base> sharedPtr)
{
    std::cout << "\n" << __PRETTY_FUNCTION__ << "---" << std::endl;
//    sharedPtr->operation();
    copySharePtr2(sharedPtr);
}

void TestSharedPtr::testCreateSharePtrCtor()
{
    std::cout << "\n---" << __PRETTY_FUNCTION__ << "---" << std::endl;
    SharedPtr<Base> sharedPtr(new Base(10));
}

void TestSharedPtr::testCreateMakeShared()
{
    std::cout << "\n---" <<__PRETTY_FUNCTION__ << "---" << std::endl;
    auto sharedPtr = makeShared<Base>();
}

void TestSharedPtr::testCopySharePtr()
{
    std::cout << "\n---" <<__PRETTY_FUNCTION__ << "---" << std::endl;
    auto sharedPtr = makeShared<Base>(4);
    std::cout << "bf copySharePtr1" << std::endl;
    copySharePtr1(sharedPtr);
    std::cout << "af copySharePtr1" << std::endl;
}



SharedPtr<Base> getSharedPtr(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    auto sharedPtr = makeShared<Base>(4);

    return sharedPtr;
}

void TestSharedPtr::testCopySharePtrReturn()
{
    SharedPtr<Base> ptr = makeShared<Base>();
    SharedPtr<Base> ptr1 = ptr;

    ptr = getSharedPtr();

    copySharePtr1(ptr1);
}
