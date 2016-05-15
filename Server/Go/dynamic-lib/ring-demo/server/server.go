package main

import (
    "C"
    "fmt"
    "log"
    "net/http"
    "github.com/gorilla/mux"
    //"../daemon"
)

var daemonMessage string = ""
var serverMessage string = "" +
    "Listening on http://127.0.0.1:8080\n" +
    "Routes of interest:\n" +
    "http://127.0.0.1:8080/reply/server/sanity/\n" +
    "http://127.0.0.1:8080/echo/daemon/rabbit/\n" +
    "http://127.0.0.1:8080/non_existing/"

//export initServer
func initServer(_message *C.char) *C.char{
    daemonMessage = C.GoString(_message)
    return C.CString(serverMessage)
}

//export startServer
func startServer(){
    router := mux.NewRouter().StrictSlash(true)
    router.HandleFunc("/", Root)
    router.HandleFunc("/reply/server/{serverReply}/", ServerReply)
    router.HandleFunc("/echo/daemon/{daemonEcho}/", DaemonEcho)
    fmt.Println(serverMessage)
    log.Fatal(http.ListenAndServe(":8080", router))
}

func main(){
    startServer()
}

// Handlers

func Root(w http.ResponseWriter, request *http.Request){
    fmt.Fprint(w, serverMessage, "\n")
}

func ServerReply(w http.ResponseWriter, request *http.Request) {
    vars := mux.Vars(request)
    fmt.Fprintln(w, "Server Reply:", vars["serverReply"])
}

func DaemonEcho(w http.ResponseWriter, request *http.Request) {
    vars := mux.Vars(request)
    echo := vars["daemonEcho"]
    fmt.Println("Server:", echo)

    // daemon = daemon.NewDaemon()
    // daemon.Echo(C.CString("Daemon: " + echo))
}

