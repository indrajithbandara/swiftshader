// Copyright 2016 The SwiftShader Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef D3D8_Direct3DVolumeTexture8_hpp
#define D3D8_Direct3DVolumeTexture8_hpp

#include "Direct3DBaseTexture8.hpp"

#include "Config.hpp"

#include <d3d8.h>

namespace D3D8
{
	class Direct3DVolume8;

	class Direct3DVolumeTexture8 : public IDirect3DVolumeTexture8, public Direct3DBaseTexture8
	{
	public:
		Direct3DVolumeTexture8(Direct3DDevice8 *device, unsigned int width, unsigned int height, unsigned int depth, unsigned int levels, unsigned long usage, D3DFORMAT format, D3DPOOL pool);

		virtual ~Direct3DVolumeTexture8();

		// IUnknown methods
		long __stdcall QueryInterface(const IID &iid, void **object);
		unsigned long __stdcall AddRef();
		unsigned long __stdcall Release();

		// IDirect3DResource8 methods
		long __stdcall FreePrivateData(const GUID &guid);
		long __stdcall GetPrivateData(const GUID &guid, void *data, unsigned long *size);
		void __stdcall PreLoad();
		long __stdcall SetPrivateData(const GUID &guid, const void *data, unsigned long size, unsigned long flags);
		long __stdcall GetDevice(IDirect3DDevice8 **device);
		unsigned long __stdcall SetPriority(unsigned long newPriority);
		unsigned long __stdcall GetPriority();
		D3DRESOURCETYPE __stdcall GetType();

		// IDirect3DBaseTexture methods
		unsigned long __stdcall GetLevelCount();
		unsigned long __stdcall GetLOD();
		unsigned long __stdcall SetLOD(unsigned long newLOD);

		// IDirect3DVolumeTexture8 methods
		long __stdcall GetLevelDesc(unsigned int level, D3DVOLUME_DESC *description);
		long __stdcall GetVolumeLevel(unsigned int level, IDirect3DVolume8 **volume);
		long __stdcall LockBox(unsigned int level, D3DLOCKED_BOX *lockedVolume, const D3DBOX *box, unsigned long flags);
		long __stdcall UnlockBox(unsigned int level);
		long __stdcall AddDirtyBox(const D3DBOX *dirtyBox);

		// Internal methods
		Direct3DVolume8 *getInternalVolumeLevel(unsigned int level);

	private:
		// Creation parameters
		const unsigned int width;
		const unsigned int height;
		const unsigned int depth;
		const D3DFORMAT format;
		const D3DPOOL pool;

		Direct3DVolume8 *volumeLevel[sw::MIPMAP_LEVELS];
	};
}

#endif // D3D8_Direct3DVolumeTexture8_hpp