#include "tpch.h"
#include "OrthographicCamera.h"

namespace Toast {

	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
		: mProjectionMatrix(DirectX::XMMatrixOrthographicLH((right - left), (bottom - top), -1.0f, 1.0f)), mViewMatrix(DirectX::XMMatrixIdentity())
	{
		mViewProjectionMatrix = DirectX::XMMatrixMultiply(mViewMatrix, mProjectionMatrix);
	}

	void OrthographicCamera::RecalculateViewMatrix()
	{
		DirectX::XMMATRIX translation = DirectX::XMMatrixTranslation(mPosition.x, mPosition.y, mPosition.z);

		DirectX::XMMATRIX transform = DirectX::XMMatrixMultiply(DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(mRotation)), DirectX::XMMatrixTranslation(mPosition.x, mPosition.y, mPosition.z));

		mViewMatrix = DirectX::XMMatrixInverse(nullptr, transform);
		mViewProjectionMatrix = DirectX::XMMatrixMultiply(mViewMatrix, mProjectionMatrix);
	}
}