#include <iostream>
namespace whoamifk_dequeue {
	template<typename T>
	struct node {
		T _data;
		node<T>* _left;
		node<T>* _right;
		node(T val, node<T>* _l = nullptr, node<T>* _r = nullptr)
			: _data(val),_left(_l),_right(_r)
		{

		}
	};

	template<class T, class _Alloc=std::allocator<node<T>>>
	class dequeue {
	public:
		typedef dequeue<T, _Alloc> _deq;
		typedef T _val_type;
		typedef _Alloc _allocator_type;
		typedef node<T>* pointer;
		typedef const node<T>* const_pointer;
		typedef node<T>* iterator;
		typedef const node<T>* const_iterator;
		typedef std::size_t size_type;
	private:
		pointer _head;
		pointer _tail;
		size_type _size;
		size_type _capacity;
	};
}

int main()
{
	
	return 0;
}
