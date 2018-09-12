#!/bin/sh

sync() {
	unison -batch -prefer newer -ignore "Path {mbed,.temp,BUILD}" ~/tmp/st7735 ~/Dropbox/sketch/mbed/st7735
}

while true
do
	sync
	sleep 10
done
