#include "Resource.hpp"
#include <iostream>
#include <memory>

class ResourceManager
{
private:
    std::unique_ptr< Resource > resource; 

public:
    ResourceManager() : resource(std::make_unique< Resource >())
    {
        std::cout << "ResourceManager created" << std::endl;
    }

    ~ResourceManager() { std::cout << "ResourceManager destroyed" << std::endl; }

    double get() { return resource->get(); }

    ResourceManager(const ResourceManager& other)
    {
        if (other.resource) {
            resource =
                std::make_unique< Resource >(*other.resource); 
        }
        std::cout << "ResourceManager copied" << std::endl;
    }

    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this == &other) {
            return *this; 
        }

        if (other.resource) {
            resource =
                std::make_unique< Resource >(*other.resource); 
        }
        else {
            resource.reset(); 
        }
        std::cout << "ResourceManager assigned" << std::endl;
        return *this;
    }

    ResourceManager(ResourceManager&&) noexcept = default;
    ResourceManager& operator=(ResourceManager&&) noexcept = default;
};
