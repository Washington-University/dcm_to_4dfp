#!/bin/sh
top_srcdir=$1
distdir=$2
if [ `cat ${distdir}/ChangeLog | wc -l` = "1" ]; then
    chmod u+w ${distdir}/ChangeLog && cd ${top_srcdir} && git log --stat --name-only --date=short --abbrev-commit >${distdir}/ChangeLog
fi
