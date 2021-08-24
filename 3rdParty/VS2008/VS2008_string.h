// xstring internal header (from <string>)
#pragma once
#ifndef _VS2008_XSTRING_
#define _VS2008_XSTRING_
#ifndef RC_INVOKED
#include "VS2008_iosfwd.h"
#include "VS2008_xmemory.h"
//#include <xmemory>

#ifdef _MSC_VER
#pragma pack(push,_CRT_PACKING)
#pragma warning(push,3)
#pragma warning(disable:4412)
#endif  /* _MSC_VER */

#define _DEFINE_DLL_OVERLOADS 0
#define _NO_DEBUG_PLACEHOLDER _No_debug_placeholder = _No_debug_placeholder()

namespace VS2008 { //_STD_BEGIN

#pragma warning(disable:4251)

template<class _Elem,
	class _Traits = char_traits<_Elem>,
	class _Ax = allocator<_Elem> >
	class basic_string;

// TEMPLATE CLASS _String_const_iterator
template<class _Elem,
	class _Traits,
	class _Alloc>
	class _String_const_iterator
	: public _Ranit_base<_Elem, typename _Alloc::difference_type,
	typename _Alloc::const_pointer, typename _Alloc::const_reference, _Iterator_base_secure>
{	// iterator for nonmutable string
public:
	typedef _String_const_iterator<_Elem, _Traits, _Alloc> _Myt;
	typedef basic_string<_Elem, _Traits, _Alloc> _Mystring;

	typedef std::random_access_iterator_tag iterator_category;
	typedef _Elem value_type;
	typedef typename _Alloc::difference_type difference_type;
	typedef typename _Alloc::const_pointer pointer;
	typedef typename _Alloc::const_reference reference;
	typedef _Elem* _Inner_type;

	__CLR_OR_THIS_CALL _String_const_iterator()
	{	// construct with null pointer
		_Myptr = 0;
	}

#define _STRING_CONST_ITERATOR(ptr)	const_iterator(ptr)

	__CLR_OR_THIS_CALL _String_const_iterator(pointer _Ptr)
	{	// construct with pointer _Ptr
		_Myptr = _Ptr;
		this->_Mycont = _IGNORE_MYCONT;
	}

	reference __CLR_OR_THIS_CALL operator*() const
	{	// return designated object

		if (this->_Mycont != _IGNORE_MYCONT)
		{
			//_SCL_SECURE_VALIDATE(this->_Has_container());
			//_SCL_SECURE_VALIDATE_RANGE(_Myptr < (((_Mystring*)this->_Mycont)->_Myptr() + ((_Mystring*)(this->_Mycont))->_Mysize));
		}

		return (*_Myptr);
	}

	pointer __CLR_OR_THIS_CALL operator->() const
	{	// return pointer to class object
		return (&**this);
	}

	_Myt& __CLR_OR_THIS_CALL operator++()
	{	// preincrement
		if (this->_Mycont != _IGNORE_MYCONT)
		{
			//_SCL_SECURE_VALIDATE(this->_Has_container());
			//_SCL_SECURE_VALIDATE_RANGE(_Myptr < (((_Mystring*)this->_Mycont)->_Myptr() + ((_Mystring*)this->_Mycont)->_Mysize));
		}
		++_Myptr;
		return (*this);
	}

	_Myt __CLR_OR_THIS_CALL operator++(int)
	{	// postincrement
		_Myt _Tmp = *this;
		++* this;
		return (_Tmp);
	}

	_Myt& __CLR_OR_THIS_CALL operator--()
	{	// predecrement
		if (this->_Mycont != _IGNORE_MYCONT)
		{
			//_SCL_SECURE_VALIDATE(this->_Has_container());
			//_SCL_SECURE_VALIDATE_RANGE(_Myptr > ((_Mystring*)this->_Mycont)->_Myptr());
		}
		--_Myptr;
		return (*this);
	}

	_Myt __CLR_OR_THIS_CALL operator--(int)
	{	// postdecrement
		_Myt _Tmp = *this;
		--* this;
		return (_Tmp);
	}

	_Myt& __CLR_OR_THIS_CALL operator+=(difference_type _Off)
	{	// increment by integer
		if (this->_Mycont != _IGNORE_MYCONT)
		{
			//_SCL_SECURE_VALIDATE(this->_Has_container());
			//_SCL_SECURE_VALIDATE_RANGE(
			//	_Myptr + _Off <= (((_Mystring*)this->_Mycont)->_Myptr() + ((_Mystring*)this->_Mycont)->_Mysize) &&
			//	_Myptr + _Off >= ((_Mystring*)this->_Mycont)->_Myptr());
		}
		_Myptr += _Off;
		return (*this);
	}

	_Myt __CLR_OR_THIS_CALL operator+(difference_type _Off) const
	{	// return this + integer
		_Myt _Tmp = *this;
		return (_Tmp += _Off);
	}

	_Myt& __CLR_OR_THIS_CALL operator-=(difference_type _Off)
	{	// decrement by integer
		return (*this += -_Off);
	}

	_Myt __CLR_OR_THIS_CALL operator-(difference_type _Off) const
	{	// return this - integer
		_Myt _Tmp = *this;
		return (_Tmp -= _Off);
	}

	difference_type __CLR_OR_THIS_CALL operator-(const _Myt& _Right) const
	{	// return difference of iterators

		if (this->_Mycont != _IGNORE_MYCONT)
		{
			//_SCL_SECURE_VALIDATE(this->_Has_container() && this->_Same_container(_Right));
		}

		return (_Myptr - _Right._Myptr);
	}

	reference __CLR_OR_THIS_CALL operator[](difference_type _Off) const
	{	// subscript
		return (*(*this + _Off));
	}

	bool __CLR_OR_THIS_CALL operator==(const _Myt& _Right) const
	{	// test for iterator equality

		if (this->_Mycont != _IGNORE_MYCONT)
		{
			//_SCL_SECURE_VALIDATE(this->_Has_container() && this->_Same_container(_Right));
		}

		return (_Myptr == _Right._Myptr);
	}

	bool __CLR_OR_THIS_CALL operator!=(const _Myt& _Right) const
	{	// test for iterator inequality
		return (!(*this == _Right));
	}

	bool __CLR_OR_THIS_CALL operator<(const _Myt& _Right) const
	{	// test if this < _Right

		if (this->_Mycont != _IGNORE_MYCONT)
		{
			//_SCL_SECURE_VALIDATE(this->_Has_container() && this->_Same_container(_Right));
		}

		return (_Myptr < _Right._Myptr);
	}

	bool __CLR_OR_THIS_CALL operator>(const _Myt& _Right) const
	{	// test if this > _Right
		return (_Right < *this);
	}

	bool __CLR_OR_THIS_CALL operator<=(const _Myt& _Right) const
	{	// test if this <= _Right
		return (!(_Right < *this));
	}

	bool __CLR_OR_THIS_CALL operator>=(const _Myt& _Right) const
	{	// test if this >= _Right
		return (!(*this < _Right));
	}

	static void __cdecl _Xlen()
	{
		_Mystring::_Xlen();
	}

	static void __cdecl _Xran()
	{
		_Mystring::_Xran();
	}

	static void __cdecl _Xinvarg()
	{
		_Mystring::_Xinvarg();
	}

	pointer _Myptr;	// offset of element in string
};

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	_String_const_iterator<_Elem, _Traits, _Alloc> __CLRCALL_OR_CDECL operator+(
		typename _String_const_iterator<_Elem, _Traits, _Alloc>
		::difference_type _Off,
		_String_const_iterator<_Elem, _Traits, _Alloc> _Next)
{	// add offset to iterator
	return (_Next += _Off);
}

// TEMPLATE CLASS _String_iterator
template<class _Elem,
	class _Traits,
	class _Alloc>
	class _String_iterator
	: public _String_const_iterator<_Elem, _Traits, _Alloc>
{	// iterator for mutable string
public:
	typedef _String_iterator<_Elem, _Traits, _Alloc> _Myt;
	typedef _String_const_iterator<_Elem, _Traits, _Alloc> _Mybase;

	typedef std::random_access_iterator_tag iterator_category;
	typedef _Elem value_type;
	typedef typename _Alloc::difference_type difference_type;
	typedef typename _Alloc::pointer pointer;
	typedef typename _Alloc::reference reference;

	__CLR_OR_THIS_CALL _String_iterator()
	{	// construct with null string pointer
	}

#define _STRING_ITERATOR(ptr)	iterator(ptr)

	__CLR_OR_THIS_CALL _String_iterator(pointer _Ptr)
		: _Mybase(_Ptr)
	{	// construct with pointer _Ptr
	}

	reference __CLR_OR_THIS_CALL operator*() const
	{	// return designated object
		return ((reference) * *(_Mybase*)this);
	}

	pointer __CLR_OR_THIS_CALL operator->() const
	{	// return pointer to class object
		return (&**this);
	}

	_Myt& __CLR_OR_THIS_CALL operator++()
	{	// preincrement
		++(*(_Mybase*)this);
		return (*this);
	}

	_Myt __CLR_OR_THIS_CALL operator++(int)
	{	// postincrement
		_Myt _Tmp = *this;
		++* this;
		return (_Tmp);
	}

	_Myt& __CLR_OR_THIS_CALL operator--()
	{	// predecrement
		--(*(_Mybase*)this);
		return (*this);
	}

	_Myt __CLR_OR_THIS_CALL operator--(int)
	{	// postdecrement
		_Myt _Tmp = *this;
		--* this;
		return (_Tmp);
	}

	_Myt& __CLR_OR_THIS_CALL operator+=(difference_type _Off)
	{	// increment by integer
		(*(_Mybase*)this) += _Off;
		return (*this);
	}

	_Myt __CLR_OR_THIS_CALL operator+(difference_type _Off) const
	{	// return this + integer
		_Myt _Tmp = *this;
		return (_Tmp += _Off);
	}

	_Myt& __CLR_OR_THIS_CALL operator-=(difference_type _Off)
	{	// decrement by integer
		return (*this += -_Off);
	}

	_Myt __CLR_OR_THIS_CALL operator-(difference_type _Off) const
	{	// return this - integer
		_Myt _Tmp = *this;
		return (_Tmp -= _Off);
	}

	difference_type __CLR_OR_THIS_CALL operator-(const _Mybase& _Right) const
	{	// return difference of iterators
		return ((_Mybase)*this - _Right);
	}

	reference __CLR_OR_THIS_CALL operator[](difference_type _Off) const
	{	// subscript
		return (*(*this + _Off));
	}
};

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	_String_iterator<_Elem, _Traits, _Alloc> __CLR_OR_THIS_CALL operator+(
		typename _String_iterator<_Elem, _Traits, _Alloc>
		::difference_type _Off,
		_String_iterator<_Elem, _Traits, _Alloc> _Next)
{	// add offset to iterator
	return (_Next += _Off);
}

// CLASS _String_base
class _CRTIMP2_PURE _String_base
	: public _Container_base_secure
{	// ultimate base class for basic_string to hold error reporters
public:
	static void __CLRCALL_PURE_OR_CDECL _Xlen() {};	// report a length_error

	static void __CLRCALL_PURE_OR_CDECL _Xran() {};	// report an out_of_range error

	static void __CLRCALL_PURE_OR_CDECL _Xinvarg() {};
};

// TEMPLATE CLASS _String_val
template<class _Ty2,
	class _Alloc>
	class _String_val
	: public _String_base
{	// base class for basic_string to hold allocator _Alval
protected:
	typedef typename _Alloc::template
		rebind<_Ty2>::other _Alty;

	__CLR_OR_THIS_CALL _String_val(_Alty _Al = _Alty())
		: _Alval(_Al)
	{	// construct allocator from _Al
	}

public:
	__CLR_OR_THIS_CALL _String_val(const _String_val& _Right)
		: _Alval(_Right._Alval)
	{	// copy constructor
	}

protected:
	_Alty _Alval;	// allocator object for strings
};

// TEMPLATE CLASS basic_string
template<class _Elem,
	class _Traits,
	class _Ax>
	class basic_string
	: public _String_val<_Elem, _Ax>
{	// null-terminated transparent array of elements
public:
	typedef basic_string<_Elem, _Traits, _Ax> _Myt;
	typedef _String_val<_Elem, _Ax> _Mybase;
	typedef typename _Mybase::_Alty _Alloc;
	typedef typename _Alloc::size_type size_type;
	typedef typename _Alloc::difference_type _Dift;
	typedef _Dift difference_type;
	typedef typename _Alloc::pointer _Tptr;
	typedef typename _Alloc::const_pointer _Ctptr;
	typedef _Tptr pointer;
	typedef _Ctptr const_pointer;
	typedef typename _Alloc::reference _Reft;
	typedef _Reft reference;
	typedef typename _Alloc::const_reference const_reference;
	typedef typename _Alloc::value_type value_type;

#define _STR_ITER_BASE(it)	(it)._Myptr

	typedef _String_iterator<_Elem, _Traits, _Alloc> iterator;
	typedef _String_const_iterator<_Elem, _Traits, _Alloc> const_iterator;

	//	friend class _String_iterator<_Elem, _Traits, _Alloc>;
	friend class _String_const_iterator<_Elem, _Traits, _Alloc>;

	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

#if defined(_DLL_CPPLIB)

	/*
	* This special _Size_type struct is used to overload operator[].
	* The correct operator[] is chosen based on the value of _SECURE_SCL.
	* See below when we define operator[].
	*/
#if _DEFINE_DLL_OVERLOADS || !_SECURE_SCL
	struct _Size_type_nosscl
	{
		size_t _Value;
		_Size_type_nosscl(size_t _Val) : _Value(_Val) { }
	};
#endif

#endif /* _DLL_CPPLIB */

#if !defined(_DEBUG) || !defined(_DLL_CPPLIB) || defined(_DEFINE_EMPTY_STRING_CONSTRUCTOR)

	__CLR_OR_THIS_CALL basic_string()
		: _Mybase()
	{	// construct empty string
		_Tidy();
	}

#endif /* !defined(_DEBUG) || !defined(_DLL_CPPLIB) */

#if !defined(_DEBUG) || !defined(_DLL_CPPLIB) || _HAS_ITERATOR_DEBUGGING

	explicit __CLR_OR_THIS_CALL basic_string(const _Alloc& _Al)
		: _Mybase(_Al)
	{	// construct empty string with allocator
		_Tidy();
	}

	__CLR_OR_THIS_CALL basic_string(const _Myt& _Right, size_type _Roff,
		size_type _Count = npos)
		: _Mybase()
	{	// construct from _Right [_Roff, _Roff + _Count)

		_Tidy();
		assign(_Right, _Roff, _Count);
	}

	__CLR_OR_THIS_CALL basic_string(const _Myt& _Right, size_type _Roff, size_type _Count,
		const _Alloc& _Al)
		: _Mybase(_Al)
	{	// construct from _Right [_Roff, _Roff + _Count) with allocator

		_Tidy();
		assign(_Right, _Roff, _Count);
	}

	__CLR_OR_THIS_CALL basic_string(const _Elem* _Ptr, size_type _Count)
		: _Mybase()
	{	// construct from [_Ptr, _Ptr + _Count)
		_Tidy();
		assign(_Ptr, _Count);
	}

	__CLR_OR_THIS_CALL basic_string(const _Elem* _Ptr, size_type _Count, const _Alloc& _Al)
		: _Mybase(_Al)
	{	// construct from [_Ptr, _Ptr + _Count) with allocator
		_Tidy();
		assign(_Ptr, _Count);
	}

	__CLR_OR_THIS_CALL basic_string(const _Elem* _Ptr)
		: _Mybase()
	{	// construct from [_Ptr, <null>)
		_Tidy();
		assign(_Ptr);
	}

	__CLR_OR_THIS_CALL basic_string(const _Elem* _Ptr, const _Alloc& _Al)
		: _Mybase(_Al)
	{	// construct from [_Ptr, <null>) with allocator
		_Tidy();
		assign(_Ptr);
	}

	__CLR_OR_THIS_CALL basic_string(size_type _Count, _Elem _Ch)
		: _Mybase()
	{	// construct from _Count * _Ch
		_Tidy();
		assign(_Count, _Ch);
	}

	__CLR_OR_THIS_CALL basic_string(size_type _Count, _Elem _Ch, const _Alloc& _Al)
		: _Mybase(_Al)
	{	// construct from _Count * _Ch with allocator
		_Tidy();
		assign(_Count, _Ch);
	}

	template<class _It>
	__CLR_OR_THIS_CALL basic_string(_It _First, _It _Last)
		: _Mybase()
	{	// construct from [_First, _Last)
		_Tidy();
		_Construct(_First, _Last, _Iter_cat(_First));
	}

	template<class _It>
	__CLR_OR_THIS_CALL basic_string(_It _First, _It _Last, const _Alloc& _Al)
		: _Mybase(_Al)
	{	// construct from [_First, _Last) with allocator
		_Tidy();
		_Construct(_First, _Last, _Iter_cat(_First));
	}

	__CLR_OR_THIS_CALL basic_string(const_pointer _First, const_pointer _Last)
		: _Mybase()
	{	// construct from [_First, _Last), const pointers

		_Tidy();
		if (_First != _Last)
			assign(&*_First, _Last - _First);
	}

	__CLR_OR_THIS_CALL basic_string(const_iterator _First, const_iterator _Last)
		: _Mybase()
	{	// construct from [_First, _Last), const_iterators

		_Tidy();
		if (_First != _Last)
			assign(&*_First, _Last - _First);
	}

#endif /* !defined(_DEBUG) || !defined(_DLL_CPPLIB) || _HAS_ITERATOR_DEBUGGING */

	// The copy constructor does not need to be overloaded.
	// If _Right._Myfirstiter == _IGNORE_MYITERLIST it will be copied over.
	__CLR_OR_THIS_CALL basic_string(const _Myt& _Right)
		: _Mybase(_Right)
	{	// construct by copying _Right
		_Tidy();
		assign(_Right, 0, npos);
	}

	template<class _It>
	void __CLR_OR_THIS_CALL _Construct(_It _Count,
		_It _Ch, _Int_iterator_tag)
	{	// initialize from _Count * _Ch
		assign((size_type)_Count, (_Elem)_Ch);
	}

	template<class _It>
	void __CLR_OR_THIS_CALL _Construct(_It _First,
		_It _Last, std::input_iterator_tag)
	{	// initialize from [_First, _Last), input iterators
		_TRY_BEGIN
			for (; _First != _Last; ++_First)
				append((size_type)1, (_Elem)*_First);
		_CATCH_ALL
			_Tidy(true);
		_RERAISE;
		_CATCH_END
	}

	template<class _It>
	void __CLR_OR_THIS_CALL _Construct(_It _First,
		_It _Last, std::forward_iterator_tag)
	{	// initialize from [_First, _Last), forward iterators

		size_type _Count = 0;
		_Distance(_First, _Last, _Count);
		reserve(_Count);

		_TRY_BEGIN
			for (; _First != _Last; ++_First)
				append((size_type)1, (_Elem)*_First);
		_CATCH_ALL
			_Tidy(true);
		_RERAISE;
		_CATCH_END
	}

	__CLR_OR_THIS_CALL ~basic_string()
	{	// destroy the string
		_Tidy(true);
	}

	typedef _Traits traits_type;
	typedef _Alloc allocator_type;

	_PGLOBAL static const size_type npos;	// generic bad/missing length/position

	_Myt& __CLR_OR_THIS_CALL operator=(const _Myt& _Right)
	{	// assign _Right
		return (assign(_Right));
	}

	_Myt& __CLR_OR_THIS_CALL operator=(const _Elem* _Ptr)
	{	// assign [_Ptr, <null>)
		return (assign(_Ptr));
	}

	_Myt& __CLR_OR_THIS_CALL operator=(_Elem _Ch)
	{	// assign 1 * _Ch
		return (assign(1, _Ch));
	}

	_Myt& __CLR_OR_THIS_CALL operator+=(const _Myt& _Right)
	{	// append _Right
		return (append(_Right));
	}

	_Myt& __CLR_OR_THIS_CALL operator+=(const _Elem* _Ptr)
	{	// append [_Ptr, <null>)
		return (append(_Ptr));
	}

	_Myt& __CLR_OR_THIS_CALL operator+=(_Elem _Ch)
	{	// append 1 * _Ch
		return (append((size_type)1, _Ch));
	}

	_Myt& __CLR_OR_THIS_CALL append(const _Myt& _Right)
	{	// append _Right
		return (append(_Right, 0, npos));
	}

	_Myt& __CLR_OR_THIS_CALL append(const _Myt& _Right,
		size_type _Roff, size_type _Count)
	{	// append _Right [_Roff, _Roff + _Count)
		if (_Right.size() < _Roff)
			_String_base::_Xran();	// _Roff off end
		size_type _Num = _Right.size() - _Roff;
		if (_Num < _Count)
			_Count = _Num;	// trim _Count to size
		if (npos - _Mysize <= _Count || _Mysize + _Count < _Mysize)
			_String_base::_Xlen();	// result too long

		if (0 < _Count && _Grow(_Num = _Mysize + _Count))
		{	// make room and append new stuff
			_Traits_helper::copy_s<_Traits>(_Myptr() + _Mysize, _Myres - _Mysize,
				_Right._Myptr() + _Roff, _Count);
			_Eos(_Num);
		}
		return (*this);
	}

	_Myt& __CLR_OR_THIS_CALL append(const _Elem* _Ptr, size_type _Count)
	{	// append [_Ptr, _Ptr + _Count)

		if (_Inside(_Ptr))
			return (append(*this, _Ptr - _Myptr(), _Count));	// substring
		if (npos - _Mysize <= _Count || _Mysize + _Count < _Mysize)
			_String_base::_Xlen();	// result too long

		size_type _Num;
		if (0 < _Count && _Grow(_Num = _Mysize + _Count))
		{	// make room and append new stuff
			_Traits_helper::copy_s<_Traits>(_Myptr() + _Mysize, _Myres - _Mysize, _Ptr, _Count);
			_Eos(_Num);
		}
		return (*this);
	}

	_Myt& __CLR_OR_THIS_CALL append(const _Elem* _Ptr)
	{	// append [_Ptr, <null>)
		//_DEBUG_POINTER(_Ptr);
		return (append(_Ptr, _Traits::length(_Ptr)));
	}

	_Myt& __CLR_OR_THIS_CALL append(size_type _Count, _Elem _Ch)
	{	// append _Count * _Ch
		if (npos - _Mysize <= _Count)
			_String_base::_Xlen();	// result too long

		size_type _Num;
		if (0 < _Count && _Grow(_Num = _Mysize + _Count))
		{	// make room and append new stuff using assign
			_Chassign(_Mysize, _Count, _Ch);
			_Eos(_Num);
		}
		return (*this);
	}

	template<class _It>
	_Myt& __CLR_OR_THIS_CALL append(_It _First, _It _Last)
	{	// append [_First, _Last)
		return (_Append(_First, _Last, _Iter_cat(_First)));
	}

	template<class _It>
	_Myt& __CLR_OR_THIS_CALL _Append(_It _Count, _It _Ch, _Int_iterator_tag)
	{	// append _Count * _Ch
		return (append((size_type)_Count, (_Elem)_Ch));
	}

	template<class _It>
	_Myt& __CLR_OR_THIS_CALL _Append(_It _First, _It _Last, std::input_iterator_tag)
	{	// append [_First, _Last), input iterators
		return (replace(end(), end(), _First, _Last));
	}

	_Myt& __CLR_OR_THIS_CALL append(const_pointer _First, const_pointer _Last)
	{	// append [_First, _Last), const pointers
		return (replace(end(), end(), _First, _Last));
	}

	_Myt& __CLR_OR_THIS_CALL append(const_iterator _First, const_iterator _Last)
	{	// append [_First, _Last), const_iterators
		return (replace(end(), end(), _First, _Last));
	}

	_Myt& __CLR_OR_THIS_CALL assign(const _Myt& _Right)
	{	// assign _Right
		return (assign(_Right, 0, npos));
	}

	_Myt& __CLR_OR_THIS_CALL assign(const _Myt& _Right,
		size_type _Roff, size_type _Count)
	{	// assign _Right [_Roff, _Roff + _Count)
		if (_Right.size() < _Roff)
			_String_base::_Xran();	// _Roff off end
		size_type _Num = _Right.size() - _Roff;
		if (_Count < _Num)
			_Num = _Count;	// trim _Num to size

		if (this == &_Right)
			erase((size_type)(_Roff + _Num)), erase(0, _Roff);	// substring
		else if (_Grow(_Num))
		{	// make room and assign new stuff
			_Traits_helper::copy_s<_Traits>(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
			_Eos(_Num);
		}
		return (*this);
	}

	_Myt& __CLR_OR_THIS_CALL assign(const _Elem* _Ptr, size_type _Count)
	{	// assign [_Ptr, _Ptr + _Count)

		if (_Inside(_Ptr))
			return (assign(*this, _Ptr - _Myptr(), _Count));	// substring

		if (_Grow(_Count))
		{	// make room and assign new stuff
			_Traits_helper::copy_s<_Traits>(_Myptr(), _Myres, _Ptr, _Count);
			_Eos(_Count);
		}
		return (*this);
	}

	_Myt& __CLR_OR_THIS_CALL assign(const _Elem* _Ptr)
	{	// assign [_Ptr, <null>)
		//_DEBUG_POINTER(_Ptr);
		return (assign(_Ptr, _Traits::length(_Ptr)));
	}

	_Myt& __CLR_OR_THIS_CALL assign(size_type _Count, _Elem _Ch)
	{	// assign _Count * _Ch
		if (_Count == npos)
			_String_base::_Xlen();	// result too long

		if (_Grow(_Count))
		{	// make room and assign new stuff
			_Chassign(0, _Count, _Ch);
			_Eos(_Count);
		}
		return (*this);
	}

	template<class _It>
	_Myt& __CLR_OR_THIS_CALL assign(_It _First, _It _Last)
	{	// assign [First, _Last)
		return (_Assign(_First, _Last, _Iter_cat(_First)));
	}

	template<class _It>
	_Myt& __CLR_OR_THIS_CALL _Assign(_It _Count, _It _Ch, _Int_iterator_tag)
	{	// assign _Count * _Ch
		return (assign((size_type)_Count, (_Elem)_Ch));
	}

	template<class _It>
	_Myt& __CLR_OR_THIS_CALL _Assign(_It _First, _It _Last, std::input_iterator_tag)
	{	// assign [First, _Last), input iterators
		return (replace(begin(), end(), _First, _Last));
	}

	_Myt& __CLR_OR_THIS_CALL assign(const_pointer _First, const_pointer _Last)
	{	// assign [First, _Last), const pointers
		return (replace(begin(), end(), _First, _Last));
	}

	_Myt& __CLR_OR_THIS_CALL assign(const_iterator _First, const_iterator _Last)
	{	// assign [First, _Last), const_iterators
		return (replace(begin(), end(), _First, _Last));
	}

	_Myt& __CLR_OR_THIS_CALL insert(size_type _Off, const _Myt& _Right)
	{	// insert _Right at _Off
		return (insert(_Off, _Right, 0, npos));
	}

	_Myt& __CLR_OR_THIS_CALL insert(size_type _Off,
		const _Myt& _Right, size_type _Roff, size_type _Count)
	{	// insert _Right [_Roff, _Roff + _Count) at _Off
		if (_Mysize < _Off || _Right.size() < _Roff)
			_String_base::_Xran();	// _Off or _Roff off end
		size_type _Num = _Right.size() - _Roff;
		if (_Num < _Count)
			_Count = _Num;	// trim _Count to size
		if (npos - _Mysize <= _Count)
			_String_base::_Xlen();	// result too long

		if (0 < _Count && _Grow(_Num = _Mysize + _Count))
		{	// make room and insert new stuff
			_Traits_helper::move_s<_Traits>(_Myptr() + _Off + _Count, _Myres - _Off - _Count,
				_Myptr() + _Off, _Mysize - _Off);	// empty out hole
			if (this == &_Right)
				_Traits_helper::move_s<_Traits>(_Myptr() + _Off, _Myres - _Off,
					_Myptr() + (_Off < _Roff ? _Roff + _Count : _Roff),
					_Count);	// substring
			else
				_Traits_helper::copy_s<_Traits>(_Myptr() + _Off, _Myres - _Off,
					_Right._Myptr() + _Roff, _Count);	// fill hole
			_Eos(_Num);
		}
		return (*this);
	}

	_Myt& __CLR_OR_THIS_CALL insert(size_type _Off,
		const _Elem* _Ptr, size_type _Count)
	{	// insert [_Ptr, _Ptr + _Count) at _Off

		if (_Inside(_Ptr))
			return (insert(_Off, *this,
				_Ptr - _Myptr(), _Count));	// substring
		if (_Mysize < _Off)
			_String_base::_Xran();	// _Off off end
		if (npos - _Mysize <= _Count)
			_String_base::_Xlen();	// result too long
		size_type _Num;
		if (0 < _Count && _Grow(_Num = _Mysize + _Count))
		{	// make room and insert new stuff
			_Traits_helper::move_s<_Traits>(_Myptr() + _Off + _Count, _Myres - _Off - _Count,
				_Myptr() + _Off, _Mysize - _Off);	// empty out hole
			_Traits_helper::copy_s<_Traits>(_Myptr() + _Off, _Myres - _Off, _Ptr, _Count);	// fill hole
			_Eos(_Num);
		}
		return (*this);
	}

	_Myt& __CLR_OR_THIS_CALL insert(size_type _Off, const _Elem* _Ptr)
	{	// insert [_Ptr, <null>) at _Off
		//_DEBUG_POINTER(_Ptr);
		return (insert(_Off, _Ptr, _Traits::length(_Ptr)));
	}

	_Myt& __CLR_OR_THIS_CALL insert(size_type _Off,
		size_type _Count, _Elem _Ch)
	{	// insert _Count * _Ch at _Off
		if (_Mysize < _Off)
			_String_base::_Xran();	// _Off off end
		if (npos - _Mysize <= _Count)
			_String_base::_Xlen();	// result too long
		size_type _Num;
		if (0 < _Count && _Grow(_Num = _Mysize + _Count))
		{	// make room and insert new stuff
			_Traits_helper::move_s<_Traits>(_Myptr() + _Off + _Count, _Myres - _Off - _Count,
				_Myptr() + _Off, _Mysize - _Off);	// empty out hole
			_Chassign(_Off, _Count, _Ch);	// fill hole
			_Eos(_Num);
		}
		return (*this);
	}

	iterator __CLR_OR_THIS_CALL insert(const_iterator _Where)
	{	// insert <null> at _Where
		return (insert(_Where, _Elem()));
	}

	iterator __CLR_OR_THIS_CALL insert(const_iterator _Where, _Elem _Ch)
	{	// insert _Ch at _Where
		size_type _Off = _Pdif(_Where, begin());
		insert(_Off, 1, _Ch);
		return (begin() + _Off);
	}

	void __CLR_OR_THIS_CALL insert(const_iterator _Where, size_type _Count, _Elem _Ch)
	{	// insert _Count * _Elem at _Where
		size_type _Off = _Pdif(_Where, begin());
		insert(_Off, _Count, _Ch);
	}

	template<class _It>
	void __CLR_OR_THIS_CALL insert(const_iterator _Where, _It _First, _It _Last)
	{	// insert [_First, _Last) at _Where
		_Insert(_Where, _First, _Last, _Iter_cat(_First));
	}

	template<class _It>
	void __CLR_OR_THIS_CALL _Insert(const_iterator _Where, _It _Count, _It _Ch,
		_Int_iterator_tag)
	{	// insert _Count * _Ch at _Where
		insert(_Where, (size_type)_Count, (_Elem)_Ch);
	}

	template<class _It>
	void __CLR_OR_THIS_CALL _Insert(const_iterator _Where, _It _First, _It _Last,
		std::input_iterator_tag)
	{	// insert [_First, _Last) at _Where, input iterators
		replace(_Where, _Where, _First, _Last);
	}

	void __CLR_OR_THIS_CALL insert(const_iterator _Where, const_pointer _First, const_pointer _Last)
	{	// insert [_First, _Last) at _Where, const pointers
		replace(_Where, _Where, _First, _Last);
	}

	void __CLR_OR_THIS_CALL insert(const_iterator _Where, const_iterator _First, const_iterator _Last)
	{	// insert [_First, _Last) at _Where, const_iterators
		replace(_Where, _Where, _First, _Last);
	}

	_Myt& __CLR_OR_THIS_CALL erase(size_type _Off = 0,
		size_type _Count = npos)
	{	// erase elements [_Off, _Off + _Count)
		if (_Mysize < _Off)
			_String_base::_Xran();	// _Off off end
		if (_Mysize - _Off < _Count)
			_Count = _Mysize - _Off;	// trim _Count
		if (0 < _Count)
		{	// move elements down
			_Traits_helper::move_s<_Traits>(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count,
				_Mysize - _Off - _Count);
			size_type _Newsize = _Mysize - _Count;
			_Eos(_Newsize);
		}
		return (*this);
	}

	iterator __CLR_OR_THIS_CALL erase(const_iterator _Where)
	{	// erase element at _Where
		size_type _Count = _Pdif(_Where, begin());
		erase(_Count, 1);
		return (_STRING_ITERATOR(_Myptr() + _Count));
	}

	iterator __CLR_OR_THIS_CALL erase(const_iterator _First, const_iterator _Last)
	{	// erase substring [_First, _Last)
		size_type _Count = _Pdif(_First, begin());
		erase(_Count, _Pdif(_Last, _First));
		return (_STRING_ITERATOR(_Myptr() + _Count));
	}

	void __CLR_OR_THIS_CALL clear()
	{	// erase all
		erase(begin(), end());
	}

	_Myt& __CLR_OR_THIS_CALL replace(size_type _Off, size_type _N0, const _Myt& _Right)
	{	// replace [_Off, _Off + _N0) with _Right
		return (replace(_Off, _N0, _Right, 0, npos));
	}

	_Myt& __CLR_OR_THIS_CALL replace(size_type _Off,
		size_type _N0, const _Myt& _Right, size_type _Roff, size_type _Count)
	{	// replace [_Off, _Off + _N0) with _Right [_Roff, _Roff + _Count)
		if (_Mysize < _Off || _Right.size() < _Roff)
			_String_base::_Xran();	// _Off or _Roff off end
		if (_Mysize - _Off < _N0)
			_N0 = _Mysize - _Off;	// trim _N0 to size
		size_type _Num = _Right.size() - _Roff;
		if (_Num < _Count)
			_Count = _Num;	// trim _Count to size
		if (npos - _Count <= _Mysize - _N0)
			_String_base::_Xlen();	// result too long

		size_type _Nm = _Mysize - _N0 - _Off;	// length of preserved tail
		size_type _Newsize = _Mysize + _Count - _N0;
		if (_Mysize < _Newsize)
			_Grow(_Newsize);

		if (this != &_Right)
		{	// no overlap, just move down and copy in new stuff
			_Traits_helper::move_s<_Traits>(_Myptr() + _Off + _Count, _Myres - _Off - _Count,
				_Myptr() + _Off + _N0, _Nm);	// empty hole
			_Traits_helper::copy_s<_Traits>(_Myptr() + _Off, _Myres - _Off,
				_Right._Myptr() + _Roff, _Count);	// fill hole
		}
		else if (_Count <= _N0)
		{	// hole doesn't get larger, just copy in substring
			_Traits_helper::move_s<_Traits>(_Myptr() + _Off, _Myres - _Off,
				_Myptr() + _Roff, _Count);	// fill hole
			_Traits_helper::move_s<_Traits>(_Myptr() + _Off + _Count, _Myres - _Off - _Count,
				_Myptr() + _Off + _N0, _Nm);	// move tail down
		}
		else if (_Roff <= _Off)
		{	// hole gets larger, substring begins before hole
			_Traits_helper::move_s<_Traits>(_Myptr() + _Off + _Count, _Myres - _Off - _Count,
				_Myptr() + _Off + _N0, _Nm);	// move tail down
			_Traits_helper::move_s<_Traits>(_Myptr() + _Off, _Myres - _Off,
				_Myptr() + _Roff, _Count);	// fill hole
		}
		else if (_Off + _N0 <= _Roff)
		{	// hole gets larger, substring begins after hole
			_Traits_helper::move_s<_Traits>(_Myptr() + _Off + _Count, _Myres - _Off - _Count,
				_Myptr() + _Off + _N0, _Nm);	// move tail down
			_Traits_helper::move_s<_Traits>(_Myptr() + _Off, _Myres - _Off,
				_Myptr() + (_Roff + _Count - _N0), _Count);	// fill hole
		}
		else
		{	// hole gets larger, substring begins in hole
			_Traits_helper::move_s<_Traits>(_Myptr() + _Off, _Myres - _Off,
				_Myptr() + _Roff, _N0);	// fill old hole
			_Traits_helper::move_s<_Traits>(_Myptr() + _Off + _Count, _Myres - _Off - _Count,
				_Myptr() + _Off + _N0, _Nm);	// move tail down
			_Traits_helper::move_s<_Traits>(_Myptr() + _Off + _N0, _Myres - _Off - _N0, _Myptr() + _Roff + _Count,
				_Count - _N0);	// fill rest of new hole
		}

		_Eos(_Newsize);
		return (*this);
	}

	_Myt& __CLR_OR_THIS_CALL replace(size_type _Off,
		size_type _N0, const _Elem* _Ptr, size_type _Count)
	{	// replace [_Off, _Off + _N0) with [_Ptr, _Ptr + _Count)

		if (_Inside(_Ptr))
			return (replace(_Off, _N0, *this,
				_Ptr - _Myptr(), _Count));	// substring, replace carefully
		if (_Mysize < _Off)
			_String_base::_Xran();	// _Off off end
		if (_Mysize - _Off < _N0)
			_N0 = _Mysize - _Off;	// trim _N0 to size
		if (npos - _Count <= _Mysize - _N0)
			_String_base::_Xlen();	// result too long
		size_type _Nm = _Mysize - _N0 - _Off;

		if (_Count < _N0)
			_Traits_helper::move_s<_Traits>(_Myptr() + _Off + _Count, _Myres - _Off - _Count,
				_Myptr() + _Off + _N0, _Nm);	// smaller hole, move tail up
		size_type _Num;
		if ((0 < _Count || 0 < _N0) && _Grow(_Num = _Mysize + _Count - _N0))
		{	// make room and rearrange
			if (_N0 < _Count)
				_Traits_helper::move_s<_Traits>(_Myptr() + _Off + _Count, _Myres - _Off - _Count,
					_Myptr() + _Off + _N0, _Nm);	// move tail down
			_Traits_helper::copy_s<_Traits>(_Myptr() + _Off, _Myres - _Off, _Ptr, _Count);	// fill hole
			_Eos(_Num);
		}
		return (*this);
	}

	_Myt& __CLR_OR_THIS_CALL replace(size_type _Off, size_type _N0, const _Elem* _Ptr)
	{	// replace [_Off, _Off + _N0) with [_Ptr, <null>)
		//_DEBUG_POINTER(_Ptr);
		return (replace(_Off, _N0, _Ptr, _Traits::length(_Ptr)));
	}

	_Myt& __CLR_OR_THIS_CALL replace(size_type _Off,
		size_type _N0, size_type _Count, _Elem _Ch)
	{	// replace [_Off, _Off + _N0) with _Count * _Ch
		if (_Mysize < _Off)
			_String_base::_Xran();	// _Off off end
		if (_Mysize - _Off < _N0)
			_N0 = _Mysize - _Off;	// trim _N0 to size
		if (npos - _Count <= _Mysize - _N0)
			_String_base::_Xlen();	// result too long
		size_type _Nm = _Mysize - _N0 - _Off;

		if (_Count < _N0)
			_Traits_helper::move_s<_Traits>(_Myptr() + _Off + _Count, _Myres - _Off - _Count,
				_Myptr() + _Off + _N0, _Nm);	// smaller hole, move tail up
		size_type _Num;
		if ((0 < _Count || 0 < _N0) && _Grow(_Num = _Mysize + _Count - _N0))
		{	// make room and rearrange
			if (_N0 < _Count)
				_Traits_helper::move_s<_Traits>(_Myptr() + _Off + _Count, _Myres - _Off - _Count,
					_Myptr() + _Off + _N0, _Nm);	// move tail down
			_Chassign(_Off, _Count, _Ch);	// fill hole
			_Eos(_Num);
		}
		return (*this);
	}

	_Myt& __CLR_OR_THIS_CALL replace(const_iterator _First, const_iterator _Last, const _Myt& _Right)
	{	// replace [_First, _Last) with _Right
		return (replace(
			_Pdif(_First, begin()), _Pdif(_Last, _First), _Right));
	}

	_Myt& __CLR_OR_THIS_CALL replace(const_iterator _First, const_iterator _Last, const _Elem* _Ptr,
		size_type _Count)
	{	// replace [_First, _Last) with [_Ptr, _Ptr + _Count)
		return (replace(
			_Pdif(_First, begin()), _Pdif(_Last, _First), _Ptr, _Count));
	}

	_Myt& __CLR_OR_THIS_CALL replace(const_iterator _First, const_iterator _Last, const _Elem* _Ptr)
	{	// replace [_First, _Last) with [_Ptr, <null>)
		return (replace(
			_Pdif(_First, begin()), _Pdif(_Last, _First), _Ptr));
	}

	_Myt& __CLR_OR_THIS_CALL replace(const_iterator _First, const_iterator _Last,
		size_type _Count, _Elem _Ch)
	{	// replace [_First, _Last) with _Count * _Ch
		return (replace(
			_Pdif(_First, begin()), _Pdif(_Last, _First), _Count, _Ch));
	}

	template<class _It>
	_Myt& __CLR_OR_THIS_CALL replace(const_iterator _First, const_iterator _Last,
		_It _First2, _It _Last2)
	{	// replace [_First, _Last) with [_First2, _Last2)
		return (_Replace(_First, _Last,
			_First2, _Last2, _Iter_cat(_First2)));
	}

	template<class _It>
	_Myt& __CLR_OR_THIS_CALL _Replace(const_iterator _First, const_iterator _Last,
		_It _Count, _It _Ch, _Int_iterator_tag)
	{	// replace [_First, _Last) with _Count * _Ch
		return (replace(_First, _Last, (size_type)_Count, (_Elem)_Ch));
	}

	template<class _It>
	_Myt& __CLR_OR_THIS_CALL _Replace(const_iterator _First, const_iterator _Last,
		_It _First2, _It _Last2, std::input_iterator_tag)
	{	// replace [_First, _Last) with [_First2, _Last2), input iterators
		_Myt _Right(_First2, _Last2);
		replace(_First, _Last, _Right);
		return (*this);
	}

	_Myt& __CLR_OR_THIS_CALL replace(const_iterator _First, const_iterator _Last,
		const_pointer _First2, const_pointer _Last2)
	{	// replace [_First, _Last) with [_First2, _Last2), const pointers
		if (_First2 == _Last2)
			erase(_Pdif(_First, begin()), _Pdif(_Last, _First));
		else
			replace(_Pdif(_First, begin()), _Pdif(_Last, _First),
				&*_First2, _Last2 - _First2);
		return (*this);
	}

	_Myt& __CLR_OR_THIS_CALL replace(const_iterator _First, const_iterator _Last,
		const_iterator _First2, const_iterator _Last2)
	{	// replace [_First, _Last) with [_First2, _Last2), const_iterators
		if (_First2 == _Last2)
			erase(_Pdif(_First, begin()), _Pdif(_Last, _First));
		else
			replace(_Pdif(_First, begin()), _Pdif(_Last, _First),
				&*_First2, _Last2 - _First2);
		return (*this);
	}

	iterator __CLR_OR_THIS_CALL begin()
	{	// return iterator for beginning of mutable sequence
		return (_STRING_ITERATOR(_Myptr()));
	}

	const_iterator __CLR_OR_THIS_CALL begin() const
	{	// return iterator for beginning of nonmutable sequence
		return (_STRING_CONST_ITERATOR(_Myptr()));
	}

	iterator __CLR_OR_THIS_CALL end()
	{	// return iterator for end of mutable sequence
		return (_STRING_ITERATOR(_Myptr() + _Mysize));
	}

	const_iterator __CLR_OR_THIS_CALL end() const
	{	// return iterator for end of nonmutable sequence
		return (_STRING_CONST_ITERATOR(_Myptr() + _Mysize));
	}

	reverse_iterator __CLR_OR_THIS_CALL rbegin()
	{	// return iterator for beginning of reversed mutable sequence
		return (reverse_iterator(end()));
	}

	const_reverse_iterator __CLR_OR_THIS_CALL rbegin() const
	{	// return iterator for beginning of reversed nonmutable sequence
		return (const_reverse_iterator(end()));
	}

	reverse_iterator __CLR_OR_THIS_CALL rend()
	{	// return iterator for end of reversed mutable sequence
		return (reverse_iterator(begin()));
	}

	const_reverse_iterator __CLR_OR_THIS_CALL rend() const
	{	// return iterator for end of reversed nonmutable sequence
		return (const_reverse_iterator(begin()));
	}

	reference __CLR_OR_THIS_CALL at(size_type _Off)
	{	// subscript mutable sequence with checking
		if (_Mysize <= _Off)
			_String_base::_Xran();	// _Off off end
		return (_Myptr()[_Off]);
	}

	const_reference __CLR_OR_THIS_CALL at(size_type _Off) const
	{	// subscript nonmutable sequence with checking
		if (_Mysize <= _Off)
			_String_base::_Xran();	// _Off off end
		return (_Myptr()[_Off]);
	}


#if defined(_DLL_CPPLIB)

#if _DEFINE_DLL_OVERLOADS || !_SECURE_SCL

	reference __CLR_OR_THIS_CALL operator[](_Size_type_nosscl _SpecialOff)
	{	// subscript mutable sequence

		size_type _Off = (size_type)_SpecialOff._Value;

		return (_Myptr()[_Off]);
	}

	const_reference __CLR_OR_THIS_CALL operator[](_Size_type_nosscl _SpecialOff) const
	{	// subscript nonmutable sequence

		size_type _Off = (size_type)_SpecialOff._Value;

		return (_Myptr()[_Off]);
	}

#endif /* _DEFINE_DLL_OVERLOADS || !_SECURE_SCL */

#endif /* _DLL_CPPLIB */

	void __CLR_OR_THIS_CALL push_back(_Elem _Ch)
	{	// insert element at end
		insert(end(), _Ch);
	}

	const _Elem* __CLR_OR_THIS_CALL c_str() const
	{	// return pointer to null-terminated nonmutable array
		return (_Myptr());
	}

	const _Elem* __CLR_OR_THIS_CALL data() const
	{	// return pointer to nonmutable array
		return (c_str());
	}

	size_type __CLR_OR_THIS_CALL length() const
	{	// return length of sequence
		return (_Mysize);
	}

	size_type __CLR_OR_THIS_CALL size() const
	{	// return length of sequence
		return (_Mysize);
	}

	size_type __CLR_OR_THIS_CALL max_size() const
	{	// return maximum possible length of sequence
		size_type _Num = _Mybase::_Alval.max_size();
		return (_Num <= 1 ? 1 : _Num - 1);
	}

	void __CLR_OR_THIS_CALL resize(size_type _Newsize)
	{	// determine new length, padding with null elements as needed
		resize(_Newsize, _Elem());
	}

	void __CLR_OR_THIS_CALL resize(size_type _Newsize, _Elem _Ch)
	{	// determine new length, padding with _Ch elements as needed
		if (_Newsize <= _Mysize)
			erase(_Newsize);
		else
			append(_Newsize - _Mysize, _Ch);
	}

	size_type __CLR_OR_THIS_CALL capacity() const
	{	// return current length of allocated storage
		return (_Myres);
	}

	void __CLR_OR_THIS_CALL reserve(size_type _Newcap = 0)
	{	// determine new minimum length of allocated storage
		if (_Mysize <= _Newcap && _Myres != _Newcap)
		{	// change reservation
			size_type _Size = _Mysize;
			if (_Grow(_Newcap, true))
				_Eos(_Size);
		}
	}

	bool __CLR_OR_THIS_CALL empty() const
	{	// test if sequence is empty
		return (_Mysize == 0);
	}

	//_SCL_INSECURE_DEPRECATE
		size_type __CLR_OR_THIS_CALL copy(_Elem* _Dest,
			size_type _Count, size_type _Off = 0) const
	{	// copy [_Off, _Off + _Count) to [_Dest, _Dest + _Count)

		// assume there is enough space in _Ptr
		return _Copy_s(_Dest, _Count, _Count, _Off);
	}

	size_type __CLR_OR_THIS_CALL _Copy_s(_Elem* _Dest, size_type _Dest_size,
		size_type _Count, size_type _Off = 0) const
	{	// copy [_Off, _Off + _Count) to [_Dest, _Dest + _Count)
		//_DEBUG_POINTER(_Dest);
		if (_Mysize < _Off)
			_String_base::_Xran();	// _Off off end
		if (_Mysize - _Off < _Count)
			_Count = _Mysize - _Off;
		_Traits_helper::copy_s<_Traits>(_Dest, _Dest_size, _Myptr() + _Off, _Count);
		return (_Count);
	}

	void __CLR_OR_THIS_CALL swap(_Myt& _Right)
	{	// exchange contents with _Right
		if (this == &_Right)
			;	// same object, do nothing
		else if (_Mybase::_Alval == _Right._Alval)
		{	// same allocator, swap control information


			_Bxty _Tbx = _Bx;
			_Bx = _Right._Bx, _Right._Bx = _Tbx;

			size_type _Tlen = _Mysize;
			_Mysize = _Right._Mysize, _Right._Mysize = _Tlen;

			size_type _Tres = _Myres;
			_Myres = _Right._Myres, _Right._Myres = _Tres;
		}
		else
		{	// different allocator, do multiple assigns
			_Myt _Tmp = *this;

			*this = _Right;
			_Right = _Tmp;
		}
	}

	size_type __CLR_OR_THIS_CALL find(const _Myt& _Right, size_type _Off = 0) const
	{	// look for _Right beginnng at or after _Off
		return (find(_Right._Myptr(), _Off, _Right.size()));
	}

	size_type __CLR_OR_THIS_CALL find(const _Elem* _Ptr,
		size_type _Off, size_type _Count) const
	{	// look for [_Ptr, _Ptr + _Count) beginnng at or after _Off

		if (_Count == 0 && _Off <= _Mysize)
			return (_Off);	// null string always matches (if inside string)

		size_type _Nm;
		if (_Off < _Mysize && _Count <= (_Nm = _Mysize - _Off))
		{	// room for match, look for it
			const _Elem* _Uptr, * _Vptr;
			for (_Nm -= _Count - 1, _Vptr = _Myptr() + _Off;
				(_Uptr = _Traits::find(_Vptr, _Nm, *_Ptr)) != 0;
				_Nm -= _Uptr - _Vptr + 1, _Vptr = _Uptr + 1)
				if (_Traits::compare(_Uptr, _Ptr, _Count) == 0)
					return (_Uptr - _Myptr());	// found a match
		}

		return (npos);	// no match
	}

	size_type __CLR_OR_THIS_CALL find(const _Elem* _Ptr, size_type _Off = 0) const
	{	// look for [_Ptr, <null>) beginnng at or after _Off
		//_DEBUG_POINTER(_Ptr);
		return (find(_Ptr, _Off, _Traits::length(_Ptr)));
	}

	size_type __CLR_OR_THIS_CALL find(_Elem _Ch, size_type _Off = 0) const
	{	// look for _Ch at or after _Off
		return (find((const _Elem*)&_Ch, _Off, 1));
	}

	size_type __CLR_OR_THIS_CALL rfind(const _Myt& _Right, size_type _Off = npos) const
	{	// look for _Right beginning before _Off
		return (rfind(_Right._Myptr(), _Off, _Right.size()));
	}

	size_type __CLR_OR_THIS_CALL rfind(const _Elem* _Ptr,
		size_type _Off, size_type _Count) const
	{	// look for [_Ptr, _Ptr + _Count) beginning before _Off

		if (_Count == 0)
			return (_Off < _Mysize ? _Off : _Mysize);	// null always matches
		if (_Count <= _Mysize)
		{	// room for match, look for it
			const _Elem* _Uptr = _Myptr() +
				(_Off < _Mysize - _Count ? _Off : _Mysize - _Count);
			for (; ; --_Uptr)
				if (_Traits::eq(*_Uptr, *_Ptr)
					&& _Traits::compare(_Uptr, _Ptr, _Count) == 0)
					return (_Uptr - _Myptr());	// found a match
				else if (_Uptr == _Myptr())
					break;	// at beginning, no more chance for match
		}

		return (npos);	// no match
	}

	size_type __CLR_OR_THIS_CALL rfind(const _Elem* _Ptr, size_type _Off = npos) const
	{	// look for [_Ptr, <null>) beginning before _Off
		//_DEBUG_POINTER(_Ptr);
		return (rfind(_Ptr, _Off, _Traits::length(_Ptr)));
	}

	size_type __CLR_OR_THIS_CALL rfind(_Elem _Ch, size_type _Off = npos) const
	{	// look for _Ch before _Off
		return (rfind((const _Elem*)&_Ch, _Off, 1));
	}

	size_type __CLR_OR_THIS_CALL find_first_of(const _Myt& _Right,
		size_type _Off = 0) const
	{	// look for one of _Right at or after _Off
		return (find_first_of(_Right._Myptr(), _Off, _Right.size()));
	}

	size_type __CLR_OR_THIS_CALL find_first_of(const _Elem* _Ptr,
		size_type _Off, size_type _Count) const
	{	// look for one of [_Ptr, _Ptr + _Count) at or after _Off

		if (0 < _Count && _Off < _Mysize)
		{	// room for match, look for it
			const _Elem* const _Vptr = _Myptr() + _Mysize;
			for (const _Elem* _Uptr = _Myptr() + _Off; _Uptr < _Vptr; ++_Uptr)
				if (_Traits::find(_Ptr, _Count, *_Uptr) != 0)
					return (_Uptr - _Myptr());	// found a match
		}

		return (npos);	// no match
	}

	size_type __CLR_OR_THIS_CALL find_first_of(const _Elem* _Ptr, size_type _Off = 0) const
	{	// look for one of [_Ptr, <null>) at or after _Off
		//_DEBUG_POINTER(_Ptr);
		return (find_first_of(_Ptr, _Off, _Traits::length(_Ptr)));
	}

	size_type __CLR_OR_THIS_CALL find_first_of(_Elem _Ch, size_type _Off = 0) const
	{	// look for _Ch at or after _Off
		return (find((const _Elem*)&_Ch, _Off, 1));
	}

	size_type __CLR_OR_THIS_CALL find_last_of(const _Myt& _Right,
		size_type _Off = npos) const
	{	// look for one of _Right before _Off
		return (find_last_of(_Right._Myptr(), _Off, _Right.size()));
	}

	size_type __CLR_OR_THIS_CALL find_last_of(const _Elem* _Ptr,
		size_type _Off, size_type _Count) const
	{	// look for one of [_Ptr, _Ptr + _Count) before _Off

		if (0 < _Count && 0 < _Mysize)
			for (const _Elem* _Uptr = _Myptr()
				+ (_Off < _Mysize ? _Off : _Mysize - 1); ; --_Uptr)
				if (_Traits::find(_Ptr, _Count, *_Uptr) != 0)
					return (_Uptr - _Myptr());	// found a match
				else if (_Uptr == _Myptr())
					break;	// at beginning, no more chance for match

		return (npos);	// no match
	}

	size_type __CLR_OR_THIS_CALL find_last_of(const _Elem* _Ptr,
		size_type _Off = npos) const
	{	// look for one of [_Ptr, <null>) before _Off
		//_DEBUG_POINTER(_Ptr);
		return (find_last_of(_Ptr, _Off, _Traits::length(_Ptr)));
	}

	size_type __CLR_OR_THIS_CALL find_last_of(_Elem _Ch, size_type _Off = npos) const
	{	// look for _Ch before _Off
		return (rfind((const _Elem*)&_Ch, _Off, 1));
	}

	size_type __CLR_OR_THIS_CALL find_first_not_of(const _Myt& _Right,
		size_type _Off = 0) const
	{	// look for none of _Right at or after _Off
		return (find_first_not_of(_Right._Myptr(), _Off,
			_Right.size()));
	}

	size_type __CLR_OR_THIS_CALL find_first_not_of(const _Elem* _Ptr,
		size_type _Off, size_type _Count) const
	{	// look for none of [_Ptr, _Ptr + _Count) at or after _Off

		if (_Off < _Mysize)
		{	// room for match, look for it
			const _Elem* const _Vptr = _Myptr() + _Mysize;
			for (const _Elem* _Uptr = _Myptr() + _Off; _Uptr < _Vptr; ++_Uptr)
				if (_Traits::find(_Ptr, _Count, *_Uptr) == 0)
					return (_Uptr - _Myptr());
		}
		return (npos);
	}

	size_type __CLR_OR_THIS_CALL find_first_not_of(const _Elem* _Ptr,
		size_type _Off = 0) const
	{	// look for one of [_Ptr, <null>) at or after _Off
		//_DEBUG_POINTER(_Ptr);
		return (find_first_not_of(_Ptr, _Off, _Traits::length(_Ptr)));
	}

	size_type __CLR_OR_THIS_CALL find_first_not_of(_Elem _Ch, size_type _Off = 0) const
	{	// look for non _Ch at or after _Off
		return (find_first_not_of((const _Elem*)&_Ch, _Off, 1));
	}

	size_type __CLR_OR_THIS_CALL find_last_not_of(const _Myt& _Right,
		size_type _Off = npos) const
	{	// look for none of _Right before _Off
		return (find_last_not_of(_Right._Myptr(), _Off, _Right.size()));
	}

	size_type __CLR_OR_THIS_CALL find_last_not_of(const _Elem* _Ptr,
		size_type _Off, size_type _Count) const
	{	// look for none of [_Ptr, _Ptr + _Count) before _Off

		if (0 < _Mysize)
			for (const _Elem* _Uptr = _Myptr()
				+ (_Off < _Mysize ? _Off : _Mysize - 1); ; --_Uptr)
				if (_Traits::find(_Ptr, _Count, *_Uptr) == 0)
					return (_Uptr - _Myptr());
				else if (_Uptr == _Myptr())
					break;
		return (npos);
	}

	size_type __CLR_OR_THIS_CALL find_last_not_of(const _Elem* _Ptr,
		size_type _Off = npos) const
	{	// look for none of [_Ptr, <null>) before _Off
		//_DEBUG_POINTER(_Ptr);
		return (find_last_not_of(_Ptr, _Off, _Traits::length(_Ptr)));
	}

	size_type __CLR_OR_THIS_CALL find_last_not_of(_Elem _Ch, size_type _Off = npos) const
	{	// look for non _Ch before _Off
		return (find_last_not_of((const _Elem*)&_Ch, _Off, 1));
	}

	_Myt __CLR_OR_THIS_CALL substr(size_type _Off = 0, size_type _Count = npos) const
	{	// return [_Off, _Off + _Count) as new string
		return (_Myt(*this, _Off, _Count, get_allocator()));
	}

	int __CLR_OR_THIS_CALL compare(const _Myt& _Right) const
	{	// compare [0, _Mysize) with _Right
		return (compare(0, _Mysize, _Right._Myptr(), _Right.size()));
	}

	int __CLR_OR_THIS_CALL compare(size_type _Off, size_type _N0,
		const _Myt& _Right) const
	{	// compare [_Off, _Off + _N0) with _Right
		return (compare(_Off, _N0, _Right, 0, npos));
	}

	int __CLR_OR_THIS_CALL compare(size_type _Off,
		size_type _N0, const _Myt& _Right,
		size_type _Roff, size_type _Count) const
	{	// compare [_Off, _Off + _N0) with _Right [_Roff, _Roff + _Count)
		if (_Right.size() < _Roff)
			_String_base::_Xran();	// _Off off end
		if (_Right._Mysize - _Roff < _Count)
			_Count = _Right._Mysize - _Roff;	// trim _Count to size
		return (compare(_Off, _N0, _Right._Myptr() + _Roff, _Count));
	}

	int __CLR_OR_THIS_CALL compare(const _Elem* _Ptr) const
	{	// compare [0, _Mysize) with [_Ptr, <null>)
		//_DEBUG_POINTER(_Ptr);
		return (compare(0, _Mysize, _Ptr, _Traits::length(_Ptr)));
	}

	int __CLR_OR_THIS_CALL compare(size_type _Off, size_type _N0, const _Elem* _Ptr) const
	{	// compare [_Off, _Off + _N0) with [_Ptr, <null>)
		//_DEBUG_POINTER(_Ptr);
		return (compare(_Off, _N0, _Ptr, _Traits::length(_Ptr)));
	}

	int __CLR_OR_THIS_CALL compare(size_type _Off,
		size_type _N0, const _Elem* _Ptr, size_type _Count) const
	{	// compare [_Off, _Off + _N0) with [_Ptr, _Ptr + _Count)

		if (_Mysize < _Off)
			_String_base::_Xran();	// _Off off end
		if (_Mysize - _Off < _N0)
			_N0 = _Mysize - _Off;	// trim _N0 to size

		size_type _Ans = _Traits::compare(_Myptr() + _Off, _Ptr,
			_N0 < _Count ? _N0 : _Count);
		return (_Ans != 0 ? (int)_Ans : _N0 < _Count ? -1
			: _N0 == _Count ? 0 : +1);
	}

	allocator_type __CLR_OR_THIS_CALL get_allocator() const
	{	// return allocator object for values
		return (_Mybase::_Alval);
	}

	enum
	{	// length of internal buffer, [1, 16]
		_BUF_SIZE = 16 / sizeof(_Elem) < 1 ? 1
		: 16 / sizeof(_Elem)
	};

protected:
	enum
	{	// roundup mask for allocated buffers, [0, 15]
		_ALLOC_MASK = sizeof(_Elem) <= 1 ? 15
		: sizeof(_Elem) <= 2 ? 7
		: sizeof(_Elem) <= 4 ? 3
		: sizeof(_Elem) <= 8 ? 1 : 0
	};

	void __CLR_OR_THIS_CALL _Chassign(size_type _Off, size_type _Count, _Elem _Ch)
	{	// assign _Count copies of _Ch beginning at _Off
		if (_Count == 1)
			_Traits::assign(*(_Myptr() + _Off), _Ch);
		else
			_Traits::assign(_Myptr() + _Off, _Count, _Ch);
	}

	void __CLR_OR_THIS_CALL _Copy(size_type _Newsize, size_type _Oldlen)
	{	// copy _Oldlen elements to newly allocated buffer
		size_type _Newres = _Newsize | _ALLOC_MASK;
		if (max_size() < _Newres)
			_Newres = _Newsize;	// undo roundup if too big
		else if (_Newres / 3 < _Myres / 2
			&& _Myres <= max_size() - _Myres / 2)
			_Newres = _Myres + _Myres / 2;	// grow exponentially if possible
		_Elem* _Ptr = 0;

		_TRY_BEGIN
			_Ptr = _Mybase::_Alval.allocate(_Newres + 1);
		_CATCH_ALL
			_Newres = _Newsize;	// allocation failed, undo roundup and retry
		_TRY_BEGIN
			_Ptr = _Mybase::_Alval.allocate(_Newres + 1);
		_CATCH_ALL
			_Tidy(true);	// failed again, discard storage and reraise
		_RERAISE;
		_CATCH_END
			_CATCH_END

			if (0 < _Oldlen)
				_Traits_helper::copy_s<_Traits>(_Ptr, _Newres + 1, _Myptr(), _Oldlen);	// copy existing elements
		_Tidy(true);
		_Bx._Ptr = _Ptr;
		_Myres = _Newres;
		_Eos(_Oldlen);
	}

	void __CLR_OR_THIS_CALL _Eos(size_type _Newsize)
	{	// set new length and null terminator
		_Traits::assign(_Myptr()[_Mysize = _Newsize], _Elem());
	}

	bool __CLR_OR_THIS_CALL _Grow(size_type _Newsize,
		bool _Trim = false)
	{	// ensure buffer is big enough, trim to size if _Trim is true
		if (max_size() < _Newsize)
			_String_base::_Xlen();	// result too long
		if (_Myres < _Newsize)
			_Copy(_Newsize, _Mysize);	// reallocate to grow
		else if (_Trim && _Newsize < _BUF_SIZE)
			_Tidy(true,	// copy and deallocate if trimming to small string
				_Newsize < _Mysize ? _Newsize : _Mysize);
		else if (_Newsize == 0)
			_Eos(0);	// new size is zero, just null terminate
		return (0 < _Newsize);	// return true only if more work to do
	}

	bool __CLR_OR_THIS_CALL _Inside(const _Elem* _Ptr)
	{	// test if _Ptr points inside string
		if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + _Mysize <= _Ptr)
			return (false);	// don't ask
		else
			return (true);
	}

	static size_type __CLRCALL_OR_CDECL _Pdif(const_iterator _P2,
		const_iterator _P1)
	{	// compute safe iterator difference
		return (_STR_ITER_BASE(_P2) == 0 ? 0 : _P2 - _P1);
	}

	void __CLR_OR_THIS_CALL _Tidy(bool _Built = false,
		size_type _Newsize = 0)
	{	// initialize buffer, deallocating any storage
		if (!_Built)
			;
		else if (_BUF_SIZE <= _Myres)
		{	// copy any leftovers to small buffer and deallocate
			_Elem* _Ptr = _Bx._Ptr;
			if (0 < _Newsize)
				_Traits_helper::copy_s<_Traits>(_Bx._Buf, _BUF_SIZE, _Ptr, _Newsize);
			_Mybase::_Alval.deallocate(_Ptr, _Myres + 1);
		}
		_Myres = _BUF_SIZE - 1;
		_Eos(_Newsize);
	}

	union _Bxty
	{	// storage for small buffer or pointer to larger one
		_Elem _Buf[_BUF_SIZE];
		_Elem* _Ptr;
	} _Bx;

	_Elem* __CLR_OR_THIS_CALL _Myptr()
	{	// determine current pointer to buffer for mutable string
		return (_BUF_SIZE <= _Myres ? _Bx._Ptr : _Bx._Buf);
	}

	const _Elem* __CLR_OR_THIS_CALL _Myptr() const
	{	// determine current pointer to buffer for nonmutable string
		return (_BUF_SIZE <= _Myres ? _Bx._Ptr : _Bx._Buf);
	}

	size_type _Mysize;	// current length of string
	size_type _Myres;	// current storage reserved for string
};

// basic_string implements a performant swap
//template<class _Elem, class _Traits, class _Ax>
//class _Move_operation_category<basic_string<_Elem, _Traits, _Ax> >
//{
//public:
//	typedef _Swap_move_tag _Move_cat;
//};

// STATIC npos OBJECT
template<class _Elem,
	class _Traits,
	class _Alloc>
	_PGLOBAL const typename basic_string<_Elem, _Traits, _Alloc>::_Alloc::size_type
	basic_string<_Elem, _Traits, _Alloc>::npos =
	(typename basic_string<_Elem, _Traits, _Alloc>::size_type)(-1);

// basic_string TEMPLATE OPERATORS

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	void __CLRCALL_OR_CDECL swap(basic_string<_Elem, _Traits, _Alloc>& _Left,
		basic_string<_Elem, _Traits, _Alloc>& _Right)
{	// swap _Left and _Right strings
	_Left.swap(_Right);
}

typedef basic_string<char, char_traits<char>, allocator<char> >
string;
typedef basic_string<wchar_t, char_traits<wchar_t>,
	allocator<wchar_t> > wstring;

#if defined(_DLL_CPPLIB) && !defined(_M_CEE_PURE)

template class _CRTIMP2_PURE allocator<char>;
template class _CRTIMP2_PURE allocator<wchar_t>;
template class _CRTIMP2_PURE _String_val<char, allocator<char> >;
template class _CRTIMP2_PURE _String_val<wchar_t, allocator<wchar_t> >;
template class _CRTIMP2_PURE basic_string<char, char_traits<char>,
	allocator<char> >;
template class _CRTIMP2_PURE basic_string<wchar_t, char_traits<wchar_t>,
	allocator<wchar_t> >;




#endif /* _DLL_CPPLIB */
} //_STD_END
#ifdef _MSC_VER
#pragma warning(default: 4251)
#pragma warning(pop)
#pragma pack(pop)
#endif  /* _MSC_VER */

#endif /* RC_INVOKED */
#endif /* _XSTRING */

/*
 * Copyright (c) 1992-2007 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
 V5.03:0009 */
