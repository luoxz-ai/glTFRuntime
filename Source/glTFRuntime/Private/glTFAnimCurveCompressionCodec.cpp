// Copyright 2022, Roberto De Ioris.


#include "glTFAnimCurveCompressionCodec.h"

void UglTFAnimCurveCompressionCodec::DecompressCurves(const FCompressedAnimSequence& AnimSeq, FBlendedCurve& Curves, float CurrentTime) const
{
	if (!AnimSequence)
	{
		return;
	}
#if !WITH_EDITOR
	AnimSequence->GetCurveData().EvaluateCurveData(Curves, CurrentTime);
#endif
}

float UglTFAnimCurveCompressionCodec::DecompressCurve(const FCompressedAnimSequence& AnimSeq, SmartName::UID_Type CurveUID, float CurrentTime) const
{
	if (!AnimSequence)
	{
		return 0.0f;
	}
#if !WITH_EDITOR
	return reinterpret_cast<const FFloatCurve*>(AnimSequence->GetCurveData().GetCurveData(CurveUID))->Evaluate(CurrentTime);
#else
	return 0.0f;
#endif
}