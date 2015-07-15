/* 
 * File:   debug_macros.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 8 Апрель 2015 г., 16:09
 */

#ifndef DEBUG_MACROS_HPP
#define	DEBUG_MACROS_HPP


//------------------------------------------------------------------------------
// FIXMEs / TODOs / NOTE macros
//------------------------------------------------------------------------------
#ifdef _DEVMESSAGES
#define DO_PRAGMA(x) _Pragma (#x)
#define _QUOTE(x) # x
#define QUOTE(x) _QUOTE(x)
#define __FILE__LINE__ __FILE__ "(" QUOTE(__LINE__) ") : "
#define __Message(x) DO_PRAGMA(message(__FILE__LINE__ x))
#else
    #define __Message(x)
#endif
#define NOTE( x ) __Message( #x )

#define TODO( x ) __Message( "\n" \
	" ------------------------------------------------\n" \
	"| TODO : " #x "\n" \
	" -------------------------------------------------\n")
#define FIXME( x ) __Message( "\n" \
	" ------------------------------------------------\n" \
	"| FIXME : " #x "\n" \
	" -------------------------------------------------\n")
#define todo( x ) __Message( " TODO : " #x "\n" ) 
#define fixme( x ) __Message( " FIXME: " #x "\n" )

#endif	/* DEBUG_MACROS_HPP */

