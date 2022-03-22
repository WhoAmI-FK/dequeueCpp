#include <iostream>
namespace whoamifk_deque {


	template<class T, class _Alloc=std::allocator<T>>
	class deque {
	public:
		typedef deque<T, _Alloc> _deq;
		typedef T _val_type;
		typedef _Alloc _allocator_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef std::size_t size_type;
		deque()
			:_que(_Alloc().allocate(20)),
			_capacity(20),_size(0)
		{

		}
		~deque() {
			if (!empty()) {
				for (iterator i = begin(); i != end(); ++i) {
					_Alloc().destroy(i);
				}
				_Alloc().deallocate(_que, _capacity);
			}
		}
		bool empty() const {
			return _size == 0;
		}
		iterator begin() {
			return &_que[0];
		}
		iterator end() {
			return &_que[_size];
		}
		void push_back(const _val_type& val) {
			if (++_size >= _capacity) {
				// resize
			}
			_Alloc().construct(&_que[_size - 1], val);	
		}
		void pop_back() {
			if (!empty()) {
				_Alloc().destroy(&_que[_size - 1]);
				_size--;
			}
			else {
				throw std::runtime_error("Trying to pop empty deque.");
			}
		}
		void push_front(const _val_type& val) {
		
			for (iterator i = end(); i != begin();i-- ) {
				std::swap(*i, *(i - 1));
			}
			_Alloc().construct(&_que[0], val);
			if (++_size >= _capacity) {
					//resize
			}
		}
	private:
		T* _que;
		size_type _size;
		size_type _capacity;
	};
}

int main()
{
	try {
		//
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}
