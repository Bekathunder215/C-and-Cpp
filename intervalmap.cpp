#include <map>
#include <iostream>
#include <iterator>
#include <list>
#include <iterator>
#include <limits>


template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val): m_valBegin(val)
	{
		m_map.insert(m_map.end(), std::make_pair(std::numeric_limits<K>::lowest(), val));
	}
	void getkeys()
	{
		for(auto&&[key, value] : m_map)
			std::cout << "[ " << key << "] = " << value << "; " << std::endl;
	}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
    
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) 
	{
if (keyEnd < keyBegin)  //reverse the order makes simpler code
	        return;
		auto end_iter = m_map.find(keyEnd);
		//if end_iter is not at the end of the map then
		//we insert the val at the position of the end_iter
		//lower_bound() returns an iterator to the first element NOT LESS than the given key
		if (auto v = m_map.lower_bound(keyEnd); end_iter != m_map.end())
		{
			end_iter->second = v->second;
		}
		//but if it is not on the map, then we insert the prev value at position keyEnd
		else
		{
			//insert( where , what)
			//here the end of the key "array" is end_iter
			// so we insert at end_iter 
			end_iter = m_map.insert(m_map.end(), std::make_pair(keyEnd, (--v)->second));
		}
		auto begin_iter = m_map.insert_or_assign(keyBegin, val).first;
		//we firt did the upperbounds of the map
		//because the begin_iter might have not been less than 
		//the first element in the map. therefore we just do the upperbounds first

		//cleanup range
		m_map.erase(std::next(begin_iter), end_iter);

		//make canonical
		auto iterright = end_iter;
		auto iterleft = (begin_iter != m_map.begin() ? std::prev(begin_iter): begin_iter);
		while(iterright!=iterleft)
		{
			auto iternext = std::prev(iterright);
			if (iterright->second == iternext->second)
				m_map.erase(iterright);
			iterright = iternext;
		}
    }

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const 
	{
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

int main()
{
	interval_map<int, char> map1{'a'};
	map1.getkeys();
	map1.assign(3, 5, 'b');
	std::cout << "Done" << std::endl;
	map1.getkeys();
	map1.assign(2, 3, 'c');
	std::cout << "Done" << std::endl;
	map1.getkeys();
	map1.assign(2, 3, 'd');
	std::cout << "Done" << std::endl;
	map1.getkeys();
	map1.assign(2, 4, 'e');
	std::cout << "Done" << std::endl;
	map1.getkeys();
	map1.assign(4, 18, 'f');
	std::cout << "Done" << std::endl;
	map1.getkeys();
	map1.assign(2, 8, 'g');
	std::cout << "Done" << std::endl;
	map1.getkeys();
	map1.assign(0, 10, 'A');
	std::cout << "Done" << std::endl;
	map1.getkeys();
	map1.assign(0, 20, 'B');
	std::cout << "Done" << std::endl;
	map1.getkeys();
	map1.assign(0, 30, 'C');
	std::cout << "Done" << std::endl;
	map1.getkeys();
}