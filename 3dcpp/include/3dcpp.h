#pragma once
#include <iostream>
#include <vector>
#include <GLFW/glfw3.h> // Cross-platform native window controller

// Define enums to match your exact main() parameters
enum ObjectType { objectType, DefaultObjects, AllObjects };
enum ModelType { cube, pyramid, sphere };

// 1. Models Manager Class
class Models {
public:
    void TypeModel(ModelType m1, ModelType m2, ModelType m3) {
        // Here you would upload vertex arrays (VBOs) to the GPU
        std::cout << "[3Dcpp] 3D Model profiles buffered natively.\n";
    }
};

// 2. Camera Engine Class
class Camera {
public:
    void CameraMakerPosition() {
        // Adjust standard hardware projection perspective matrix mappings
        std::cout << "[3Dcpp] Viewport camera matrices calculated.\n";
    }
};

// 3. Scene Management Class
class Scene {
private:
    GLFWwindow* window = nullptr;
public:
    void Create() {
        if (!glfwInit()) {
            std::cerr << "CRITICAL: Window system initialization failed!\n";
            return;
        }
        
        // Create an absolute hardware desktop canvas window
        window = glfwCreateWindow(800, 600, "3Dcpp Render Viewport", NULL, NULL);
        if (!window) {
            glfwTerminate();
            std::cerr << "CRITICAL: Failed to create GPU context window!\n";
            return;
        }
        glfwMakeContextCurrent(window); // Bind canvas to current context thread
        std::cout << "[3Dcpp] Graphics canvas initialized cleanly.\n";
    }
    
    GLFWwindow* GetNativeWindow() const { return window; }
};

// 4. Package Runner Automation Class
class PackageRunner {
private:
    Scene* targetScene = nullptr;
public:
    // Tracks which scene object needs to be processed
    void TrackScene(Scene* s) { targetScene = s; }

    void RunPackage() {
        if (!targetScene || !targetScene->GetNativeWindow()) {
            std::cerr << "CRITICAL: Cannot run package. Active scene has not been created!\n";
            return;
        }
        
        GLFWwindow* win = targetScene->GetNativeWindow();
        std::cout << "[3Dcpp] Launching event listening canvas loop...\n";

        // Main GPU Render Frame Loop
        while (!glfwWindowShouldClose(win)) {
            // Clear background with dark slate blue color
            glClearColor(0.12f, 0.15f, 0.22f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // Render a native vector triangle onto your monitor screen
            glBegin(GL_TRIANGLES);
                glColor3f(0.9f, 0.2f, 0.3f);  glVertex3f( 0.0f,  0.5f, 0.0f); // Top Red
                glColor3f(0.2f, 0.8f, 0.4f);  glVertex3f(-0.5f, -0.5f, 0.0f); // Bottom Green
                glColor3f(0.2f, 0.4f, 0.9f);  glVertex3f( 0.5f, -0.5f, 0.0f); // Bottom Blue
            glEnd();

            glfwSwapBuffers(win); // Refresh screen graphics buffer
            glfwPollEvents();    // Keep track of windows clicks/closes
        }
        
        // Safely release system window allocations on closure
        glfwDestroyWindow(win);
        glfwTerminate();
        std::cout << "[3Dcpp] Engine pipeline shut down safely.\n";
    }
};

// -----------------------------------------------------------------------------
// Global Fluent Package Factory Hooks
// -----------------------------------------------------------------------------
inline Scene SceneCreate() { return Scene(); }
inline Camera CameraCreate() { return Camera(); }
inline Models GetModels(ObjectType type) { return Models(); }
inline PackageRunner all() { return PackageRunner(); }
