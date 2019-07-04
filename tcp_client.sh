#!/bin/bash
if [ $# -ne 1 ]
then
	echo "Usage: tcp_client.sh <port>"
	exit 1
fi

for i in {1..50000}
do
	client/tcp_client localhost $1
done
