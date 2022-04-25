/*
 * Copyright (C) 2022 Fabian Ruhland <ruhland@hhu.de>
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

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