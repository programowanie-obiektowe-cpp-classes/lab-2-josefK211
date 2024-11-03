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

    ResourceManager(const ResourceManager&)                = delete;
    ResourceManager& operator=(const ResourceManager&)     = delete;
    ResourceManager(ResourceManager&&) noexcept            = default;
    ResourceManager& operator=(ResourceManager&&) noexcept = default;
};
