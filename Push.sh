#!/bin/sh

rm -rf $(dirname "$0")/*.bak

#通用推送模板
git gc --prune=all
su -c sh $(pwd)/权限.sh
git add .
git commit -m "$1"
git push -f origin main
