# ImAnimate
Immediate Mode animation extension for [Dear ImGui](https://github.com/ocornut/imgui).

## Usage & How it works

**Function Signature**
```cpp
void Animate(float aStartValue, float aEndValue, double aDurationMs, float* aValue, ECurve aCurve = ECurve::Linear);
```
The parameter `aCurve` is both the out parameter as usual with ImGui and the current value.

**Example hover animation**
```cpp
if (ImGui::IsItemHovered)
{
    ImGui::Animate(1000, 1500, 500, &hoverSize, ECurve::InOutSine);
}
else
{
    ImGui::Animate(1500, 1000, 500, &hoverSize, ECurve::InOutSine);
}
```
You don't need to track any current value, animation start or state.  
You just provide your start and end values, as well as the duration in milliseconds and your curve.