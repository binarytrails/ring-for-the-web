bin_PROGRAMS = ring_http
ring_http_SOURCES = main.cpp \
					parserHTTP.cpp \
					parserHTTP.hpp \
					response.cpp \
					response.hpp \
					router.cpp \
					router.hpp \
					json.hpp \
					connection.hpp \
					manager.hpp \
					server.hpp \
					http_status.hpp


ring_http_CXXFLAGS = -std=c++14 -g -Wall -Wextra -Wno-reorder -pedantic -DBOOST_LOG_DYN_LINK
ring_http_LDFLAGS = -lpthread -lboost_system -lboost_log -lboost_program_options -lcrypto -lssl
ring_http_LDADD = /usr/local/lib/libring.la 
