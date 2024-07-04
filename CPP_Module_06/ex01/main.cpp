#include "Serializer.hpp"


int main() {
    Data* data = new Data;
    data->n = 42;

    std::cout << "Data address     : " << data << std::endl;


    uintptr_t rawData = Serializer::serialize(data);
    std::cout << "Raw data         : " << rawData << std::endl;

    Data* retData = Serializer::deserialize(rawData);
    std::cout << "Deserialized data: " << retData << std::endl;

    std::cout << "Data value       : " << retData->n << std::endl;

    delete data;
    return 0;
}