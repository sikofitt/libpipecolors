#ifdef _PIPECOLORS_H
#undef _PIPECOLORS_H
#endif
#ifndef _PIPECOLORS_H
#define _PIPECOLORS_H
#endif
namespace pipecolors {
#ifdef __cplusplus
extern "C" {
#endif

void pcprintf(const char* fmt, ...);
void pcsprintf(char **strp, const char *fmt, va_list ap);

#ifdef __cplusplus
}
#endif

}