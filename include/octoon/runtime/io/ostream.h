#ifndef OCTOON_OSTREAM_H_
#define OCTOON_OSTREAM_H_


#include <octoon/runtime/platform.h>

#include <octoon/runtime/io/stream.h>

namespace octoon
{
    namespace runtime
    {
        namespace io
        {
            class OCTOON_EXPORT StreamWrite : public virtual StreamBase
            {
            public:
                StreamWrite(StreamBuf* buf) noexcept;
                virtual ~StreamWrite() noexcept;

                StreamWrite& write(const char* str, std::streamsize cnt) noexcept;
                StreamWrite& write(const char* str, streamsize size, streamsize cnt) noexcept;

                StreamWrite& seekg(ios_base::off_type pos) noexcept;
                StreamWrite& seekg(ios_base::off_type pos, ios_base::seekdir dir) noexcept;

                StreamWrite& flush() noexcept;

                streamsize gcount() const noexcept;

                ios_base::pos_type tellg() noexcept;

                StreamWrite& operator << (const char* str) noexcept;
                StreamWrite& operator << (const std::string& str) noexcept;
                StreamWrite& operator << (char value) noexcept;
                StreamWrite& operator << (short value) noexcept;
                StreamWrite& operator << (int value) noexcept;
                StreamWrite& operator << (long long value) noexcept;
                StreamWrite& operator << (unsigned char value) noexcept;
                StreamWrite& operator << (unsigned short value) noexcept;
                StreamWrite& operator << (unsigned int value) noexcept;
                StreamWrite& operator << (unsigned long value) noexcept;
                StreamWrite& operator << (unsigned long long value) noexcept;
                StreamWrite& operator << (float value) noexcept;
                StreamWrite& operator << (double value) noexcept;
                StreamWrite& operator << (ios_base& (*function)(ios_base&)) noexcept;
                StreamWrite& operator << (StreamWrite& (*function)(StreamWrite&)) noexcept;

            protected:
                class osentry
                {
                public:
                    osentry(StreamWrite* _ostr);
                    ~osentry() noexcept;
                    operator bool() const noexcept;

                private:
                    osentry(const osentry&) noexcept = delete;
                    const osentry& operator=(const osentry&) noexcept = delete;

                private:
                    bool _ok;
                    StreamWrite* _my_ostr;
                };

            private:
                StreamWrite& operator=(const StreamWrite&) = delete;
                StreamWrite(const StreamWrite&) = delete;

            private:

                streamsize _count;
            };
        }
    }
}

#endif // OCTOON_OSTREAM_H_