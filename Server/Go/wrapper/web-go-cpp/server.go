package main

import (
    "fmt"
    "net/http"
    "./daemon"
)

func main(){

    dring := daemon.NewDaemon()

    fmt.Println(dring.Echo())

    diveAndGrab := daemon.NewStringVector()
    dring.Echo(diveAndGrab)
    fmt.Println(diveAndGrab.Get(0))

    http.HandleFunc("/", handlerRoot)

    fmt.Println("Listening on http://127.0.0.1:8080")
    http.ListenAndServe(":8080", nil)
}

func handlerRoot(w http.ResponseWriter, request *http.Request){

    fmt.Fprint(w, "Home page\n")

}
