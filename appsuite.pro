TEMPLATE = subdirs
SUBDIRS = common cot-host cot-target test \
    dhcp-server
cot-host.depends = common
cot-target.depends = common
test.depends = common
TRANSLATIONS = languages/ja_jp.ts
