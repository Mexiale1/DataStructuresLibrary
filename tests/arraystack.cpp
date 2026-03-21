#include "../src/arraystack.h"
#include <iostream>

int main() {
    ArrayStack<int> st;

    st.push(10);
    st.push(20);

    std::cout << st.top() << std::endl; // 20
    std::cout << st.pop() << std::endl; // 20
    std::cout << st.pop() << std::endl; // 10

    return 0;
}