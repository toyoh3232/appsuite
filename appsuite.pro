TEMPLATE = subdirs
SUBDIRS = common cot-host \
    test
cot-host.depends = common
test.depends = common

TRANSLATIONS = languages/ja_jp.ts
