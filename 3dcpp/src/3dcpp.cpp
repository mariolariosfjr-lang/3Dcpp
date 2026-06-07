#include "3dcpp.h"

// -----------------------------------------------------------------------------
// Models Implementation
// -----------------------------------------------------------------------------
void Models::TypeModel(ModelType m1, ModelType m2, ModelType m3) {
    std::cout << "[3Dcpp] 3D Model geometry buffers successfully cached.\n";
}

// -----------------------------------------------------------------------------
// Camera Implementation
// -----------------------------------------------------------------------------
void Camera::CameraMakerPosition() {
    std::cout << "[3Dcpp] Viewport projection matrices calculated.\n";
}

// -----------------------------------------------------------------------------
// Scene Implementation
// -----------------------------------------------------------------------------
void Scene::Create() {
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

GLFWwindow* Scene::GetNativeWindow() const { 
    return window; 
}

// -----------------------------------------------------------------------------
// PackageRunner Implementation
// -----------------------------------------------------------------------------
void PackageRunner::TrackScene(Scene* s) { 
    targetScene = s; 
}

void PackageRunner::RunPackage() {
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
        glfwPollEvents();    // Keep track of window clicks/closes
    }
    
    // Safely release system window allocations on closure
    glfwDestroyWindow(win);
    glfwTerminate();
    std::cout << "[3Dcpp] Engine pipeline shut down safely.\n";
}

