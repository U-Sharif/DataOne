#!/bin/sh

# Modify TCP parameters
echo 10 > /proc/sys/net/ipv4/tcp_fin_timeout
echo 10 > /proc/sys/net/ipv4/tcp_keepalive_time
echo 5 > /proc/sys/net/ipv4/tcp_keepalive_intvl
echo 3 > /proc/sys/net/ipv4/tcp_keepalive_probes

echo "Checking Network"
# Wait until the network is both connected and we have a DNS server
# if we are
while true; do
  netconf | grep -q "connectionStatus='Connected'"
  if [ $? = 0 ]
  then
    netconf | grep -q "ipAddressMode='Static'"
    if [ $? = 0 ]
    then
      #don't wait around for a dns server.  It won't come
      break;
    else
      dnsconf | grep -q Server
      if [ $? = 0 ]
      then
        break;
      fi
    fi
  fi
  sleep 1
done

echo "Checking LLA"
#if LLA is enabled, wait until mdnsd starts and reset syslog
netconf | grep -q "LLAStatus='enabled'"
if [ $? = 0 ]
then
  while [ ! -f "/var/run/mdnsd.pid" ]
  do
    sleep 1;
  done

  while [ ! -f "/var/run/syslogd.pid" ]
  do
    sleep 1;
  done

  kill -9 `cat /var/run/syslogd.pid`
  sleep 2
  /sbin/syslogd -m 0 &
  sleep 2
fi

echo "Fining Reader Number"
reader_no=$(/sbin/ifconfig | grep 'inet addr:'| grep -v '127.0.0.1' | cut -d: -f2 | cut -d '.' -f4 | awk '{print $1}')

echo "Checking Internet Connection to update server."
wget -v --tries=1 --timeout=5 --spider --no-check-certificate  http://www.datasport.ag/sys/d1_update.cfm
if [[ $? -eq 0 ]]; then
    echo "Internet available. Checking for updates."
	
	if [ -d /mnt/usbfs/usbsda1 ] ; then
		echo "USB device exists"

		echo "############# UPDATE #############" >> /mnt/usbfs/usbsda1/log/log.txt
		echo "Reader No. $reader_no" >> /mnt/usbfs/usbsda1/log/log.txt
		echo "Downloading latest DataOne from http" >> /mnt/usbfs/usbsda1/log/log.txt
		echo "Downloading latest DataOne from http"

		if [ -f /cust/app/DataOne ] ; then
			curl -f -o /mnt/usbfs/usbsda1/DataOne.upg "http://www.datasport.ag/sys/d1_update.cfm?f=DataOne&readerno=$reader_no" -z /cust/app/DataOne -m180
		else 
			curl -f -o /mnt/usbfs/usbsda1/DataOne.upg "http://www.datasport.ag/sys/d1_update.cfm?f=DataOne&readerno=$reader_no" -m180
		fi

		filesize=$(du -k /mnt/usbfs/usbsda1/DataOne.upg | awk '{print $1}')
		if [ $filesize -gt 4000 ] ; then
			cp -f /mnt/usbfs/usbsda1/DataOne.upg /cust/app/DataOne
			rm /mnt/usbfs/usbsda1/DataOne.upg
			
			echo "Downloading latest DataOne.ini from http" >> /mnt/usbfs/usbsda1/log/log.txt
			echo "Downloading latest DataOne.ini from http"

			if [ -f /cust/app/DataOne.ini ] ; then
				curl -f -o /mnt/usbfs/usbsda1/DataOne.ini.upg "http://www.datasport.ag/sys/d1_update.cfm?f=DataOne.ini&readerno=$reader_no" -z /cust/app/DataOne.ini -m30
			else
				curl -f -o /mnt/usbfs/usbsda1/DataOne.ini.upg "http://www.datasport.ag/sys/d1_update.cfm?f=DataOne.ini&readerno=$reader_no" -m30
			fi

			cp -f /mnt/usbfs/usbsda1/DataOne.ini.upg /cust/app/DataOne.ini
			rm /mnt/usbfs/usbsda1/DataOne.ini.upg
		fi
		echo "##################################" >> /mnt/usbfs/usbsda1/log/log.txt
	fi

else
        echo "Could not access update server. Skipping update check."
fi

echo "Starting DataOne."
while true ; do
	if [ -f /cust/app/DataOne ] ; then
		if [ -x /cust/app/DataOne ] ; then
			echo "############# START #############" >> /mnt/usbfs/usbsda1/log/log.txt
			date >> /mnt/usbfs/usbsda1/log/log.txt
			if [ ! -s "/cust/app/DataOne.ini" ] ; then
				echo "DataOne.ini corrupted." >> /mnt/usbfs/usbsda1/log/log.txt
				echo "Copying DataOne.ini from master." >> /mnt/usbfs/usbsda1/log/log.txt
				cp /cust/app/DataOne.ini.master /cust/app/DataOne.ini
			fi
			echo "Starting DataOne." >> /mnt/usbfs/usbsda1/log/log.txt
			echo "#################################" >> /mnt/usbfs/usbsda1/log/log.txt
			/cust/app/DataOne
		fi
		sleep 3
	else
		exit 0
	fi
done


