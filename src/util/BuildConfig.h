#ifndef G15TOP_BUILDCONFIG_H
#define G15TOP_BUILDCONFIG_H

#define XSTRINGIFY(a) STRINGIFY(a)
#define STRINGIFY(a) #a

namespace G15::Util {

class BuildConfig {

public:
    /**
     * Get the version number.
     *
     * @return The version number
     */
    static inline const char *getVersion() {
        return VERSION;
    }

    /**
     * Get the git revision.
     *
     * @return The git revision
     */
    static inline const char *getGitRevision() {
        return GIT_REV;
    }

    /**
     * Get the git branch.
     *
     * @return The git branch
     */
    static inline const char *getGitBranch() {
        return GIT_BRANCH;
    }

    /**
     * Get the build date.
     *
     * @return The build date
     */
    static inline const char *getBuildDate() {
        return BUILD_DATE;
    }

private:

    static const char *VERSION;
    static const char *GIT_REV;
    static const char *GIT_BRANCH;
    static const char *BUILD_DATE;
};

}

#undef STRINGIFY
#undef XSTRINGIFY

#endif