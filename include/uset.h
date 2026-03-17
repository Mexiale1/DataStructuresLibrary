#pragma once

template <typename T>

class Uset{
    public:
        // Returns the number of items in the set.  
        virtual size_t size() const = 0;
        // Add an item to the set, accepts the item (any data type) as a parameter. If the item already exists in the set, it should not be added again.
        virtual void add(const T& item) = 0;
        // Remove an item from the set, accepts the item (any data type) as a parameter. 
        virtual void remove(const T& item) = 0;
        // Returns true if the item exists in the set, false otherwise.
        virtual bool find(const T& item) const = 0;
};