# 3Dcpp
3D making for C++

# It includes
<b>Cubes, Pyramids, Spheres, etc.</b>

# DEVELOPER READ THIS
You must add functions to the <b>3Dcpp.h</b>
<b>For Example:</b>
```cpp
#include <iostream>
#include <3dcpp.h>

int main() {
int scene = SceneCreate();
int camera = CameraCreate();
int models = GetModels(objectType);
int moreThings = all();
scene.Create();
camera.CameraMakerPosition();
models.TypeModel(cube, pyramid, sphere);
moreThings.RunPackage();
return 0;
}
