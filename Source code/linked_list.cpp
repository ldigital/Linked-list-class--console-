#include <iostream>
#include <linked_list.h>
#include <string>

linked_list::linked_list(): _List(NULL){} //List must be initialised to NULL because it starts as empty

linked_list::~linked_list(){
    delete _entry;  //when finished, memory can be given back to free store
}

void linked_list::add(){

    std::cin.ignore(); //This is to prevent interference with getline()
    _entry = new node; //borrow memory to create records, and store them to the list

    std::cout << "Please enter first name" << std::endl;
    std::getline(std::cin, _entry->firstName, '\n');

    std::cout << "Please enter last name" << std::endl;
    std::getline(std::cin, _entry->lastName, '\n');

    std::cout << "Please enter email address" << std::endl;
    std::getline(std::cin, _entry->email, '\n');

    std::cout << "Please enter age" << std::endl;
    std::cin >> _entry->age;

    std::cin.ignore();
    std::cout << "Please enter membership number" << std::endl;
    std::getline(std::cin, _entry->memberNumber, '\n');

    std::cout << "Please enter occupation" << std::endl;
    std::getline(std::cin, _entry->occupation, '\n');

    std::cout << "Please enter address line 1" << std::endl;
    std::getline(std::cin, _entry->addressLine1, '\n');

    std::cout << "Please enter address line 2" << std::endl;
    std::getline(std::cin, _entry->addressLine2, '\n');

    std::cout << "Please enter postcode" << std::endl;
    std::getline(std::cin, _entry->postCode, '\n');

    std::cout << "Please enter contact phone number" << std::endl;
    std::getline(std::cin, _entry->contactPhoneNumber, '\n');

    std::cout << "\n\n";

    _entry->next = _List; //must connect to the next node, or top of list
    _List = _entry;  //save the record to the list

}

void linked_list::remove(){

    node * removeNode = _List;  //the pointer to be isolated, then eventually deleted
    node * trail = NULL;   //keeps track of where link has been broken, and will reconnect
    std::string valuetoRemove; //input from user
    std::cin >> valuetoRemove;

    //search list for value
    while(removeNode != NULL){
        if(valuetoRemove == removeNode->firstName || valuetoRemove == removeNode->lastName ){
           break;
        }
        else{
            trail = removeNode;   //if the removeNode wasn't at the top, and thus needs to move forward, copy to trail for later use
            removeNode = removeNode->next; //now the address of the removeNode is continuosly saved to trail, its safe to push forward in list
        }
    }

    //case 1 when value has been found, check if its at top of list
    if(removeNode == _List){
        _List = _List->next;     // because top of the list is going to be removed need to assign new top of the list to the next in node of list
    }

    //case 2 if not at top, then must be anywhere else
    else{
        trail->next = removeNode->next; //from any other location, use the address saved in trail to point to what the node to be removed
                                        //is pointing to.
    }
    delete removeNode; //one of the above cases will enable this node to be removed, while successfully reconnecting the list from any node.
}

void linked_list::search(){

    node * searchList = _List;
    std::string valueSearch;
    std::cin.ignore();
    std::cout << "Please enter name of person to search" << std::endl;
    std::getline(std::cin, valueSearch, '\n');

    //search the list
    while(searchList != NULL){
        if(valueSearch == searchList->firstName || valueSearch == searchList->lastName){
           std::cout << "match found" << std::endl;
           break;
        }
        else{
            std::cout << "no match found" << std::endl;
            searchList = searchList->next;
        }
    }

    //if match has been found - display results
    std::cout << "Full details for " << valueSearch;
    std::cout << "\n\n";
    std::cout << " ------------------------------------------------------------------------\n";
    std::cout << "| First Name:           " << searchList->firstName << std::endl;
    std::cout << "| Last Name:            " << searchList->lastName << std::endl;
    std::cout << "| Email:                " << searchList->email << std::endl;
    std::cout << "| Age:                  " << searchList->age << std::endl;
    std::cout << "| Membership Number:    " << searchList->memberNumber << std::endl;
    std::cout << "| Occupation:           " << searchList->occupation << std::endl;
    std::cout << "| Address line 1:       " << searchList->addressLine1 << std::endl;
    std::cout << "| Address line 2:       " << searchList->addressLine2 << std::endl;
    std::cout << "| Post/Zip code:        " << searchList->postCode << std::endl;
    std::cout << "| Contact phone number: " << searchList->contactPhoneNumber << std::endl;
    std::cout << " ------------------------------------------------------------------------\n";
    std::cout << "\n\n";
}

void linked_list::display(){

    node * current = _List;
    /*when called, run through the entire list, starting from the most recent entry, printing
      it's details, then moving on to the next node...*/

    while(current != NULL){
        std::cout << "\n\n";
        std::cout << " ------------------------------------------------------------------------\n";
        std::cout << "| First Name:           " << current->firstName << std::endl;
        std::cout << "| Last Name:            " << current->lastName << std::endl;
        std::cout << "| Email:                " << current->email << std::endl;
        std::cout << "| Age:                  " << current->age << std::endl;
        std::cout << "| Membership Number:    " << current->memberNumber << std::endl;
        std::cout << "| Occupation:           " << current->occupation << std::endl;
        std::cout << "| Address line 1:       " << current->addressLine1 << std::endl;
        std::cout << "| Address line 2:       " << current->addressLine2 << std::endl;
        std::cout << "| Post/Zip code:        " << current->postCode << std::endl;
        std::cout << "| Contact phone number: " << current->contactPhoneNumber << std::endl;
        std::cout << " ------------------------------------------------------------------------\n";
        std::cout << "\n\n";

        current = current->next;
    }
}

