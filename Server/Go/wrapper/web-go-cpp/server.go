package main

import "C"

import (
    "fmt"
    "log"
    "net/http"
    "github.com/gorilla/mux"
)

import "./daemon"
var dring = daemon.NewDaemon()

var daemonMessage string = "Go: I started the started"
var serverMessage string = "" +
    "Routes of interest:\n" +
    "http://127.0.0.1:8080/\n" +
    "http://127.0.0.1:8080/reply/server/sanity/\n" +
    "http://127.0.0.1:8080/echo/daemon/rabbit/\n" +
    "http://127.0.0.1:8080/non_existing/"

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
    fmt.Fprint(w, daemonMessage, "\n")
}

func ServerReply(w http.ResponseWriter, request *http.Request) {
    vars := mux.Vars(request)
    fmt.Fprintln(w, "Server:", vars["serverReply"])
}

func DaemonEcho(w http.ResponseWriter, request *http.Request) {
    vars := mux.Vars(request)
    echo := vars["daemonEcho"]
    dring.Echo(echo)
}

