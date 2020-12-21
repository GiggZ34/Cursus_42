ifconfig -a link | grep 'ether' | sed 's/ether//g' | xargs -n1
