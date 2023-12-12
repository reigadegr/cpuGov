#!/bin/sh
chown -R 10227:10227 $(pwd)
chmod -R 0755 $(pwd)
for i in $(find $(pwd) -name "*"); do
    if [ -f $i ]; then
        chmod 0644 $i
    fi
done
