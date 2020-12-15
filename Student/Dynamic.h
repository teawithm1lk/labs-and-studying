#include <iostream>

template <class C>
class Dynamic {
public:
	Dynamic()
	{
		size_ = 0;
		data_ = nullptr;
	}
	Dynamic(size_t size)
	{
		size_ = size;
		data_ = new C[size];
	}
	Dynamic(const Dynamic<C>& object)
	{
		this->size_ = object.size_;
		data_ = new C[this->size_];
		for (int i = 0; i < this->size_; i++)
		{
			this->data_[i] = object.data_[i];
		}
	}
	~Dynamic()
	{
		delete[]data_;
	};

	size_t getSize() const
	{
		return this->size_;
	}
	C& operator[] (size_t index) const
	{
		if (index >= this->size_)
		{
			throw "Error! Get out of range of array!";
		}
		return this->data_[index];
	}
	Dynamic& operator= (Dynamic& other)
	{
		delete[] this->data_;
		this->size_ = other.size_;
		this->data_ = new C[this->size_];
		for (size_t i; i < this->size_; ++i)
		{
			this->data_[i] = other.data_[i];
		}
		return *this;
	}

	void push_back(C& element)
	{
		Dynamic<C> temp = *this;
		delete[] this->data_;
		data_ = new C[this->size_ + 1];
		for (size_t i = 0; i < this->size_; ++i) 
		{
			this->data_[i] = temp[i];
		}
		this->data_[size_] = element;
		size_++;
	}
private:
	size_t size_;
	C* data_;
};