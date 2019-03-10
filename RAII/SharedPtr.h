#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <memory>
#include <iostream>

template <class T>
class SharedPtr{
public:
    explicit SharedPtr(T* h)
            :m_resource(h)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        m_instCount = new InstCount;
        m_instCount->m_count = 1;
    }

    SharedPtr(const SharedPtr & sharedPtr)
    {
        std::cout << __PRETTY_FUNCTION__ << sharedPtr.m_instCount->m_count << " m_instCount++" << std::endl;
        m_resource = sharedPtr.m_resource;
        m_instCount = sharedPtr.m_instCount;
        m_instCount->m_count++;
    };
    SharedPtr<T>& operator=(SharedPtr<T> const&) = default;

    SharedPtr(SharedPtr&& handler){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
		m_resource=handler.m_resource;
		handler.m_resource=nullptr;
	}
    SharedPtr& operator=(SharedPtr&& rhs)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

		if ( std::addressof(*this) != std::addressof(rhs) ){
			delete m_resource;
			m_resource=rhs.m_resource;
			rhs.m_resource=nullptr;

			std::cout << std::hex << m_resource << std::endl;
		}

		return *this;
	}

    template<class P> SharedPtr(SharedPtr<P>&& handler)
            :m_resource(handler.release()){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
    ~SharedPtr()
    {
        std::cout << __PRETTY_FUNCTION__ << m_instCount->m_count << " m_instCount--" << std::endl;
        m_instCount->m_count--;
        if (m_instCount->m_count < 1){
            delete m_resource;
            delete m_instCount;
        }

    }

    T& operator *(){
		return *m_resource;
	}
    T* operator ->(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return m_resource;
	}
    T* release(){
		T* t=m_resource;
		m_resource=nullptr;
		return t;
	}

private:
    class InstCount{
    public:

        int m_count{};
    };

    InstCount * m_instCount = nullptr;
    T* m_resource;
};

template <class T, class ...ARG>
SharedPtr<T> makeShared(ARG&& ...arg){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return SharedPtr<T>(new T( std::forward<ARG>(arg)...));
}
#endif // SHARED_PTR_H
