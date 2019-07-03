#!/bin/bash
for i in {1..50000}
do
	./tcp_client localhost 8989
done
