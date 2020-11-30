**Don't look at the code, it sucks.**

Output format copied from http://jodies.de/ipcalc

**USAGE**

1. make to create executable "calc.exe"
2. ./calc to execute program

Input:

	IP + Netmask

	IP format: n1.n2.n3.n4
	Netmask: '24' or 255.255.255.0 (CIDR or Dotted Decimal notation)

Output for IP calculator:

	Address:	n1.n2.n3.n4		[binary representation]
	Netmask:	n1.n2.n3.n4		[binary representation]
	Wildcard:	n1.n2.n3.n4		[binary representation]
	=>
	Network:	n1.n2.n3.n4/NM	[binary representation] (Class type)
	Broadcast:	n1.n2.n3.n4		[binary representation]
	Hostmin:	n1.n2.n3.n4		[binary representation]
	Hostmax:	n1.n2.n3.n4		[binary representation]
	Hosts/net:	[Amount] - (2 ^ (32 - netmask) - 1).

Output for just netmask:

	Netmask:	[Dotted Decimal] [Binary] [CIDR]
	Hosts/net:	[Amount]
