#pragma once
#include <iostream>
class IntegerSet {
	friend std::ostream& operator<<(std::ostream& , const IntegerSet& );
public:
	IntegerSet();
	IntegerSet(const IntegerSet& );
	IntegerSet(int[], int); //(array, size ) 
	IntegerSet operator+(const IntegerSet& ) const; // Union of 2 sets
	IntegerSet operator*(const IntegerSet&) const;  // Intersection of 2 sets
	IntegerSet operator-(const IntegerSet& right) const; // Difference Set1 - Set2
private:
	const static size_t capacity = 101;
	bool a[capacity];
};

IntegerSet::IntegerSet() {
	for (size_t i = 0; i < capacity; i++) a[i] = false;
}
IntegerSet::IntegerSet(const IntegerSet& other) {
	for (size_t i = 0; i < capacity; i++) a[i] = other.a[i];
}
IntegerSet::IntegerSet(int arr[], int size) {
	for (size_t i = 0; i < capacity; i++) a[i] = false;
	for (size_t i = 0; i < size; i++) a[arr[i]] = true;
}
IntegerSet IntegerSet::operator+(const IntegerSet& right) const {
	IntegerSet result;
	for (size_t i = 0; i < capacity; i++)
	{
		result.a[i] = this->a[i] || right.a[i];
	}
	return result;
}
IntegerSet IntegerSet::operator*(const IntegerSet& right) const {
	IntegerSet result;
	for (size_t i = 0; i < capacity; i++)
	{
		result.a[i] = this->a[i] && right.a[i];
	}
	return result;
}
IntegerSet IntegerSet::operator-(const IntegerSet& right) const {
	IntegerSet result;
	for (size_t i = 0; i < capacity; i++)
	{
		result.a[i] = this->a[i] && !right.a[i];
	}
	return result;
}
std::ostream& operator<<(std::ostream& output, const IntegerSet& set) {
	// output private  array
	for (size_t i{ 0 }; i < set.capacity; ++i)
		if (set.a[i])
			output << i << " ";

	return output;
}
