#ifndef IMANIMATE_H
#define IMANIMATE_H

#include <imgui.h>
#include <map>

///----------------------------------------------------------------------------------------------------
/// ImAnimate Namespace
///----------------------------------------------------------------------------------------------------
namespace ImAnimate
{
	///----------------------------------------------------------------------------------------------------
	/// ECurve Enumeration
	///----------------------------------------------------------------------------------------------------
	enum class ECurve
	{
		Linear,

		InSine,
		OutSine,
		InOutSine,

		InQuad,
		OutQuad,
		InOutQuad,

		InCubic,
		OutCubic,
		InOutCubic,

		InQuart,
		OutQuart,
		InOutQuart,

		InQuint,
		OutQuint,
		InOutQuint,

		InExpo,
		OutExpo,
		InOutExpo,

		InCirc,
		OutCirc,
		InOutCirc
	};

	float CurveFunc_Linear(float aProgress);

	float CurveFunc_InSine(float aProgress);
	float CurveFunc_OutSine(float aProgress);
	float CurveFunc_InOutSine(float aProgress);

	float CurveFunc_InQuad(float aProgress);
	float CurveFunc_OutQuad(float aProgress);
	float CurveFunc_InOutQuad(float aProgress);

	float CurveFunc_InCubic(float aProgress);
	float CurveFunc_OutCubic(float aProgress);
	float CurveFunc_InOutCubic(float aProgress);

	float CurveFunc_InQuart(float aProgress);
	float CurveFunc_OutQuart(float aProgress);
	float CurveFunc_InOutQuart(float aProgress);

	float CurveFunc_InQuint(float aProgress);
	float CurveFunc_OutQuint(float aProgress);
	float CurveFunc_InOutQuint(float aProgress);

	float CurveFunc_InExpo(float aProgress);
	float CurveFunc_OutExpo(float aProgress);
	float CurveFunc_InOutExpo(float aProgress);

	float CurveFunc_InCirc(float aProgress);
	float CurveFunc_OutCirc(float aProgress);
	float CurveFunc_InOutCirc(float aProgress);
}

///----------------------------------------------------------------------------------------------------
/// ImGui Namespace
///----------------------------------------------------------------------------------------------------
namespace ImGui
{
	///----------------------------------------------------------------------------------------------------
	/// Animate:
	///     Animates a value.
	///     - aStartValue: Is the initial value.
	///     - aEndValue: Is the final value.
	///     - aDurationMs: Is the duration in milliseconds.
	///     - aValue: Is the out/current value.
	///     - aCurve: Is of type ImAnimate::ECurve and is the easing curve used for this animation.
	///----------------------------------------------------------------------------------------------------
	void Animate(float aStartValue, float aEndValue, double aDurationMs, float* aValue, ImAnimate::ECurve aCurve = ImAnimate::ECurve::Linear);
}

#endif
