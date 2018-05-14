/*
 * Handler.h
 *
 *  Created on: May 3, 2018
 *      Author: training
 */


#ifndef UNUQUE_PTR_H
#define UNUQUE_PTR_H

#include <memory>

template <class T>
class UniquePtr{
public:
	UniquePtr(T* h):m_resource(h){}

	UniquePtr(const UniquePtr &) = delete;
	UniquePtr<T>& operator=(UniquePtr<T> const&) = delete;

	UniquePtr(UniquePtr&& handler){
		m_resource=handler.m_resource;
		handler.m_resource=nullptr;
	}

	UniquePtr& operator=(UniquePtr&& rhs){
		if ( std::addressof(*this) != std::addressof(rhs) ) {
			delete m_resource;
			m_resource=rhs.m_resource;
			rhs.m_resource=nullptr;

			std::cout << std::hex << m_resource << std::endl;
		}
		return *this;
	}

	template<class P>
	UniquePtr(UniquePtr<P>&& handler)
		:m_resource(handler.release()){
	}

	~UniquePtr(){
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
UniquePtr<T> makeUnique(ARG&& ...arg){
	return UniquePtr<T>(new T( std::forward<ARG>(arg)...));
}
#endif // UNUQUE_PTR_H
