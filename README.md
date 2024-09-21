# ImAnimate
Immediate Mode animation extension for [Dear ImGui](https://github.com/ocornut/imgui).

## Usage & How it works

**Function Signature**
```cpp
void Animate(float aStartValue, float aEndValue, double aDurationMs, float* aValue, ECurve aCurve = ECurve::Linear);
```
The parameter `aCurve` is both the out parameter as usual with ImGui and the current value.

**Example: Hover Animation**  
![hover_animation_example](https://github.com/user-attachments/assets/bdd7c943-0f4d-400e-b95d-29e9e3e296d4)  
```cpp
static float imgSize = 1.0f;
ImGui::Image(icon, ImVec2(imgSize, imgSize));
if (ImGui::IsItemHovered)
{
    ImGui::Animate(1.0f, 1.1f, 500, &imgSize, ECurve::InCubic);
}
else
{
    ImGui::Animate(1.1f, 1.0, 500, &imgSize, ECurve::OutCubic);
}
```
You don't need to track any current value, animation start or state.  
You just provide your start and end values, as well as the duration in milliseconds and your curve.
