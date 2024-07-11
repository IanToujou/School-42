ifconfig -a | grep ether | awk '{print $2}' | head -n 3
