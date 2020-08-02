// TheForge - src/forge_vars (c) Andrew Woo, 2020

#pragma warning(disable : 26495)
#pragma once

#ifndef THEFORGE_VARS
#define THEFORGE_VARS

// Standard Library
#include <array>
#include <vector>
#include <utility>
#include <optional>

// Dependencies
#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>

namespace Forge {

    // Check if in debug mode
#ifdef NDEBUG
    constexpr bool DEBUG_MODE = false;          // If false, do not enable debug mode
#else
    constexpr bool DEBUG_MODE = true;           // If true, enable debug mode
#endif

    static const std::vector<const char*> ValidationLayers = { "VK_LAYER_KHRONOS_validation" };             // List of validation layers to enable
    static const std::vector<const char*> DeviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };           // List of device extensions to enable

    constexpr int MAX_FRAMES_IN_FLIGHT = 2;

    struct Vertex {

        glm::vec2 position;         // Vertex position in 2D space
        glm::vec3 color;            // Vertex color

        // Create a vertex binding description
        static VkVertexInputBindingDescription GetBindingDescription();

        // Array of vertex attribute descriptions
        static std::array<VkVertexInputAttributeDescription, 2> GetAttributeDesciptions();
    };

    const Vertex vertices[] = {
        {{ 0.0f, -0.5f}, {1.0f, 0.0f, 0.0f}},
        {{ 0.5f,  0.5f}, {0.0f, 1.0f, 0.0f}},
        {{-0.5f,  0.5f}, {0.0f, 0.0f, 1.0f}}
    };

    // Create buffer object
    //int CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkBuffer& buffer, VmaAllocator& _allocator, VmaAllocation& _allocation);
    //// Copy buffer from source to destination
    //void CopyBuffer(VkDevice& device, VkCommandPool& cmdPool, VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

    struct QueueFamilyIndices {                         // Struct containing Queue Family indices

        std::optional<uint32_t> graphicsFamily;         // Index for graphics queue family
        std::optional<uint32_t> presentFamily;          // Index for presentation queue family

        bool hasValue();        // Function to determine if all queue families have indices
    };
    QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice& device, VkSurfaceKHR& surface);     // Finds queue family supported by specified device

    struct SwapChainSupportDetails {                    // Struct containing Swap Chain support details

        VkSurfaceCapabilitiesKHR capabilities;          // Struct containing details of the capabilities of the swap chains
        std::vector<VkSurfaceFormatKHR> formats;        // List of structures describing a supported swapchain format-color space pair
        std::vector<VkPresentModeKHR> presentModes;     // List of presentation modes supported by the device
    };
    SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice& device, VkSurfaceKHR& surface);             // Populates SwapChainSupportDetails
    VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);        // Choose surface format
    VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);         // Choose surface present mode
    VkExtent2D ChooseSwapExtent(GLFWwindow* window, const VkSurfaceCapabilitiesKHR& capabilities);              // Choose swap extent -> surface resolution

    // TEMP
    enum class RendererType {       // Renderer type
        Render_2D,
        Render_3D
    };

    enum class ShaderLanguage {
        THE_FORGE_VK_SHADER_LANGUAGE_SPV,
        THE_FORGE_VK_SHADER_LANGUAGE_GLSL
    };

    enum class ShaderType {
        THE_FORGE_VK_SHADER_TYPE_VERTEX,
        THE_FORGE_VK_SHADER_TYPE_FRAGMENT
    };
}

#endif // !THEFORGE_VARS
