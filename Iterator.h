//
// Created by DARIO on 18/09/2019.
//

#ifndef ALGORITMOS_ITERATOR_H
#define ALGORITMOS_ITERATOR_H
template<class T>
class Iterator {
public:
    typedef T node_t;
    typedef typename node_t::value_t value_t;

protected:
    node_t * pointer;
public:

    Iterator(node_t* _pointer = nullptr):pointer(_pointer){
    }

    ~Iterator(void){
    }

    virtual bool operator!= (Iterator<T> it){
        return pointer != it.pointer;
    }

    virtual value_t& operator* (void) {
        return **pointer;
    }

	virtual Iterator& operator++(void) const = 0;
	virtual Iterator& operator++(int) const = 0;
	virtual Iterator& operator--(void) const = 0;
	virtual Iterator& operator--(int) const = 0;

	virtual bool operator == (const Iterator&) const = 0;
	virtual bool operator != (const Iterator&) const = 0;
	virtual bool operator <= (const Iterator&) const = 0;
	virtual bool operator >= (const Iterator&) const = 0;
	virtual bool operator < (const Iterator&) const = 0;
	virtual bool operator > (const Iterator&) const = 0;

	virtual void operator=(const T&) = 0;

};
#endif //ALGORITMOS_ITERATOR_H
