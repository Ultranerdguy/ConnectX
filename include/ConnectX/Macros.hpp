#ifndef _CONNECT_X_MACROS_HPP_
#define _CONNECT_X_MACROS_HPP_

#ifndef TOSTRING
#define TOSTRING(x) #x
#endif // #ifndef TOSTRING

#ifndef MACROSTRING
#define MACROSTRING(x) TOSTRING(x)
#endif // #ifndef MACROSTRING

#ifndef TODO
#define TODO(x) "TODO " MACROSTRING(__FILE__) MACROSTRING(__LINE__) " - " TOSTRING(x) "\n"
#endif // #ifndef TODO

#endif // #ifndef _CONNECT_X_MACROS_HPP_