#ifndef RAII_TESTSHAREDPTR_H
#define RAII_TESTSHAREDPTR_H

class TestSharedPtr
{
public:
    void Do();

private:
    void testCreateSharePtrCtor();
    void testCreateMakeShared();
    void testCopySharePtr();
    void testCopySharePtrReturn();
};
#endif //RAII_TESTSHAREDPTR_H
