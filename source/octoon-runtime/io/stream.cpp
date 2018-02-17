#include <octoon/runtime/io/stream.h>

namespace octoon
{
    namespace runtime
    {
        namespace io
        {
            StreamBase::StreamBase() noexcept
            {
            }

            StreamBase::~StreamBase() noexcept
            {
            }

            StreamBuf* StreamBase::rdbuf() const noexcept
            {
                return _strbuf;
            }

            void StreamBase::set_rdbuf(StreamBuf* buf) noexcept
            {
                _strbuf = buf;
            }

            void  StreamBase::_init(StreamBuf* _buf, ios_base::openmode mode) noexcept
            {
                this->set_rdbuf(_buf);
                _mode = mode;
                ios_base::_init();
            }

            void StreamBase::setOpenMode(ios_base::openmode mode) noexcept
            {
                _mode = mode;
            }

            ios_base::openmode StreamBase::getOpenMode() const noexcept
            {
                return _mode;
            }
        }
    }
}