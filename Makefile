include theos/makefiles/common.mk

TOOL_NAME = extractdyld
extractdyld_FILES = extractdyld.c
extractdyld_CFLAGS = -mdynamic-no-pic
extractdyld_LDFLAGS = -mdynamic-no-pic

include $(THEOS_MAKE_PATH)/tool.mk
