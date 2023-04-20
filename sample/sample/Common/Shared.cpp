#include "Shared.h"
#include <DxLib.h>
#include "../SceneManager.h"
#include "../Common/Debug.h"
#include "ResourceManager.h"


SharedHandle::SharedHandle(const int handle)
{
}

SharedHandle::SharedHandle(SharedHandle&& sharedHandle) noexcept
{
}

SharedHandle::SharedHandle(const SharedHandle& sharedHandle) noexcept
{
}

SharedHandle::~SharedHandle() noexcept
{
}

SharedHandle& SharedHandle::operator=(SharedHandle&& sharedHandle) noexcept
{
	// TODO: return ステートメントをここに挿入します
}

const int SharedHandle::operator*(void) const noexcept
{
	return 0;
}

void SharedHandle::SetPtr(std::shared_ptr<int>& ptr)
{
}

//SharedRenderTargetHandle::SharedRenderTargetHandle(const int handle, const ScreenID id):
//	SharedHandle{ handle },id_{id}
//{
//}

SharedRenderTargetHandle::SharedRenderTargetHandle(const SharedRenderTargetHandle& sharedHandle) noexcept
{
}

SharedRenderTargetHandle::~SharedRenderTargetHandle()
{
}

SharedRenderTargetHandle& SharedRenderTargetHandle::operator=(const SharedRenderTargetHandle& sharedHandle) noexcept
{
	// TODO: return ステートメントをここに挿入します
}

void SharedRenderTargetHandle::SetHandle(const int handle)
{
}

void SharedRenderTargetHandle::CopyParent(void)
{
}

SharedFontHandle::SharedFontHandle(const int handle)
{
}

SharedFontHandle::SharedFontHandle(const SharedFontHandle& sharedHandle) noexcept:
	SharedHandle{sharedHandle}
{
}

SharedFontHandle::~SharedFontHandle()
{
	if (ptr_ && ptr_.use_count() <= 1)
	{
		DeleteFontToHandle(*ptr_);
		ptr_.reset();
	}
}

SharedFontHandle& SharedFontHandle::operator=(const SharedFontHandle& sharedHandle) noexcept
{
	if (ptr_ && ptr_.use_count() <= 1)
	{
		DeleteFontToHandle(*ptr_);
	}
	else
	{
		ptr_ = std::make_shared<int>();
	}
	ptr_ = sharedHandle.ptr_;
	return *this;
}

SharedShaderHandle::SharedShaderHandle(const int handle):
	SharedHandle{ handle }
{
}

SharedShaderHandle::SharedShaderHandle(const SharedShaderHandle& sharedHandle) noexcept:
	SharedHandle{sharedHandle}

{
}

SharedShaderHandle::~SharedShaderHandle()
{
}

SharedShaderHandle& SharedShaderHandle::operator=(const SharedShaderHandle& sharedHandle) noexcept
{
	// TODO: return ステートメントをここに挿入します
}

SharedModelHandle::~SharedModelHandle()
{
}

SharedModelHandle& SharedModelHandle::operator=(const SharedModelHandle& sharedHandle) noexcept
{
	// TODO: return ステートメントをここに挿入します
}

void SharedModelHandle::CopyParent(void)
{
}

void SharedModelHandle::SetHandle(const int handle)
{
}

void SharedModelHandle::SetParent(std::shared_ptr<int>& parent)
{
}

const int SharedModelHandle::operator*(void) const noexcept
{
	return 0;
}

SharedDivGraphicHandle::SharedDivGraphicHandle(const int handle)
{
}

SharedDivGraphicHandle::SharedDivGraphicHandle(const SharedDivGraphicHandle& sheardHandle) noexcept
{
}

SharedDivGraphicHandle::~SharedDivGraphicHandle()
{
}

SharedDivGraphicHandle& SharedDivGraphicHandle::operator=(const SharedDivGraphicHandle& heardHandle) noexcept
{
	// TODO: return ステートメントをここに挿入します
}

const int SharedDivGraphicHandle::operator[](size_t idx) const
{
	return 0;
}

void SharedDivGraphicHandle::Set(const std::span<int> handles)
{
}

SharedGraphicHandle::SharedGraphicHandle(const int handle)
{
}

SharedGraphicHandle::SharedGraphicHandle(const SharedGraphicHandle& sheardHandle) noexcept
{
}

SharedGraphicHandle::~SharedGraphicHandle()
{
}

SharedGraphicHandle& SharedGraphicHandle::operator=(const SharedGraphicHandle& heardHandle) noexcept
{
	// TODO: return ステートメントをここに挿入します
}

