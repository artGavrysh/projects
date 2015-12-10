/*
 *  Imagine you have a call center with three levels of employees: fresher, technical lead (TL), product manager (PM). 
 *  There can be multiple employees, but only one TL or PM. An incoming telephone call must be allocated to a fresher 
 *  who is free. If a fresher can’t handle the call, he or she must escalate the call to technical lead. 
 *  If the TL is not free or not able to handle it, then the call should be escalated to PM. 
 *  Design the classes and data structures for this problem. Implement a method getCallHandler().
 */
#include <iostream>

typedef void (*fpt)(int); // a pointer to a function taking int and returning nothing

static void foo (int argc);

class Employee //interface
{
public:
    virtual ~Employee() {}
    virtual fpt getCallHandler(void) = 0;
};

class ProductManager : public Employee
{
public:
    ProductManager();
    virtual ~ProductManager() {}
    virtual fpt getCallHandler(void)
    {
        return &foo; 
    }
};

class TechnicalLead : public ProductManager
{
protected:
    bool isAble;
    bool isFree;
public:
    TechnicalLead();
    virtual ~TechnicalLead(){}
    
    virtual fpt getCallHandler(void)
    {
        if (!isFree || !isAble)
            return ProductManager::getCallHandler();
        else
            return &foo;
    }
};

class Fresher : public TechnicalLead
{
public:
    Fresher();
    virtual ~Fresher();
    virtual fpt getCallHandler(void)
    {
        if (!isFree || !isAble)
           return TechnicalLead::getCallHandler();
        else
           return &foo;
    }
};

int main()
{
    //
    return 0;
}
