#include <octoon/runtime/rtti.h>
#include <octoon/runtime/rtti_factory.h>

namespace octoon
{
	namespace runtime
	{
		Rtti::Rtti(const std::string& name, RttiConstruct creator, const Rtti* parent) noexcept
			: name_(name)
			, parent_(parent)
			, construct_(creator)
		{
			RttiFactory::instance()->add(this);
		}

		RttiInterfacePtr
		Rtti::create() const throw(std::bad_alloc)
		{
			assert(construct_);
			return std::shared_ptr<RttiInterface>(construct_());
		}

		const Rtti*
		Rtti::get_parent() const noexcept
		{
			return parent_;
		}

		const std::string&
		Rtti::type_name() const noexcept
		{
			return name_;
		}

		bool
		Rtti::is_derived_from(const Rtti* other) const noexcept
		{
			assert(other);

			for (const Rtti* cur = this; cur != 0; cur = cur->get_parent())
			{
				if (cur == other)
				{
					return true;
				}
			}

			return false;
		}

		bool
		Rtti::is_derived_from(const Rtti& other) const noexcept
		{
			return this->is_derived_from(&other);
		}

		bool
		Rtti::is_derived_from(const std::string& name) const noexcept
		{
			for (const Rtti* cur = this; cur != 0; cur = cur->get_parent())
			{
				if (cur->name_ == name)
				{
					return true;
				}
			}

			return false;
		}

		bool
		Rtti::is_derived_from(const char* const name) const noexcept
		{
			for (const Rtti* cur = this; cur != 0; cur = cur->get_parent())
			{
				if (cur->name_ == name)
				{
					return true;
				}
			}

			return false;
		}
	}
}