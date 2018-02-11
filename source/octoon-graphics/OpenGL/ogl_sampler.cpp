#include "ogl_sampler.h"
#include "ogl_device.h"

namespace octoon
{
	namespace graphics
	{
		OctoonImplementSubClass(OGLSampler, GraphicsSampler, "OGLSampler")

		OGLSampler::OGLSampler() noexcept
			: _sampler(GL_NONE)
		{
		}

		OGLSampler::~OGLSampler() noexcept
		{
			this->close();
		}

		bool
		OGLSampler::setup(const GraphicsSamplerDesc& samplerDesc) except
		{
			assert(_sampler == GL_NONE);

			glGenSamplers(1, &_sampler);
			if (_sampler == GL_NONE)
			{
				this->getDevice()->downcast<OGLDevice>()->message("glGenSamplers() fail");
				return false;
			}

			GraphicsSamplerWrap wrap = samplerDesc.getSamplerWrap();
			if (GraphicsSamplerWrap::GraphicsSamplerWrapRepeat == wrap)
			{
				glSamplerParameteri(_sampler, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glSamplerParameteri(_sampler, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glSamplerParameteri(_sampler, GL_TEXTURE_WRAP_R, GL_REPEAT);
			}
			else if (GraphicsSamplerWrap::GraphicsSamplerWrapClampToEdge == wrap)
			{
				glSamplerParameteri(_sampler, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				glSamplerParameteri(_sampler, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
				glSamplerParameteri(_sampler, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
			}
			else if (GraphicsSamplerWrap::GraphicsSamplerWrapMirror == wrap)
			{
				glSamplerParameteri(_sampler, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
				glSamplerParameteri(_sampler, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
				glSamplerParameteri(_sampler, GL_TEXTURE_WRAP_R, GL_MIRRORED_REPEAT);
			}
			else
			{
				this->getDevice()->downcast<OGLDevice>()->message("Invalid SamplerWrap");
				return false;
			}

			GraphicsSamplerFilter filter = samplerDesc.getSamplerFilter();
			if (filter == GraphicsSamplerFilter::GraphicsSamplerFilterNearest)
			{
				glSamplerParameteri(_sampler, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glSamplerParameteri(_sampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			}
			else if (filter == GraphicsSamplerFilter::GraphicsSamplerFilterLinear)
			{
				glSamplerParameteri(_sampler, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glSamplerParameteri(_sampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			}
			else if (filter == GraphicsSamplerFilter::GraphicsSamplerFilterNearestMipmapLinear)
			{
				glSamplerParameteri(_sampler, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glSamplerParameteri(_sampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
			}
			else if (filter == GraphicsSamplerFilter::GraphicsSamplerFilterNearestMipmapNearest)
			{
				glSamplerParameteri(_sampler, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glSamplerParameteri(_sampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
			}
			else if (filter == GraphicsSamplerFilter::GraphicsSamplerFilterLinearMipmapNearest)
			{
				glSamplerParameteri(_sampler, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glSamplerParameteri(_sampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
			}
			else if (filter == GraphicsSamplerFilter::GraphicsSamplerFilterLinearMipmapLinear)
			{
				glSamplerParameteri(_sampler, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glSamplerParameteri(_sampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			}
			else
			{
				this->getDevice()->downcast<OGLDevice>()->message("Invalid SamplerFilter");
				return false;
			}

			if (GLEW_EXT_texture_filter_anisotropic)
			{
				GraphicsSamplerAnis anis = samplerDesc.getSamplerAnis();

				if (anis == GraphicsSamplerAnis::GraphicsSamplerAnis1)
					glSamplerParameteri(_sampler, GL_TEXTURE_MAX_ANISOTROPY_EXT, 1);
				else if (anis == GraphicsSamplerAnis::GraphicsSamplerAnis2)
					glSamplerParameteri(_sampler, GL_TEXTURE_MAX_ANISOTROPY_EXT, 2);
				else if (anis == GraphicsSamplerAnis::GraphicsSamplerAnis4)
					glSamplerParameteri(_sampler, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4);
				else if (anis == GraphicsSamplerAnis::GraphicsSamplerAnis8)
					glSamplerParameteri(_sampler, GL_TEXTURE_MAX_ANISOTROPY_EXT, 8);
				else if (anis == GraphicsSamplerAnis::GraphicsSamplerAnis16)
					glSamplerParameteri(_sampler, GL_TEXTURE_MAX_ANISOTROPY_EXT, 16);
				else if (anis != GraphicsSamplerAnis::GraphicsSamplerAnis0)
				{
					this->getDevice()->downcast<OGLDevice>()->message("Invalid SamplerAnis");
					return false;
				}
			}

			_sampleDesc = samplerDesc;
			return true;
		}

		void
		OGLSampler::close() noexcept
		{
			if (_sampler)
			{
				glDeleteSamplers(1, &_sampler);
				_sampler = 0;
			}
		}

		GLuint
		OGLSampler::getInstanceID() noexcept
		{
			return _sampler;
		}

		const GraphicsSamplerDesc&
		OGLSampler::getGraphicsSamplerDesc() const noexcept
		{
			return _sampleDesc;
		}

		void
		OGLSampler::setDevice(const GraphicsDevicePtr& device) noexcept
		{
			_device = device;
		}

		GraphicsDevicePtr
		OGLSampler::getDevice() noexcept
		{
			return _device.lock();
		}
	}
}