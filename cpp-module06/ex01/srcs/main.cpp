#include "Serial.hpp"



int main() {
    Data originalData;
    originalData.value = 42;
	originalData.name = "Hello World";


	std::cout << "Data value: " << originalData.value << std::endl;
	std::cout << "Data name: " << originalData.name << std::endl;
	std::cout << std::endl;
    // Serialize the pointer
    uintptr_t originalRaw = serialize(&originalData);

    std::cout << "Serialized value: " << originalRaw << std::endl;
	std::cout << std::endl;
    // Deserialize back to pointer
    Data* oldRaw = deserialize(originalRaw);
    std::cout << "Deserialized value int: " << oldRaw->value << std::endl;
	std::cout << "Deserialized value name: " << oldRaw->name << std::endl;

	std::cout << std::endl;
	if (&originalData == oldRaw) {
        std::cout << "Serialization/Deserialization successful.\n";
    } else {
        std::cout << "Error in Serialization/Deserialization.\n";
    }

    return 0;
}
