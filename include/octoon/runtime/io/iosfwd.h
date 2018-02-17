#ifndef OCTOON_IOSFWD_H_
#define OCTOON_IOSFWD_H_

#include <iosfwd>
#include <ios>
#include <cstdio>

#include <octoon/runtime/platform.h>


namespace octoon
{
    namespace runtime
    {
        namespace io
        {
            typedef std::shared_ptr<class Stream> StreamPtr;
            typedef std::shared_ptr<class StreamReader> StreamReaderPtr;
            typedef std::shared_ptr<class StreamWrite> StreamWritePtr;

            typedef std::shared_ptr<class Package> PackagePtr;
            typedef std::shared_ptr<class IoListener> IoListenerPtr;
        }
    }
}

#endif // OCTOON_IOSFWD_H_