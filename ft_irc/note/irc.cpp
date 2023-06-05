#include "irc.hpp"

int create_socket(string port) {
	// https://mintnlatte.tistory.com/267
	// 
	// AF_INET = 2		:	'A'dress 'F'amily 'I'nter'NET'
	// SOCK_STREAM = 1
	int sock_fd = socket(AF_INET, SOCK_STREAM, 0);	
    if (sock_fd == -1)
        throw runtime_error("Error: socket open");

	// https://snowdeer.github.io/c++/2017/08/17/setsockopt/
	// 
	// set options on socket
	// 
	// https://mintnlatte.tistory.com/275
	// 
	// SO_REUSEADDR		:	enables local address reuse
	// 						by man setsockopt
	int option_val = 1;
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &option_val, sizeof(option_val)))
        throw runtime_error("Error: socket options");

	// F_SETFL			:	Set descriptor status flags to arg
	// O_NONBLOCK		:	Non-blocking I/O; if no data is available to a read call, or if a write
    //						operation would block, the read or write call returns -1 with the error
    //						EAGAIN.
	//						by man fcntl
    if (fcntl(sock_fd, F_SETFL, O_NONBLOCK))
        throw runtime_error("Error: socket setting");

	// https://techlog.gurucat.net/292
	// 
	// struct  in_addr {
	//		u_long			s_addr;			// 32비트 IP 주소를 저장 할 구조체, network byte order
	// };
	// 
	// struct sockaddr_in {
	//		short    		sin_family;		// 주소 체계: AF_INET
	//		u_short  		sin_port;		// 16 비트 포트 번호, network byte order
	//		struct in_addr	sin_addr;		// 32 비트 IP 주소
	//		char			sin_zero[8];	// 전체 크기를 16 비트로 맞추기 위한 dummy
	// };
    struct sockaddr_in  addr = {};
	memset((void *) &addr, 0, sizeof(addr));

	// sin_family		: 항상 AF_INET을 설정한다. 이것은 필수다.
    addr.sin_family = AF_INET;

	// sin_addr			: 호스트 IP주소이다.
	// 이 변수에는 INADDR_ 로 시작하는 값, 예를 들면 'INADDR_ANY' 와 같은 것이 저장되어야 한다.
	//
	// INADDR_ANY는 자동으로 이 컴퓨터에 존재하는 랜카드 중 사용가능한 랜카드의 IP주소를 사용하라는 의미이다.
	// INADDR_ANY 를 사용하면 여러 ip주소에 들어오는 데이터를 모두 수신한다.
    addr.sin_addr.s_addr = INADDR_ANY;
	
	// sin_port			: 포트번호를 가진다.
	// 2bytes ( 16bits ) 이다. 즉, 포트번호는 0~65535 의 범위를 갖는 숫자 값이다.
	// 이 변수에 저장되는 값은 network byte order이어야 한다. 
	//
	// https://yongho1037.tistory.com/516
	// 컴퓨터 고유의 바이트 순서를 host byte order라 하고,					( little-endian )
	// 네트워크 상에서 사용하는 바이트 순서를 network byte order라 부른다.	( big-endian )
	// host byte order를 network byte order로 변환해 주는 함수가 htons 함수
	addr.sin_port = htons(atoi(port.c_str()));

	// https://badayak.com/entry/C%EC%96%B8%EC%96%B4-%EC%86%8C%EC%BC%93%EC%97%90-IP%EC%A3%BC%EC%86%8C%EC%99%80-%ED%8F%AC%ED%8A%B8%EB%B2%88%ED%98%B8-%EC%A7%80%EC%A0%95-%ED%95%A8%EC%88%98-bind
	// 
	// bind() assigns a name to an unnamed socket.
	// When a socket is created with socket(2) it exists in a name space (address family)
	// but has no name assigned.
	// bind() requests that address be assigned to the socket.
	//						by man bind
    if (bind(sock_fd, (sockaddr *) &addr, sizeof(addr)) < 0)
        throw runtime_error("Error: socket binding");

	// https://www.joinc.co.kr/w/man/2/listen
	//
	// Creation of socket-based connections requires several operations.
	// First, a socket is created with socket().
	// Next, a willingness to accept incoming connections and a queue limit
	// for incoming connections are specified with listen().
	// Finally, the connections are accepted with accept.
	// The listen() call applies only to sockets of type SOCK_STREAM.
	// 						by man bind
	// 
	// MAX_CONNECTIONS	:	the maximum length for the queue of pending connections.
	// my MAX_CONNECTIONS is 16
    if (listen(sock_fd, MAX_CONNECTIONS) < 0)
        throw runtime_error("Error: socket listening");

    return sock_fd;
}
