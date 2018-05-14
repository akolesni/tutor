/*
 * Handler.h
 *
 *  Created on: May 3, 2018
 *      Author: training
 */


#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <memory>

template <class T>
class SharedPtr{
public:
	SharedPtr(T* h):m_resource(h){}

	SharedPtr(const SharedPtr &) = delete;
	SharedPtr<T>& operator=(SharedPtr<T> const&) = delete;

	SharedPtr(SharedPtr&& handler){
		m_resource=handler.m_resource;
		handler.m_resource=nullptr;
	}

	SharedPtr& operator=(SharedPtr&& rhs){
		if ( std::addressof(*this) != std::addressof(rhs) ) {
			delete m_resource;
			m_resource=rhs.m_resource;
			rhs.m_resource=nullptr;

			std::cout << std::hex << m_resource << std::endl;
		}
		return *this;
	}

	template<class P>
	SharedPtr(SharedPtr<P>&& handler)
		:m_resource(handler.release()){
	}

	~SharedPtr(){
		delete m_resource;
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
	T* m_resource;
};

template <class T, class ...ARG>
SharedPtr<T> makeUnique(ARG&& ...arg){
	return SharedPtr<T>(new T( std::forward<ARG>(arg)...));
}
#endif // SHARED_PTR_H
