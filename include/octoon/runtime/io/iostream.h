#ifndef OCTOON_ISTREAM_H_
#define OCTOON_ISTREAM_H_


#include <octoon/runtime/platform.h>

#include <octoon/runtime/io/istream.h>

namespace octoon
{
    namespace runtime
    {
        namespace io
        {
            class OCTOON_EXPORT Stream : public StreamReader, public StreamWrite
            {
            public:
                Stream(StreamBuf* buf) noexcept;
                virtual ~Stream() noexcept;

                Stream& read(char* str, std::streamsize cnt) noexcept;
                Stream& read(char* str, streamsize size, streamsize cnt) noexcept;

                Stream& write(const char* str, std::streamsize cnt) noexcept;
                Stream& write(const char* str, streamsize size, streamsize cnt) noexcept;

                Stream& seekg(ios_base::off_type pos) noexcept;
                Stream& seekg(ios_base::off_type pos, ios_base::seekdir dir) noexcept;

                Stream& flush() noexcept;

                streamsize size() noexcept;

                streamsize gcount() const noexcept;

                streampos tellg() noexcept;

            protected:
                class iosentry final
                {
                public:
                    iosentry(Stream* _istr);
                    ~iosentry() noexcept;

                    operator bool() const noexcept;

                private:
                    iosentry(const iosentry&) = delete;
                    const iosentry& operator=(const iosentry&) = delete;

                private:
                    bool _ok;
                    Stream* _myIostr;
                };

            private:
                Stream& operator=(const Stream&) noexcept = delete;
                Stream(const Stream&) noexcept = delete;

            private:

                streamsize _count;
            };
        }
    }
}

#endif // OCTOON_ISTREAM_H_