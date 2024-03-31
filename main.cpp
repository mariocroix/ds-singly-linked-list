#include "forward-list.hpp"

int main() {
    // Create a ForwardList of integers
    ForwardList<int> myList;

    // Test push_back and push_front
    myList.push_back(1);
    myList.push_back(2);
    myList.push_front(0);

    // Test print
    std::cout << "Original List: ";
    myList.print();

    // Test pop_back and pop_front
    myList.pop_back();
    myList.pop_front();

    // Test print after modifications
    std::cout << "Modified List: ";
    myList.print();

    // Test reverseIt
    myList.reverseIt();
    std::cout << "Reversed List: ";
    myList.print();

    // Test reverseRec
//    myList.reverseRec();
//    std::cout << "Reversed Recursive List: ";
//    myList.print();

//    // Test getMiddleNode
//    ForwardList<int>::Node* middleNode = myList.getMiddleNode();
//    std::cout << "Middle Node Value: " << middleNode->_data << std::endl;

    // Test hasCycle
    bool hasCycle = myList.hasCycle();
    std::cout << "Has Cycle: " << (hasCycle ? "Yes" : "No") << std::endl;

    // Test getStartPoint
    ForwardList<int>::size_type startPoint = myList.getStartPoint();
    std::cout << "Start Point of Cycle: " << startPoint << std::endl;

    // Clear the list
    myList.clear();

    // Test empty after clear
    std::cout << "Is the list empty? " << (myList.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
