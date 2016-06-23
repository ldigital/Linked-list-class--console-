/* This little program was written by Leon Harvey to demonstrate a data-structure being stored to a Linked List.
 * The data structure is an example of a customer/employee file system, that can be easily
 * added to, searched on, removed from, and viewed.
 *
 * This program was designed and written by Leon Harvey*/

#include <iostream>
#include <linked_list.h>

int main()
{
    linked_list obj;
    int menuOption = 0;

    while(1){
        std::cout << "Please enter:\n"
                  << "1 to add an entry to the list\n"
                  << "2 to search on an existing entry\n"
                  << "3 to remove from the list\n"
                  << "4 to view contents of the list\n\n";
        std::cin >> menuOption;

        if(menuOption == 1){
            std::cout << "[Add an entry to the list]\n\n";
            obj.add();
        }

        if(menuOption == 2){
            std::cout << "[Search the list]\n\n";
            obj.search();
        }

        if(menuOption == 3){
            std::cout << "[Remove an entry from the list]\n\n";
            obj.remove();
        }

        if(menuOption == 4){
            std::cout << "[View the entire list]\n\n";
            obj.display();
        }
    }
    return 0;
}
