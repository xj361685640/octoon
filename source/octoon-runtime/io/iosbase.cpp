#include <octoon/runtime/io/stream.h>

namespace octoon
{
    namespace runtime
    {
        namespace io
        {
            ios_base::ios_base() noexcept
            {
            }

            ios_base::~ios_base() noexcept
            {
            }

            ios_base::operator bool() const noexcept
            {
                return this->good();
            }

            bool
            ios_base::operator!() const noexcept
            {
                return this->fail();
            }

            bool
            ios_base::good() const noexcept
            {
                return (this->rdstate() == (ios_base::iostate)ios_base::goodbit);
            }

            bool
            ios_base::eof() const noexcept
            {
                return ((this->rdstate() & (ios_base::iostate)(ios_base::eofbit)) != 0);
            }

            bool
            ios_base::fail() const noexcept
            {
                return ((this->rdstate() & (ios_base::iostate)(ios_base::badbit | ios_base::failbit)) != 0);
            }

            bool
            ios_base::bad() const noexcept
            {
                return (this->rdstate() == (ios_base::iostate)ios_base::badbit);
            }

            ios_base::iostate
            ios_base::exceptions() const noexcept
            {
                return _my_except;
            }

            ios_base::iostate
            ios_base::rdstate() const noexcept
            {
                return _my_state;
            }

            ios_base::fmtflags
            ios_base::flags() const noexcept
            {
                return _fmtfl;
            }

            void
            ios_base::clear(ios_base::io_state _state)
            {
                this->clear((ios_base::iostate)_state);
            }

            void
            ios_base::clear(ios_base::iostate _state)
            {
                this->clear(_state, false);
            }

            void
            ios_base::clear(ios_base::iostate _state, bool _reraise)
            {
                _my_state = (ios_base::iostate)(_state & ios_base::_Statmask);
                if ((_my_state & _my_except) == 0)
                    return;
                else if (_reraise)
                    throw;
                else if (_my_state & _my_except & ios_base::badbit)
                    throw failure(__TEXT("ios_base::badbit set"));
                else if (_my_state & _my_except & ios_base::failbit)
                    throw failure(__TEXT("ios_base::failbit set"));
                else
                    throw failure(__TEXT("ios_base::eofbit set"));
            }

            void
            ios_base::setstate(ios_base::iostate _state) noexcept
            {
                this->setstate(_state, false);
            }

            void
            ios_base::setstate(ios_base::io_state _state) noexcept
            {
                this->setstate((ios_base::iostate)_state);
            }

            void
            ios_base::setstate(ios_base::iostate _state, bool _exreraise) noexcept
            {
                if (_state != ios_base::goodbit)
                    this->clear((ios_base::iostate)((int)this->rdstate() | (int)_state), _exreraise);
                else
                    this->clear(ios_base::goodbit);
            }

            void
            ios_base::exceptions(ios_base::iostate _new) noexcept
            {
                _my_except = (ios_base::iostate)((int)(_new)& (int)ios_base::_Statmask);
                this->clear(_my_state);
            }

            void
            ios_base::_init() noexcept
            {
                _fmtfl = (ios_base::fmtflags)(ios_base::skipws | ios_base::dec);
                _my_except = ios_base::goodbit;
                this->clear(ios_base::goodbit);
            }

        }
    }
}