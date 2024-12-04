#include <iostream>
#include <fstream>
#include "person.pb.h"  // Generated file

void Serialize(const Person& person, const std::string& filename) {
    std::ofstream output(filename, std::ios::binary);
    if (!person.SerializeToOstream(&output)) {
        std::cerr << "Failed to write to file." << std::endl;
    }
}

Person Deserialize(const std::string& filename) {
    Person person;
    std::ifstream input(filename, std::ios::binary);
    if (!person.ParseFromIstream(&input)) {
        std::cerr << "Failed to read from file." << std::endl;
    }
    return person;
}

int main() {
    // Create a new Person object
    Person person;
    person.set_name("John Doe");
    person.set_id(123);
    person.set_email("john.doe@example.com");

    // Serialize to file
    Serialize(person, "person.dat");

    // Deserialize from file
    Person new_person = Deserialize("person.dat");

    // Output the deserialized data
    std::cout << "Name: " << new_person.name() << std::endl;
    std::cout << "ID: " << new_person.id() << std::endl;
    std::cout << "Email: " << new_person.email() << std::endl;

    return 0;
}