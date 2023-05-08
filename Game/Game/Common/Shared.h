#pragma once
#include <map>
#include <memory>
#include <functional>
#include <span>
#include "Math.h"
#include "ScreenID.h"

// Dxlib�̃n���h�������[�N�������L����N���X
class SharedHandle
{
public:
	SharedHandle() {}

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="handle"></param>
	SharedHandle(const int handle);
	
	/// <summary>
	/// ���[�u�R���X�g���N�^
	/// </summary>
	/// <param name="sharedHandle"></param>
	/// <returns></returns>
	SharedHandle(SharedHandle&& sharedHandle) noexcept;
	
	/// <summary>
	/// �R�s�[�R���X�g���N�^
	/// </summary>
	/// <param name="sharedHandle"></param>
	/// <returns></returns>
	SharedHandle(const SharedHandle& sharedHandle) noexcept;

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	/// <returns></returns>
	virtual ~SharedHandle() noexcept;

	SharedHandle& operator=(SharedHandle&& sharedHandle) noexcept;

	/// <summary>
	/// �n���h���擾�̂���
	/// </summary>
	/// <param name="ptr"></param>
	virtual const int operator*(void) const noexcept;
	
	void SetPtr(std::shared_ptr<int>& ptr);

protected:

	// �n���h���Ǘ��p
	std::shared_ptr<int> ptr_;
};

// �O���t�B�b�N�p
class SharedGraphicHandle :
	public SharedHandle
{
public:
	SharedGraphicHandle() {}
	explicit SharedGraphicHandle(const int handle);
	SharedGraphicHandle(const SharedGraphicHandle& sharedHandle) noexcept;
	~SharedGraphicHandle();
	SharedGraphicHandle& operator=(const SharedGraphicHandle& sharedHandle) noexcept;
};

// �����O���t�B�b�N�p
class SharedDivGraphicHandle :
	public SharedHandle
{
public:
	SharedDivGraphicHandle() {}
	explicit SharedDivGraphicHandle(const int handle);
	SharedDivGraphicHandle(const SharedDivGraphicHandle& sharedHandle) noexcept;
	~SharedDivGraphicHandle();
	SharedDivGraphicHandle& operator=(const SharedDivGraphicHandle& sharedHandle) noexcept;

	/// <summary>
	/// �w��̒��̃n���h���ɃA�N�Z�X����
	/// </summary>
	/// <param name="idx"></param>
	/// <returns></returns>
	const int operator[](size_t idx) const;

	/// <summary>
	/// �Q�Ƃ���span���Z�b�g����
	/// </summary>
	/// <param name="handles"></param>
	void Set(const std::span<int> handles);
private:
	// span�ŎQ�Ƃł���悤�Ɏ���
	std::span<int> handles_;
};

// �X�N���[���p
class SharedRenderTargetHandle :
	public SharedHandle
{
public:
	SharedRenderTargetHandle() : id_{} {}
	explicit SharedRenderTargetHandle(const int handle, const ScreenID id);
	SharedRenderTargetHandle(const SharedRenderTargetHandle& sharedHandle)noexcept;
	~SharedRenderTargetHandle();
	SharedRenderTargetHandle& operator=(const SharedRenderTargetHandle& sharedHandle)noexcept;
	void SetScreenID(ScreenID id) { id_ = id; }
private:
	ScreenID id_;
};

// ���f���p
class SharedModelHandle :
	public SharedHandle
{
public:
	SharedModelHandle() {}
	~SharedModelHandle();
	SharedModelHandle& operator=(const SharedModelHandle& sharedHandle)noexcept;
	
	void CopyParent(void);
	void SetHandle(const int handle);
	void SetParent(std::shared_ptr<int>& parent);
	const int operator*(void) const noexcept final;
private:
	int handle_{ -1 };

};

// �V�F�[�_�[�p
class SharedShaderHandle :
	public SharedHandle
{
public:
	SharedShaderHandle(){}
	explicit SharedShaderHandle(const int handle);
	SharedShaderHandle(const SharedShaderHandle& sharedHandle)noexcept;
	~SharedShaderHandle();
	SharedShaderHandle& operator=(const SharedShaderHandle& sharedHandle)noexcept;
};

// �t�H���g�p
class SharedFontHandle :
	public SharedHandle
{
public:
	SharedFontHandle() {}
	SharedFontHandle(const int handle);
	SharedFontHandle(const SharedFontHandle& sharedHandle)noexcept;
	~SharedFontHandle();
	SharedFontHandle& operator=(const SharedFontHandle& sharedHandle)noexcept;
};

// �T�E���h�p
class SharedSoundHandle :
	public SharedHandle
{
public:
	SharedSoundHandle(){}
	~SharedSoundHandle();
	SharedSoundHandle& operator=(const SharedSoundHandle& sharedHandle)noexcept;
	void SetHandle(const int handle);
	void CopyParent(void);
	int handle_{ -1 };
};
