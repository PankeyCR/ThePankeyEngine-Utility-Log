#pragma once

#include "CharPointer.hpp"

namespace pankey{

	namespace Utility{

		namespace Log{

			template<class Policy>
			class Logger{
				public:
					using STRING_TYPE = typename Policy::SIZE_TYPE;

				

				protected:
					pankey::Utility::Base::InvokeMethod<int,const pankey::Type::Array::CharPointer&,,const pankey::Type::Array::CharPointer&,> m_log;
			};

		}

	}

}



