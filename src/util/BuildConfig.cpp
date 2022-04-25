#include "BuildConfig.h"

#define XSTRINGIFY(a) STRINGIFY(a)
#define STRINGIFY(a) #a

namespace G15::Util {

#ifdef G15TOP_VERSION
const char *BuildConfig::VERSION = XSTRINGIFY(G15TOP_VERSION);
#else
const char *BuildConfig::VERSION = "v0.0.0";
#endif

#ifdef G15TOP_GIT_REV
const char *BuildConfig::GIT_REV = XSTRINGIFY(G15TOP_GIT_REV);
#else
const char *BuildConfig::GIT_REV = "unknown";
#endif

#ifdef G15TOP_GIT_BRANCH
const char *BuildConfig::GIT_BRANCH = XSTRINGIFY(G15TOP_GIT_BRANCH);
#else
const char *BuildConfig::GIT_BRANCH = "unknown";
#endif

#ifdef G15TOP_BUILD_DATE
const char *BuildConfig::BUILD_DATE = XSTRINGIFY(G15TOP_BUILD_DATE);
#else
const char *BuildConfig::BUILD_DATE = "0000-00-00 00:00:00";

#endif

}

#undef STRINGIFY
#undef XSTRINGIFY