/*
*  Copyright (c) 2014, Facebook, Inc.
*  All rights reserved.
*
*  This source code is licensed under the BSD-style license found in the
*  LICENSE file in the root directory of this source tree. An additional grant
*  of patent rights can be found in the PATENTS file in the same directory.
*
*/

#pragma once

#include "IGraphicsDeviceCapture.h"
#include "Core/Common/ScopedCOMPtr.h"
#include "TextureRender.h"

using namespace FBCapture::Render;

namespace FBCapture {
  namespace Common {
    class GraphicsDeviceCaptureD3D11 : public IGraphicsDeviceCapture {
    public:
      GraphicsDeviceCaptureD3D11(ID3D11Device* device) : pDevice_(device) {};
      FBCAPTURE_STATUS captureTextureToSharedHandle(void* fromTexturePtr) override;
      FBCAPTURE_STATUS copyTexture(void* toTexturePtr, HANDLE fromOtherDeviceSharedHandle) override;
      HANDLE getSharedHandle() override { return pSharedHandle_; }
    private:
      FBCAPTURE_STATUS updateSharedHandle(int width, int height, DXGI_FORMAT format);
      ScopedCOMPtr<ID3D11Texture2D> pTexture_;
      ID3D11Device* pDevice_ = {};
      HANDLE pSharedHandle_ = {};
    };
  }
}
