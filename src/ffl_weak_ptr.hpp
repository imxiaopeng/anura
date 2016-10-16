#pragma once

#include "reference_counted_object.hpp"

namespace ffl
{

template<typename T>
class weak_ptr : public weak_ptr_base {
public:
	explicit weak_ptr(T* obj=nullptr) : weak_ptr_base(obj)
	{}

	void reset(T* obj=nullptr) {
		init(obj);
	}

	T* get() const { return reinterpret_cast<T*>(get_obj()); }

	weak_ptr(const weak_ptr<T>& p) : weak_ptr_base(p.get()) {
	}

	const weak_ptr<T>& operator=(const weak_ptr<T>& p) {
		init(p.get());
		return *this;
	}
};
}
