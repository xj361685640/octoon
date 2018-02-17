#ifndef OCTOON_STREAM_BASE_H_
#define OCTOON_STREAM_BASE_H_


#include <octoon/runtime/platform.h>

#include <octoon/runtime/io/streambuf.h>

namespace octoon
{
    namespace runtime
    {
        namespace io
        {
            class OCTOON_EXPORT StreamBase : public ios_base
            {
            public:
                StreamBase() noexcept;
                virtual ~StreamBase() noexcept;

                void setOpenMode(ios_base::openmode mode) noexcept;
                ios_base::openmode getOpenMode() const noexcept;

                StreamBuf* rdbuf() const noexcept;
                void set_rdbuf(StreamBuf* buf) noexcept;

            protected:
                void _init(StreamBuf* _buf, ios_base::openmode mode) noexcept;

            private:
                StreamBase& operator=(const StreamBase&) = delete;
                StreamBase(const StreamBase&) = delete;

            private:
                StreamBuf* _strbuf;
                ios_base::openmode _mode;
            };
        }
    }
}

#endif // OCTOON_STREAM_BASE_H_