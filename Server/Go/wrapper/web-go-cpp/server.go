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
    "http://127.0.0.1:8080/account/contacts/toto/\n" +
    "http://127.0.0.1:8080/non_existing/"

func startServer(){
    router := mux.NewRouter().StrictSlash(true)
    router.HandleFunc("/", Root)
    router.HandleFunc("/reply/server/{serverReply}/", ServerReply)
    router.HandleFunc("/echo/daemon/{daemonEcho}/", DaemonEcho)
    router.HandleFunc("/account/contacts/{ring_id}/", GetContacts)
    fmt.Println(serverMessage)
    log.Fatal(http.ListenAndServe(":8080", router))
}

func main(){
    startServer()
}

// Handlers

func Root(w http.ResponseWriter, request *http.Request){
    fmt.Fprint(w, daemonMessage)
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


func GetContacts(w http.ResponseWriter, request *http.Request) {
    vars := mux.Vars(request)
    ring_id := vars["ring_id"]

    vcontacts := daemon.NewStringVector()
    dring.GetContacts(ring_id, vcontacts)

    contacts := make([]string, vcontacts.Size())
    for i := 0; i < int(vcontacts.Size()); i++ {
        contacts = append(contacts, vcontacts.Get(i))
    }

    fmt.Fprint(w, contacts)
}

