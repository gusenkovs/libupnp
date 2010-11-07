
#ifndef UPNPINET_H
#define UPNPINET_H

/*!
 * \file
 *
 * \brief Provides a platform independent way to include TCP/IP types and functions.
 */

#ifdef WIN32
	#include <iphlpapi.h>
	#include <winsock2.h>
	#include <Ws2tcpip.h>

	#define UpnpCloseSocket closesocket
#else
	#include <sys/param.h>
	#if (defined(BSD) && BSD >= 199306) || defined (__FreeBSD_kernel__)
		#include <ifaddrs.h>
		/* Do not move or remove the include below for "sys/socket"!
		 * Will break FreeBSD builds. */
		#include <sys/socket.h>
	#endif
	#include <netinet/in.h>

	/* include <unistd.h> for close().
	 * Do not include this file in win32. */
	#include <unistd.h>
	/* SOCKET is unsigned and is not a file descriptor on win32. */
	#define SOCKET int
	/* INVALID_SOCKET is unsigned on win32. */
	#define INVALID_SOCKET (-1)
	/* select() returns SOCKET_ERROR on win32. */
	#define SOCKET_ERROR (-1)
	#define UpnpCloseSocket close
#endif

#endif /* UPNPINET_H */

