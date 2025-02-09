/*
 * Copyright 2011-2025 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#ifndef NANOVG_BGFX_H_HEADER_GUARD
#define NANOVG_BGFX_H_HEADER_GUARD

#include <bgfx/bgfx.h>

namespace bx { struct AllocatorI; }

struct NVGcontext;

struct NVGLUframebuffer
{
  NVGcontext* ctx;
  bgfx::FrameBufferHandle handle;
  int image;
  bgfx::ViewId viewId;
};

// These are additional flags on top of NVGimageFlags.
enum NVGimageFlagsGL {
	NVG_IMAGE_NODELETE = 1<<16, // Do not delete GL texture handle.
};

///
NVGcontext* nvgCreate(int32_t _edgeaa, bgfx::ViewId _viewId, bx::AllocatorI* _allocator);

///
NVGcontext* nvgCreate(int32_t _edgeaa, bgfx::ViewId _viewId);

///
void nvgDelete(NVGcontext* _ctx);

///
void nvgSetViewId(NVGcontext* _ctx, bgfx::ViewId _viewId);

///
uint16_t nvgGetViewId(struct NVGcontext* _ctx);

// Helper functions to create bgfx framebuffer to render to.
// Example:
//		float scale = 2;
//		NVGLUframebuffer* fb = nvgluCreateFramebuffer(ctx, 100 * scale, 100 * scale, 0);
//		nvgluSetViewFramebuffer(VIEW_ID, fb);
//		nvgluBindFramebuffer(fb);
//		nvgBeginFrame(ctx, 100, 100, scale);
//		// renders anything offscreen
//		nvgEndFrame(ctx);
//		nvgluBindFramebuffer(NULL);
//
//		// Pastes the framebuffer rendering.
//		nvgBeginFrame(ctx, 1024, 768, scale);
//		NVGpaint paint = nvgImagePattern(ctx, 0, 0, 100, 100, 0, fb->image, 1);
//		nvgBeginPath(ctx);
//		nvgRect(ctx, 0, 0, 100, 100);
//		nvgFillPaint(ctx, paint);
//		nvgFill(ctx);
//		nvgEndFrame(ctx);

///
NVGLUframebuffer* nvgluCreateFramebuffer(NVGcontext* _ctx, int32_t _width, int32_t _height, int32_t _imageFlags, bgfx::ViewId _viewId);

///
NVGLUframebuffer* nvgluCreateFramebuffer(NVGcontext* _ctx, int32_t _width, int32_t _height, int32_t _imageFlags);

///
NVGLUframebuffer* nvgluCreateFramebuffer(NVGcontext* _ctx, int32_t _imageFlags, bgfx::ViewId _viewId);

///
NVGLUframebuffer* nvgluCreateFramebuffer(NVGcontext* _ctx, int32_t _imageFlags);

///
void nvgluBindFramebuffer(NVGLUframebuffer* _framebuffer);

///
void nvgluDeleteFramebuffer(NVGLUframebuffer* _framebuffer);

///
void nvgluSetViewFramebuffer(bgfx::ViewId _viewId, NVGLUframebuffer* _framebuffer);

///
int nvgCreateBgfxTexture(struct NVGcontext *_ctx, bgfx::TextureHandle _id, int _width, int _height, int _flags);

#endif // NANOVG_BGFX_H_HEADER_GUARD
