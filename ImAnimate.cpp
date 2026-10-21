///----------------------------------------------------------------------------------------------------
/// Copyright (c) Raidcore.GG - Licensed under the MIT license.
///
/// Name         :  ImAnimate.cpp
/// Description  :  Immediate mode animations.
/// Authors      :  K. Bieniek
///----------------------------------------------------------------------------------------------------

#include "ImAnimate.h"

#include <cmath>

#define PI 3.14159f

namespace ImAnimate
{
	float CurveFunc_Linear(float aProgress)
	{
		return aProgress;
	}

	float CurveFunc_InSine(float aProgress)
	{
		return 1 - cos((aProgress * PI) / 2);
	}
	float CurveFunc_OutSine(float aProgress)
	{
		return sin((aProgress * PI) / 2);
	}
	float CurveFunc_InOutSine(float aProgress)
	{
		return -(cos(PI * aProgress) - 1) / 2;
	}

	float CurveFunc_InQuad(float aProgress)
	{
		return aProgress * aProgress;
	}
	float CurveFunc_OutQuad(float aProgress)
	{
		return 1 - (1 - aProgress) * (1 - aProgress);
	}
	float CurveFunc_InOutQuad(float aProgress)
	{
		return aProgress < 0.5f ? 2 * aProgress * aProgress : 1 - powf(-2 * aProgress + 2, 2) / 2.0f;
	}

	float CurveFunc_InCubic(float aProgress)
	{
		return aProgress * aProgress * aProgress;
	}
	float CurveFunc_OutCubic(float aProgress)
	{
		return 1 - powf(1 - aProgress, 3);
	}
	float CurveFunc_InOutCubic(float aProgress)
	{
		return aProgress < 0.5f ? 4 * aProgress * aProgress * aProgress : 1 - powf(-2 * aProgress + 2, 3) / 2.0f;
	}

	float CurveFunc_InQuart(float aProgress)
	{
		return aProgress * aProgress * aProgress * aProgress;
	}
	float CurveFunc_OutQuart(float aProgress)
	{
		return 1 - powf(1 - aProgress, 4);
	}
	float CurveFunc_InOutQuart(float aProgress)
	{
		return aProgress < 0.5f ? 8 * aProgress * aProgress * aProgress * aProgress : 1 - powf(-2 * aProgress + 2, 4) / 2.0f;
	}

	float CurveFunc_InQuint(float aProgress)
	{
		return aProgress * aProgress * aProgress * aProgress * aProgress;
	}
	float CurveFunc_OutQuint(float aProgress)
	{
		return 1 - powf(1 - aProgress, 5);
	}
	float CurveFunc_InOutQuint(float aProgress)
	{
		return aProgress < 0.5f ? 16 * aProgress * aProgress * aProgress * aProgress * aProgress : 1 - powf(-2 * aProgress + 2, 5) / 2.0f;
	}

	float CurveFunc_InExpo(float aProgress)
	{
		return aProgress == 0 ? 0 : powf(2, 10 * aProgress - 10);
	}
	float CurveFunc_OutExpo(float aProgress)
	{
		return aProgress == 1 ? 1 : 1 - powf(2, -10 * aProgress);
	}
	float CurveFunc_InOutExpo(float aProgress)
	{
		return aProgress == 0 ? 0 : aProgress == 1 ? 1 : aProgress < 0.5 ? powf(2, 20 * aProgress - 10) / 2.0f : (2 - powf(2, -20 * aProgress + 10)) / 2.0f;
	}

	float CurveFunc_InCirc(float aProgress)
	{
		return 1 - sqrt(1 - powf(aProgress, 2));
	}
	float CurveFunc_OutCirc(float aProgress)
	{
		return sqrt(1 - powf(aProgress - 1, 2));
	}
	float CurveFunc_InOutCirc(float aProgress)
	{
		return aProgress < 0.5f ? (1 - sqrt(1 - powf(2 * aProgress, 2))) / 2.0f : (sqrt(1 - powf(-2 * aProgress + 2, 2)) + 1) / 2.0f;
	}

	float CurveInv_InSine(float aValue)
	{
		return acos(1 - aValue) * 2 / PI;
	}
	float CurveInv_OutSine(float aValue)
	{
		return asin(aValue) * 2 / PI;
	}
	float CurveInv_InOutSine(float aValue)
	{
		return acos(1 - 2 * aValue) / PI;
	}

	float CurveInv_InQuad(float aValue)
	{
		return sqrt(aValue);
	}
	float CurveInv_OutQuad(float aValue)
	{
		return 1 - sqrt(1 - aValue);
	}
	float CurveInv_InOutQuad(float aValue)
	{
		return aValue < 0.5f ? sqrt(aValue / 2) : 1 - sqrt(2 * (1 - aValue)) / 2.0f;
	}

	float CurveInv_InCubic(float aValue)
	{
		return cbrt(aValue);
	}
	float CurveInv_OutCubic(float aValue)
	{
		return 1 - cbrt(1 - aValue);
	}
	float CurveInv_InOutCubic(float aValue)
	{
		return aValue < 0.5f ? cbrt(aValue / 4) : 1 - cbrt(2 * (1 - aValue)) / 2.0f;
	}

	float CurveInv_InQuart(float aValue)
	{
		return powf(aValue, 1 / 4.0f);
	}
	float CurveInv_OutQuart(float aValue)
	{
		return 1 - powf(1 - aValue, 1 / 4.0f);
	}
	float CurveInv_InOutQuart(float aValue)
	{
		return aValue < 0.5f ? powf(aValue / 8, 1 / 4.0f) : 1 - powf(2 * (1 - aValue), 1 / 4.0f) / 2.0f;
	}

	float CurveInv_InQuint(float aValue)
	{
		return powf(aValue, 1 / 5.0f);
	}
	float CurveInv_OutQuint(float aValue)
	{
		return 1 - powf(1 - aValue, 1 / 5.0f);
	}
	float CurveInv_InOutQuint(float aValue)
	{
		return aValue < 0.5f ? powf(aValue / 16, 1 / 5.0f) : 1 - powf(2 * (1 - aValue), 1 / 5.0f) / 2.0f;
	}

	float CurveInv_InExpo(float aValue)
	{
		return aValue == 0 ? 0 : (log2f(aValue) + 10) / 10;
	}
	float CurveInv_OutExpo(float aValue)
	{
		return aValue == 1 ? 1 : -log2f(1 - aValue) / 10;
	}
	float CurveInv_InOutExpo(float aValue)
	{
		return aValue == 0 ? 0 : aValue == 1 ? 1 : aValue < 0.5f ? (log2f(2 * aValue) + 10) / 20 : (10 - log2f(2 - 2 * aValue)) / 20;
	}

	float CurveInv_InCirc(float aValue)
	{
		return sqrt(1 - powf(1 - aValue, 2));
	}
	float CurveInv_OutCirc(float aValue)
	{
		return 1 - sqrt(1 - powf(aValue, 2));
	}
	float CurveInv_InOutCirc(float aValue)
	{
		return aValue < 0.5f ? sqrt(1 - powf(1 - 2 * aValue, 2)) / 2.0f : 1 - sqrt(1 - powf(2 * aValue - 1, 2)) / 2.0f;
	}

	typedef float(*PFN_CURVEFUNC)(float);

	///----------------------------------------------------------------------------------------------------
	/// GetCurveFunc:
	///     Internal function to return the function correlating to the curve.
	///----------------------------------------------------------------------------------------------------
	PFN_CURVEFUNC GetCurveFunc(ECurve aCurve)
	{
		switch (aCurve)
		{
			default:
			case ImAnimate::ECurve::Linear:     return CurveFunc_Linear;

			case ImAnimate::ECurve::InSine:     return CurveFunc_InSine;
			case ImAnimate::ECurve::OutSine:    return CurveFunc_OutSine;
			case ImAnimate::ECurve::InOutSine:  return CurveFunc_InOutSine;

			case ImAnimate::ECurve::InQuad:     return CurveFunc_InQuad;
			case ImAnimate::ECurve::OutQuad:    return CurveFunc_OutQuad;
			case ImAnimate::ECurve::InOutQuad:  return CurveFunc_InOutQuad;

			case ImAnimate::ECurve::InCubic:    return CurveFunc_InCubic;
			case ImAnimate::ECurve::OutCubic:   return CurveFunc_OutCubic;
			case ImAnimate::ECurve::InOutCubic: return CurveFunc_InOutCubic;

			case ImAnimate::ECurve::InQuart:    return CurveFunc_InQuart;
			case ImAnimate::ECurve::OutQuart:   return CurveFunc_OutQuart;
			case ImAnimate::ECurve::InOutQuart: return CurveFunc_InOutQuart;

			case ImAnimate::ECurve::InQuint:    return CurveFunc_InQuint;
			case ImAnimate::ECurve::OutQuint:   return CurveFunc_OutQuint;
			case ImAnimate::ECurve::InOutQuint: return CurveFunc_InOutQuint;

			case ImAnimate::ECurve::InExpo:     return CurveFunc_InExpo;
			case ImAnimate::ECurve::OutExpo:    return CurveFunc_OutExpo;
			case ImAnimate::ECurve::InOutExpo:  return CurveFunc_InOutExpo;

			case ImAnimate::ECurve::InCirc:     return CurveFunc_InCirc;
			case ImAnimate::ECurve::OutCirc:    return CurveFunc_OutCirc;
			case ImAnimate::ECurve::InOutCirc:  return CurveFunc_InOutCirc;
		}
	}

	///----------------------------------------------------------------------------------------------------
	/// GetCurveInvFunc:
	///     Internal function to return the inverse of the function correlating to the curve.
	///----------------------------------------------------------------------------------------------------
	PFN_CURVEFUNC GetCurveInvFunc(ECurve aCurve)
	{
		switch (aCurve)
		{
			default:
			case ImAnimate::ECurve::Linear:     return CurveFunc_Linear;

			case ImAnimate::ECurve::InSine:     return CurveInv_InSine;
			case ImAnimate::ECurve::OutSine:    return CurveInv_OutSine;
			case ImAnimate::ECurve::InOutSine:  return CurveInv_InOutSine;

			case ImAnimate::ECurve::InQuad:     return CurveInv_InQuad;
			case ImAnimate::ECurve::OutQuad:    return CurveInv_OutQuad;
			case ImAnimate::ECurve::InOutQuad:  return CurveInv_InOutQuad;

			case ImAnimate::ECurve::InCubic:    return CurveInv_InCubic;
			case ImAnimate::ECurve::OutCubic:   return CurveInv_OutCubic;
			case ImAnimate::ECurve::InOutCubic: return CurveInv_InOutCubic;

			case ImAnimate::ECurve::InQuart:    return CurveInv_InQuart;
			case ImAnimate::ECurve::OutQuart:   return CurveInv_OutQuart;
			case ImAnimate::ECurve::InOutQuart: return CurveInv_InOutQuart;

			case ImAnimate::ECurve::InQuint:    return CurveInv_InQuint;
			case ImAnimate::ECurve::OutQuint:   return CurveInv_OutQuint;
			case ImAnimate::ECurve::InOutQuint: return CurveInv_InOutQuint;

			case ImAnimate::ECurve::InExpo:     return CurveInv_InExpo;
			case ImAnimate::ECurve::OutExpo:    return CurveInv_OutExpo;
			case ImAnimate::ECurve::InOutExpo:  return CurveInv_InOutExpo;

			case ImAnimate::ECurve::InCirc:     return CurveInv_InCirc;
			case ImAnimate::ECurve::OutCirc:    return CurveInv_OutCirc;
			case ImAnimate::ECurve::InOutCirc:  return CurveInv_InOutCirc;
		}
	}

	///----------------------------------------------------------------------------------------------------
	/// Clamp01:
	///     Internal function to ensure a value is within 0 and 1.
	///----------------------------------------------------------------------------------------------------
	float Clamp01(float aValue)
	{
		if (aValue < 0.0f) { return 0.0f; }
		if (aValue > 1.0f) { return 1.0f; }
		return aValue;
	}
}

namespace ImGui
{
	void Animate(float aStartValue, float aEndValue, float aDurationMs, float* aValue, ImAnimate::ECurve aCurve)
	{
		if (aStartValue == aEndValue || aDurationMs <= 0)
		{
			*aValue = aEndValue;
			return;
		}

		float range = aEndValue - aStartValue;

		/* The current value is the only state: recover the time progress that produces it. */
		float progress = ImAnimate::Clamp01(ImAnimate::GetCurveInvFunc(aCurve)(ImAnimate::Clamp01((*aValue - aStartValue) / range)));
		float step = ImGui::GetIO().DeltaTime * 1000.0f / aDurationMs;

		progress += step;

		if (progress >= 1.0f)
		{
			*aValue = aEndValue;
			return;
		}

		float result = aStartValue + ImAnimate::GetCurveFunc(aCurve)(progress) * range;

		/* On flat curve sections a frame's step can be below float precision and would never advance. */
		if (result == *aValue && step > 0.0f)
		{
			result = nextafterf(*aValue, aEndValue);
		}

		*aValue = result;
	}
}
