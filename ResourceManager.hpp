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
    ~ResourceManager() { std::cout << "ResourceManager destroyed" << std::endl; }
<<<<<<<<< Temporary merge branch 1

    double get() { return resource->get(); }

    double get() const { return resource->get(); }

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
};

    ResourceManager(ResourceManager&&) noexcept = default;
=========
    double get() { return resource->get(); }
    ResourceManager(const ResourceManager&)                = delete;
    ResourceManager& operator=(const ResourceManager&)     = delete;
    ResourceManager(ResourceManager&&) noexcept            = default;
>>>>>>>>> Temporary merge branch 2
    ResourceManager& operator=(ResourceManager&&) noexcept = default;
};
