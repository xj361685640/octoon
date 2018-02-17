#ifndef OCTOON_ISTREAM_H_
#define OCTOON_ISTREAM_H_


#include <octoon/runtime/platform.h>

#include <octoon/runtime/io/stream.h>

namespace octoon
{
    namespace runtime
    {
        namespace io
        {
            class OCTOON_EXPORT StreamReader : public virtual StreamBase
            {
            public:
                StreamReader(StreamBuf* buf) noexcept;
                virtual ~StreamReader() noexcept;

                StreamReader& read(char* str, std::streamsize cnt) noexcept;
                StreamReader& read(char* str, streamsize size, streamsize cnt) noexcept;

                StreamReader& seekg(ios_base::off_type pos) noexcept;
                StreamReader& seekg(ios_base::off_type pos, ios_base::seekdir dir) noexcept;

                StreamReader& flush() noexcept;

                streamsize size() noexcept;

                streamoff tellg() noexcept;

                streamsize gcount() const noexcept;

            protected:
                class isentry final
                {
                public:
                    isentry(StreamReader* _istr);
                    ~isentry() noexcept;

                    operator bool() const noexcept;

                private:
                    isentry(const isentry&) noexcept = delete;
                    const isentry& operator=(const isentry&) noexcept = delete;

                private:
                    bool _ok;
                    StreamReader* _my_istr;
                };

            private:
                StreamReader& operator=(const StreamReader&) = delete;
                StreamReader(const StreamReader&) = delete;

            private:

                streamsize _count;
            };
        }
    }
}

#endif // OCTOON_ISTREAM_H_