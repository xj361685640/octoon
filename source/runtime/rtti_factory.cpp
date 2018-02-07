#include <octoon/runtime/rtti_factory.h>

namespace octoon
{
	namespace runtime
	{
		namespace rtti
		{
			bool
				Factory::open() noexcept
			{
				for (auto& it : _rttis)
				{
					if (it)
						_rtti_lists[it->type_name()] = it;
				}
				return true;
			}

			bool
				Factory::add(Rtti* rtti) noexcept
			{
				_rttis.push_back(rtti);
				return true;
			}

			Rtti*
				Factory::getRTTI(const std::string& name) noexcept
			{
				return _rtti_lists[name];
			}

			Rtti*
				Factory::getRTTI(const char* name) noexcept
			{
				return _rtti_lists[name];
			}

			const Rtti*
				Factory::getRTTI(const std::string& name) const noexcept
			{
				auto it = _rtti_lists.lower_bound(name);
				for (; it != _rtti_lists.end(); ++it)
					if ((*it).first == name)
						return (*it).second;
				return nullptr;
			}

			const Rtti*
				Factory::getRTTI(const char* name) const noexcept
			{
				auto it = _rtti_lists.lower_bound(name);
				for (; it != _rtti_lists.end(); ++it)
					if ((*it).first == name)
						return (*it).second;
				return nullptr;
			}

			InterfacePtr
				Factory::createObject(const char* name, const Rtti& base) const except
			{
				assert(name);

				auto rtti = this->getRTTI(name);
				if (!rtti)
					return nullptr;

				if (rtti->isDerivedFrom(base))
					return rtti->create();

				return nullptr;
			}

			InterfacePtr
				Factory::createObject(const std::string& name, const Rtti& base) const except
			{
				assert(!name.empty());

				auto rtti = this->getRTTI(name);
				if (!rtti)
					return nullptr;

				if (rtti->isDerivedFrom(base))
					return rtti->create();

				return nullptr;
			}
		}
	}
}