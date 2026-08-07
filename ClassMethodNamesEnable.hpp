#pragma once

#include "Logger_status.hpp"
#include "InvokeMethod.hpp"
#include "InvokeRawList.hpp"
#include "ArrayRawMap.hpp"

namespace pankey{

	namespace Utility{

		namespace Log{

			ArrayRawMap<String,ArrayRawList<String>> g_log_map;
		
			template<class L>
			bool ArduinoClassMethodNamesEnable(int a_status, const String& a_name, const String& a_method, L a_log){
				if(!g_log_map.containKey(a_name)){
					return false;
				}
				ArrayRawList<String>* i_methods = g_log_map.getValuePointer(a_name);
				if(i_methods != nullptr){
					if(i_methods->isEmpty()){
						return true;
					}
					if(i_methods->contain(a_method)){
						return true;
					}
				}
				return false;
			}

			void pankey_Log_Class(String a_class){
				if(g_log_map.containKey(a_class)){
					return;
				}
				g_log_map.add(a_class,ArrayRawList<String>());
			}

			template<class... Args>
			void pankey_Log_Class_Method(String a_class, Args... a_methods){
				ArrayRawList<String> i_methods;
				i_methods.addPack(a_methods...);
				if(g_log_map.containKey(a_class)){
					ArrayRawList<String>* l_methods = g_log_map.getValuePointer(a_class);
					if(l_methods == nullptr){
						return;
					}
					l_methods->addCopy(i_methods);
					return;
				}
				g_log_map.add(a_class,i_methods);
			}

		}

	}

}

#ifndef pankey_Log_enable
	#define pankey_Log_enable(status,name,method,mns) pankey::Base::ArduinoClassMethodNamesEnable(status,name,method,mns)
#endif

