#include <iostream>
#include <3dcpp.h>

int main() {
    // 3Dcpp - Running your precise target pipeline cleanly!
    auto scene = SceneCreate();
    auto camera = CameraCreate();
    auto models = GetModels(objectType); 
    auto moreThings = all();

    scene.Create();
    camera.CameraMakerPosition();
    models.TypeModel(cube, pyramid, sphere);
    
    // Automatically hooks your scene pointer address to your background loop logic
    moreThings.TrackScene(&scene); 
    moreThings.RunPackage();
    
    return 0;
}

