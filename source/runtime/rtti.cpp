#include <octoon/runtime/rtti.h>
#include <octoon/runtime/rtti_factory.h>

namespace octoon
{
	namespace runtime
	{
		namespace rtti
		{
			__ImplementClass(Interface, "RTTI")

				Rtti::Rtti(const std::string& name, RttiConstruct creator, const Rtti* parent) noexcept
				: _name(name)
				, _parent(parent)
				, _construct(creator)
			{
				Factory::instance()->add(this);
			}

			InterfacePtr
				Rtti::create() const except
			{
				assert(_construct);
				return std::shared_ptr<Interface>(_construct());
			}

			const Rtti*
				Rtti::getParent() const noexcept
			{
				return _parent;
			}

			const std::string&
				Rtti::type_name() const noexcept
			{
				return _name;
			}

			bool
				Rtti::isDerivedFrom(const Rtti* other) const
			{
				assert(other);

				for (const Rtti* cur = this; cur != 0; cur = cur->getParent())
				{
					if (cur == other)
					{
						return true;
					}
				}

				return false;
			}

			bool
				Rtti::isDerivedFrom(const Rtti& other) const
			{
				return this->isDerivedFrom(&other);
			}

			bool
				Rtti::isDerivedFrom(const std::string& name) const
			{
				for (const Rtti* cur = this; cur != 0; cur = cur->getParent())
				{
					if (cur->_name == name)
					{
						return true;
					}
				}

				return false;
			}

			bool
				Interface::isInstanceOf(const Rtti* rtti) const noexcept
			{
				return this->rtti() == rtti;
			}

			bool
				Interface::isInstanceOf(const Rtti& rtti) const noexcept
			{
				return this->rtti() == &rtti;
			}

			bool
				Interface::isInstanceOf(const std::string& className) const noexcept
			{
				return this->rtti()->type_name() == className;
			}

			bool
				Interface::isA(const Rtti* rtti) const noexcept
			{
				return this->rtti()->isDerivedFrom(rtti);
			}

			bool
				Interface::isA(const Rtti& rtti) const noexcept
			{
				return this->rtti()->isDerivedFrom(rtti);
			}

			bool
				Interface::isA(const std::string& rttiName) const noexcept
			{
				return this->rtti()->isDerivedFrom(rttiName);
			}
		}
	}
}