#ifndef OCTOON_STREAM_BUF_H_
#define OCTOON_STREAM_BUF_H_


#include <octoon/runtime/platform.h>

#include <octoon/runtime/io/iosbase.h>

namespace octoon
{
    namespace runtime
    {
        namespace io
        {
            class OCTOON_EXPORT StreamBuf
            {
            public:
                StreamBuf() noexcept;
                virtual ~StreamBuf() noexcept;

                virtual streamsize read(char* str, std::streamsize cnt) noexcept = 0;
                virtual streamsize write(const char* str, std::streamsize cnt) noexcept = 0;

                virtual streamoff seekg(ios_base::off_type pos, ios_base::seekdir dir) noexcept = 0;
                virtual streamoff tellg() noexcept = 0;

                virtual streamsize size() const noexcept = 0;

                virtual bool is_open() const noexcept = 0;

                virtual int flush() noexcept = 0;

                virtual void lock() noexcept;
                virtual void unlock() noexcept;
            };
        }
    }
}

#endif // OCTOON_STREAM_BUF_H_