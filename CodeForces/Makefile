PEDANTIC_FLAGS = -O2 -std=c++20 -Wl,-z,stack-size=268435456 -g -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fstack-protector -Wno-unused-parameter -Wno-unused-variable -Wno-variadic-macros

NORMAL_FLAGS = -O2 -std=c++20 -Wl,-z,stack-size=268435456 -ftree-vectorize -fopt-info-vec -Wshadow

LOCAL_FLAGS = -DLOCAL

D ?= 0

ifeq ($(D), 1)
	CXXFLAGS = $(LOCAL_FLAGS) $(PEDANTIC_FLAGS)
else
	CXXFLAGS = $(LOCAL_FLAGS) $(NORMAL_FLAGS)
endif

# clean:
# 	find . -maxdepth 1 -type f -executable -delete
