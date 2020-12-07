#!/bin/bash -ex

#  pack.*.bash - Bash script to help packaging samd core releases.
#  Copyright (c) 2015 Arduino LLC.  All right reserved.
#
#  This library is free software; you can redistribute it and/or
#  modify it under the terms of the GNU Lesser General Public
#  License as published by the Free Software Foundation; either
#  version 2.1 of the License, or (at your option) any later version.
#
#  This library is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#  Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public
#  License along with this library; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#
#
# Modified for Mac by Andres Sabas @ Electronic Cats
# For MacOS install gnu-tar 'brew install gnu-tar'
#

VERSION=`grep version= ../platform.txt | sed 's/version=//g'`

cd ../
PWD=`pwd`
FOLDERNAME=`basename $PWD`
THIS_SCRIPT_NAME=`basename $0`
FILENAME=electroniccats-samd-$VERSION.tar.bz2
rm -rf $FILENAME
cd ..
cp -R $FOLDERNAME samd
pwd
tar --exclude=extras/** --exclude=realese --exclude=.git* -jcvf $FILENAME samd 
rm -rf samd
cd -
pwd
mv ../$FILENAME realese/$FILENAME

CHKSUM=`shasum -a 256 realese/$FILENAME | awk '{ print $1 }'`
SIZE=`wc -c realese/$FILENAME | awk '{ print $1 }'`

cat extras/package_index.json.Release.template |
sed "s/%%VERSION%%/${VERSION}/" |
sed "s/%%FILENAME%%/${FILENAME}/" |
sed "s/%%CHECKSUM%%/${CHKSUM}/" |
sed "s/%%SIZE%%/${SIZE}/" > realese/package_electroniccats-samd-${VERSION}_index.json
