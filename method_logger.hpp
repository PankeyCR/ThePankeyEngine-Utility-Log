#pragma once

#ifndef pankey_Log

	#include "InvokeMethod.hpp"

	namespace pankey{

		namespace Utility{

			namespace Log{

				template<class S, class T>
				using LogMethod = pankey::Utility::Base::InvokeMethod<int,const S&,const S&,T>;

				template<class S, class T>
				struct Logging{
					static LogMethod<S,T> m_log;

					void log(int a_status, const S& a_name, const S& a_method, T a_log){
						m_log(a_status, a_name, a_method, a_log);
					}
				};

				template<class S, class T>
				LogMethod<S,T> Logging<S,T>::m_log;

				bool g_method_logger_enable = true;

				#ifndef pankey_Log_enable
					#define pankey_Log_enable(status,name,method,mns) g_method_logger_enable
				#endif
				
					
				template<class S, class L>
				void LoggingMethod(int status, const S& name, const S& method, L mns){
					if(!pankey_Log_enable(status,name,method,mns)){
						return;
					}
					Logging<S,L>::m_log(status, name, method, mns);
				}

				void LoggingStartPrint_(){
					g_method_logger_enable = true;
				}
			
				void LoggingStopPrint_(){
					g_method_logger_enable = false;
				}
			}

		}

	}

	#ifndef pankey_Log_set
		#define pankey_Log_set(S) 
	#endif 

	#ifndef pankey_Log_Split
		#define pankey_Log_Split(tittle) Serial.println("------------------Split----------------------");
	#endif
	
	#ifndef pankey_Log_Start
		#define pankey_Log_Start pankey::Arduino::LoggingStartPrint_
	#endif
	
	#ifndef pankey_Log_Stop
		#define pankey_Log_Stop pankey::Arduino::LoggingStopPrint_
	#endif 

	#ifndef pankey_Log
		#define pankey_Log(status,name,method,mns) pankey::Arduino::LoggingMethod(status,name,method,mns)
	#endif 

	#ifndef pankey_Trigger_Log
		#define pankey_Trigger_Log(trigger,status,name,method,mns) if(trigger){pankey_Log(status,name,method,mns);}
	#endif

	#ifndef pankey_Logger
		#define pankey_Logger(status,name,method,mns) pankey::Arduino::LoggingMethod(status,name,method,mns)
	#endif

	#ifndef pankey_Trigger_Logger
		#define pankey_Trigger_Logger(trigger,status,name,method,mns) if(trigger){pankey_Logger(status,name,method,mns);}
	#endif

#endif