#ifndef LINKED_LIST //include guard
#define LINKED_LIST

#include <string>
struct node{
    //Create's a file/record system for customers/employee's etc
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string age;
    std::string memberNumber;
    std::string occupation;
    std::string addressLine1;
    std::string addressLine2;
    std::string postCode;
    std::string contactPhoneNumber;
    node * next;
};

class linked_list{
public:
    linked_list();
    ~linked_list();

    void add();
    void remove();
    void search();
    void display();

private:
    node * _List;  //This is the ACTUAL list that is only refered to, but kept seperate from other processes.
    node * _entry; /*This like other _List based pointers, is also a private member because it will create
                     record entries to the list in runtime, and will thus use dynamic memory. Creating it here makes sure
                     it can be sent to destructor*/
};

#endif
