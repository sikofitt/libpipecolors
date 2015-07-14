#ifdef _PIPECOLORS_H
#undef _PIPECOLORS_H
#endif
#ifndef _PIPECOLORS_H
#define _PIPECOLORS_H
#endif

#ifdef __cplusplus
namespace pipecolors {
extern "C" {
#endif

int pcprintf( const char * format, ... );
int pcsprintf( char * str, const char * fmt, ... );

#ifdef __cplusplus
}
}
#endif
