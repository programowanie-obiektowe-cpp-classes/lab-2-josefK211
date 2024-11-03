#include "Resource.hpp"
#include <iostream>

class ResourceManager
{
private:
    Resource* resource; 

public:
    ResourceManager() : resource(new Resource())
    {
        std::cout << "ResourceManager created" << std::endl;
    }

    ~ResourceManager()
    {
        delete resource;
        std::cout << "ResourceManager destroyed" << std::endl;
    }

    double get() const { return resource->get(); }

    ResourceManager(const ResourceManager& other)
    {
        resource = new Resource(*other.resource);
        std::cout << "ResourceManager copied" << std::endl;
    }

    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            delete resource;                         
            resource = new Resource(*other.resource); 
        }
        std::cout << "ResourceManager assigned" << std::endl;
        return *this;
    }

    ResourceManager(ResourceManager&& other) noexcept : resource(other.resource)
    {
        other.resource = nullptr;
        std::cout << "ResourceManager moved" << std::endl;
    }

    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        if (this != &other) {
            delete resource;                 
            resource       = other.resource; 
            other.resource = nullptr;        
        }
        std::cout << "ResourceManager move-assigned" << std::endl;
        return *this;
    }
};

