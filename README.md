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
// 3Dcpp
auto scene = SceneCreate();
auto camera = CameraCreate();
auto models = GetModels(objectType);
auto moreThings = all();
scene.Create();
camera.CameraMakerPosition();
models.TypeModel(cube, pyramid, sphere);
moreThings.RunPackage();
return 0;
}
