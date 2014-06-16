
#ifndef _ERRORS_H
#define _ERRORS_H

#include "../Define.h"

namespace AceBot
{

    DECLSPEC_NORETURN void Assert(char const* file, int line, char const* function, char const* message) ATTR_NORETURN;

    DECLSPEC_NORETURN void Fatal(char const* file, int line, char const* function, char const* message) ATTR_NORETURN;

    DECLSPEC_NORETURN void Error(char const* file, int line, char const* function, char const* message) ATTR_NORETURN;

    void Warning(char const* file, int line, char const* function, char const* message);

} // namespace AceBot

#define WPAssert(cond) do { if (!(cond)) AceBot::Assert(__FILE__, __LINE__, __FUNCTION__, #cond); } while (0)
#define WPFatal(cond, msg) do { if (!(cond)) AceBot::Fatal(__FILE__, __LINE__, __FUNCTION__, (msg)); } while (0)
#define WPError(cond, msg) do { if (!(cond)) AceBot::Error(__FILE__, __LINE__, __FUNCTION__, (msg)); } while (0)
#define WPWarning(cond, msg) do { if (!(cond)) AceBot::Warning(__FILE__, __LINE__, __FUNCTION__, (msg)); } while (0)

#define ASSERT WPAssert

#endif
